#pragma once
#include <iostream>
#include <random>
#include <Windows.h>
using namespace std;







#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define H 7







namespace CardFlip {
	inline int* newArrary() {
		int* result = new int[8];
		bool Flag[8] = { false, };

		srand(time(NULL));


		for (auto i = 0; i < 8; ++i) {
			while (true) {
				result[i] = rand() % 8;
				if (!Flag[result[i]]) {
					Flag[result[i]] = true;
					break;
				}
			}
		}



		return result;
	}

	



	class CardFlip
	{

	public:

		int** Board;
		bool inVisible[4][4] = { false, };

		int* Color;


		bool inClear[8] = { false, };
		
		int preX = 0;
		int preY = 0;

		int times = 0;

		bool two = false;

		CardFlip() {

			int Cards[8] = { 0, };
			int newcard = 0;
			this->Color = newArrary();



			this->Board = new int * [4];
			for (auto i = 0; i < 4; ++i) {
				this->Board[i] = new int[4];
			}
			srand(time(NULL));
			for (auto i = 0; i < 4; ++i) {
				for (auto j = 0; j < 4; ++j) {

					while (true) {
						newcard = rand() % 8;
						if (Cards[newcard] != 2) {
							this->Board[i][j] = newcard;
							Cards[newcard] += 1;
							break;
						}

					}



				}
			}
		}

		void print() {
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "< print >" << endl;

	
			cout << "  0 1 2 3" << endl;
			for (auto i = 0; i < 4; ++i) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

				cout << i << " ";
				for (auto j = 0; j < 4; ++j) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					if (this->inVisible[i][j]) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), this->Color[this->Board[i][j]] + 1);
						cout << this->Board[i][j] << " ";
					}
					else {
						cout << ". ";
					}
				}
				cout << endl;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}


		void CardSelect(int tarx,int tary) {

			this->times += 1;

			if (this->inClear[this->Board[tary][tarx]]) {
				return;
			}




			if (this->two) { //두번째 입력
				this->inVisible[tary][tarx] = true;
				this->two = false;



				if (this->Board[this->preY][this->preX] == this->Board[tary][tarx]) {
					
					this->inClear[this->Board[tary][tarx]] = true;



					this->print();
					Sleep(1000);
				}
				else {
					this->print();


					this->inVisible[this->preY][this->preX] = false;
					this->inVisible[tary][tarx] = false;



					Sleep(1000);
					return;

				}



			}
			else { // 첫번째 입력


				this->inVisible[tary][tarx] = true;
				this->two = true;


				this->preX = tarx;
				this->preY = tary;

				this->print();
				Sleep(1000);


			}









		}






	};
}




namespace CardFliprun {
	void Run();
}