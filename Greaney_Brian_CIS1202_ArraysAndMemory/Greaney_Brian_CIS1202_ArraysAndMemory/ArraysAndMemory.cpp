//Brian Greaney
//February 08, 2016
//Arrays & Memory
/*This program will help the Menocu Property
Mgmt. Co. to do everything the last program did
but using pointers instead of subscripts. */

#include <iostream>
#include <iomanip>
using namespace std;

int getMenuItem();
void enterRents(int*, int);
void displayRents(int*, int);
int sumRents(int*, int);	
void displayMemoryLocations(int*, int);
void selectionSort(int*, int);
const int SIZE = 7;
int main()
{
	int choice, sum;
	int *ptr = nullptr;
	ptr = new int[SIZE];
	choice = getMenuItem();
	while (choice != 6)
	{
		if (choice == 1)
			enterRents(ptr, SIZE);
		else if (choice == 2)
			displayRents(ptr, SIZE);
		else if (choice == 3)
			selectionSort(ptr, SIZE);
		else if (choice == 4)
		{
			sum = sumRents(ptr, SIZE);
			cout << "Total rent amount = $"
				<< sum << endl;
		}
		else if (choice == 5)
			displayMemoryLocations(ptr, SIZE);
		else
		cout << "  !!!Invalid menu selection, try again!!! \n";
		cout << "\n";
		choice = getMenuItem();
	}

	delete[] ptr;
	ptr = nullptr;
	system("pause");
	return 0;
}

int getMenuItem()
{
	int choice;
	cout << ":^:_____Menocu Property  Management Co.____:^:\n"
		 << "| |                                        | |\n"
		 << "|M|  1. Enter rent ammounts                |M|\n"
		 << "|E|  2. Display rents                      |E|\n"
		 << "|N|  3. Sort rent amounts from low to high |N|\n"
		 << "|O|  4. Total rents                        |O|\n"
		 << "|C|  5. Display memory locations           |C|\n"
		 << "|U|  6. *EXIT program*                     |U|\n"
		 << "|_|________________________________________|_|\n"
		 << "        Enter selection : ";
	cin >> choice;
	cout << "\n";
	return choice;
}

void enterRents(int *ptr, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Enter rent amount " << (i + 1) << ": ";
		cin >> *(ptr + i);
	}
}

void displayRents(int *ptr, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Rental property " << (i + 1)
			<< " = $ " << *(ptr + i) << endl;
	}
}

void selectionSort(int *ptr, int SIZE)
{
	bool swap;
	int temp;
	do
	{
		swap = false;
		for (int i = 0; i < SIZE-1; i++)
		{
			if (*(ptr + i) > *(ptr + (i + 1)))
			{
				temp = *(ptr + i);
				*(ptr + i) = *(ptr + (i + 1));
				*(ptr + (i + 1)) = temp;
				swap = true;
			}
		}
	} while (swap);
}

int sumRents(int*ptr, int SIZE)
{
	int total = 0;
	for (int i = 0; i < SIZE; i++)
	{
		total += *(ptr + i);
	}
	return total;
}

void displayMemoryLocations(int *ptr, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Memory address for cell " << i
			<< " = " << &ptr[i] << endl;
	}
}