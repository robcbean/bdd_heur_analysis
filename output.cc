#include "output.h"
#include <algorithm>
#include <list>


int get_max_nodes(std::vector<BDD>& _output, unsigned long& _total_nodes){

  int ret=0;
  int tmp;
  _total_nodes = 0;
  for(std::vector<BDD>::iterator it=_output.begin(); it != _output.end(); it++ ){
    tmp = Cudd_DagSize((*it).getNode());
    if (tmp > ret ) {
        ret = tmp;
    }
    _total_nodes = _total_nodes + tmp;
  }
  //std::cerr<<"total nodes"<<total<<std::endl;
  return ret;

}


void print_output(int _nvars,std::string _file,std::string _type, Cudd& _mgr,std::vector<BDD>& _output, bool _procesed, BDD* _function, bool _get_total)
{
	
	unsigned long total_nodes=-1;
	int max_nodes=-1;
    if(_procesed){
	    max_nodes = get_max_nodes(_output,total_nodes);
	    if(_get_total && _function != NULL ){
	        total_nodes = Cudd_DagSize(_function->getNode());
	    }
	}
	std::cout<<_file<<"\t"<<_type<<"\t"<<max_nodes<<"\t"<<total_nodes<<std::endl;
}

double get_user_time()
{
	struct rusage usage;
	double ret=0;
	
	getrusage(RUSAGE_SELF,&usage);
	ret = usage.ru_utime.tv_usec / 1000000.00 + usage.ru_utime.tv_sec;
	
	return ret;

}

double get_diftime(double _ts, double _te)
{
	double ret = _te -_ts;
	return ret;
}

void writeSize(std::string _file_name, std::string _function_file, std::string _order, std::vector<unsigned long>& _count_nodes, std::vector<unsigned long> _count_id)
{
    std::ofstream fd;
    int i=0;

    fd.open(_file_name.c_str(),std::ios::out | std::ios::app);

    for(int i=0; i < _count_nodes.size(); i++ )
    {
        fd<<_function_file<<"\t"<<_order<<"\t"<<i<<"\t"<<_count_id[i]<<"\t"<<_count_nodes[i]<<std::endl;
    }

    fd.close();
}


double ddCountPathLenToNonZero(DdNode* N, st_table* table, int length, std::list<int>& lengths)
{

    DdNode    *node, *Nt, *Ne;
    double    paths, *ppaths, paths1, paths2;
    void    *dummy;

    node = Cudd_Regular(N);
    if (cuddIsConstant(node)) {
        double value = (double) !(Cudd_IsComplement(N) || cuddV(node)==DD_ZERO_VAL);
        if( value != 0)
        //<< ROB : 02/06/2018 Save length
            lengths.push_back(length);
        //<< ROB : 02/06/2018 Save length

        return(value);
    }

    if (st_lookup(table, N, &dummy)) {
    	paths = *(double *) dummy;
    	return(paths);
    }

    Nt = cuddT(node); Ne = cuddE(node);
    if (node != N) {
        Nt = Cudd_Not(Nt); Ne = Cudd_Not(Ne);
    }

    paths1 = ddCountPathLenToNonZero(Nt,table,length+1,lengths);
    if (paths1 == (double)CUDD_OUT_OF_MEM) return((double)CUDD_OUT_OF_MEM);
    paths2 = ddCountPathLenToNonZero(Ne,table,length+1,lengths);
    if (paths2 == (double)CUDD_OUT_OF_MEM) return((double)CUDD_OUT_OF_MEM);
    paths = paths1 + paths2;

    ppaths = ALLOC(double,1);
    if (ppaths == NULL) {
        return((double)CUDD_OUT_OF_MEM);
    }

    *ppaths = paths;

    if (st_add_direct(table, N, ppaths) == ST_OUT_OF_MEM) {
	FREE(ppaths);
	return((double)CUDD_OUT_OF_MEM);
    }


    return(paths);
}

double averagePathLenToNonZero(DdNode* N)
{
    double ret = 0;
    int length=0;
    std::list<int> lengths;
    st_table* table = st_init_table(st_ptrcmp,st_ptrhash);

    ddCountPathLenToNonZero(N,table,length,lengths);
    for(std::list<int>::iterator it = lengths.begin(); it != lengths.end(); it++)
    {
        ret = ret + (*it);
    }

    if(lengths.size() != 0 )
        ret = ret / lengths.size();

    return ret;
}






