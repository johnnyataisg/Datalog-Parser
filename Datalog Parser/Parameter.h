#pragma once
#ifndef PARAMETER_H_
#define PARAMETER_H_

using namespace std;

class Parameter
{
private:
public:
	Parameter() {};
	virtual ~Parameter() {};
	virtual string toString() = 0;
	virtual void clearContent() = 0;
};

#endif