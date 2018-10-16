#pragma once
#ifndef ID_H_
#define ID_H_

using namespace std;

class Id : public Parameter
{
private:
	string value;
public:
	Id() {};
	Id(string str)
	{
		value = str;
	}
	virtual ~Id() {};
	string toString()
	{
		return value;
	}
	void clear()
	{
		value = "";
	}
	void clearContent() {};
};

#endif