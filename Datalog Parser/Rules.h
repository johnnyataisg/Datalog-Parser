#pragma once
#ifndef RULES_H_
#define RULES_H_

using namespace std;

class Rules
{
private:
	Predicate headPred;
	vector<Predicate> predicates;
public:
	Rules() {};
	Rules(Predicate head)
	{
		headPred = head;
	}
	~Rules() {};
	Predicate getHead()
	{
		return this->headPred;
	}
	vector<Predicate> getPredicates()
	{
		return this->predicates;
	}
	void setHead(Predicate pred)
	{
		headPred = pred;
	}
	void push(Predicate pred)
	{
		predicates.push_back(pred);
	}
	string toString()
	{
		string output;
		output += headPred.toString() + " :- ";
		for (size_t i = 0; i < predicates.size(); i++)
		{
			if (i != predicates.size() - 1)
			{
				output += predicates.at(i).toString() + ",";
			}
			else
			{
				output += predicates.at(i).toString();
			}
		}
		return output;
	}
};

#endif