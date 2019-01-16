//Brian Greaney
//March 28, 2016
//BookClass Header
#ifndef BOOKCLASS_H
#define BOOKCLASS_H
#include<string>
using namespace std;
class Book {
private:
	string title,
		author,
		publisher,
		isbn;
	double price;
	int year,
		numInStock;
public:
	void storeBook(string, string, string,
		string, double, int, int);
	void displayBookInfo() const;
	void checkOutBook();
	void returnBook();
	string getTitle() const;
	int getNumInStock() const;
};
#endif
