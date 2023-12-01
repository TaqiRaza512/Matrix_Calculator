#pragma once
#include<fstream>
#include<string>
#include<iostream>
using namespace std;
class Matrix
{
	int Rows;
	int Cols;
	int** Vs;
	void DeepCopy(const Matrix& M);
	void AllocateMatrix();
	void DeAllocateMatrix();
	static Matrix& UnitMatrix(int Rows, int Cols)
	{
		Matrix m(Rows, Cols);
		for (int ri = 0; ri < m.Rows; ri++)
		{
			for (int ci = 0; ci < m.Cols; ci++)
			{
				m.Vs[ri][ci] = 1;
			}
		}
		return m;
	}

public:

	Matrix();
	Matrix(int R, int C);
	Matrix(ifstream& Rdr);
	Matrix(const Matrix& M);
	void LoadMatrix(ifstream& Rdr);
	const Matrix& operator=(const Matrix& M);   //M1=M2 deep memory..Also M1=M2=M3
	ostream& operator<<(ostream&);
	friend ostream& operator<<(ostream&, const Matrix& M);	
	const Matrix operator+(const Matrix& M);
	const Matrix operator-(const Matrix& M);
	const Matrix operator*(const Matrix& M);

	const Matrix operator%(int num)const;  //M multiply scalar values &M[ri](5)
	const Matrix operator&(int num)const;  //M subtract scalar values
	
	const Matrix& operator*=(const Matrix& M);
	const Matrix& operator+=(const Matrix& M);  
	const Matrix& operator-=(const Matrix& M);
	void operator==(const Matrix& M)const;  //Check Equivalency of matrix.
	const Matrix& operator!=(const Matrix& M);
	const Matrix& operator&=(const Matrix& M);
	const Matrix& operator|=(const Matrix& M); //Rotation Clockwise
	const Matrix& operator^=(const Matrix& M);

	~Matrix();

};

