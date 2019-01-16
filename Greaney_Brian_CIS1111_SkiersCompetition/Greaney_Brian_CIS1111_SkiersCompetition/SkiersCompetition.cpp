//Brian Greaney
//July 29th, 2015
//Skiers Competition
//This program will take info from a recent downhill ski competition. 
//   It will then allow a user to display fastest times, average times, 
//   look up a skier's individual time and display a list of skiers and their times.

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//function prototypes
void showMenu();
void fastest(string[], double[], int);
void average(double[], int);
void times(string[], double[], int);
void skierList(string[], double[], int);
//main
int main()
{
	const int SIZE = 5;
	int choice;
	double scores[SIZE] = { 2.03, 2.40, 1.85, 1.90, 2.50 };
	string names[SIZE] = { "Leela", "Sarah", "Anna",
						   "Keesha", "Heidi" };
	choice = 1;
	do
	{
		showMenu();
		cin >> choice;
		if (choice == 1)
			fastest(names, scores, SIZE);
		if (choice == 2)
			average(scores, SIZE);
		if (choice == 3)
			times(names, scores, SIZE);
		if (choice == 4)
			skierList(names, scores, SIZE);
	} while (choice > 0 && choice < 5);
	
	system("pause");
	return 0;
}
//functions
void showMenu()
{
	cout << "Enter 1 to determine the fastest skier\n"
		<< "Enter 2 to calculate the average time\n"
		<< "Enter 3 to find the time of a skier\n"
		<< "Enter 4 to display the list of skiers\n"
		<< "To exit enter any other number\n"
		<< "\n";
}

void fastest(string names[], double scores[], int SIZE)
{
	int count;
	double fast;
	string fastName = names[0];
	fast = scores[0];

	for (count = 1; count < SIZE; count++)
	{
		if (scores[count] < fast)
		{
			fast = scores[count];
			fastName = names[count];
		}
	}
	cout << "The fastest skier is " << fastName
		<< " with a time of " << fast << ". \n";
	cout << "\n";
}

void average(double scores[], int SIZE)
{
	double AVG, total = 0;

	for (int i = 0; i < SIZE; i++)
	{
		total += scores[i];
	}
	AVG = total / SIZE;
	cout << "The average time is: " << AVG << endl;
	cout << "\n";
}

void times(string names[], double scores[], int SIZE)
{
	string skier;
	cout << "Skiers\n"
		<< setw(10) << names[0] << endl
		<< setw(10) << names[1] << endl
		<< setw(10) << names[2] << endl
		<< setw(10) << names[3] << endl
		<< setw(10) << names[4] << endl;
	cout << "\n"
		<< "Enter the name of the skier to find their time\n";
	cin >> skier;
	cout << fixed << showpoint << setprecision(2);
	if (skier == "Leela")
		cout << names[0] << "'s time is " << scores[0] << endl;
	else if (skier == "Sarah")
		cout << names[1] << "'s time is " << scores[1] << endl;
	else if (skier == "Anna")
		cout << names[2] << "'s time is " << scores[2] << endl;
	else if (skier == "Keesha")
		cout << names[3] << "'s time is " << scores[3] << endl;
	else if (skier == "Heidi")
		cout << names[4] << "'s time is " << scores[4] << endl;
	else
	{
		cout << "Invalid input!\n"
			<< "Please choose option '3' again and "
			<< "\n\tchoose a name from the list. "
			<< "\n\t^ Rember, type carefully... ^\n";
	}
	cout << "\n";
}

void skierList(string names[], double scores[], int SIZE)
{
	cout << "*Skiers and their times*\n";
	for (int i = 0; i < SIZE; i++)
	{
		cout << fixed << showpoint << setprecision(2);
		cout << setw(10) << names[i] << setw(7) << scores[i] << endl;
	}
	cout << "\n";
}