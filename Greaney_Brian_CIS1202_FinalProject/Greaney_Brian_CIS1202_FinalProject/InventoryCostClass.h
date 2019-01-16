#ifndef INVENTORYCOSTCLASS_H
#define INVENTORYCOSTCLASS_H
#include"InventoryClass.h"

class InventoryCost :public Inventory {
private:
	double wCost, rCost;
	int month, day, year;
public:
	InventoryCost() {};
	InventoryCost(int id, string desc, int qty,
		double wc,double rc,int m,int d, int y) 
		: Inventory(id, desc, qty)
		{ wCost = wc; rCost = rc; month = m; day = d; year = y; }
	void setWCost(double wc) 
		{ wCost = wc; }
	void setRCost(double rc) 
		{ rCost = rc; }
	void setMonth(int m) 
		{ month = m; }
	void setDay(int d)
		{ day = d; }
	void setYear(int y)		
		{ year = y; }
	double getWCost() const
		{ return wCost; }
	double getRCost() const
		{ return rCost; }
	int getDay() const
		{ return day; }
	int getMonth() const
		{ return month; }
	int getYear() const
		{ return year; }
	void setInfo() 
		{ double wc, rc;
		int m, d, y;
		Inventory::setInfo();
		cin.ignore();
		cout << "Enter Wholesale Cost: $";
		cin >> wc;
		cout << "Enter Retail Cost: $";
		cin >> rc;
		cout << "Enter Inventory Update date in mm/dd/yyyy format\n"
			<< "Month: ";
		cin >> m;
		cout << "Day: ";
		cin >> d;
		cout << "Year: ";
		cin >> y;
		setWCost(wc);
		setRCost(rc);
		setMonth(m);
		setDay(d);
		setYear(y);	}
	void print()
		{ Inventory::print();
		cout << fixed << showpoint << setprecision(2);
		cout << setw(19) << "Wholesale Cost: $" << getWCost() << endl;
		cout << setw(19) << "Retail Cost: $" << getRCost() << endl;
		cout << setw(18) << "Date Modified: " << getMonth() << "/"
			<< getDay() << "/" << getYear() << endl << endl; }
};

#endif