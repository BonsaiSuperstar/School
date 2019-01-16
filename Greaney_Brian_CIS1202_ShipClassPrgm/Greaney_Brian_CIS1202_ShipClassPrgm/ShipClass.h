#ifndef SHIPCLASS_H
#define SHIPCLASS_H
#include<string>
#include<iostream>
using namespace std;

class Ship{
	protected:
		string name;
		int year;
	public:
		Ship() {};
		Ship(string n, int y) 
			{ name = n; year = y;}
		void setName(string shipName)
			{ name = shipName; }
		void setYear(int shipYear)
			{ year = shipYear; }
		string getName() const
			{ return name; }
		int getYear() const
			{ return year; }
		virtual void setInfo()
			{ string n;
			  int y;
			  cout << "Please enter the ship name: ";
			  cin >> n;
			  cout << "Please enter the year the ship was built: ";
			  cin >> y;
			  setName(n);
			  setYear(y); }
		virtual void print()
			{ cout << "Ship name: " << getName() << endl;
			  cout << "Year built: " << getYear() << endl; }
};
#endif