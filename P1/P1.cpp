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
#include <string>
#include <vector>
#include <algorithm>

#include "MatrixClass.h"
using namespace std;

/*

1 개 이상의 공백이 있는 경우는 1 개로 취급한다

알파벳이나 숫자 외의 특수문자들은 예 , /, --* 같은 문자 는 구분하지 않고 연결된 값으로 카운트 한다 .

숫자와 문자가 모두 있는 문자열인 경우에는 문 자로 카운트 하도록 한다

*/

bool isCharNum(const char c) {
	if (c >= '0' && c <= '9') return true;
	return false;
}


bool isStringNum(const string s) {
	bool result = false;

	for (auto i = 0; i < s.length(); ++i) {
		if (isdigit(s[i]) != 0) {
			
			result = true;
		} 


		if (isdigit(s[i]) == 0) {
			return false;
		}
	}

	return result;
}


bool isCapital(const string s) {

	bool result = false;

	for (auto i = 0; i < s.length(); ++i) {
		if (isupper(s[i])) {
			result = true;
		}

		if (isdigit(s[i])  != 0) {
			return false;
		}
	}




	return result;
}


class Text {
private:
	ifstream*	fin			= nullptr;
	string*		str			= nullptr;
	vector<string> words;

	int NumberofWord = 0;
	int NumberofNum = 0;
	

	


public:
	Text(const char* path) {
		this->fin = new ifstream(path,ios::in);
		if (this->fin->fail()) {
			throw -1;
		}




		this->str = new string[10];


		string temp;

		for (auto i = 0; i < 10; ++i) {
			getline(*this->fin, this->str[i]);
			
		}

		this->fin->clear();
		this->fin->seekg(0, ios::beg);
		




		while (!this->fin->eof()) {
			if (this->fin->eof()) break;
			*this->fin >> temp;
			this->words.push_back(temp);
		}
	}

	string* getString() { return this->str; }


	void print() {

		for (auto line = 0; line < 10; ++line) {
			cout << this->str[line] << endl;

		}
		cout << endl;
	}

	
	void printUnits() {
		vector<string>::iterator iter;
		for (iter = this->words.begin(); iter != this->words.end(); ++iter) {
			cout << *iter << endl;
		}
	}

	int NumsNo() {
		int result = 0;

		vector<string>::iterator iter;
		for (iter = this->words.begin(); iter != this->words.end(); ++iter) {
			if (isStringNum(*iter)) {
				result += 1;
			}
		}




		this->NumberofNum = result;
		this->NumberofWord = this->words.size() - result;

		return result;

	}

	



	int WordsNo() {
		return this->NumberofWord;
	}

	int CapsNo() {
		int result = 0;

		vector<string>::iterator iter;
		for (iter = this->words.begin(); iter != this->words.end(); ++iter) {
			if (isCapital(*iter))result += 1;
		}



		
		return result;

	}



	void rev() {

		for (auto i = 0; i < 10; ++i) {
			reverse(this->str[i].begin(), this->str[i].end());

		}


		return this->print();
	}




	void Ins() {

		int size = 0;
		for (auto line = 0; line < 10; ++line) {
			size = static_cast<int>(this->str[line].length());

			for (auto it = 0; it < size; ++it) {

				if (it % 4 == 3) {
					this->str[line].insert(it, "@@");
				}



			}
		}

		return this->print();

	}













};






int main()
{

	Text* T = nullptr;

	try{
		T = new Text("TEST.txt");
	}
	catch (int exeption)
	{
		if (exeption == -1) {
			cout << "File read Failed" << endl;
		}
	}


	
	
	
	T->print();
	
	T->NumsNo();

	cout << "Words count : " << T->WordsNo() << endl;
	cout << "Numbers count : " << T->NumsNo() << endl;
	cout << "Caps count : " << T->CapsNo() << endl;



	T->rev();
	T->rev();

	T->Ins();

	
	return 1;
	//TestProblem_1();


}

