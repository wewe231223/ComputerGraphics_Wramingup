#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>


using namespace std;



namespace Text {

	bool isNumber(const string);
	int Clamp(const int , int , int );



	class TextProcessor {
	private:

		vector<string> Lines;

	public:
		TextProcessor(const char*);

		void print();
		void count();


		void Reverse_By_Line();
		void Reverse_By_Word();

		void InsertCharacter(const char* insertion, int interval);
		void EraseCharacter(const char Target);

		void ReplaceCharacters(const char* Target, const char* Obj);

		void Increase(int);
		void Decrease(int);


		void FoldLines();


	private:

		vector<string> Split(const string, const char);

		string Merge(vector<string>, const char);

		string Reverse(const string);


		string Insert(const string&, const char* ,int);

		string Erase(const string&, const char);

		string Replace(const string&, const char*, const char*);

		string Fold(const string);

	









	


	};






}




namespace Textrun {
	void Run();
}