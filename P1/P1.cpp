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
#include <Windows.h>

#include "MatrixClass.h"

#pragma warning(disable:4267)
using namespace std;

/*

1 개 이상의 공백이 있는 경우는 1 개로 취급한다

알파벳이나 숫자 외의 특수문자들은 예 , /, --* 같은 문자 는 구분하지 않고 연결된 값으로 카운트 한다 .

숫자와 문자가 모두 있는 문자열인 경우에는 문 자로 카운트 하도록 한다

*/




namespace Text {

	bool isNumber(const string Word) {
		bool digitFlag = false;
		for (const char c : Word) {
			if (isdigit(c)) {
				digitFlag = true;
			}
			else {
				digitFlag = false;
				return digitFlag;
			}
		}
		return digitFlag;

	}

	int Clamp(const int Src, int Min, int Max = 0) {
		int result = Src;

		if (Max != 0) {
			if (result < Min) result = Min;
			if (result > Max) result = Max;
		}
		else {
			if (result < Min) result = Min;
		}
		return result;
	}



	class TextProcessor {
	private:
		vector<string> Lines;


	public:

		TextProcessor(const char* path) {
			ifstream FILE(path);
			if (!FILE) {
				cout << "File Load Failed" << endl;
				exit(0);
			}
			string buffer;
			while (getline(FILE, buffer)) {
				this->Lines.push_back(buffer);
				buffer.clear();
			}
			FILE.close();
		}





		void print() {
			for (const string line : this->Lines) {
				cout << line << endl;
			}
			cout << endl << endl << endl << endl << endl;
		}





		void count() {
			cout << "Count Each Words" << endl << endl;
			vector<string> words;
			int Nums = 0;
			int Phases = 0;
			int Capitals = 0;


			bool digitFlag = false;



			for (const string& line : this->Lines) {

				words = this->Split(line, ' ');


				for (const string& word : words) {
					digitFlag = false;
					for (const char& c : word) {

						if (isdigit(c)) {
							digitFlag = true;
						}
						else {
							if (digitFlag) {
								digitFlag = false;
								break;
							}
							if (isupper(c)) {
								Capitals += 1;
							}

						}
					}
					if (digitFlag) {
						Nums += 1;
					}
					else {
						Phases += 1;

					}
				}
			}
			cout << "Total Result : " << endl;
			cout << "Words			:	" << Phases << endl;
			cout << "Numbers			:	" << Nums << endl;
			cout << "Capitals		:	" << Capitals << endl << endl << endl << endl << endl;

		}


		void Reverse_By_Line() {
			cout << "Reverse by Line" << endl << endl;
			for (string& line : this->Lines) {
				line = this->Reverse(line);
			}
		}

		void Reverse_By_Word() {
			cout << "Reverse by Word" << endl << endl;

			vector<string> Words;

			for (string& line : this->Lines) {


				Words = this->Split(line, ' ');

				for (string& word : Words) {
					word = this->Reverse(word);
				}

				line = this->Merge(Words, ' ');
			}
		}


		void InsertChracters(const char* insertion, int interval) {

			cout << "Insert '@@' Words " << endl << endl;

			for (string& line : this->Lines) {
				line = this->Insert(line, insertion, interval);
			}
		}

		void EraseCharacters(const char Target) {

			cout << "Erase '@@' in Words " << endl << endl;

			for (string& line : this->Lines) {
				line = this->Erase(line, Target);
			}


		}

		
		void ReplaceCharacters(const char* Target, const char* Obj) {

			cout << "Replace "<< Target <<" in Words to "<< Obj << endl << endl;

			for (string& line : this->Lines) {
				line = this->Replace(line,Target,Obj);

			}


		}


		void Increase(int Amount) {

			cout << "+" << Amount <<" for Every Numbers" << endl << endl;
			vector<string> Words;
			int buffer = 0;

			for (string& line : this->Lines) {
				Words = this->Split(line, ' ');
				buffer = 0;
				for (string& word : Words) {

					if (isNumber(word)) {
						buffer = stoi(word);
						buffer += Amount;

						word = to_string(buffer);

					}


				}

				line = this->Merge(Words, ' ');
				

			}

		}
	



