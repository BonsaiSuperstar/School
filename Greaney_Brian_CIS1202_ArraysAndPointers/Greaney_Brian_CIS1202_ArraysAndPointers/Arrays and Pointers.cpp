//Brian Greaney
//February 1, 2016
//Arrays & Pointers
/*This program uses an array to store, display,
  sort, and total the income for his 5 rental
  properties.*/

#include<iostream>
using namespace std;

const int S = 5;
int getMenuItem();
void enterRents(int[], int);
void displayRents(int*, int);
void displayMemoryLocations(int[], int);
void selectionSort(int[], int);

int main()
{
	int choice, rent[S];
	int *ptr = nullptr;
	ptr = rent;
	choice = getMenuItem();
	while (choice != 5)
	{
		if (choice == 1)
			enterRents(rent, S);
		else if (choice == 2)
			displayRents(ptr, S);
		else if (choice == 3)
			selectionSort(rent, S);
		else if (choice == 4)
			displayMemoryLocations(rent, S);
		else
			cout << "Invalid menu selection, try again\n";
		choice = getMenuItem();
	}

	system("pause");
	return 0;
}

int getMenuItem()
{
	int choice;
	cout << "Menocu Property Management Co.\n\n"
		<< "1. Enter rent amounts\n"
		<< "2. Display rents\n"
		<< "3. Sort rent amounts\n"
		<< "4. Display rent array memory locations\n"
		<< "5. *EXIT Program*\n"
		<< "\n";
	cout << "Enter selection: ";
	cin >> choice;
	return choice;
}

void enterRents(int rent[], int S)
{
	for (int i = 0; i < S; i++)
	{
		cout << "Enter rent ammount " << (i + 1) << ": ";
		cin >> rent[i];
	}
}

void displayRents(int *ptr, int S)
{
	for (int i = 0; i < S; i++)
	{
		cout << "Rental property " << i + 1 
			<< " = $" << *ptr << endl;
		*ptr++;
	}
}

void displayMemoryLocations(int rent[], int S)
{
	for (int i = 0; i < S; i++)
	{
		cout << "Memory address for cell " << i
			<< " = " << &rent[i] << endl;
	}
}
void selectionSort(int rent[], int S)
{
	bool swap;
	int temp;
	do
	{
		swap = false;
		for (int i = 0; i < S - 1; i++)
		{
			if (rent[i]>rent[i + 1])
			{
				temp = rent[i];
				rent[i] = rent[i + 1];
				rent[i + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}