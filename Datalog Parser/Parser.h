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

//Define a set of symbols used to annotate the grammar productions
enum Symbols { datalogProgram, scheme, schemeList, idList, fact, factList, rule, ruleList, headPredicate, predicate, predicateList, 
			   parameter, parameterList, expression, Operator, query, queryList, stringList, comma, period, qmark, lpar, rpar,
			   colon, cdash, multiply, add, schemes, facts, rules, queries, id, str, ef, Start, End };

enum parseState {PS, PR, PQ, STRPARAM, IDPARAM, EXPPARAM};

class Parser
{
private:
	parseState state;
	parseState substate;
	vector<Token> tokenList;
	int index;
	stack<Symbols> ss;
	//Array of token types to be referenced by TokenType values
	string myList[18] = { "COMMA", "PERIOD", "Q_MARK", "LEFT_PAREN", "RIGHT_PAREN", "COLON", "COLON_DASH"
						, "MULTIPLY", "ADD", "SCHEMES", "FACTS", "RULES", "QUERIES", "ID", "STRING", "COMMENT", "UNDEFINED", "EOF" };
	DatalogProgram datalog;
	//Temporary data members to help instantialize datalog
	string temp;
	Parameter param;
	Predicate pred;
	string temp2;
public:
	Parser(list<Token> list);
	~Parser();
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
};

#endif