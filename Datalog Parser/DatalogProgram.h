#pragma once
#ifndef DATALOG_PROGRAM_H_
#define DATALOG_PROGRAM_H_
#include <set>
#include "Scheme.h"
#include "Fact.h"
#include "Rule.h"
#include "Query.h"

using namespace std;

class DatalogProgram
{
private:
	Scheme schemeList;
	Fact factList;
	Rule ruleList;
	Query queryList;
	set<string> domain;
public:
	//Default constructor
	DatalogProgram() {};

	//Destructor
	~DatalogProgram() {};

	void setScheme(Scheme scheme)
	{
		schemeList = scheme;
	}

	//Setter for factList
	void setFact(Fact fact)
	{
		factList = fact;
	}

	//Setter for ruleList
	void setRule(Rule rule)
	{
		ruleList = rule;
	}

	//Setter for queryList
	void setQuery(Query query)
	{
		queryList = query;
	}

	//Copies all ID's and strings within the list of fact predicates into a set which removes duplicates and sorts them and initializes domain to be equal to this set
	void createDomain()
	{
		for (size_t i = 0; i < factList.getPredicates().size(); i++)
		{
			for (size_t t = 0; t < factList.getPredicates().at(i).size(); t++)
			{
				domain.insert(factList.getPredicates().at(i).at(t)->toString());
			}
		}
	}

	//Returns all elements of domain
	string domainToString()
	{
		string output;
		stringstream ss;
		ss << domain.size();
		createDomain();
		output += "Domain(" + ss.str() + "):\n";
		for (set<string>::iterator iter = domain.begin(); iter != domain.end(); ++iter)
		{
			output += "  " + *iter + "\n";
		}
		return output;
	}

	//Prints out the entire datalog program
	string toString()
	{
		string output;
		output += schemeList.toString() + factList.toString() + ruleList.toString() + queryList.toString() + domainToString();
		return output;
	}
};

#endif