#pragma once
#ifndef STRING_H_
#define STRING_H_
#include "Parameter.h"

using namespace std; 

class String : public Parameter
{
private:
	string value;
public:
	String() {};
	String(string str)
	{
		value = str;
	}
	virtual ~String() {};
	string toString()
	{
		return value;
	}
};

#endif