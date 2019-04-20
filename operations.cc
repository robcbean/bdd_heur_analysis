/*
//<< ROB : 22/12/2016 Is zero if all are zero * operations.cc+
 *
 *  Created on: 20 dic. 2016
 *      Author: rbean
 */

#include "operations.h"




//<< ROB : 20/12/2016 Get a pointer string from a BDD CUDD Node
BddNode get_pointer(DdManager* _mgr, DdNode* _f)
{
	BddNode ret(_f,NULL);
    
	return ret;
}
//>> ROB : 20/12/2016 Get a pointer string from a BDD CUDD Node



//<< ROB : 20/12/2016 Get the node index
unsigned int get_index(DdManager* _mgr, DdNode* _node){
	unsigned int ret = UINT_MAX;
	if(!Cudd_IsConstant(_node)){
		//ret =  Cudd_NodeReadIndex(_node);
		int node_index = Cudd_NodeReadIndex(_node);
		ret = Cudd_ReadIndex(_mgr,node_index);
	}
	return ret;
}
//>> ROB : 20/12/2016 Get the node index


//<< ROB : 20/12/2016 Get the regular node index
unsigned int get_index_regular(DdManager* _mgr, DdNode* _node){
	unsigned int ret = UINT_MAX;
	if ( !Cudd_IsConstant(_node) ) {
		//ret = Cudd_NodeReadIndex(_node);
		int node_index = Cudd_NodeReadIndex(_node);
		ret = Cudd_ReadIndex(_mgr,node_index);
	}
	return ret;
}
//<< ROB : 20/12/2016 Get the regular node index



//<< ROB : 20/12/2016 Get index from a vector array
unsigned int get_index(DdManager* _manager, DdNode** _nodes, unsigned int _nnodes ) {

	unsigned int ret = UINT_MAX;
	unsigned int index;

	for(unsigned int i=0;i<_nnodes;i++)
	{
		index = get_index(_manager,_nodes[i]);
		if( index < ret ){
			ret = index;
		}
	}
	return ret;
}
//<< ROB : 20/12/2016 Get index from a vector array

unsigned int get_minor_index(DdManager* _manager, DdNode** _nodes, unsigned int _nnodes)
{
	unsigned int ret = -1;
	unsigned int index = UINT_MAX;

	for(unsigned int i=0; i<_nnodes;i++ )
	{
		if(_nodes[i] != NULL ){
			if(get_index(_manager,_nodes[i]) < index ){
				index = get_index(_manager,_nodes[i]);
				ret = index;
			}
		}
	}
	return ret;
}


unsigned int get_minor_index_regular(DdManager* _manager, DdNode** _nodes, unsigned int _nnodes)
{
	unsigned int ret = -1;
	unsigned int index = UINT_MAX;

	for(unsigned int i=0; i<_nnodes;i++ )
	{
		if(_nodes[i] != NULL ){
			if(!Cudd_IsConstant( _nodes[i]) ){
				if(get_index_regular(_manager,_nodes[i]) < index ){
					index = get_index_regular(_manager,_nodes[i]);
					ret = index;
				}
			}
		}
	}
	return ret;
}



bool Cudd_IsConstant(DdNode** _nodes, unsigned int _nnodes)
{
	bool ret = false;
	int nConstants = 0;
	for(unsigned int i=0;i <_nnodes; i++)
	{
		if(Cudd_IsConstant(_nodes[i])){
			nConstants = nConstants + 1;
		}
	}
	ret = nConstants == _nnodes;
	return ret;
}


unsigned int get_regular_minor_index(DdManager* _manager, DdNode** _nodes, unsigned int _nnodes)
{
	unsigned int ret = -1;
	unsigned int index = UINT_MAX;

	for(unsigned int i=0; i<_nnodes;i++ )
	{
		if(_nodes[i] != NULL ){
			if(get_index_regular(_manager,_nodes[i]) < index ){
				index = get_index_regular(_manager,_nodes[i]);
				ret = index;
			}
		}
	}
	return ret;
}


//<< ROB :14/01/2017 Is one for only one node
bool is_one_node(DdManager* _manager, DdNode* _node )
{
	bool ret = Cudd_ReadOne(_manager) == _node;

	return ret;

}
//<< ROB :14/01/2017 Is one for only one node


//<< ROB :14/01/2017 Is one for only one node
bool is_zero_node(DdManager* _manager, DdNode* _node )
{
	bool ret = Cudd_Not(Cudd_ReadOne(_manager)) == _node;

	return ret;

}
//<< ROB :14/01/2017 Is one for only one node



