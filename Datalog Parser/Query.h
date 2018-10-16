#pragma once
#ifndef QUERY_H_
#define QUERY_H_

using namespace std;

class Query
{
private:
	vector<Predicate> predicates;
public:
	//Default constructor
	Query() {};

	//Destructor
	~Query() {};

	//Pushes a predicate onto the vector
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

	//Prints out all query predicates
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
};

#endif