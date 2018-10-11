#pragma once
#ifndef DATALOG_PROGRAM_H_
#define DATALOG_PROGRAM_H_
#include "LexicalAnalyzer.h"
#include "Schemes.h"

using namespace std;

class DatalogProgram
{
private:
	Schemes schemes;
	//Facts facts;
	//Rules rules;
	//Queries queries;
	//Dom1ain domain;
public:
	DatalogProgram(LexicalAnalyzer lex)
	{
		//domain = new Domain();
		schemes = new Schemes(lex);
		//facts = new Facts(lex, domain);
		//rules = new Rules(lex);
		//queries = new Queries(lex);
	}

};

#endif