//<< ROB : 22/12/2016 Is one if all are one
bool is_one(DdManager* _manager, DdNode** _nodes, unsigned int _nnodes, unsigned int _index) {

	bool ret=false;
	DdNode* node;
	DdNode* one = Cudd_ReadOne(_manager);
	unsigned int oneNodes=0;
	unsigned int constNodes=0;

	for(unsigned int i=0;i<_nnodes;i++)
	{
		node = _nodes[i];
		if( Cudd_IsConstant(node))
		{
			constNodes++;
			if( node == one  )
			{
				oneNodes = oneNodes  + 1;
			}
		}
	}
	ret = (oneNodes  == _nnodes);
	return ret;
}
//<< ROB : 22/12/2016 Is one if all are one

//<< ROB : 22/12/2016 Is zero if all are zero
bool is_zero(DdManager* _manager, DdNode** _nodes, unsigned int _nnodes, unsigned int _index ) {

	bool ret=false;
	DdNode* node;
	DdNode* zero = Cudd_Not(Cudd_ReadOne(_manager));
	unsigned int constNodes=0;
	unsigned int zeroNodes=0;

	for(unsigned int i=0;i<_nnodes; i++)
	{
		if(Cudd_IsConstant(node))
		{
			node = _nodes[i];
			constNodes++;
			if(  zero == node   )
			{
				zeroNodes++;
			}
		}
	}

	ret = (zeroNodes > 0 && constNodes == _nnodes);


	return ret;
}
//>> ROB : 22/12/2016 Is zero if all are zero

//<< ROB : 22/12/2016 Convert pointers to string
BddNode convert_pointers_to_string(DdManager* _manager, DdNode** _nodes, unsigned int _nnodes)
{
    BddNode ret(_nodes[0],_nodes[1]);
    
	return ret;
}
//<< ROB : 22/12/2016 Is zero if all are zero


//<< ROB : 23/12/2016 Update reduced nodes
void update_reduced_nodes(unsigned int _curindex, unsigned int _nextindex, unsigned int* _var_low, unsigned int* _var_high, unsigned int _size)
{
	if (_nextindex > _size ) {
		//return;
		_nextindex = _size;
		//_nextindex = _size;
	}
	if( _nextindex == 0 ) {
		return;
		//_nextindex = _size;
	}
	for( unsigned int i=_curindex+1; i < _nextindex; i++ ) {
		_var_high[i] = 1;
		_var_low[i] = 1;
	}
	return;

}
//>> ROB : 23/12/2016 Update reduced nodes

int get_depend_conflic_aux(
		std::unordered_map<unsigned long,bool>* _visited,
		DdManager* _manager,
		DdNode** _nodes,
		unsigned int _nnodes,
		unsigned int _size,unsigned int* _var_low, unsigned int* _var_high, std::unordered_map<unsigned long,bool>* _reaches_one)
{
	int ret = 0;
	DdNode** R = new DdNode*[_nnodes];
	DdNode** f = new DdNode*[_nnodes];
	DdNode** fn = new DdNode*[_nnodes];
	unsigned int top[_nnodes];

	//<< ROB : 22/12/2016 Calculate regular nodes and levels
	for(unsigned int i=0;i<_nnodes;i++){
		R[i] = _nodes[i];
		top[i] = get_index_regular(_manager,R[i]);
	}
	//<< ROB : 23/12/2016 Set node has visited
	BddNode strnode = convert_pointers_to_string(_manager,R,_nnodes);
	unsigned int index = get_minor_index_regular(_manager,R,_nnodes);


	if(_visited->find(strnode.getKey()) != _visited->end()){
		delete[] R;
		delete[] f;
		delete[] fn;
		return  (*_reaches_one)[strnode.getKey()];
	}

	(*_visited)[strnode.getKey()] = true;

	if(!Cudd_IsConstant(R,_nnodes)){
		for(unsigned int i=0;i<_nnodes;i++)
		{

			if(!Cudd_IsConstant(R[i])){
				if(top[i] == index)
				{
					f[i] =  Cudd_T(R[i]);
					fn[i] = Cudd_E(R[i]);
					if(Cudd_IsComplement(R[i])){
						fn[i] = Cudd_Not(fn[i]);
						f[i] = Cudd_Not(f[i]);
					}
				}else{
					f[i] = R[i];
					fn[i]= R[i];
				}
			}else{
				f[i] = R[i];
				fn[i] = R[i];
			}
		}

#if EXTRA_INFO
		std::cerr<<"multi_get_depend_conflic:Visiting nodes index: ";
		for(unsigned int i=0;i<_nnodes;i++)
		{
			std::cerr<<top[i]<<"\t";
		}
		std::cerr<<std::endl;
#endif

		unsigned int indexT = get_minor_index_regular(_manager,f,_nnodes);
		unsigned int indexE = get_minor_index_regular(_manager,fn,_nnodes);

		//<< ROB : 23/12/2016 Does v reach the 1-terminal through high?
		if(is_one(_manager,f,_nnodes,index)){
#if EXTRA_INFO
			std::cerr<<"multi_get_depend_conflic:One found from f index "<<index<<" indexT:"<<indexT<<std::endl;
#endif
			(*_reaches_one)[strnode.getKey()] = true;
			_var_high[index] = 1;
			if(indexT > index )
			{
				update_reduced_nodes(index,indexT,_var_low,_var_high,_size);
			}

		} else {
			if (!is_zero(_manager,f,_nnodes,index)){
				//keep searching
#if EXTRA_INFO
				std::cerr<<"multi_get_depend_conflic:Descending f index "<<index<<" indexT:"<<indexT<<std::endl;
#endif
				if(get_depend_conflic_aux(_visited,_manager,f,_nnodes,_size,_var_low, _var_high, _reaches_one)){
					(*_reaches_one)[strnode.getKey()] = true;
					_var_high[index] = 1;
					if(indexT > index){
						update_reduced_nodes(index,indexT,_var_low,_var_high,_size);
					}
				}
			}
		}

		//>> ROB : 23/12/2016 Does v reach the 1-terminal through low?
		if(is_one(_manager,fn,_nnodes,index)){
#if EXTRA_INFO
			std::cerr<<"multi_get_depend_conflic:One found from fn index "<<index<<" indexE:"<<indexE<<std::endl;
#endif
			(*_reaches_one)[strnode.getKey()] = true;
			_var_low[index] = 1;
			//the 1-terminal nodes is reached
			if(indexE > index )
			{
				update_reduced_nodes(index,indexE,_var_low,_var_high,_size);
			}

		}else
			{
				if (!is_zero(_manager,fn,_nnodes,index)){
					//keep searching
#if EXTRA_INFO
					std::cerr<<"get_depend_conflic:Descending fn index "<<index<<" indexE:"<<indexE<<std::endl;
#endif
					if(get_depend_conflic_aux(_visited,_manager,fn,_nnodes,_size,_var_low, _var_high, _reaches_one)){
						(*_reaches_one)[strnode.getKey()] = true;
						_var_low[index] = 1;
						if(indexE > index)
						{
							update_reduced_nodes(index,indexE,_var_low,_var_high,_size);
						}
					}
				}
			}
	}

	delete[] R;
	delete[] f;
	delete[] fn;

	ret = (_reaches_one->find(strnode.getKey()) != _reaches_one->end()) ;

	return ret;

}


