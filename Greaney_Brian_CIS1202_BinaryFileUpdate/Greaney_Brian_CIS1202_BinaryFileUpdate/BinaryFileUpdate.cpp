//Brian Greaney
//March 26, 2016
//Binary File Update
/*This is a menu driven program that will allow
users to display, search and modify inventory 
records.*/
#include <iostream>	
#include <fstream>
#include<iomanip>
using namespace std;

const int DESC_SIZE = 40;
struct Product
{
	long prodNum;
	char prodName[DESC_SIZE];
	double price;
	int qty;
};

int showMenu();
void printFile(fstream&);
void displayRecord(fstream&);
void modifyRecord(fstream&);

int main() {
	
	int menu = 0;
	fstream record;

	while (menu != 4) {
		menu = showMenu();
		switch (menu)
		{
		case 1:
			printFile(record);
			break;
		case 2:
			displayRecord(record);
			break;
		case 3:
			modifyRecord(record);
			break;
		case 4:
			cout << "Goodbye...\n";
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}

int showMenu() {
	int choice;
	cout << "1 - Display product inventory\n"
		<< "2 - Display a particular product\n"
		<< "3 - Modify a product\n"
		<< "4 - EXIT program\n\n"
		<< "Enter menu choice: ";
	cin >> choice;
	if (choice < 1 || choice > 4) {
		cout << "WRONG!\nEnter menu choice: ";
		cin >> choice;
	}
	return choice;
}

void printFile(fstream &file) {
	Product pt;
	int i = 0;
	file.open("inventory.dat", ios::in | ios::binary);
	if (!file) {
		cout << "ERROR opening file!\n";
	}
	file.clear();
	file.read(reinterpret_cast<char *>(&pt), sizeof(pt));
	while (!file.eof()) {
		cout << "Record #" << i << " Product Number: "
			<< pt.prodNum << endl;
		cout << "Product Name: " << pt.prodName << endl;
		cout << fixed << showpoint << setprecision(2) 
			<< "Price: $" << pt.price << endl;
		cout << "Quantity: " << pt.qty << endl << endl;
		i++;
		file.read(reinterpret_cast<char *>(&pt), sizeof(pt));
	}
	file.close();
}

void displayRecord(fstream &file) {
	Product pt;
	int choice;
	long byteNum;
	cout << "Enter record number to be displayed: ";
	cin >> choice;
	if (choice > 10 || choice < 0) {
		cout << "WRONG!\nEnter record number to be displayed: ";
		cin >> choice;
	}
	byteNum = sizeof(Product)*choice;
	file.open("inventory.dat", ios::in | ios::binary);
	if (!file) {
		cout << "ERROR opening file!\n";
	}
	file.clear();
	file.seekg(byteNum, ios::beg);
	file.read(reinterpret_cast<char *>(&pt), sizeof(pt));
	cout << "Record #" << choice << " Product Number: "
		<< pt.prodNum << endl;
	cout << "Product Name: " << pt.prodName << endl;
	cout << fixed << showpoint << setprecision(2)
		<< "Price: $" << pt.price << endl;
	cout << "Quantity: " << pt.qty << endl << endl;
	file.close();
}

void modifyRecord(fstream &file) {
	Product pt;
	int choice;
	long byteNum;
	cout << "Enter record number to be modified: ";
	cin >> choice;
	if (choice > 10 || choice < 0) {
		cout << "WRONG!\nEnter record number to be displayed: ";
		cin >> choice;
	}
	byteNum = sizeof(Product)*choice;
	file.open("inventory.dat", ios::in | ios::out | ios::binary);
	if (!file) {
		cout << "ERROR opening file!\n";
	}
	file.clear();
	file.seekg(byteNum, ios::beg);
	file.read(reinterpret_cast<char *>(&pt), sizeof(pt));
	cout << "Enter new data...\n"
		<< "Product Number: ";
	cin >> pt.prodNum;
	cout << "Product Name: ";
	cin.ignore();
	cin.getline(pt.prodName, DESC_SIZE);
	cout << "Price: $";
	cin >> pt.price;
	cout << "Quantity: ";
	cin >> pt.qty;
	file.seekp(byteNum, ios::beg);
	file.write(reinterpret_cast<char *>(&pt), sizeof(pt));
	file.close();
}