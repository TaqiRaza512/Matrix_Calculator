//#pragma once
//#include<fstream>
//#include<string>
//#include<iostream>
//using namespace std;
//class Matrix
//{
//	int Rows;
//	int Cols;
//	int** Vs;
//	void DeepCopy(const Matrix& M);
//	void AllocateMatrix();
//	void DeAllocateMatrix();
//	static Matrix& UnitMatrix(int Rows, int Cols)
//	{
//		Matrix m(Rows, Cols);
//		for (int ri = 0; ri < m.Rows; ri++)
//		{
//			for (int ci = 0; ci < m.Cols; ci++)
//			{
//				m.Vs[ri][ci] = 1;
//			}
//		}
//		return m;
//	}
//
//public:
//
//	Matrix();
//	Matrix(int R, int C);
//	Matrix(ifstream& Rdr);
//	Matrix(const Matrix& M);
//	void LoadMatrix(ifstream& Rdr);
//	const Matrix& operator=(const Matrix& M);   //M1=M2 deep memory..Also M1=M2=M3
//	ostream& operator<<(ostream&);
//	friend ostream& operator<<(ostream&, const Matrix& M);
//	const Matrix operator+(const Matrix& M);
//	const Matrix operator-(const Matrix& M);
//	const Matrix operator*(const Matrix& M);
//
//	const Matrix operator%(int num)const;  //M multiply scalar values &M[ri](5)
//	const Matrix operator&(int num)const;  //M subtract scalar values
//
//	const Matrix& operator*=(const Matrix& M);
//	const Matrix& operator+=(const Matrix& M);
//	const Matrix& operator-=(const Matrix& M);
//	void operator==(const Matrix& M)const;  //Check Equivalency of matrix.
//	const Matrix& operator!=(const Matrix& M);
//	const Matrix& operator&=(const Matrix& M);
//	const Matrix& operator|=(const Matrix& M); //Rotation Clockwise
//	const Matrix& operator^=(const Matrix& M);
//
//	~Matrix();
//
//};
//
//#include "Matrix.h"
//#include<iostream>
//#include<iomanip>
//#include<fstream>
//#include<string>
//using namespace std;
//Matrix::Matrix()
//{
//	Vs = nullptr;
//	Rows = 0;
//	Cols = 0;
//}
//Matrix::Matrix(int R, int C)
//{
//	this->Rows = R, this->Cols = C;
//	AllocateMatrix();
//}
//Matrix::Matrix(ifstream& Rdr)
//{
//
//	Rdr >> this->Rows >> this->Cols;
//	AllocateMatrix();
//	for (int ri = 0; ri < this->Rows; ri++)
//	{
//		for (int ci = 0; ci < this->Cols; ci++)
//		{
//			Rdr >> this->Vs[ri][ci];
//		}
//	}
//}
//Matrix::Matrix(const Matrix& M)
//{
//	DeepCopy(M);
//
//}
//void Matrix::LoadMatrix(ifstream& Rdr)
//{
//	Rdr >> this->Rows >> this->Cols;
//	this->AllocateMatrix();
//	for (int ri = 0; ri < Rows; ri++)
//	{
//		for (int ci = 0; ci < Cols; ci++)
//		{
//			Rdr >> Vs[ri][ci];
//		}
//
//	}
//}
//
//void Matrix::DeepCopy(const Matrix& M)
//{
//	this->Rows = M.Rows;
//	this->Cols = M.Cols;
//	this->AllocateMatrix();
//	for (int ri = 0; ri < Rows; ri++)
//	{
//		for (int ci = 0; ci < Cols; ci++)
//		{
//			Vs[ri][ci] = M.Vs[ri][ci];
//		}
//	}
//}
//void Matrix::AllocateMatrix()
//{
//	this->Vs = new int* [this->Rows];
//	for (int ri = 0; ri < this->Rows; ri++)
//	{
//		Vs[ri] = new int[this->Cols]{};
//	}
//}
//void Matrix::DeAllocateMatrix()
//{
//
//	if (Vs != nullptr)
//	{
//		for (int ri = 0; ri < Rows; ri++)
//		{
//			delete[] Vs[ri];
//		}
//		delete[]Vs;
//		Rows = 0;
//		Cols = 0;
//	}
//}
//
//const Matrix& Matrix::operator=(const Matrix& M)   //M1=M2 deep memory..Also M1=M2=M3
//{
//	DeAllocateMatrix();
//	DeepCopy(M);
//	return *this;
//}
//ostream& Matrix::operator<<(ostream&)
//{
//	cout << "[" << Rows << "][" << Cols << "]";
//
//	for (int ri = 0; ri < Rows; ri++)
//	{
//		for (int ci = 0; ci < Cols; ci++)
//		{
//			cout << Vs[ri][ci];
//		}
//		cout << endl;
//	}
//	return cout;
//}
//ostream& operator<<(ostream&, const Matrix& M)
//{
//	cout << "[" << M.Rows << "][" << M.Cols << "]" << endl;
//
//	for (int ri = 0; ri < M.Rows; ri++)
//	{
//		for (int ci = 0; ci < M.Cols; ci++)
//		{
//			cout << left << setw(4) << M.Vs[ri][ci];
//		}
//		cout << endl;
//	}
//	return cout;
//}
//const Matrix Matrix::operator+(const Matrix& M)
//{
//	Matrix R;
//	if (this->Rows == M.Rows && this->Cols == M.Cols)
//	{
//		R.Rows = this->Rows;
//		R.Cols = Cols;
//		R.AllocateMatrix();
//		for (int ri = 0; ri < Rows; ri++)
//		{
//			for (int ci = 0; ci < Cols; ci++)
//			{
//				R.Vs[ri][ci] = M.Vs[ri][ci] + this->Vs[ri][ci];
//			}
//		}
//		return R;
//	}
//	else
//	{
//		cout << "Matrices cannot be added because the order are not same....\n";
//
//	}
//}
//const Matrix Matrix::operator-(const Matrix& M)
//{
//	Matrix R;
//	if (this->Rows == M.Rows && this->Cols == M.Cols)
//	{
//		R.Rows = Rows;
//		R.Cols = Cols;
//
//		R.AllocateMatrix();
//		for (int ri = 0; ri < Rows; ri++)
//		{
//			for (int ci = 0; ci < Cols; ci++)
//			{
//				R.Vs[ri][ci] = this->Vs[ri][ci] - M.Vs[ri][ci];
//			}
//		}
//		return R;
//	}
//	else
//	{
//		cout << "Matrices cannot be subtract because the order are not same....\n";
//	}
//}
//const Matrix Matrix::operator*(const Matrix& M)
//{
//	Matrix Res;
//
//	if (this->Cols == M.Rows)
//	{
//		Res.Rows = this->Rows;
//		Res.Cols = M.Cols;
//		Res.AllocateMatrix();
//		for (int ri = 0; ri < Res.Rows; ri++)
//		{
//			for (int ci = 0; ci < Res.Cols; ci++)
//			{
//				Res.Vs[ri][ci] = 0;
//				for (int k = 0; k < this->Rows; k++)
//				{
//					Res.Vs[ri][ci] += this->Vs[ri][k] * M.Vs[k][ci];
//				}
//			}
//		}
//		return Res;
//	}
//	else
//	{
//		cout << "These matrices cannot be multiplied \n";
//		return *this;
//	}
//}
//
//
//const Matrix Matrix::operator%(int num)const
//{
//	//Multiply with a number.
//	Matrix Res;
//	Res.Rows = this->Rows;
//	Res.Cols = this->Cols;
//	Res.AllocateMatrix();
//
//	for (int ri = 0; ri < Rows; ri++)
//	{
//		for (int ci = 0; ci < Cols; ci++)
//		{
//			Res.Vs[ri][ci] = num * this->Vs[ri][ci];
//		}
//	}
//	return Res;
//}
//const Matrix Matrix::operator&(int num)const  //M subtract scalar values
//{
//	Matrix Res;
//	Res.Rows = this->Rows;
//	Res.Cols = this->Cols;
//	Res.AllocateMatrix();
//
//	for (int ri = 0; ri < Rows; ri++)
//	{
//		for (int ci = 0; ci < Cols; ci++)
//		{
//			Res.Vs[ri][ci] = this->Vs[ri][ci] - num;
//		}
//	}
//	return Res;
//}
//
//const Matrix& Matrix::operator*=(const Matrix& M)
//{
//	if (M.Cols == this->Rows)
//	{
//		*this = *this * M;
//		return *this;
//	}
//	else
//	{
//
//		cout << "Matrices cannot be multilplied....\n";
//	}
//
//}
//const Matrix& Matrix:: operator+=(const Matrix& M)
//{
//	if (M.Cols == this->Cols && M.Rows == this->Rows)
//	{
//		*this = *this + M;
//		return *this;
//	}
//	else
//	{
//		cout << "Matrices cannot be added ......\n";
//	}
//}
//const Matrix& Matrix:: operator-=(const Matrix& M)
//{
//	*this = *this - M;
//	return *this;
//
//}
//const Matrix& Matrix::operator!=(const Matrix& M)
//{
//	for (int ri = 0; ri < Rows; ri++)
//	{
//		for (int ci = 0; ci < Cols; ci++)
//		{
//			this->Vs[ri][ci] = (-1) * M.Vs[ri][ci];
//		}
//	}
//	return *this;
//}
//void Matrix::operator==(const Matrix& M)const
//{
//	if (M.Rows == this->Rows && M.Cols == this->Cols)
//	{
//		cout << "\nThe order of Matrices are same.";
//		for (int ri = 0; ri < this->Rows; ri++)
//		{
//			for (int ci = 0; ci < M.Cols; ci++)
//			{
//				if (!(M.Vs[ri][ci] == this->Vs[ri][ci]))
//				{
//					cout << " But the values are not same. \n";
//					return;
//				}
//			}
//		}
//		cout << "The values are same also.\n";
//	}
//	else if (M.Rows != this->Rows or M.Cols != this->Cols)
//	{
//		cout << "\nThe order of Matrices are not same and values are also not same.\n";
//	}
//
//}
//const Matrix& Matrix::operator&=(const Matrix& M)
//{
//	this->Rows = M.Cols;
//	this->Cols = M.Rows;
//	for (int ri = 0; ri < M.Rows; ri++)
//	{
//		for (int ci = 0; ci < M.Cols; ci++)
//		{
//			this->Vs[ci][ri] = M.Vs[ri][ci];
//		}
//	}
//	return *this;
//
//}
//const Matrix& Matrix::operator|=(const Matrix& M)
//{
//	int temp = 0, angle;
//	int r;
//	cout << "\nplease enter the angle you want the matrix to rotate clockwise : ";
//	cin >> angle;
//	angle = angle / 90;
//	angle = angle % 4;
//	Matrix Res = M;
//
//	for (int j = 0; j < angle; j++)
//	{
//		if (j % 2 == 0)
//		{
//			this->DeAllocateMatrix();
//			this->Rows = Res.Cols;
//			this->Cols = Res.Rows;
//			this->AllocateMatrix();
//			temp = 0;
//			for (int ri = 0; ri < this->Rows; ri++)
//			{
//				r = Res.Rows - 1;
//				for (int ci = 0; ci < this->Cols; ci++)
//				{
//					this->Vs[ri][ci] = Res.Vs[r][temp];
//					r--;
//				}
//				temp++;
//			}
//			if (j == angle - 1)
//			{
//				return *this;
//			}
//		}
//		else
//		{
//			temp = 0;
//			Res.DeAllocateMatrix();
//			Res.Rows = this->Cols;
//			Res.Cols = this->Rows;
//			Res.AllocateMatrix();
//			for (int ri = 0; ri < Res.Rows; ri++)
//			{
//				r = this->Rows - 1;
//				for (int ci = 0; ci < Res.Cols; ci++)
//				{
//					Res.Vs[ri][ci] = this->Vs[r][temp];
//					r--;
//				}
//				temp++;
//			}
//			if (j == angle - 1)
//			{
//				*this = Res;
//				return *this;
//			}
//		}
//	}
//
//} //M1
//const Matrix& Matrix::operator^=(const Matrix& M)
//{
//	int temp = 0, angle;
//	int r;
//	cout << "\nplease enter the angle you want the matrix to rotate Anit-clockwise : ";
//	cin >> angle;
//	angle = angle / 90;
//	angle = angle % 4;
//	Matrix Res = M;
//
//	for (int j = 0; j < angle; j++)
//	{
//		if (j % 2 == 0)
//		{
//			this->DeAllocateMatrix();
//			this->Rows = Res.Cols;//4
//			this->Cols = Res.Rows;//3
//			this->AllocateMatrix();
//			r = Res.Cols - 1;//3
//			for (int ri = 0; ri < this->Rows; ri++)
//			{
//				temp = 0;
//				for (int ci = 0; ci < this->Cols; ci++)
//				{
//					this->Vs[ri][ci] = Res.Vs[temp][r];
//					temp++;
//				}
//				r--;
//			}
//			if (j == angle - 1)
//			{
//				return *this;
//			}
//		}
//		else
//		{
//			Res.DeAllocateMatrix();
//			Res.Rows = this->Cols;
//			Res.Cols = this->Rows;
//			Res.AllocateMatrix();
//			r = this->Cols - 1;
//			for (int ri = 0; ri < Res.Rows; ri++)
//			{
//				temp = 0;
//				for (int ci = 0; ci < Res.Cols; ci++)
//				{
//					Res.Vs[ri][ci] = this->Vs[temp][r];
//					temp++;
//				}
//				r--;
//			}
//			if (j == angle - 1)
//			{
//				*this = Res;
//				return *this;
//			}
//		}
//	}
//}
//
//Matrix::~Matrix()
//{
//	//DeAllocateMatrix();
//
//}
//
///*
//
//2
//
//3  3
//1    3    5
//2   5    12
//2   4    3
//
//3  3
//10  3    2    1
//2   2    11   7
//1   6    5    9
//
//
//
//*/
//
//#include<iostream>
//#include"Matrix.h"
//#include<fstream>
//using namespace std;
//
//void LoadMatrices(Matrix*& M, int& size)
//{
//	int R, C;
//	ifstream Rdr("Matrix.txt");
//	Rdr >> size;
//	M = new Matrix[size];
//
//	for (int ri = 0; ri < size; ri++)
//	{
//		M[ri].LoadMatrix(Rdr);
//	}
//}
//void PrintMatrices(Matrix* M, int size)
//{
//	for (int ri = 0; ri < size; ri++)
//	{
//
//		cout << "M" << ri + 1 << "\n" << M[ri];
//		cout << endl << endl;
//	}
//}
//void Calculator(Matrix*& M, int size)
//{
//	char tocont;
//	char d, oprt1;
//	int resi, pi, di;
//	char oprt, g;
//	int li2 = 0;
//	do
//	{
//		system("cls");
//		PrintMatrices(M, size);
//
//		//      M     1      +      =     M     2     //          
//		//      M     1      =      M     0     %     (      5   )  
//		//      M     1      =      M     2     +      M     3
//		cin >> d >> resi >> oprt1 >> d >> pi >> oprt;
//		if (!(47 < oprt && oprt < 58))
//		{
//			cin >> d >> di;
//			if (oprt == '%' or oprt == '&')
//			{
//				cin >> g;
//				di++;
//			}
//		}
//		resi--;
//		pi--;
//		di--;
//		switch (oprt)
//		{
//		case '+':
//			M[resi] = M[pi] + M[di];
//			cout << endl << M[resi];
//			break;
//		case '-':
//			M[resi] = M[pi] + M[di];      //Matrix C=B;
//			cout << endl << M[resi];
//			break;
//
//		case'*':
//			M[resi] = M[pi] * M[di];
//			cout << M[resi];
//			break;
//		case'%':
//
//			M[resi] = M[pi] % (di);
//			cout << endl << M[resi];
//			break;
//		case'&':
//
//			M[resi] = M[pi] & (di);
//			cout << endl << M[resi];
//			break;
//		default:
//
//			//cout << "\nplease enter valid equation.......\n";
//			switch (oprt1)
//			{
//				li2 = oprt - '0';
//				li2--;
//			case'+':
//				M[resi] += M[li2];
//				cout << endl << M[resi];
//
//				break;
//			case'-':
//				M[resi] -= M[li2 + 1];
//				cout << endl << M[resi];
//
//				break;
//			case'*':
//				M[resi] *= M[li2];
//				cout << endl << M[resi];
//				break;
//			case'|':
//				M[resi] |= M[li2];
//				cout << endl << M[resi];
//
//				break;
//			case'^':
//				M[resi] ^= M[li2];
//				cout << endl << M[resi];
//
//				break;
//			case'=':
//				M[resi] == M[li2];
//				break;
//			case '&':
//				M[resi] &= M[li2];
//				cout << endl << M[resi];
//
//				break;
//			case '!=':
//				M[resi] != M[li2];
//				cout << endl << M[resi];
//
//				break;
//			default:
//				break;
//
//				//break;
//			}
//		}
//		cout << "\nDo you want to continue (Y/N)";
//		cin >> tocont;
//
//	} while (tocont == 'y' or tocont == 'Y');
//
//
//
//
//}
//
//int main()
//{
//	Matrix* M;
//	int size = 0;
//	LoadMatrices(M, size);
//	Calculator(M, size);
//
//	PrintMatrices(M, size);
//
//}
//
///*
//M1
//[3][3]
//1   3   5
//2   5   12
//2   4   3
//
//
//M2
//[3][3]
//10  3   2
//1   2   2
//11  7   1
//
//*/