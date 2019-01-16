//Brian Greaney
//March 28, 2016
//BookClass.cpp
#include <iostream>
#include <string>
#include <iomanip>
#include "BookClass.h"

using namespace std;

void Book::storeBook(string bookTitle, string authorName,
	string bookPublisher, string bookISBN, double bookPrice,
	int bookYear, int booksInStock) {
	cout << "Enter book information: \nEnter book title: ";
	getline(cin, bookTitle);
	cout << "Enter author name: ";
	getline(cin, authorName);
	cout << "Enter book publisher: ";
	getline(cin, bookPublisher);
	cout << "Enter book ISBN: ";
	getline(cin, bookISBN,'\n');
	cout << "Enter book price: $";
	cin >> bookPrice;
	cout << "Enter year published: ";
	cin >> bookYear;
	cout << "Enter the number of books in stock: ";
	cin >> booksInStock;
	title = bookTitle;
	author = authorName;
	publisher = bookPublisher;
	isbn = bookISBN;
	price = bookPrice;
	year = bookYear;
	numInStock = booksInStock;
}

void Book::displayBookInfo() const {
	cout << "\n" << setw(17) << "Title: " << title << endl
		<< setw(17) << "Author: " << author << endl
		<< setw(17) << "Publisher: " << publisher << endl
		<< setw(17) << "ISBN: " << isbn << endl
		<< setw(18) << "Price: $" << price << endl
		<< setw(17) << "Year: " << year << endl
		<< setw(17) << "Number in stock: " << numInStock << endl;
}

void Book::checkOutBook() {
	numInStock = numInStock - 1;
}

void Book::returnBook() {
	numInStock = numInStock + 1;
}

string Book::getTitle() const {
	return title;
}

int Book::getNumInStock() const {
	return numInStock;
}