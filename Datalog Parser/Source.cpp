#include <iostream>
#include <fstream>
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
		parser.parse();
		cout << endl;

		cout << parser.getVec().size() << endl << parser.getVec().at(0).size() << endl << parser.getVec().at(1).size() << endl;
		for (int i = 0; i < parser.getVec().size(); i++)
		{
			for (int t = 0; t < parser.getVec().at(i).size(); t++)
			{
				cout << parser.getVec()[i][t];
			}
		}

		system("pause");
	return 0;
}