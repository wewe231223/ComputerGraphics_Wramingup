

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

#include "MatrixClass.h"
#include "Text.h"

#pragma warning(disable:4267)
using namespace std;

void (*run)();



int main()
{
	//run = Textrun::Run;
	run = Matrixrun::Run;
	
	
	run();

















	//TP->print();
	//
	//TP->count();
	//TP->print();

	//TP->Reverse_By_Line();
	//TP->print();

	//TP->Reverse_By_Word();
	//TP->print();

	//TP->Reverse_By_Word();
	//TP->Reverse_By_Line();

	//TP->InsertChracters("@@", 3);
	//TP->print();


	//TP->EraseCharacters('@');
	//TP->print();

	//TP->ReplaceCharacters("i", "K");
	//TP->print();

	//TP->ReplaceCharacters("K", "i");
	//TP->print();


	//
	//TP->FoldLines();
	//


	//TP->print();

}

