#pragma once
#ifndef ID_H_
#define ID_H_
#include "Parameter.h"
#include <vector>
#include "LexicalAnalyzer.h"

using namespace std;

class Id : Parameter
{
private:
	Token id;
public:
	Id(LexicalAnalyzer& lex) 
	{
		 lex.getNextToken(ID);
	}
	string print()
	{
		return id.getValue();
	}
};

#endif