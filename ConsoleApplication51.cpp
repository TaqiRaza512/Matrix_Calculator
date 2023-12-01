#include<iostream>
#include"Matrix.h"
#include<fstream>
using namespace std;

void LoadMatrices(Matrix* &M,int &size)
{
	int R,C;
	ifstream Rdr("Matrix.txt");
	Rdr >> size;
	M = new Matrix[size];

	for (int ri=0;ri<size;ri++)
	{
		M[ri].LoadMatrix(Rdr);
	}
}
void PrintMatrices(Matrix *M,int size)
{
	for (int ri=0;ri<size;ri++)
	{

		cout <<"M"<<ri+1<<"\n"<< M[ri];
		cout << endl << endl;
	}
}
void Calculator(Matrix* &M, int size)
{
	char tocont;
	char d,oprt1;
	int resi, pi, di;
	char oprt,g;
	int li2=0;
	do
	{
		system("cls");
		PrintMatrices(M, size); 
			
		//      M     1      +      =     M     2     //          
		//      M     1      =      M     0     %     (      5   )  
		//      M     1      =      M     2     +      M     3
			cin >> d >> resi >> oprt1 >> d >> pi >> oprt;
		  if (!(47<oprt && oprt<58))
		  {
			  cin >> d >> di;
			  if (oprt=='%' or oprt=='&')
			  {
				  cin >> g;
				  di++;
			  }
		  }
		resi--;
		pi--;
		di--;
		switch (oprt)
		{
		case '+':
			M[resi] = M[pi] + M[di];
			cout <<endl<< M[resi];
			break;
		case '-':
			M[resi] = M[pi] + M[di];      //Matrix C=B;
			cout << endl << M[resi];
			break;

		case'*':
			M[resi] = M[pi] * M[di];
			cout << M[resi];
			break;
		case'%':

			M[resi] = M[pi] % (di);
			cout <<endl<< M[resi];
			break;
		case'&':

			M[resi] = M[pi] & (di);
			cout << endl << M[resi];
			break;
		default:
			
			//cout << "\nplease enter valid equation.......\n";
			switch (oprt1)
			{
				li2 = oprt - '0';
				li2--;
			case'+':
				M[resi] += M[li2];
				cout << endl << M[resi];

				break;
			case'-':
				M[resi] -= M[li2+1];
				cout << endl << M[resi];

				break;
			case'*':
				M[resi]*=M[li2];
				cout << endl << M[resi];
				break;
			case'|':
				M[resi] |= M[li2];
				cout << endl << M[resi];

				break;
			case'^':
				M[resi] ^= M[li2];
				cout << endl << M[resi];

				break;
			case'=':
				M[resi] == M[li2];
				break;
			case '&':
				M[resi] &= M[li2];
				cout << endl << M[resi];

				break;
			case '!=':
				M[resi] != M[li2];
				cout << endl << M[resi];

				break;
			default:				
				break;

			//break;
			}
		}
		cout << "\nDo you want to continue (Y/N)";
		cin >> tocont;

	} while (tocont=='y' or tocont=='Y');




}

int main()
{
	Matrix* M;
	int size=0;
	LoadMatrices(M,size);
	Calculator(M,size);
	
	PrintMatrices(M, size);

}