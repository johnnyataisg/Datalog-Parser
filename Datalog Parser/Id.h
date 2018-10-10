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
	vector<Token> vec;
public:
	Id(LexicalAnalyzer& lex) 
	{
		 lex.getNextToken(SCH);
	}
	string print()
	{
		return id.getValue();
	}
};

#endif