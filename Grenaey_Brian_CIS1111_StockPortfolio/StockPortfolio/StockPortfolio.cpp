//Brian P Greaney
//June 6th, 2015
//Stock Portfolio
//This program will calculate gains and losses on two stocks purchased from two different technology companies.

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	//Variables
	int max, random;
	double numberOfShares, pricePerShares, newSharePrice, total, randomPercent;
	string name1, name2, symbol1, symbol2;
	max = 100;
	//Input	A
	cout << "Enter the information for your first stock \n";
	cout << "Enter the company name: ";
	getline(cin, name1);
	cout << "Enter the stock symbol: ";
	getline(cin, symbol1);
	cout << "Enter the number of shares purchased: ";
	cin >> numberOfShares;
	cout << "Enter the purchase price per share: $";
	cin >> pricePerShares;
	total = numberOfShares * pricePerShares;
	//Output A
	cout << "Cost of shares = $" << total << endl;
	cout << "Total cost of purchase = $" << total << endl;
	srand(time(0));
	random = ((rand() % max) + 1);
	randomPercent = random * 0.01;
	newSharePrice = (randomPercent  * pricePerShares) + pricePerShares;
	//New_Output A
	cout << "\n";
	cout << "The new value of the stock\n";
	cout << "The new share price is = $" << newSharePrice << endl;
	cout << "The new value of the shares is = $" << newSharePrice * numberOfShares << endl;
	cout << "The total profit or loss is $" << newSharePrice - pricePerShares << endl;
	cout << "\n";
	cin.ignore(); //Figured out pretty quickly that this was necessary.
	//Input B
	cout << "Enter the information for your second stock \n";
	cout << "Enter the company name: ";
	getline(cin,name2);
	cout << "Enter the stock symbol: ";
	getline(cin, symbol2);
	cout << "Enter the number of shares purchased: ";
	cin >> numberOfShares;
	cout << "Enter the purchase price per share: $";
	cin >> pricePerShares;
	total = numberOfShares * pricePerShares;
	//Output B
	cout << "Cost of shares = $" << total << endl;
	cout << "Total cost of purchase = $" << total << endl;
	srand(time(0));
	random = ((rand() % max) + 1);
	randomPercent = random * 0.01;
	newSharePrice = (randomPercent  * pricePerShares) + pricePerShares;
	//New_Output B
	cout << "\n";
	cout << "The new value of the stock\n";
	cout << "The new share price is = $" << newSharePrice << endl;
	cout << "The new value of the shares is = $" << newSharePrice * numberOfShares << endl;
	cout << "The total profit or loss is $" << newSharePrice - pricePerShares << endl;


	system("pause");
	return 0;
}