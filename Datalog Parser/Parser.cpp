#include "Parser.h"

Parser::Parser(list<Token> list)
{
	while (!list.empty())
	{
		tokenList.push_back(list.front());
		list.pop_front();
	}
	index = 0;
	ss.push(End);
	ss.push(Start);
}

Parser::~Parser() {}

string Parser::print()
{
	string output;
	for (size_t i = 0; i < tokenList.size(); i++)
	{
		stringstream iss;
		iss << tokenList.at(i).getLineNum();
		string num = iss.str();
		output += "(" + myList[tokenList.at(i).getType()] + "," + "\"" + tokenList.at(i).getValue() + "\"," + num + ")" + "\n";
	}
	return output;
}

void Parser::match(TokenType tt)
{
	if (tokenList.at(index).getType() == tt)
	{
		ss.pop();
		index++;
	}
	else
	{
		throw tokenList.at(index);
	}
}

void Parser::parse()
{
	ss.pop();
	ss.push(datalogProgram);
	try 
	{
		parseDatalog();
		cout << "Success!" << endl;
	}
	catch (Token token)
	{
		cout << "Failure!" << endl << "  {" << myList[token.getType()] << "," << token.getValue() << "," << token.getLineNum() << ")" << endl;
	}
}

void Parser::parseDatalog()
{
	ss.pop();
	ss.push(queryList);
	ss.push(query);
	ss.push(colon);
	ss.push(queries);
	ss.push(ruleList);
	ss.push(colon);
	ss.push(rules);
	ss.push(factList);
	ss.push(colon);
	ss.push(facts);
	ss.push(schemeList);
	ss.push(scheme);
	ss.push(colon);
	ss.push(schemes);
	match(SCH);
	match(COL);
	parseScheme();
	parseSchemeList();
	match(FAC);
	match(COL);
	parseFactList();
	match(RUL);
	match(COL);
	parseRuleList();
	match(QUE);
	match(COL);
	parseQuery();
	parseQueryList();
	match(EF);
}

void Parser::parseScheme()
{
	if (tokenList.at(index).getType() == ID)
	{
		ss.pop();
		ss.push(rpar);
		ss.push(idList);
		ss.push(id);
		ss.push(lpar);
		ss.push(id);
		match(ID);
		match(LPAR);
		match(ID);
		parseIdList();
		match(RPAR);
	}
	else
	{
		throw tokenList.at(index);
	}
}

void Parser::parseSchemeList()
{
	if (tokenList.at(index).getType() == ID)
	{
		ss.pop();
		ss.push(schemeList);
		ss.push(scheme);
		parseScheme();
		parseSchemeList();
	}
	else if (tokenList.at(index).getType() == FAC)
	{
		ss.pop();
		ss.push(facts);
	}
	else
	{
		throw tokenList.at(index);
	}
}

void Parser::parseIdList()
{
	if (tokenList.at(index).getType() == COM)
	{
		ss.pop();
		ss.push(idList);
		ss.push(id);
		ss.push(comma);
		match(COM);
		match(ID);
		parseIdList();
	}
	else if (tokenList.at(index).getType() == RPAR)
	{
		ss.pop();
		ss.push(rpar);
	}
	else
	{
		throw tokenList.at(index);
	}
}

void Parser::parseFact()
{
	if (tokenList.at(index).getType() == ID)
	{
		ss.pop();
		ss.push(period);
		ss.push(rpar);
		ss.push(stringList);
		ss.push(str);
		ss.push(lpar);
		ss.push(id);
		match(ID);
		match(LPAR);
		match(STR);
		parseStringList();
		match(RPAR);
		match(PER);
	}
	else
	{
		throw tokenList.at(index);
	}
}

void Parser::parseFactList()
{
	if (tokenList.at(index).getType() == ID)
	{
		ss.pop();
		ss.push(factList);
		ss.push(fact);
		parseFact();
		parseFactList();
	}
	else if (tokenList.at(index).getType() == RUL)
	{
		ss.pop();
		ss.push(rule);
	}
	else
	{
		throw tokenList.at(index);
	}
}

void Parser::parseRule()
{
	if (tokenList.at(index).getType() == ID)
	{
		ss.pop();
		ss.push(period);
		ss.push(predicateList);
		ss.push(predicate);
		ss.push(cdash);
		ss.push(headPredicate);
		parseHeadPredicate();
		match(COLD);
		parsePredicate();
		parsePredicateList();
		match(PER);
	}
	else
	{
		throw tokenList.at(index);
	}
}

