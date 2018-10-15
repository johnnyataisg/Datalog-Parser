#pragma once
#ifndef QUERY_H_
#define QUERY_H_

using namespace std;

class Query
{
private:
	vector<Predicate> predicates;
public:
	Query() {};
	~Query() {};
	void push(Predicate pred)
	{
		predicates.push_back(pred);
	}
	string toString()
	{
		string output;
		stringstream ss;
		ss << predicates.size();
		output += "Queries(" + ss.str() + "):\n";
		for (size_t i = 0; i < predicates.size(); i++)
		{
			output += "  " + predicates.at(i).toString() + "?\n";
		}
		return output;
	}
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
};

#endif