/*
 * operations.h
 *
 *  Created on: 20 dic. 2016
 *      Author: rbean
 */

#ifndef OPERATIONS_H_

#include <cuddInt.h>
#include <cuddObj.hh>
#include <string>
#include <list>
#include <map>
#include <unordered_map>
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <functional>

#define OPERATIONS_H_


class BddNode
{
public:
    DdNode* m_left;
    DdNode* m_right;
    
    
public:
    static std::hash<std::string> getHash()
    {
        static std::hash<std::string> ret;
        
        return ret;
    }
    BddNode(DdNode* _left=NULL, DdNode* _right=NULL)
    {
        this->m_left = _left;
        this->m_right = _right;
        //this->m_dir = _dir;
        //<< ROB : ever 0
        //std::cerr<<"left:"<<_left<<"\tright:"<<_right<<"\tdir:"<<_dir<<std::endl;
    }
    unsigned long getKey()
    {
        unsigned long ret;
        char buffer[100];
        
        sprintf(buffer,"%p-%p",this->m_left,this->m_right);
        std::string str = buffer;
        
        ret = BddNode::getHash()(str);
        
        
        return ret;
        
    }
};

#define BUFFER_SIZE 100

struct feature_model_info
{
	std::list<unsigned int> core;
	std::list<unsigned int> dead;
	std::unordered_map<unsigned int,std::list<unsigned int>*> impact_set;
	std::unordered_map<unsigned int,std::list<unsigned int>*> exclusion_set;
	unsigned int* var_low;
	unsigned int* var_high;
};


void get_depen_conflic(DdManager* _manager, DdNode** _nodes, unsigned int _nnodes, unsigned int _num_vars,unsigned int* _var_low,unsigned int* _var_high);
feature_model_info* calc_dead_core_and_impact_exclusion(DdManager* _manager, DdNode** _nodes,unsigned int _nnodes, unsigned int _nvars);
feature_model_info* calc_dead_core_and_impact_exclusion_only_one(DdManager* _manager, DdNode* _node, unsigned int _nvars);


#endif /* OPERATIONS_H_ */
