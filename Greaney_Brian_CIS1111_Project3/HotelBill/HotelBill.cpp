//Brian P Greaney
//May 30, 2015
//Hotel Bill
//This program calculates a hotel bill based on room rates and length of stay

#include<iostream>
using namespace std;

int main()
{
	//List of Variables
	double roomRate = 100;
	double depositRate = .10;
	double resortFee = 10;
	double resortTax = .085;
	double numberOfDays = 6;
	double roomCharge = numberOfDays * roomRate;
	double totalResortFees = resortFee * numberOfDays;
	double totalCharges = roomCharge + totalResortFees;
	double tax = resortTax * totalCharges;
	double deposit = totalCharges * depositRate;
	double totalBill = roomCharge + totalResortFees + tax;
	double checkIn = totalBill - deposit;

	//Output
	cout << "Length of stay = " << numberOfDays << endl;
	cout << "Daily rate = $" << roomRate << endl;
	cout << "Daily resort fee = $" << resortFee << endl;
	cout << "Resort tax rate = " << resortTax << endl;
	cout << "" << endl; //Not sure how to do a line break, but this worked.
	cout << "Itemized Bill: \n";
	cout << "     Total Room Charge: $" << roomCharge << endl; //Still not sure how to indent lines, so I just spaced them within the quotes.
	cout << "     Total Resort Fees: $" << totalResortFees << endl;
	cout << "     Total Resort Tax: $" << tax << endl;
	cout << "     Total Bill: $" << totalBill << endl;
	cout << "     Total Deposit: $" << deposit << endl;
	cout << "Ammount due at check in: $" << checkIn << endl;
	
	system("pause");
	return 0;
}