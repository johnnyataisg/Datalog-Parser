#pragma once
#ifndef FACT_H_
#define FACT_H_

using namespace std;

class Fact
{
private:
	vector<Predicate> predicates;
public:
	Fact() {};
	~Fact() {};
	void push(Predicate pred)
	{
		predicates.push_back(pred);
	}
	vector<Predicate> getPredicates()
	{
		return this->predicates;
	}
	string toString()
	{
		string output;
		stringstream ss;
		ss << predicates.size();
		output += output + "Facts(" + ss.str() + "):\n";
		for (size_t i = 0; i < predicates.size(); i++)
		{
			output += "  " + predicates.at(i).toString() + ".\n";
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