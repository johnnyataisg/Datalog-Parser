#pragma once
#ifndef FACT_H_
#define FACT_H_

using namespace std;

class Fact
{
private:
	vector<Predicate> predicates;
public:
	//Default constructor
	Fact() {};

	//Destructor
	~Fact() {};

	//Push a predicate onto the vector
	void push(Predicate pred)
	{
		predicates.push_back(pred);
	}

	//Getter for vector<Predicate>
	vector<Predicate> getPredicates()
	{
		return this->predicates;
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

	//Print out all fact predicates
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
};

#endif