void get_depen_conflic(DdManager* _manager, DdNode** _nodes, unsigned int _nnodes,unsigned int _num_vars, unsigned int* _var_low, unsigned int* _var_high)
{

	std::unordered_map<unsigned long,bool>* visited = new std::unordered_map<unsigned long,bool>();
	std::unordered_map<unsigned long,bool>* reaches_one = new std::unordered_map<unsigned long,bool>();


	get_depend_conflic_aux(visited,_manager,_nodes,_nnodes,_num_vars,_var_low,_var_high,reaches_one);
	//<< ROB : 06/01/2017 Display visited nodes equivalent to count all nodes
	fprintf(stderr,"Dead core visited nodes decomposed %lu\n",visited->size());
	//>> ROB : 06/01/2017 Display visited nodes equivalent to count all nodes
}



void get_all_dependencies_conflicts (
		unsigned int* _var_high_2,unsigned int* _var_high_1,
		unsigned int* var_low_2,unsigned int* var_low_1,
		unsigned int**  all_vars_dependencies,
		unsigned int** all_vars_conflicts,unsigned int num_var, unsigned int var)
{
	unsigned int index;

	for (unsigned int i = 0; i < num_var; ++i){
		if (_var_high_1[i] && var_low_1[i] && i != var)
		{
			if (!_var_high_2[i] && var_low_2[i])
			{
				index = all_vars_conflicts[var][0];
				index++;
				all_vars_conflicts[var][0] = index;
				all_vars_conflicts[var][index] = i;
			}
			else if (_var_high_2[i] && !var_low_2[i] && i != var)
			{
				index = all_vars_dependencies[i][0];
				index++;
				all_vars_dependencies[i][0] = index;
				all_vars_dependencies[i][index] = var;
			}
		}
	}
}



feature_model_info* calc_dead_core_and_impact_exclusion(DdManager* _manager, DdNode** _nodes,unsigned int _nnodes, unsigned int _nvars)
{
	feature_model_info* ret = new feature_model_info;
	unsigned int* var_low_1 = (unsigned int*)calloc(_nvars,sizeof(unsigned int));
	unsigned int* var_high_1 =(unsigned int*)calloc(_nvars,sizeof(unsigned int));
	bool* complements = (bool*)calloc(_nvars,sizeof(bool));


	get_depen_conflic(_manager,_nodes,_nnodes,_nvars,var_low_1,var_high_1);
	ret->var_low = var_low_1;
	ret->var_high = var_high_1;

	return ret;
}




