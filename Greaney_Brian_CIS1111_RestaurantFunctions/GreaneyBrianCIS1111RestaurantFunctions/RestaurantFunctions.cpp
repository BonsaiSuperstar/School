//Brian Grenaey
//July 16th, 2015
//Restaurant Functions
//This is a menu-driven program for food purchases at the baseball stadium restaurant.
//It will total the bill and tell the user their change after paying.

#include <iostream>
#include <iomanip>
using namespace std;

void menu();
void addingUp(double, double, double, double);
void finishUp(double, double);

int main()
{
	int choice;
	double bill = 0.00,
		totBill = 0.00,
		tax = 0.00,
		tip = 0.00,
		amtTendered = 0.00;
	
	menu();

	cout << "Please select your choices using 1-7. Use 8 to end order & pay your bill\n";
	
	cout << fixed << showpoint << setprecision(2);

	do
	{
		cout << "\tEnter menu item: ";
		cin >> choice;

		while (choice < 1 || choice > 8)
		{
			cout << "Please enter a valid menu choice: ";
			cin >> choice;
		}
		if (choice == 1)
			bill += 6.00;
		else if (choice == 2)
			bill += 4.50;
		else if (choice == 3)
			bill += 3.75;
		else if (choice == 4)
			bill += 5.50;
		else if (choice == 5)
			bill += 2.80;
		else if (choice == 6)
			bill += 1.00;
		else if (choice == 7)
			bill += 2.00;

	} while (choice != 8);
	cout << "\n";

	tax = bill * .065;
	tip = bill * .20;
	totBill = bill + tax + tip;

	addingUp(bill, totBill, tax, tip);

	cout << "\n";
	cout << " Ammount tendered: $";
	cin >> amtTendered;
	
	while (amtTendered < totBill)
	{
		cout << "That's not enough money\n"
			<< "Please enter a new ammount: $";
		cin >> amtTendered;
	}
	cout << "\n";

	finishUp(totBill, amtTendered);

	system("pause");
	return 0;
}

void menu()
{
	cout << "**************************************************************************\n"
		 << "X|______________________BASEBALL_GAME_SNACKS_MENU_______________________|X\n"
		 << "X|                   1. Hamburger              $6.00                    |X\n"
		 << "X|                   2. Hotdog                 $4.50                    |X\n"
		 << "X|                   3. Peanuts                $3.75                    |X\n"
		 << "X|                   4. Popcorn                $5.50                    |X\n"
		 << "X|                   5. Soda                   $2.80                    |X\n"
		 << "X|                   6. Chips                  $1.00                    |X\n"
	 	 << "X|                   7. Water                  $2.00                    |X\n"
		 << "X|                   8. 'END ORDER'                                     |X\n"
		 << "X|______________________________________________________________________|X\n"
		<< "\n"
		<< "\n";
}

void addingUp(double bill, double totBill, double tax, double tip)
{
		
	cout << "            Bill = $" << bill << endl;
	cout << "             Tax = $" << tax << endl;
	cout << "             Tip = $" << tip << endl;
	cout << "           Total = $" << totBill << endl;
	
}

void finishUp(double totBill, double amtTendered)
{
	cout << "       Change due: $" << amtTendered - totBill << endl;
	cout << "\n";
}