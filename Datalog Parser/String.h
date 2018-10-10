#pragma once
#ifndef STRING_H_
#define STRING_H_
#include "Parameter.h"

using namespace std;

class String : public Parameter
{
private:
	int num;
public:
	String(int number)
	{
		num = number;
	}
	~String() {};
	int ret()
	{
		return num;
	}
};

#endif