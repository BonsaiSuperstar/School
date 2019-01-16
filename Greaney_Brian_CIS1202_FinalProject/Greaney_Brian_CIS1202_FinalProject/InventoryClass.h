#ifndef INVENTORYCLASS_H
#define INVENTORYCLASS_H
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Inventory {
protected:
	int itemID, itemQty;
	string itemDesc;
public:
	Inventory() {};
	Inventory(int id,string desc,int qty)
		{ itemID = id; itemDesc = desc; itemQty = qty; }
	void setID(int id)
		{ itemID = id; }
	void setDesc(string desc)
		{ itemDesc = desc; }
	void setQty(int qty) 
		{ itemQty = qty; }
	int getID() const 
		{ return itemID; }
	string getDesc() const 
		{ return itemDesc; }
	int getQty() const 
		{ return itemQty; }
	virtual void setInfo() 
		{ int id, qty;
		string desc;
		cout << "Enter ItemID: ";
		cin >> id;
		cout << "Enter ItemDescription: ";
		cin.ignore();
		getline(cin, desc);
		cout << "Enter ItemQuantity: ";
		cin >> qty;
		setID(id);
		setDesc(desc);
		setQty(qty); }
	virtual void print() 
		{ cout << setw(18) << "Item ID: " << getID() << endl;
		cout << setw(18) << "Item Description: " << getDesc() << endl;
		cout << setw(18) << "Item Quantity: " << getQty() << endl; }
};

#endif