		void Decrease(int Amount) {

			cout << "-" << Amount << " for Every Numbers" << endl << endl;
			vector<string> Words;
			int buffer = 0;

			for (string& line : this->Lines) {
				Words = this->Split(line, ' ');
				buffer = 0;
				for (string& word : Words) {

					if (isNumber(word)) {
						buffer = stoi(word);
						buffer -= Amount;

						buffer = Clamp(buffer, 0);
						

						word = to_string(buffer);

					}


				}

				line = this->Merge(Words, ' ');
				

			}

		}


		void FoldLines() {

			for (const string& line : this->Lines) {
				cout << line << " : " << this->Fold(line) << endl;
				
			}

			

			cout << endl  << endl << endl << endl << endl;


		}
		






	private:



		vector<string> Split(const string Src, const char Sign) {
			vector<string> Words;

			string buffer;


			for (const char c : Src) {
				if (c == Sign) {
					Words.push_back(buffer);
					buffer.clear();
				}
				else {
					buffer += c;
				}


			}

			if (!buffer.empty()) {
				Words.push_back(buffer);
			}


			return Words;
		}









		string Merge(vector<string> Words, const char Sign) {
			string result;


			for (string buffer : Words) {
				result += buffer;
				result += Sign;
			}


			if (!result.empty()) {
				result.pop_back();
			}


			return result;
		}

		string Reverse(const string Src) {
			string result = Src;
			reverse(result.begin(), result.end());
			return result;
		}
		

		string Insert(const string& Src, const char* insertion, int interval) {

			int pivot = 1;

			string result;


			for (char c : Src) {
				result += c;
				if (pivot == interval) {
					result += insertion;
					pivot = 1;
				}
				else {
					pivot += 1;
				}
				
				
			}
			return result;
		}
		




		string Erase(const string& Src, const char Tar) {
			string result = Src;
			result.erase(remove(result.begin(), result.end(), Tar), result.end());
			return result;
		}


		
		string Replace(const string& Src, const char* Tar, const char* Obj) {

			string result = Src;


			size_t pos;

			while ((pos = result.find(Tar)) != string::npos) {
				result.replace(pos, 1, Obj);
			}

			return result;
		}





		string Fold(const string Src) {

			string Forward = Src;
			string Backward = this->Reverse(Src);

			string result;

			for (auto i = 0; i < Forward.length() / 2; ++i) {
				if (Forward[i] != Backward[i]) {
					break;
				}
				else {
					result += Forward[i];
				}
			}

			if (result.empty()) {
				result.push_back('0');
			}

			return result;
		}








	};// End of Class 


}



int main()
{
	Text::TextProcessor* TP = new Text::TextProcessor("TEST.txt");
	TP->count();

	char input;

	char target[10] = {  };
	char obj[10] = {	};

	bool insertion_toggle = false;



	while (true) {
		
		cin >> input;
		system("cls");
		switch (input)
		{

		case 'd':
			TP->Reverse_By_Line();
			TP->print();
			break;
		case 'e':
			if (insertion_toggle) {
				TP->EraseCharacters('@');
				TP->print();
				insertion_toggle = false;
				break;
			}

			TP->InsertChracters("@@", 3);
			TP->print();
			insertion_toggle = true;
			break;
		case 'f':
			TP->Reverse_By_Word();
			TP->print();
			break;
		case 'g':
			cout << "Please input (Target Char,New Char)" << endl;
			cin >> target >> obj;
			TP->ReplaceCharacters(target, obj);
			TP->print();
			break;
		case 'h':
			TP->FoldLines();
			break;
		case '+':
			TP->Increase(1);
			TP->print();
			break;
		case '-':
			TP->Decrease(1);
			TP->print();
			break;
		case 'q':
			return 1;
		default:
			break;
		}





	}























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

