#include "Parser.h"

//Constructor: Takes the list of tokens inside the LexicalAnalyzer object and loads it into a vector data member of the Parser object
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

//Destructor: Deallocates all memory used for parameter pointers by calling a clear function from each member of DatalogProgram
Parser::~Parser()
{
}

//Matches the current input token with a token that should come next and saves its value to string temp
void Parser::match(TokenType tt)
{
	if (tokenList.at(index).getType() == tt)
	{
		temp = tokenList.at(index).getValue();
		ss.pop();
		index++;
	}
	else
	{
		throw tokenList.at(index);
	}
}

//Begin the parsing process
void Parser::parse()
{
	ss.pop();
	ss.push(datalogProgram);
	try 
	{
		parseDatalog();
		cout << "Success!" << endl;
		cout << datalog.toString();
	}
	catch (Token token)
	{	
		cout << "Failure!" << endl << "  (" << myList[token.getType()] << ",\"" << token.getValue() << "\"," << token.getLineNum() << ")" << endl;
	}
}

//Begin a recursive process of parsing the datalog program
void Parser::parseDatalog()
{
	//Push production symbols onto the stack and continue further productions until a token is encountered and match it with the tokens from the vector
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

//Parse the scheme section of the datalog program
void Parser::parseScheme()
{
	if (tokenList.at(index).getType() == ID)
	{
		state = PS;
		ss.pop();
		ss.push(rpar);
		ss.push(idList);
		ss.push(id);
		ss.push(lpar);
		ss.push(id);
		match(ID);
		datalog.pushSchemeList(Predicate((temp)));
		temp = "";
		match(LPAR);
		match(ID);
		datalog.addSchemeParam(Parameter(temp, "ID"));
		temp = "";
		parseIdList();
		match(RPAR);
	}
	else
	{
		throw tokenList.at(index);
	}
}

//Recursive function to parse a list of scheme predicates
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

//Recursive function to parse a list of ID's
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
		if (state == PS)
		{
			datalog.addSchemeParam(Parameter(temp, "ID"));
		}
		else
		{
			datalog.addParamToHead(Parameter(temp, "ID"));
		}
		temp = "";
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

//Parse the fact section of the datalog program
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
		datalog.pushFactList(Predicate(temp));
		temp = "";
		match(LPAR);
		match(STR);
		datalog.addFactParam(Parameter(temp, "String"));
		temp = "";
		parseStringList();
		match(RPAR);
		match(PER);
	}
	else
	{
		throw tokenList.at(index);
	}
}

//Recursive function to parse a list of fact predicates
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

//Parse the rule section of the datalog program
void Parser::parseRule()
{
	if (tokenList.at(index).getType() == ID)
	{
		state = PR;
		ss.pop();
		ss.push(period);
		ss.push(predicateList);
		ss.push(predicate);
		ss.push(cdash);
		ss.push(headPredicate);
		parseHeadPredicate();
		match(COLD);
		parsePredicate();
		datalog.addPredToRules(pred);
		pred.clear();
		parsePredicateList();
		match(PER);
	}
	else
	{
		throw tokenList.at(index);
	}
}

//Recursive function to parse a list of Rule rules
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

//Parse the head predicate for rules
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
		datalog.pushRuleList(Rules(Predicate(temp)));
		temp = "";
		match(LPAR);
		match(ID);
		datalog.addParamToHead(Parameter(temp, "ID"));
		temp = "";
		parseIdList();
		match(RPAR);
	}
	else
	{
		throw tokenList.at(index);
	}
}

//Parse a predicate for rules and queries
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
		pred = Predicate(temp);
		temp = "";
		match(LPAR);
		parseParameter();
		pred.push(param);
		temp = "";
		temp2 = "";
		parseParameterList();
		match(RPAR);
	}
	else
	{
		throw tokenList.at(index);
	}
}

//Recursive function to parse a list of predicates for rules and queries
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
		datalog.addPredToRules(pred);
		pred.clear();
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

//Parse a parameter with different methods depending on its derived class type
void Parser::parseParameter()
{
	if (tokenList.at(index).getType() == STR)
	{
		ss.pop();
		ss.push(str);
		match(STR);
		param = Parameter(temp, "String");
	}
	else if (tokenList.at(index).getType() == ID)
	{
		ss.pop();
		ss.push(id);
		match(ID);
		param = Parameter(temp, "ID");
	}
	else if (tokenList.at(index).getType() == LPAR)
	{
		ss.pop();
		ss.push(expression);
		parseExpression();
		param = Parameter(temp2, "Expression");
	}
	else
	{
		throw tokenList.at(index);
	}
}

//Recursive function to parse a list of parameters for a predicate
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
		pred.push(param);
		temp = "";
		temp2 = "";
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

//Parse an expression
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
		temp2 += temp;
		parseParameter();
		temp2 += temp;
		parseOperator();
		temp2 += temp;
		parseParameter();
		temp2 += temp;
		match(RPAR);
		temp2 += temp;
		temp = "";
	}
	else
	{
		throw tokenList.at(index);
	}
}

//Parse an operator
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

//Parse the query section of the datalog program
void Parser::parseQuery()
{
	state = PQ;
	if (tokenList.at(index).getType() == ID)
	{
		ss.pop();
		ss.push(qmark);
		ss.push(predicate);
		parsePredicate();
		datalog.pushQueryList(pred);
		match(QM);
	}
	else
	{
		throw tokenList.at(index);
	}
}

//Recursive function to parse a list of query predicates
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

//Recursive function to parse a list of strings
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
		datalog.addFactParam(Parameter(temp, "String"));
		temp = "";
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