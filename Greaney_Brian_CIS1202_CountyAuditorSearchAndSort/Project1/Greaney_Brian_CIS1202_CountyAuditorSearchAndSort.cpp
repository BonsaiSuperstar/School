//Brian Greaney
//January 30, 2016
//County Auditor's Search & Sort
/*This program will read property tax data 
from a file and allow the user to display,
look up, sort and see largest amounts due.*/
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

const int SIZE = 7;
ifstream inFile;
void loadArrays(string[], double[], int&);
void showArrays(string[], double[], int);
void lookUpTaxes(string[], double[], int);
void sortTaxes(string[], double[], int);
void biggestTaxes(string[], double[], int);
int showMenu();

int main()
{
	string address[SIZE];
	double amtDue[SIZE];
	int length, choice;

	loadArrays(address, amtDue, length);
	choice = showMenu();
	while (choice != 5)
	{
		if (choice == 1)
			showArrays(address, amtDue, length);
		else if (choice == 2)
			lookUpTaxes(address, amtDue, length);
		else if (choice == 3)
			sortTaxes(address, amtDue, length);
		else if (choice == 4)
			biggestTaxes(address, amtDue, length);
		else
			cout << "Invalid choice - try again\n\n";
		choice = showMenu();
	}
	system("pause");
	return 0;
}

int showMenu()
{
	int choice;
	cout << "County Auditor's Property Tax Sort & Search\n"
		<< "\n"
		<< "1: Display the property tax data\n"
		<< "2: Look up taxes for a particular address\n"
		<< "3: Sort tax ammounts in ascending order\n"
		<< "4: Display property with largest tax due\n"
		<< "5: EXIT\n"
		<< "\n"
		<< "Please enter your selection: ";
	cin >> choice;
	return choice;
}

void loadArrays(string address[], double amtDue[], int &length)
{
	inFile.open("prog3Input.txt");
	if (inFile.fail())
		cout << "Error opening the file\n";
	for (int i = 0; i < SIZE; i++)
	{
		getline((inFile >> ws), address[i]);
		inFile >> amtDue[i];
		length = i + 1;
	}
	inFile.close();
}

void showArrays(string address[], double amtDue[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << left << setw(10) << address[i]
			<< " = $" << amtDue[i] << endl;
	}
}

void lookUpTaxes(string address[], double amtDue[], int length)
{
	int i = 0, position = -1;
	bool found = false;
	string choice;
	cout << "Enter address to look up: ";
	cin.ignore();
	getline(cin, choice);
	while (i < length&&!found)
	{
		if (address[i] == choice)
		{
			found = true;
			position = i;
		}
		i++;
	}
	cout << "The taxes for " << address[position] << " = $"
		<< amtDue[position] << endl;
}

void sortTaxes(string address[], double amtDue[], int length)
{
	bool swap;
	double temp1;
	string temp2;
	do
	{
		swap = false;
		for (int i = 0; i < (length - 1); i++)
		{
			if (amtDue[i] >amtDue[i + 1])
			{
				temp1 = amtDue[i];
				temp2 = address[i];
				amtDue[i] = amtDue[i + 1];
				address[i] = address[i + 1];
				amtDue[i + 1] = temp1;
				address[i + 1] = temp2;
				swap = true;
			}
		}
	} while (swap);
}

void biggestTaxes(string address[], double amtDue[], int length)
{
	double temp = 0;
	string temp2;
	for (int i = 0; i < length; i++)
	{
		if (amtDue[i]>temp)
		{
			temp = amtDue[i];
			temp2 = address[i];
		}
	}
	cout << "The largest tax amount is: $" << temp
		<< " at " << temp2 << endl;
}