#pragma once
#define Command_M	109
#define Command_A	97
#define Command_D	100
#define Command_R	114
#define Command_T	116
#define Command_H	104
#define Command_S	115
#define Command_Q	113




int Sign(int);
int Determine2by2(int[4]);



class Matrix {
private:
	int**		mat;
	int			size = 3;

private:
	int* CreateMinorMatrix(int);

public:
	Matrix();
	Matrix(int);

	~Matrix();

	void print();
	void reLocation();
	void Expantion();



	int Determine();
	int TransDetermine();

	
	Matrix operator*(Matrix& other);
	Matrix operator+(Matrix& other);
	Matrix operator-(Matrix& other);


	Matrix* operator* (int no);
	
	void operator*=(Matrix& other);

};


void TestProblem_1();