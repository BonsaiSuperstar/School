//Brian Greaney
//June 10th, 2015
//Shipping Charges Calculator
//This program will calculate the charges for shipping based on weight and miles shipped.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

	//Initial information for the consumer.
	cout << "\n"
		 << "Freight Shipping Company Rates\n"
		 << "________________________________________________________________________________\n"
		 << "Weight of Package (pounds)                 Rate per 500 miles shipped\n";
	cout << "________________________________________________________________________________\n"
		 << "      5 pounds or less                       $1.10\n"
		 << "Over  5 pounds but not more than 15          $2.20\n"
		 << "Over 15 pounds but not more than 30          $3.70\n"
		 << "Over 30 pounds but not more than 50          $4.80\n"
		 << "\n"
		 << "________________________________________________________________________________\n";
	cout << "NOTICE: We do not ship packages over 50 pounds\n"
		 << "        We do not ship less than 10 miles or more than 3,000 miles\n"
		 << "\n";
		 
	//Variables.
	double sRate, totalBill;
	int shippingWeight, shippingDistance, distance, totalDistance;
	
	//Get user's input.
	cout << "Please enter the weight (in pounds) of your package: ";
	cin >> shippingWeight;
	cout << "Please enter the distance (in miles) of your shipment: ";
	cin >> shippingDistance;
	
	//Calculate the shipping distance in 500 mile units.
	distance = shippingDistance / 500;
	
	//Decide how to handle shipping distance.
	if (shippingDistance % 500 == 0)
		totalDistance = distance;
	else
        totalDistance = distance + 1;

	//Decide how to handle shipping rates.
	if (shippingWeight < 5)
		sRate = 1.10;
	else if (shippingWeight < 15)
		sRate = 2.20;
	else if (shippingWeight < 30)
		sRate = 3.70;
	else if (shippingWeight <= 50)
		sRate = 4.80;
	else
		cout << "We apologize, but it appears we can not help you.\n";

	totalBill = totalDistance * sRate;
	
	if ((shippingDistance > 3000) || (shippingDistance < 10))
		cout << "We apologize, but it appears we can not help you.\n";
	//Output statements.
	cout << fixed << showpoint << setprecision(2) << "Your shipping rate is: $" << sRate << endl;
	cout << "Number of 500 mile segments: " << totalDistance << endl;

	
	cout << fixed << showpoint << setprecision(2) << "Your total cost is = $" << totalBill << endl;
	
	system("pause");
	return (0);
}
