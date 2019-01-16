//Brian Greaney
//January 22, 2016
//Magic Squares 
/*This program will read an unknown number of "n x n" matrices 
and determine whether or no they are Magic Squares.*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int SIZE = 99;
ifstream inf;
void menu();
void readSquare(int, int[][SIZE]);
void printSquare(int, int[][SIZE]);
bool checkMagic(int, int[][SIZE]);
int sumRow(int, int, int[][SIZE]);
int sumColumn(int, int, int[][SIZE]);
int sumDiagonal1(int, int[][SIZE]);
int sumDiagonal2(int, int[][SIZE]);

int main()
{
	int n;
	int square[SIZE][SIZE];
	inf.open("Prog2Input.txt");
	menu();
	while (inf >> n)
	{
		cout << "Matrix Size = " << n << endl;
		readSquare(n, square);
		printSquare(n, square);
		if (checkMagic(n, square))
		{
			cout << "~MAGIC SQUARE~" << endl;
		}
		else
		{
			cout << "**NOT A MAGIC SQUARE**" << endl;
		}
		cout << endl;
	}

	inf.close();

	system("pause");
	return 0;
}

void readSquare(int n, int square[][SIZE]) 
{
	int x;
	for (int i = 0; i<n; i++) 
	{
		for (int j = 0; j<n; j++) 
		{
			inf >> x;
			square[i][j] = x;
		}
	}
}

void printSquare(int n, int square[][SIZE]) 
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			cout << setw(4) << square[i][j] << setw(4);
		}
		cout << endl;
	}
}
bool checkMagic(int n, int square[][SIZE]) 
{
	int total = ((1 + n*n) / 2)*n;
	for (int i = 0; i < n; i++) 
	{
		if (sumRow(i, n, square) != total) 
		{
			return false;
		}
	}
	for (int i = 0; i<n; i++) 
	{
		if (sumColumn(i, n, square) != total) 
		{
			return false;
		}
	}
	if (sumDiagonal1(n, square) != total) 
	{
		return false;
	}
	if (sumDiagonal2(n, square) != total) 
	{
		return false;
	}
	return true;
}

int sumRow(int row, int n, int square[][SIZE]) 
{
	int sum = 0;
	for (int i = 0; i<n; i++) 
	{
		sum += square[row][i];
	}
	return sum;
}

int sumColumn(int col, int n, int square[][SIZE]) 
{
	int sum = 0;
	for (int i = 0; i<n; i++) 
	{
		sum += square[i][col];
	}
	return sum;
}

int sumDiagonal1(int n, int square[][SIZE]) 
{
	int sum = 0;
	for (int i = 0; i<n; i++) 
	{
		sum += square[i][i];
	}
	return sum;
}

int sumDiagonal2(int n, int square[][SIZE]) 
{
	int sum = 0;
	for (int i = 0; i<n; i++) 
	{
		sum += square[i][(n - i) - 1];
	}
	return sum;
}

void menu()
{
	cout << "******************************************\n";
	cout << "|  Welcome to the Magic Squares program  |\n";
	cout << "******************************************\n";
	cout << endl;
}