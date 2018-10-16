#pragma once
#ifndef EXPRESSION_H_
#define EXPRESSION_H_

using namespace std;

class Expression : public Parameter
{
private:
	Parameter* leftParam;
	string sign;
	Parameter* rightParam;
public:
	Expression() 
	{
		leftParam = NULL;
		sign = "";
		rightParam = NULL;
	}

	Expression(Parameter* param1)
	{
		leftParam = param1;
		rightParam = NULL;
	}

	virtual ~Expression() {};

	void setOperator(string oper)
	{
		sign = oper;
	}

	void setLParam(Parameter* param1)
	{
		leftParam = param1;
	}

	void setRParam(Parameter* param2)
	{
		rightParam = param2;
	}
	
	void clearContent()
	{
		if (leftParam != NULL)
		{
			leftParam->clearContent();
			delete leftParam;
		}
		if (rightParam != NULL)
		{
			rightParam->clearContent();
			delete rightParam;
		}
	}

	string toString()
	{
		string output;
		output += "(" + leftParam->toString() + sign + rightParam->toString() + ")";
		return output;
	}
};

#endif