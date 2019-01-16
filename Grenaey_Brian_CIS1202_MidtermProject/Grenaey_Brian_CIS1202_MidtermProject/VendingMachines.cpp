//Brian Greaney
//March 18, 2016
//Vending Machine Midterm Project
/*This is a program that will read data from
a file and load it into an array of structures.
This will help keep track of purchases and inventory.*/

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>	
using namespace std;

const int MAX_SODA_BRANDS = 5;

enum SodaBrands{COKE, DIET_COKE, SPRITE,
				SPRITE_ZERO, DASANI};	

struct Drinks {
	double prices;
	int numSodas;
};

struct VendingMachine {
	string location;
	Drinks sodas[MAX_SODA_BRANDS];
};

void loadVendingMachines(VendingMachine[]);
void showVendingMachines(VendingMachine[]);
int getLocation();
int getDrinkSelection();
void makePurchase(VendingMachine[], int, int);

int main() {
	VendingMachine VM[6];
	int choice=0, dChoice;

	loadVendingMachines(VM);

	do {
		choice = getLocation();
		if (choice != 6) {
			dChoice = getDrinkSelection();
			makePurchase(VM, choice, dChoice);
		}
	} while (choice != 6);
	
	showVendingMachines(VM);

	system("pause");
	return 0;
}

void loadVendingMachines(VendingMachine VM[6]) {
	ifstream inFile;
	inFile.open("vendingMachines.txt");
	if (inFile.fail())
		cout << "Error opening the file\n";
	for (int i = 0; i < 6; i++) {
		getline((inFile>>ws), VM[i].location);
		for (int j = 0; j < MAX_SODA_BRANDS; j++) {
			inFile >> VM[i].sodas[j].prices
				>> VM[i].sodas[j].numSodas;
		}

	}
	inFile.close();
}

void showVendingMachines(VendingMachine VM[6]) {
	cout << "Vending Machines\n\n";
	cout << fixed << setprecision(2);
	for (int i = 0; i < 6; i++) {
		cout << "\nVending Machine Location: "
			<< VM[i].location << endl;
		cout << "\tCoke price: $" << VM[i].sodas[COKE].prices
			<< " - # of sodas: " << VM[i].sodas[COKE].numSodas
			<< endl;
		cout << "\tDiet Coke price: $" << VM[i].sodas[DIET_COKE].prices
			<< " - # of sodas: " << VM[i].sodas[DIET_COKE].numSodas
			<< endl;
		cout << "\tSprite price: $" << VM[i].sodas[SPRITE].prices
			<< " - # of sodas: " << VM[i].sodas[SPRITE].numSodas
			<< endl;
		cout << "\tSprite Zero price: $" << VM[i].sodas[SPRITE_ZERO].prices
			<< " - # of sodas: " << VM[i].sodas[SPRITE_ZERO].numSodas
			<< endl;
		cout << "\tDasani price: $" << VM[i].sodas[DASANI].prices
			<< " - # of sodas: " << VM[i].sodas[DASANI].numSodas
			<< endl;
	}
}

int getLocation() {
	int c;
	cout << "Select location from the following: \n"
		<< "0: Sinclair Community College\n"
		<< "1: Wright State University\n"
		<< "2: University of Dayton\n"
		<< "3: The Ohio State University\n"
		<< "4: Clark State Community College\n"
		<< "5: Ohio University\n"
		<< "6: EXIT\n"
		<< "Enter your location: ";
	cin >> c;
	return c;
}

int getDrinkSelection() {
	int d;
	cout << "Soda Choices: \n\n"
		<< "0: Coke\n"
		<< "1: Diet Coke\n"
		<< "2: Sprite\n"
		<< "3: Sprite Zero\n"
		<< "4: Dasani\n"
		<< "Enter soda choice: ";
	cin >> d;
	return d;
}

void makePurchase(VendingMachine VM[6], int local, int soda) {
	string drink;
	VendingMachine temp = VM[local];
	double amt, chng;
	switch (soda) {
	case 0: drink = "Coke";
		break;
	case 1: drink = "Diet Coke";
		break;
	case 2: drink = "Sprite";
		break;
	case 3: drink = "Sprite Zero";
		break;
	case 4: drink = "Dasani";
	}
	cout << "\nYou selected location: " << temp.location << endl;
	cout << "Drink selection: " << drink << endl;
	cout << fixed << setprecision(2);
	cout << "The price of your selection is: $"
		<< temp.sodas[soda].prices << endl;
	cout << "Please enter amount paid: $";
	cin >> amt;
	chng = amt - temp.sodas[soda].prices;
	cout << fixed << setprecision(2) << "Change due = $"
		<< chng << "\n\n";
}