bool get_depend_conflic_aux_only_one(
		std::unordered_map<unsigned long,bool>* _visited,
		DdManager* _manager,
		DdNode* _f,
		unsigned int _size,unsigned int* _var_low, unsigned int* _var_high, std::unordered_map<unsigned long,bool>* _reaches_one)
{

	DdNode *F,*fv,*fvn,*one;

	unsigned int index,indexT,indexE;


	F = _f;
	one = Cudd_ReadOne(_manager);
	index =  get_index_regular(_manager,F);
	BddNode strnode = get_pointer(_manager,F);

	//std::cerr<<"\tdead_core_one:"<<index<<"-->"<<_direction<<std::endl;


	if(_visited->find(strnode.getKey()) != _visited->end()){
		return (*_reaches_one)[strnode.getKey()];
	}
#if EXTRA_INFO
	std::cerr<<"get_depend:visiting index:"<<index<<std::endl;
#endif

	if(!Cudd_IsConstant(F)){


		//<< ROB 19/01/2017 Don't set visited R2 reduced nodes
		(*_visited)[strnode.getKey()] = true;

		fv = Cudd_T(F);
		fvn = Cudd_E(F);
		if(Cudd_IsComplement(_f)){
			fv  = Cudd_Not(fv);
			fvn = Cudd_Not(fvn);
		}
		indexT = get_index_regular(_manager,fv);
		indexE = get_index_regular(_manager,fvn);
		//does v reach the 1-terminal throwgh high?
		if( one == fv )
		{
#if EXTRA_INFO
			std::cerr<<"get_depend:reach one T:"<<index<<std::endl;
#endif
			_var_high[index] = 1;
			(*_reaches_one)[strnode.getKey()] = true;
			if(indexT > index )
			{
				update_reduced_nodes(index,indexT,_var_low,_var_high,_size);
			}
		}else{
			//keep searching
#if EXTRA_INFO
			std::cerr<<"get_depend:keep searchingT:"<<index<<std::endl;
#endif
			if(Cudd_Not(one) != fv ){
				if(get_depend_conflic_aux_only_one(_visited,_manager,fv,_size,_var_low,_var_high,_reaches_one)){
					(*_reaches_one)[strnode.getKey()] = true;
					_var_high[index] = 1;
					if(indexT > index )
					{
						update_reduced_nodes(index,indexT,_var_low,_var_high,_size);
					}
				}
			}
		}

		//does v reach the 1-terminal throwgh low?
		if(one == fvn)
		{
#if EXTRA_INFO
			std::cerr<<"get_depend:reach one F:"<<index<<std::endl;
#endif
			_var_low[index] = 1;
			(*_reaches_one)[strnode.getKey()] = true;
			if(indexE > index )
			{
				update_reduced_nodes(index,indexE,_var_low,_var_high,_size);
			}
		}
		else
		{
			//keep searching
			if(Cudd_Not(one) != fvn )
			{
#if EXTRA_INFO
				std::cerr<<"get_depend:keep searching F:"<<index<<std::endl;
#endif
				if(get_depend_conflic_aux_only_one(_visited,_manager,fvn,_size,_var_low,_var_high,_reaches_one)){
					(*_reaches_one)[strnode.getKey()] = true;
					_var_low[index] = 1;
					if(indexE > index )
					{
						update_reduced_nodes(index,indexE,_var_low,_var_high,_size);
					}
				}
			}
		}
	}
	return _reaches_one->find(strnode.getKey()) != _reaches_one->end();
}


feature_model_info* calc_dead_core_and_impact_exclusion_only_one(DdManager* _manager, DdNode* _node, unsigned int _nvars)
{
	feature_model_info* ret = new feature_model_info;
	unsigned int* var_low = (unsigned int*)calloc(_nvars,sizeof(unsigned int));
	unsigned int* var_high =(unsigned int*)calloc(_nvars,sizeof(unsigned int));
	std::unordered_map<unsigned long,bool>* visited = new std::unordered_map<unsigned long,bool>();
	std::unordered_map<unsigned long,bool>* reaches_one = new std::unordered_map<unsigned long,bool>();


	get_depend_conflic_aux_only_one(
			visited,
			_manager,
			_node,
			_nvars,var_low,var_high,reaches_one);

	ret->var_high = var_high;
	ret->var_low = var_low;


	//<< ROB : 06/01/2017 Display visited nodes equivalent to count all nodes
	fprintf(stderr,"Dead core visited nodes only one %lu\n",visited->size());
	//>> ROB : 06/01/2017 Display visited nodes equivalent to count all nodes


	return ret;

}

double usecs_to_secs(unsigned long _usecs)
{
    double ret = ((double)_usecs) / 1000000.0;
    return ret;
}

