#include <iostream>
#include <fstream>
#include <list>
#include "LexicalAnalyzer.h"
#include "Parser.h"
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

using namespace std;

int main(int argc, char* argv[])
{
	VS_MEM_CHECK;
		ifstream inputFile(argv[1]);
		string line;
		string con;
		while (getline(inputFile, line))
		{
			con = con + line + "\n";
		}

		LexicalAnalyzer lex(con);
		lex.generateList();
		Parser parser(lex.getList());

		system("pause");
	return 0;
}