void Parser::parseRuleList()
{
	if (tokenList.at(index).getType() == ID)
	{
		ss.pop();
		ss.push(ruleList);
		ss.push(rule);
		parseRule();
		parseRuleList();
	}
	else if (tokenList.at(index).getType() == QUE)
	{
		ss.pop();
		ss.push(queries);
	}
	else
	{
		throw tokenList.at(index);
	}
}

void Parser::parseHeadPredicate()
{
	if (tokenList.at(index).getType() == ID)
	{
		ss.pop();
		ss.push(rpar);
		ss.push(idList);
		ss.push(id);
		ss.push(lpar);
		ss.push(id);
		match(ID);
		match(LPAR);
		match(ID);
		parseIdList();
		match(RPAR);
	}
	else
	{
		throw tokenList.at(index);
	}
}

void Parser::parsePredicate()
{
	if (tokenList.at(index).getType() == ID)
	{
		ss.pop();
		ss.push(rpar);
		ss.push(parameterList);
		ss.push(parameter);
		ss.push(lpar);
		ss.push(id);
		match(ID);
		match(LPAR);
		parseParameter();
		parseParameterList();
		match(RPAR);
	}
	else
	{
		throw tokenList.at(index);
	}
}

void Parser::parsePredicateList()
{
	if (tokenList.at(index).getType() == COM)
	{
		ss.pop();
		ss.push(predicateList);
		ss.push(predicate);
		ss.push(comma);
		match(COM);
		parsePredicate();
		parsePredicateList();
	}
	else if (tokenList.at(index).getType() == PER)
	{
		ss.pop();
		ss.push(period);
	}
	else
	{
		throw tokenList.at(index);
	}
}

void Parser::parseParameter()
{
	if (tokenList.at(index).getType() == STR)
	{
		ss.pop();
		ss.push(str);
		match(STR);
	}
	else if (tokenList.at(index).getType() == ID)
	{
		ss.pop();
		ss.push(id);
		match(ID);
	}
	else if (tokenList.at(index).getType() == LPAR)
	{
		ss.pop();
		ss.push(expression);
		parseExpression();
	}
	else
	{
		throw tokenList.at(index);
	}
}

void Parser::parseParameterList()
{
	if (tokenList.at(index).getType() == COM)
	{
		ss.pop();
		ss.push(parameterList);
		ss.push(parameter);
		ss.push(comma);
		match(COM);
		parseParameter();
		parseParameterList();
	}
	else if (tokenList.at(index).getType() == RPAR)
	{
		ss.pop();
		ss.push(rpar);
	}
	else
	{
		throw tokenList.at(index);
	}
}

void Parser::parseExpression()
{
	if (tokenList.at(index).getType() == LPAR)
	{
		ss.pop();
		ss.push(rpar);
		ss.push(parameter);
		ss.push(Operator);
		ss.push(parameter);
		ss.push(lpar);
		match(LPAR);
		parseParameter();
		parseOperator();
		parseParameter();
		match(RPAR);
	}
	else
	{
		throw tokenList.at(index);
	}
}

void Parser::parseOperator()
{
	if (tokenList.at(index).getType() == ADD)
	{
		ss.pop();
		ss.push(add);
		match(ADD);
	}
	else if (tokenList.at(index).getType() == MUL)
	{
		ss.pop();
		ss.push(multiply);
		match(MUL);
	}
	else
	{
		throw tokenList.at(index);
	}
}

void Parser::parseQuery()
{
	if (tokenList.at(index).getType() == ID)
	{
		ss.pop();
		ss.push(qmark);
		ss.push(predicate);
		parsePredicate();
		match(QM);
	}
	else
	{
		throw tokenList.at(index);
	}
}

void Parser::parseQueryList()
{
	if (tokenList.at(index).getType() == ID)
	{
		ss.pop();
		ss.push(queryList);
		ss.push(query);
		parseQuery();
		parseQueryList();
	}
	else if (tokenList.at(index).getType() == EF)
	{
		ss.pop();
		ss.push(End);
	}
	else
	{
		throw tokenList.at(index);
	}
}

void Parser::parseStringList()
{
	if (tokenList.at(index).getType() == COM)
	{
		ss.pop();
		ss.push(stringList);
		ss.push(str);
		ss.push(comma);
		match(COM);
		match(STR);
		parseStringList();
	}
	else if (tokenList.at(index).getType() == RPAR)
	{
		ss.pop();
		ss.push(rpar);
	}
	else
	{
		throw tokenList.at(index);
	}
}