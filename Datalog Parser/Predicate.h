#pragma once
#ifndef PREDICATE_H_
#define PREDICATE_H_
#include "String.h"
#include <vector>

using namespace std;

class Predicate
{
private:
	vector<Parameter*> parameters;
public:
	Predicate(Parameter* parameter)
	{
		parameters.push_back(parameter);
	}
	~Predicate() 
	{
	}
	vector<Parameter*> getVec()
	{
		return parameters;
	}
};
#endif