
#include "MatrixClass.h"
#include "Text.h"
#include "PointList.h"
#include "CardFlip.h"

#pragma warning(disable:4267)
using namespace std;




void(*run[10])();

int main()
{
	
	run[0] = Matrixrun::Run;
	run[1] = Textrun::Run;
	run[2] = PointListrun::Run;
	run[3] = CardFliprun::Run;
	



	run[3]();





}

