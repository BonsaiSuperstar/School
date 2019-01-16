//Brian Greaney
//May 30, 2015
//Defining Variables
//This program will use cout to output values of the variables

#include<iostream> 
#include <string>
using namespace std;

int main()
{
	string Name;
	string Major;
	int CreditHours;
	double tuitionRate;
	double total;
	Name = "Brian Greaney";
	Major = "CIS_User Support";
	CreditHours = 6;
	tuitionRate = 99.03;
	total = CreditHours * tuitionRate;

	cout << "Hello, my name is " << Name << endl;
	cout << "My major here at Siclair is " << Major << endl;
	cout << "I am currently taking " << CreditHours << " credit hours this summer." << endl;
	cout << "I am paying $" << tuitionRate << " per credit hour." << endl;
	cout << "For a grand total of: $" << total << endl;


	system("pause");
	return 0;

}