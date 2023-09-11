

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

#include "MatrixClass.h"
#include "Text.h"
#include "PointList.h"

#pragma warning(disable:4267)
using namespace std;


void (*run)();



int main()
{
	//run = Textrun::Run;
	run = Matrixrun::Run;
	
	
	run();










}

