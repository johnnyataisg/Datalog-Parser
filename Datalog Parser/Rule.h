#pragma once
#ifndef RULE_H_
#define RULE_H_
#include "Rules.h"

using namespace std;

class Rule
{
private:
	vector<Rules> ruleList;
public:
	//Default constructor
	Rule() {};

	//Destructor
	~Rule() {};

	//Push a rule onto this vector
	void push(Rules rules)
	{
		ruleList.push_back(rules);
	}

	//Push a predicate onto the last Rules member of this vector
	void pushPred(Predicate pred)
	{
		ruleList.back().push(pred);
	}

	//Deallocate all memory of parameter pointers within all predicates inside Rules contained by this vector
	void clear()
	{
		for (size_t i = 0; i < ruleList.size(); i++)
		{
			for (size_t t = 0; t < ruleList.at(i).getHead().size(); t++)
			{
				delete ruleList.at(i).getHead().at(t);
			}
			for (size_t x = 0; x < ruleList.at(i).getPredicates().size(); x++)
			{
				for (size_t p = 0; p < ruleList.at(i).getPredicates().at(x).size(); p++)
				{
					ruleList.at(i).getPredicates().at(x).at(p)->clearContent();
					delete ruleList.at(i).getPredicates().at(x).at(p);
				}
			}
		}
	}

	//Print out all rule predicates
	string toString()
	{
		string output;
		stringstream ss;
		ss << ruleList.size();
		output += "Rules(" + ss.str() + "):\n";
		for (size_t i = 0; i < ruleList.size(); i++)
		{
			output += "  " + ruleList.at(i).toString() + ".\n";
		}
		return output;
	}
};

#endif
