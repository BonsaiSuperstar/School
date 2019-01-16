//Brian Greaney
//June 24th, 2015
//BMI and Caloric Intake Calculator
//This program calculates and displays a person’s body mass index (BMI) along with their recommended daily caloric intake.

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	string name, weightClass;
	char gender;
	double weight, height, BMI, dailyCaloric;
	int activityLevel;
	
	cout << "_______________________________________________________________________________\n"
		 << "                        BMI & Caloric Intake Calculator                        \n"
		 << "_______________________________________________________________________________\n"
		 << "\n";

	cout << "Please enter your name: ";
	getline(cin, name);
	cout << "Please enter your height in inches: ";
	cin >> height;
	cout << "Please enter your weight in pounds: ";
	cin >> weight;

	BMI = ((weight * 703) / pow(height, 2.0));

	if (BMI <= 25 && BMI >= 18.5)
		weightClass = "Optimal";
	else if (BMI < 18.5)
		weightClass = "Underweight";
	else if (BMI > 25)
		weightClass = "Overweight";
	cout << "\n";

	cout << "\tName:            " << name << endl;
	cout << fixed << setprecision(1) << "\tBMI:             " << BMI << endl;
	cout << "\tWeight Class:    " << weightClass << endl;
	cout << "\n";

	cout << "Please enter your gender.\n Use 'M' for Male, 'F' for Female. ";
	cin >> gender;
	cout << "Please enter your activity level.\n Use '1' for Active and '2' for Inactivity. ";
	cin >> activityLevel;
	cout << "\n";

	if (gender == 'M' || gender == 'm')
	{
		if (activityLevel == 1)
			dailyCaloric = weight * 15;
		else if (activityLevel == 2)
			dailyCaloric = weight * 13;
		else
			cout << "Please use a '1' or '2' for activity level. \n";
	}
	else if (gender == 'F' || gender == 'f')
	{
		if (activityLevel == 1)
			dailyCaloric = weight * 12;
		else if (activityLevel == 2)
			dailyCaloric = weight * 10;
		else
			cout << "Please use a '1' or '2' for activity level. \n";
	}
	else
		cout << "Please use 'M' or 'F' for gender. \n";

	cout << "\tGender:                     " << gender << endl;
	cout << "\tActivity Level:             " << activityLevel << endl;
	cout << "\tRecommended Caloric Intake: " << dailyCaloric << endl;
	cout << "\n"
		<< "Thanks for using this program. Have a nice day!\n"
		<< "\n";

	system("pause");
	return 0;
}
