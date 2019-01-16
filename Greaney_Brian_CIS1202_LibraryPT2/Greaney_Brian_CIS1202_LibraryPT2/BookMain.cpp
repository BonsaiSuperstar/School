//Brian Greaney
//April 4, 2016
//Library - Part 2
/*This program uses my BookClass
from last weeks program. It will 
fill an array of class objects from
a text file and allow a user to
preform some basic librarian functions.*/
#include "BookClass.h"
#include <iostream>
#include <string>	
#include <iomanip>
#include <fstream>	
using namespace std;

ifstream inFile;
const int MAXBOOKS = 6;
void getBooks(Book[]);
void showBooks(Book[]);
void showTitles(Book[]);
void findBook(Book[]);
void checkIn(Book[]);
void checkOut(Book[]);
int getMenuChoice();
 
int main(){
	Book books[MAXBOOKS];
	int choice=0;
	getBooks(books);
	
	do {
		choice = getMenuChoice();
		if (choice != 6) {
			switch (choice) {
			case 1:
				showBooks(books);
				break;
			case 2:
				showTitles(books);
				break;
			case 3:
				findBook(books);
				break;
			case 4:
				checkOut(books);
				break;
			case 5: 
				checkIn(books);
			}
		}
	} while (choice != 6);
	
	return 0;
}

int getMenuChoice() {
	int c;
	cout<< "************************\n" 
		<< "*____Menocu Library____*\n"
		<< "************************\n"
		<< " 1. Display all books\n"
		<< " 2. Display book titles\n"
		<< " 3. Find book\n"
		<< " 4. Check out\n"
		<< " 5. Check in\n"
		<< " 6. EXIT program\n\n"
		<< "Enter menu choice: ";
	cin >> c;
	if (c > 6 || c < 1) {
		cout << "Wrong!!\n"
			<< "Enter menu choice: ";
		cin >> c;
	}
	return c;
}

void getBooks(Book bks[MAXBOOKS]) {
	string t, a, i, p;
	double prc = 0;
	int yr = 0, num = 0;
	inFile.open("books.txt");
	if (inFile.fail())
		cout << "Error opening the file\n";
	for (int n = 0; n < MAXBOOKS; n++) {
		getline((inFile >> ws), t);
		getline((inFile >> ws), a);
		getline((inFile >> ws), p);
		getline((inFile >> ws), i);
		inFile >> prc;
		inFile >> yr;
		inFile >> num;
		bks[n].storeBook(t, a, p, i, prc, yr, num);
	}
	inFile.close();
}

void showBooks(Book books[MAXBOOKS]) {
	for (int i = 0; i < MAXBOOKS; i++) {
		books[i].displayBookInfo();
	}
}

void showTitles(Book books[MAXBOOKS]) {
	cout << "\n";
	for (int i = 0; i < MAXBOOKS; i++) {
		cout << "\t" << books[i].getTitle() 
			<< endl;
	}
	cout << "\n";
}

void findBook(Book bks[MAXBOOKS]) {
	string name;
	int i = 0, pos = -1;
	bool found = false;
	cin.ignore();
	cout << "Enter book title: ";
	getline(cin, name);
	while (i < MAXBOOKS && !found) {
		if (bks[i].getTitle() == name) {
			found = true;
			pos = i;
		}
		i++;
	}
	if (found) {
		cout << bks[pos].getNumInStock()
			<< " copies of " << bks[pos].getTitle()
			<< " are in stock " << endl << endl;
	}
	else {
		cout << name << " not found\n\n";
	}
}

void checkIn(Book bks[MAXBOOKS]) {
	string name;
	int i = 0, pos = -1;
	bool found = false;
	cin.ignore();
	cout << "Enter book title: ";
	getline(cin, name);
	while (i < MAXBOOKS && !found) {
		if (bks[i].getTitle() == name) {
			found = true;
			pos = i;
		}
		i++;
	}
	if (found) {
		bks[pos].returnBook();
		cout << "We now have "
			<< bks[pos].getNumInStock()
			<< " copies in stock.\n\n";
	}
	else {
		cout << "Sorry we do not stock "
			<< name << endl << endl;
	}
}

void checkOut(Book bks[MAXBOOKS]) {
	string name;
	int i = 0, pos = -1;
	bool found = false;
	cin.ignore();
	cout << "Enter book title: ";
	getline(cin, name);
	while (i < MAXBOOKS && !found) {
		if (bks[i].getTitle() == name) {
			found = true;
			pos = i;
		}
		i++;
	}
	if (found) {
		bks[pos].checkOutBook();
		cout << "We now have "
			<< bks[pos].getNumInStock()
			<< " copies in stock.\n\n";
	}
	else {
		cout << "Sorry we do not stock "
			<< name << endl << endl;
	}
}