//Brian Greaney
//March 28, 2016
//BookMain.cpp
/*This is a testing ground for my 
  BookClass class.*/
#include "BookClass.h"
#include <iostream>
#include <string>	
#include <iomanip>				
using namespace std;
 
int main(){
	Book books;
	string t, a, i, p;
	double prc=0;
	int yr=0, num=0;
	cout << "Testing 1,2,3...\n";
	books.storeBook(t,a,i,p,prc,yr,num);
	books.displayBookInfo();
	cout << "book checked out...\n";
	books.checkOutBook();
	cout << "\t" << books.getTitle() << " # in stock: "
		<< books.getNumInStock() << endl;
	cout << "book returned...\n";
	books.returnBook();
	cout << "\t" << books.getTitle() << " # in stock: "
		<< books.getNumInStock() << endl;
	system("pause");
	return 0;
}