//Brian P. Greaney
//Junes 17th, 2015
//Horse Stable
/*This program will determine of a horse is overweight or underweight, given the type of 
horse. Once the determination has been made, this will calculate how much the horse
should be fed given it's weight.*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int horseType, horseWeight;
	double feed;
	string horse, weightCat;

	cout << "Joe Bob's Horse Stable\n"
		<< "_______________________________________________________________________________\n"
		<< "Horse Type            Minimum Optimum Weight            Maximum Optimum Weight \n"
		<< "_______________________________________________________________________________\n"
		<< "1. Light Riding Horse        840                           1200\n"
		<< "2. Large Riding Horse        1110                          1300\n"
		<< "3. Draft Horse               1500                          2200\n"
		<< "_______________________________________________________________________________\n"
		<< " \n";

	cout << "Enter type of horse (1-3): ";
	cin >> horseType;

	if (horseType == 1)
	{
		horse = "Light Riding Horse";
		cout << "Horse Type: " << horse << endl;
		cout << "Enter horse's wieght in pounds: ";
		cin >> horseWeight;
		cout << "The horse's weight is " << horseWeight << " pounds. \n";
		if ((horseWeight >= 840) && (horseWeight <= 1200))
		{
			weightCat = "Optimum";
			feed = 3.0;
			cout << "Weight Category: " << weightCat << endl;
			cout << "Feed: " << feed << " pounds." << endl;
		}
		else if (horseWeight < 840)
		{
			weightCat = "Underweight";
			feed = 3.3;
			cout << "Weight Category: " << weightCat << endl;
			cout << "Feed: " << feed << " pounds." << endl;
		}
		else if (horseWeight > 1200)
		{
			weightCat = "Overweight";
			feed = 2.5;
			cout << "Weight Category: " << weightCat << endl;
			cout << "Feed: " << feed << " pounds." << endl;
		}
	}
	else if (horseType == 2)
	{
		horse = "Large Riding Horse";
		cout << "Horse Type: " << horse << endl;
		cout << "Enter horse's wieght in pounds: ";
		cin >> horseWeight;
		cout << "The horse's weight is " << horseWeight << " pounds. \n";
		if ((horseWeight >= 1110) && (horseWeight <= 1300))
		{
			weightCat = "Optimum";
			feed = 3.0;
			cout << "Weight Category: " << weightCat << endl;
			cout << "Feed: " << feed << " pounds." << endl;
		}
		else if (horseWeight < 1110)
		{
			weightCat = "Underweight";
			feed = 3.3;
			cout << "Weight Category: " << weightCat << endl;
			cout << "Feed: " << feed << " pounds." << endl;
		}
		else if (horseWeight > 1300)
		{
			weightCat = "Overweight";
			feed = 2.5;
			cout << "Weight Category: " << weightCat << endl;
			cout << "Feed: " << feed << " pounds." << endl;
		}
	}
	else if (horseType == 3)
	{
		horse = "Draft Horse";
		cout << "Horse Type: " << horse << endl;
		cout << "Enter horse's wieght in pounds: ";
		cin >> horseWeight;
		cout << "The horse's weight is " << horseWeight << " pounds. \n";
		if ((horseWeight >= 1500) && (horseWeight <= 2200))
		{
			weightCat = "Optimum";
			feed = 3.0;
			cout << "Weight Category: " << weightCat << endl;
			cout << "Feed: " << feed << " pounds." << endl;
		}
		else if (horseWeight < 1500)
		{
			weightCat = "Underweight";
			feed = 3.3;
			cout << "Weight Category: " << weightCat << endl;
			cout << "Feed: " << feed << " pounds." << endl;
		}
		else if (horseWeight > 2200)
		{
			weightCat = "Overweight";
			feed = 2.5;
			cout << "Weight Category: " << weightCat << endl;
			cout << "Feed: " << feed << " pounds." << endl;
		}
	}
	else
		cout << "Not a valid horse type. \n";
	
	system("pause");
	return 0;

}