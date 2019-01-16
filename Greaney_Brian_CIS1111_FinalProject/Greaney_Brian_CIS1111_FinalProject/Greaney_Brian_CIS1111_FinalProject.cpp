//Brian Greaney
//August 5th, 2015
//Final Project
/*This final project is for gathering and calculating 
payroll for employees through arrays & functions*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
//Function Prototypes
void getEmployeeData(int[], int[], double[], int);
void calcPay(int[], int[], double[], double[], int);
//Main
int main()
{
	const int AMNT = 7;
	int empID[AMNT] = { 5658845, 4520125, 7895122, 8777542,
		                845277, 1302850, 7580489 };
	int hours[AMNT];
	double payRate[AMNT];
	double wages[AMNT];
	ofstream backupFile;
	backupFile.open("PayrollDataBackup.txt");

	getEmployeeData(empID, hours, payRate, AMNT);
	calcPay(empID, hours, payRate, wages, AMNT);

	for (int i = 0; i < AMNT; i++)
	{
		cout << fixed << showpoint << setprecision(2); //Ensure a .00 decimal point for currancy
		cout << "_______________________________________________\n";
		cout << "             Employee # " << empID[i] << "\n";
		cout << "    Pay Rate = $" << payRate[i] << " ^^^ Hours Worked = " << hours[i] << endl;
		cout << "              Gross Pay = $" << wages[i] << endl;
		cout << "_______________________________________________\n";
		backupFile << empID[i] << " " << hours[i] << " " << payRate[i] << " " << endl;
	}

	backupFile.close();

	system("pause");
	return 0;
}
//Functions
void getEmployeeData(int empID[], int hours[], double payRate[], int AMNT)
{
	for (int i = 0; i < AMNT; i++)
	{
		cout << "Enter hours for Employee # " << empID[i] << ": ";
		cin >> hours[i];
		while (hours[i] <= 0)//Validate input
		{
			cout << "Hours can't be negative!!\n"
				<< "Enter hours for Employee # " << empID[i] << ": ";
			cin >> hours[i];
		}
		cout << "Enter pay rate for Employee # " << empID[i] << ": $";
		cin >> payRate[i];
		while (payRate[i] < 15.00)//Validate input
		{
			cout << "Nobody makes less than $15.00!!\n"
				<< "Enter pay rate for Employee # " << empID[i] << ": $";
			cin >> payRate[i];
		}
		cout << "\n";
	}

}
//More Functions
void calcPay(int empID[], int hours[], double payRate[], double wages[], int AMNT)
{
	for (int i = 0; i < AMNT; i++)
	{
		wages[i] = hours[i] * payRate[i];
	}
}