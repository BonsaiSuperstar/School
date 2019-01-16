//Brian Greaney
//February 20, 2016
//C-Strings
//This program takes a C-string work order code
// and break it down into specific sections.

#include<iostream>
#include<cstring>
#include<cctype>
#include<cstdlib>
using namespace std;

int findW(char[], int);
long getCustNum(char[], int);
int getYear(char[], int);
long getOrderNum(char[], int, int);
const int MAX = 15;

int main()
{
	char number[] = "91800w941770";
	int w, year, length;
	long custNum, orderNum;
	
	cout << "Enter a three part work order code in the format "
		<< "CustomerNumber Year OrderNumber\n"
		<< "The first 5-6 digits contain the customer "
		<< "number (digits before the 'w')\n"
		<< "The 2 digits following the 'w' represent the year\n"
		<< "The remaing digits (up to 5) represent the work "
		<< "order number\n"
		<< "Enter work order code: " << number
		<< endl << endl;

	length = strlen(number);
	w = findW(number, length);
	custNum = getCustNum(number, w);
	year = getYear(number, w);
	orderNum = getOrderNum(number, length, w);

	cout << "Work order breakdown\n"
		<< "Lenght = " << length << "\n"
		<< "Location of 'w' = " << w << "\n"
		<< "Customer number = " << custNum << "\n"
		<< "Year of the order = " << year << "\n"
		<< "Order number = " << orderNum << "\n"
		<< endl;

	system("pause");
	return 0;
}



int findW(char number[], int length)
{
	char * pch;
	int found;
	pch = strchr(number, 'w');
	found = (pch - number + 1);
	return found;
}

long getCustNum(char number[], int w)
{
	char numCopy[MAX];
	long csNum;
	strncpy_s(numCopy, number, w);
	numCopy[w] = '\0';
	csNum = atol(numCopy);
	return csNum;
}

int getYear(char number[], int w)
{
	int year, i=0;
	char copy[2];
	while (i < 2)
	{
		copy[i] = number[i + w];
		i++;
	}
	year = atoi(copy);
	return year;
}

long getOrderNum(char number[], int length, int w)
{
	int oNum, i = 0;
	char temp[MAX];
	while (i < length)
	{
		temp[i] = number[i + (w + 2)];
		i++;
	}
	oNum = atol(temp);
	return oNum;
}