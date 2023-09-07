// P1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

/*
2차원 순회



		for (auto i = 0; i < this->size; ++i) {
			for (auto j = 0; j < this->size; ++j) {


			}
		}


*/

#include <iostream>
#include <fstream>
#include "MatrixClass.h"
using namespace std;



class Text {
private:
	ifstream*	ifs			= nullptr;
	char**		readbuffer	= nullptr;
public:
	Text(const char* path) {
		this->ifs = new ifstream(path,ios::in);
		if (this->ifs->fail()) {
			throw -1;
		}

		this->readbuffer = new char* [10];
		for (auto i = 0; i < 10; ++i) {
			this->readbuffer[i] = new char[256];
		}









	}



};






int main()
{
	try{
		Text* T = new Text("TEST.txt");
	}
	catch (int exeption)
	{
		if (exeption == -1) {
			cout << "File read Failed" << endl;
		}
	}


	











	
	return 1;
	//TestProblem_1();


}