double countMinterms(Cudd& _mgr,BDD& _node)
{
    double ret = 0.0;
    FILE *fd = fopen(MINTERMS_FILE,"w");
    std::string line;

    _mgr.SetStdout(fd);
    _node.PrintMinterm();
    fclose(fd);
    _mgr.SetStdout(stdout);

    std::ifstream ffd(MINTERMS_FILE);
    if(ffd.is_open()){
        while (getline(ffd,line)){
            if(line.find("-") != std::string::npos)
            {
                double tmp = 0;
                for(int i=0;i<line.size();i++){
                    if (line[i] == '-'){
                        tmp = tmp + 1;
                    }
                }
                ret = ret + pow(2.0,tmp);
            }else{
                ret = ret + 1.0;
            }
            //std::cout<<line<<std::endl;
        }
    }
    ffd.close();


    return ret;
}


std::vector<std::string> split(const std::string& str, const std::string& delim)
{
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}


extern "C" int cuddSymmCheck(DdManager * table,int  x,int  y);


double  auxiliarTotalSymmetric(Cudd& _mgr, BDD& _bdd, std::list<unsigned int>& _symmetric_variables, unsigned int* _symmetrics_pairs, unsigned int* _symmetric_continius_pairs, unsigned int _total_variables )
{
    double ret=0;
    for(unsigned int j=0; j < _total_variables; j++ ){

        for(unsigned int i= j + 1 ; i < _total_variables; i++)
        {
            ret = ret + 1;
            //if(Cudd_VarsAreSymmetric(_mgr.getManager(),_bdd.getNode(),i,_current_variable) && Cudd_VarsAreSymmetric(_mgr.getManager(),_bdd.getNode(),_current_variable,i))
            bool bSymmetric  = cuddSymmCheck(_mgr.getManager(),j,i);
            if( bSymmetric )
            {
                if(std::find(_symmetric_variables.begin(),_symmetric_variables.end(),j) == _symmetric_variables.end())
                {
                    _symmetric_variables.push_back(j);
                }
                if(std::find(_symmetric_variables.begin(),_symmetric_variables.end(),i) == _symmetric_variables.end())
                {
                    _symmetric_variables.push_back(i);
                }

                
                (*_symmetrics_pairs) = (*_symmetrics_pairs) + 1;
                
                if( (_mgr.ReadPerm(i) + 1) ==  _mgr.ReadInvPerm(j) ||  ( _mgr.ReadInvPerm(j) + 1) ==  _mgr.ReadInvPerm(i)  )
                {
                    (*_symmetric_continius_pairs) = (*_symmetric_continius_pairs) + 1;
                }
                
            }
        }
    }
    return ret;
}


std::string totalSymmetric(Cudd& _mgr,BDD& _bdd, unsigned int _total_variables, bool _count_continuos, bool _after  )
{
    std::string ret = "";
    char buf[100];
    unsigned int symmetrics_pairs=0;
    unsigned int symmetric_continius_pairs=0;
    std::list<unsigned int> symmetric_variables;
    double total_coninuos = 0;

    double total = auxiliarTotalSymmetric(_mgr, _bdd, symmetric_variables, &symmetrics_pairs, &symmetric_continius_pairs, _total_variables);
    double number_of_variables = symmetric_variables.size();
    
    //double variables_percent = number_of_variables / (double)_total_variables*100;
    double variables_percent = symmetrics_pairs / (double)total*100.0;
    //double variables_percent = symmetrics_pairs;

    if(symmetrics_pairs != 0 )
    {
        total_coninuos = (double)symmetric_continius_pairs / (double)total*100.0;
    }


    //sprintf(buf,"%g",symmetrics_pairs / total * 100);
    if(!_after){
        sprintf(buf,"%g\t%g",total,variables_percent);
        if(_count_continuos)
        {

            sprintf(buf,"%s\t%g",buf,total_coninuos);
        }
     } else{
            sprintf(buf,"%g",total_coninuos);
     }

    ret = buf;

    return ret;
}


