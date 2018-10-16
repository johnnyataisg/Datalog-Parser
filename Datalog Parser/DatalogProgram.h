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
	DatalogProgram() 
	{
	}
	~DatalogProgram() 
	{
	}
	void setScheme(Scheme scheme)
	{
		schemeList = scheme;
	}
	void setFact(Fact fact)
	{
		factList = fact;
	}
	void setRule(Rule rule)
	{
		ruleList = rule;
	}
	void setQuery(Query query)
	{
		queryList = query;
	}
	string toString()
	{
		string output;
		output += schemeList.toString() + factList.toString() + ruleList.toString() + queryList.toString() + domainToString();
		return output;
	}
	void sortFacts()
	{
		for (size_t i = 0; i < factList.getPredicates().size(); i++)
		{
			for (size_t t = 0; t < factList.getPredicates().at(i).size(); t++)
			{
				domain.insert(factList.getPredicates().at(i).at(t)->toString());
			}
		}
	}
	string domainToString()
	{
		string output;
		stringstream ss;
		ss << domain.size();
		sortFacts();
		output += "Domain(" + ss.str() + "):\n";
		for (set<string>::iterator iter = domain.begin(); iter != domain.end(); ++iter)
		{
			output += "  " + *iter + "\n";
		}
		return output;
	}
};

#endif