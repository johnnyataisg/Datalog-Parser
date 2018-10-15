#pragma once
#ifndef PARSER_H_
#define PARSER_H_
#include <list>
#include <stack>
#include <sstream>
#include <iostream>
#include "DatalogProgram.h"
#include "Token.h"

using namespace std;

enum Symbols { datalogProgram, scheme, schemeList, idList, fact, factList, rule, ruleList, headPredicate, predicate, predicateList, 
			   parameter, parameterList, expression, Operator, query, queryList, stringList, comma, period, qmark, lpar, rpar,
			   colon, cdash, multiply, add, schemes, facts, rules, queries, id, str, ef, Start, End };

class Parser
{
private:
	vector<Token> tokenList;
	int index;
	stack<Symbols> ss;
	string myList[18] = { "COMMA", "PERIOD", "Q_MARK", "LEFT_PAREN", "RIGHT_PAREN", "COLON", "COLON_DASH"
						, "MULTIPLY", "ADD", "SCHEMES", "FACTS", "RULES", "QUERIES", "ID", "STRING", "COMMENT", "UNDEFINED", "EOF" };
	string temp;
	DatalogProgram datalog;
	Scheme allSchemes;
	Fact allFacts;
	Rule allRules;
	Query allQueries;
	Predicate pred;
public:
	Parser(list<Token> list);
	~Parser();
	string print();
	void match(TokenType tt);
	void parse();
	void parseDatalog();
	void parseScheme();
	void parseSchemeList();
	void parseIdList();
	void parseFact();
	void parseFactList();
	void parseRule();
	void parseRuleList();
	void parseHeadPredicate();
	void parsePredicate();
	void parsePredicateList();
	void parseParameter();
	void parseParameterList();
	void parseExpression();
	void parseOperator();
	void parseQuery();
	void parseQueryList();
	void parseStringList();
	DatalogProgram getProgram()
	{
		return datalog;
	}
};

#endif