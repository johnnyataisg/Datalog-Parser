#pragma once
#ifndef SCHEME_H_
#define SCHEME_H_
#include "Predicate.h"

using namespace std;

class Scheme
{
private:
	vector<Predicate> predicates;
public:
	//Default constructor
	Scheme() {};

	//Destructor
	~Scheme() {};

	//Push a predicate onto the vector
	void push(Predicate pred)
	{
		predicates.push_back(pred);
	}

	//Deallocate all memory of parameter pointers contained by this vector's elements
	void clear()
	{
		for (size_t i = 0; i < predicates.size(); i++)
		{
			for (size_t t = 0; t < predicates.at(i).size(); t++)
			{
				delete predicates.at(i).at(t);
			}
		}
	}

	//Print out all scheme predicates
	string toString()
	{
		string output;
		stringstream ss;
		ss << predicates.size();
		output += output + "Schemes(" + ss.str() + "):\n";
		for (size_t i = 0; i < predicates.size(); i++)
		{
			output += "  " + predicates.at(i).toString() +"\n";
		}
		return output;
	}
	
};

#endif