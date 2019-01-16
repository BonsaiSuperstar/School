#include "InventoryClass.h"
#include "InventoryCostClass.h"
#include<iostream>
#include<fstream>
#include<ctime>
#include<cstring>
#include<algorithm>
using namespace std;

const int SIZE = 6;

struct Edit {
	int itID;
	char  code[3], edit[51];
};


int menu();
void displayInv(InventoryCost[]);
void createFile(fstream&, string, int*);
void updateArray(fstream&, string, InventoryCost[],int);
void prof(InventoryCost[]);

int main() {

	InventoryCost itemInv[SIZE] = 
	  { InventoryCost(209875, "Global - Designed Wrench : catalog 145HN - 89", 1056,
		  14.67, 23.99, 10, 13, 2014),
	    InventoryCost(176524, "Steeheel Chainsaw - 120 H - P: catalog 133NM - 65", 2654,
		  234.67, 299.99, 10, 13, 2014),
	    InventoryCost(340965, "Plurers Pliers with Sure - Grip: catalog 764TW - 12", 1043,
		  11.45, 19.98, 10, 13, 2014),
		InventoryCost(453285, "Rapid Recoil Hand Tape Measure: catalog 127UY - 32", 3316, 
		  8.56, 15.99, 10, 13, 2014),
		InventoryCost(893167, "Steady Built Steel Saw Horses: catalog 564HG - 34", 764, 
		  45.54, 79.99, 10, 13, 2014),
		InventoryCost(597895, "Big Boy Bib Overalls - L - XL - XXL: catalog 278LG - 45", 5032, 
		  19.76, 39.99, 10, 13, 2014) };
	int ch = 0, num = 0;
	fstream file;
	string filename, name, extension = ".dat";

	cout << " *Choose a name for the update file: ";
	cin >> name;
	filename = name + extension;
	do {
		ch = menu();
		if (ch != 6) {
			switch (ch)
			{
			case 1:
				displayInv(itemInv);
				break;
			case 2:
				createFile(file, filename, &num); 
				break;
			case 3:
				updateArray(file, filename, itemInv, num);
				break;
			case 4: 
				displayInv(itemInv);
				break;
			case 5:
				prof(itemInv);
				break;
			}
		}
	} while (ch != 6);

	system("pause");
	return 0;
}

int menu() {
	int choice;
	cout << "**********************************\n"
		<< "*________MENOCU TOOL SHOP________*\n"
		<< "**********************************\n"
		<< "*  1. Display Inventory          *\n"
		<< "*  2. Create a Transaction File  *\n"
		<< "*  3. Update Inventory           *\n"
		<< "*  4. Display Updated Inventory  *\n"
		<< "*  5. Compute Profit Projection  *\n"
		<< "*  6. EXIT                       *\n"
		<< "**********************************\n"
		<< " Menu Choice: ";
	cin >> choice;
	return choice;
}

void displayInv(InventoryCost itemInv[SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		cout << "Item #" << i+1 << ": " << endl;
		itemInv[i].print();
	}
}

void createFile(fstream &file, string filename, int *num) {
	Edit ed;
	int times;
	file.open(filename, ios::out | ios::binary);
	if (!file) {
		cout << "ERROR opening file!\n";
	}
	cout << "How many records to ammend: ";
	cin >> times;
	*num = times;
	cout << "Her are the Transaction Codes: \n"
		<< "\tAI: Add to Inventory\n"
		<< "\tRI: Reduce from Inventory\n"
		<< "\tCW: Change Wholesale Cost\n"
		<< "\tCR: Change Retail Price\n"
		<< "\tCD: Change Description\n\n";
	for (int i = 0; i < *num; i++) {
		cout << "\nEnter the ItemID #: ";
		cin >> ed.itID;
		cout << "Enter the Transaction Code: ";
		cin.ignore();
		cin.getline(ed.code, 3);
		cout << "Enter New Data: ";
		cin.getline(ed.edit, 51);
		file.write(reinterpret_cast<char *>(&ed), sizeof(ed));
	}
	file.close();
}
 
void updateArray(fstream &file, string filename, InventoryCost inv[SIZE], int num) {
	Edit it;
	time_t t = time(0);
	struct tm * now = localtime(&t);
	file.open(filename, ios::in | ios::binary);
	if (!file) {
		cout << "ERROR opening file!\n";
	}
	file.clear();
	file.read(reinterpret_cast<char *>(&it), sizeof(it));
	while (!file.eof()) {		
		for (int i = 0; i < num; i++) {
			int itemNum, Ednum;
			itemNum = inv[i].getID();
			Ednum = it.itID;
			if (itemNum == Ednum) {
				if (strcmp(it.code,"AI")==0) {
					int add = inv[i].getQty() + (atoi(it.edit));
					inv[i].setQty(add);
				}
				else if (strcmp(it.code, "RI") == 0) {
					int sub = inv[i].getQty() - (atoi(it.edit));
					inv[i].setQty(sub);
				}
				else if (strcmp(it.code, "CW") == 0) {
					double whsale = (atof(it.edit));
					inv[i].setWCost(whsale);
				}
				else if (strcmp(it.code, "CR") == 0) {
					double retail = (atof(it.edit));
					inv[i].setRCost(retail);
				}
				else if (strcmp(it.code, "CD") == 0) {
					inv[i].setDesc(it.edit);
				}
				//else
					//cout << "Invalid Transaction Code\n";
			}
			inv[i].setMonth(now->tm_mon + 1);
			inv[i].setDay(now->tm_mday);
			inv[i].setYear(now->tm_year + 1900);
		}
		file.read(reinterpret_cast<char *>(&it), sizeof(it));
	}
	file.close();
	cout << "*Items Succesfully Updated*\n";
}

void prof(InventoryCost itInv[SIZE]) {
	double p;
	for (int i = 0; i < SIZE; i++) {
		p = (itInv[i].getRCost() * itInv[i].getQty())
			- (itInv[i].getWCost() * itInv[i].getQty());
		cout << fixed << showpoint << setprecision(2)
			<< "Profit Projection for Inventory Item #" 
			<< i + 1 << " = $" << p << endl;
	}
}