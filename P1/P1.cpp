﻿// P1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

/*
2차원 순회



		for (auto i = 0; i < this->size; ++i) {
			for (auto j = 0; j < this->size; ++j) {


			}
		}


*/


#include <iostream>
#include <random>


#define EXEPT_ROW 0
using namespace std;

random_device rd;
mt19937 gen(rd());


//----------------------------------------------------FUNCTIONS---------------------------------------------------------------------



int Sign(int n) {
	if (n % 2 == 0) {
		return 1;
	}
	else {
		return -1;
	}
}


int Determine2by2(int m[4]) {
	return m[0] * m[3] - m[1] * m[2];
}












//----------------------------------------------------------------------------------------------------------------------------------





class Matrix {

private:
	int** mat;
	int         size = 3;


private:


	//todo : size == 4 일때 작동에 문제있음
	//깊은복사를통해 같은 Matirx 구조체를 하나 더 만들어야함 
	int* CreateMinorMatrix(int column) {
		int MinorMatrix[4] = { 0, };
		int c = 0;
		for (auto i = 0; i < 3; ++i) {
			if (i == EXEPT_ROW) continue;
			for (auto j = 0; j < 3; ++j) {
				if (j == column) continue;
				MinorMatrix[c] = this->mat[i][j];
				c += 1;

			}
		}
		return MinorMatrix;
	}




public:
	Matrix() {

		uniform_int_distribution<> dist(0, 2);



		this->mat = new int* [4];
		for (auto i = 0; i < 4; ++i) {

			this->mat[i] = new int[4];
			for (auto j = 0; j < 4; ++j) {
				this->mat[i][j] = dist(gen);

			}
		}
	}

	Matrix(int z) {
		this->mat = new int* [4];
		for (auto i = 0; i < 4; ++i) {

			this->mat[i] = new int[4];
			for (auto j = 0; j < 4; ++j) {
				this->mat[i][j] = 0;

			}
		}
	}

	~Matrix() {

		for (auto i = 0; i < 4; ++i) {
			delete[] this->mat[i];
		}
		delete[] this->mat;


	}


	void print() {

		for (auto i = 0; i < this->size; ++i) {
			for (auto j = 0; j < this->size; ++j) {

				cout << this->mat[i][j];

			}

			cout << endl;
		}

		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;

	}


	void reLocation() {
		uniform_int_distribution<> dist(0, 2);
		for (auto i = 0; i < this->size; ++i) {
			for (auto j = 0; j < this->size; ++j) {
				this->mat[i][j] = dist(gen);
			}
		}
	}


	// 1+1 1+2 1+3
	// 1+0 1+1 1+2
	int Determine() {
		int result = 0;
		for (auto i = 0; i < 3; ++i) {
			result += Sign(i + 2 + EXEPT_ROW) * (this->mat[EXEPT_ROW][i]) * (Determine2by2(this->CreateMinorMatrix(i)));
		}
		return result;
	}

	int TransDetermine() {
		Matrix m(0);
		*this *= m;
		m.print();
		return m.Determine();
	}


	void Expantion() {
		// 확장해도 행렬식은 결과적으로 같음 
		// --> 4열을 선택할때, 여인수전개에서 결국 C_4_4에서만 여인수가 나오기때문(이때 여인수는 확장하기 전 행렬식과 같다 =>  (-1) ^ 4+4 = 1 이므로 부호도 같음 ). 
		this->size = 4;
		this->mat[0][3] = 0; this->mat[1][3] = 0; this->mat[2][3] = 0; this->mat[3][3] = 1;
		this->mat[3][0] = 0; this->mat[3][1] = 0; this->mat[3][2] = 0;
		this->print();
		cout << this->Determine() << endl;;



	}

	Matrix* operator*(int no) {

		for (auto i = 0; i < this->size; ++i) {
			for (auto j = 0; j < this->size; ++j) {

				this->mat[i][j] = this->mat[i][j] * no;

			}
		}

		return this;

	}




	Matrix operator*(Matrix& other) {
		int temp = 0;
		Matrix result(0);

		for (auto i = 0; i < this->size; ++i) {
			for (auto j = 0; j < this->size; ++j) {
				for (auto k = 0; k < this->size; ++k) {
					temp = this->mat[i][k] * other.mat[k][j];
					result.mat[i][j] += temp;

				}



			}
		}

		return result;
	}




	Matrix operator+(Matrix& other) {
		int temp = 0;
		Matrix result(0);

		for (auto i = 0; i < this->size; ++i) {
			for (auto j = 0; j < this->size; ++j) {

				result.mat[i][j] = this->mat[i][j] + other.mat[i][j];

			}
		}

		return result;
	}

	Matrix operator-(Matrix& other) {
		int temp = 0;
		Matrix result(0);

		for (auto i = 0; i < this->size; ++i) {
			for (auto j = 0; j < this->size; ++j) {

				result.mat[i][j] = this->mat[i][j] - other.mat[i][j];

			}
		}

		return result;
	}






	void operator*=(Matrix& other) {
		other.size = this->size;
		for (auto i = 0; i < this->size; ++i) {
			for (auto j = 0; j < this->size; ++j) {

				other.mat[i][j] = this->mat[j][i];

			}
		}


	}















};


#define Command_M	109
#define Command_A	97
#define Command_D	100
#define Command_R	114
#define Command_T	116
#define Command_H	104
#define Command_S	115
#define Command_Q	113







int main()
{
	Matrix m1;
	Matrix m2;

	char	Command	= NULL;
	int		Decode		= NULL;


	cout << "m1 : " << endl;
	m1.print();
	cout << "m2 : " << endl;
	m2.print();


	while (1) {
		cin >> Command;


		Decode = static_cast<int>(Command);


		if(Decode > 48 && Decode <	58){
			Decode = Decode - static_cast<int>('0');
			(m1 * Decode)->print();
			(m2 * Decode)->print();
			continue;
		
		}


		



		switch (Decode){


		case Command_M:
			(m1 * m2).print();
			break;

		case Command_A:
			(m1 + m2).print();
			break;

		case Command_D:
			(m1 - m2).print();
			break;

		case Command_R:
			cout << m1.Determine() << endl;
			cout << m2.Determine() << endl;
			break;

		case Command_T:
			cout << m1.TransDetermine() << endl;
			cout << m2.TransDetermine() << endl;
			break;

		case Command_H:
			m1.Expantion();
			m2.Expantion();
			break;

		case Command_S:
			m1.reLocation();
			m2.reLocation();

			m1.print();
			m2.print();

			break;
			
		case Command_Q:
			return 0;
		default:


			cout << "명령어 확인 : (m, a, d, r, t, h, s, q) " << endl;
			


			break;
		}





	}

























}

