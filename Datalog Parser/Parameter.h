#pragma once
#ifndef PARAMETER_H_
#define PARAMETER_H_

using namespace std;

class Parameter
{
private:
	string value;
	string type;
public:
	Parameter() {};
	Parameter(string value, string type)
	{
		this->value = value;
		this->type = type;
	}

	string getValue()
	{
		return this->value;
	}

	string getType()
	{
		return this->type;
	}

	string toString()
	{
		return this->value;
	}

	class Expression
	{
	public:
		Expression(Parameter* param, string * oper, Parameter * param2)
		{
			this->param = param;
			this->oper = oper;
			this->param2 = param2;
		}
		Parameter * param;
		string * oper;
		Parameter * param2;
	private:
	};
};

#endif