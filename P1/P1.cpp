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

#pragma warning(disable:4267)
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
	int		WordPerLine[10] = { 0, };
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
		int ind = 0;
		int b = 0;

		for (auto i = 0; i < 10; ++i) {
			getline(*this->fin, this->str[i]);
			
			while (this->str[i][ind] != NULL) {
				
				if (this->str[i][ind] == ' ') {
					b += 1;
				}

				ind += 1;

			}

			
			this->WordPerLine[i] = b + 1;
			b = 0;
			ind = 0;
		}

		this->fin->clear();
		this->fin->seekg(0, ios::beg);
		




		while (!this->fin->eof()) {
			if (this->fin->eof()) break;
			*this->fin >> temp;
			this->words.push_back(temp);
		}
	}



	void reasignUnits() {
		this->fin->clear();
		this->fin->seekg(0, ios::beg);


		string temp;

		vector<string>().swap(this->words);

		for (auto line = 0; line < 10; ++line) {
			
			for (auto it = 0; it < this->str[line].length(); ++it) {

				if (this->str[line][it] == ' ' ) {
					this->words.push_back(temp);
					temp.clear();
					continue;
				}

				
				if (&this->str[line][it] == &this->str[line].back()) {
					temp.push_back(this->str[line][it]);
					this->words.push_back(temp);
					temp.clear();
					break;
				}

				temp.push_back(this->str[line][it]);



			}
		}
		




	}

	string* getString() { return this->str; }


	void print() {

		for (auto line = 0; line < 10; ++line) {
			cout << this->str[line] <</* "           WordPerLine = " << this->WordPerLine[line] <<*/ endl;

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
		int counter = 0;

		for (auto line = 0; line < 10; ++line) {
			counter = 0;
			for (auto it = 0; it < this->str[line].length(); ++it) {

				if (counter == 3) {
					this->str[line].insert(it, "@@");
					it += 1;
					counter = 0;
				}
				else {
					counter += 1;
				}

			}
		}


		this->reasignUnits();
		return this->print();

	}

	

	void rev_FromBlank() {
		
		string* NewString = new string[10];

		int i = 0;
		int ind = 0;

		vector<string>::iterator iter;
		for (iter = this->words.begin(); iter != this->words.end(); ++iter) {

			

			
			reverse((*iter).begin(), (*iter).end());
			NewString[i].append(*iter);
			NewString[i].append(" ");
			ind += 1;


			if (ind == this->WordPerLine[i]) {
				i += 1;
				ind = 0;
			}





		}



		this->str = NewString;



		return this->print();


	}


	void er() {

		for (auto line = 0; line < 10; ++line) {
			this->str[line].erase(remove(this->str[line].begin(), this->str[line].end(), '@'), this->str[line].end());
		}

		this->reasignUnits();
		return this->print();

	}
	

	void rep(char t, char s) {

		for (auto line = 0; line < 10; ++line) {
			for (auto iter = 0; iter < this->str[line].length(); ++iter) {

				if (this->str[line][iter] == t) {
					this->str[line][iter] = s;
				}
			}
		}

		this->reasignUnits();
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



	//T->rev();
	//T->rev();

	T->Ins();
	T->printUnits();
	cout << endl;

	T->rev_FromBlank();
	T->rev_FromBlank();

	T->er();

	T->rep('i', 'K');


	return 1;
	//TestProblem_1();


}

