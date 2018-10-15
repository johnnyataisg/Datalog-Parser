#pragma once
#ifndef DATALOG_PROGRAM_H_
#define DATALOG_PROGRAM_H_
#include <algorithm>
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
	vector<string> domain;
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
				domain.push_back(factList.getPredicates().at(i).at(t)->toString());
			}
		}
		sort(domain.begin(), domain.end());
		domain.erase(unique(domain.begin(), domain.end()), domain.end());
	}
	string domainToString()
	{
		string output;
		stringstream ss;
		ss << domain.size();
		output += "Domain(" + ss.str() + "):\n";
		for (size_t i = 0; i < domain.size(); i++)
		{
			output += "  " + domain.at(i) + "\n";
		}
		return output;
	}
};

#endif