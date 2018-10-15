#pragma once
#ifndef PREDICATE_H_
#define PREDICATE_H_
#include <vector>
#include "String.h"
#include "Id.h"
#include "Expression.h"

using namespace std;

class Predicate
{
private:
	Id id;
	vector<Parameter*> parameterList;
public:
	Predicate() {};
	~Predicate() 
	{
	};
	void push(Parameter* param)
	{
		parameterList.push_back(param);
	}
	void clear()
	{
		parameterList.clear();
		id.clear();
	}
	size_t size()
	{
		return parameterList.size();
	}
	Parameter*& at(size_t index)
	{
		return this->parameterList.at(index);
	}
	void setID(Id ID)
	{
		id = ID;
	}
	string toString()
	{
		string output;
		output += id.toString() +'(';
		for (size_t i = 0; i < parameterList.size(); i++)
		{
			output += parameterList.at(i)->toString();
			if (i < parameterList.size() - 1)
			{
				output += ',';
			}
			else
			{
				output += ')';
			}
		}
		return output;
	}
};

#endif