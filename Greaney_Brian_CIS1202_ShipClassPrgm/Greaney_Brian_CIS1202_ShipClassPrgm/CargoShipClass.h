#ifndef CARGOSHIPCLASS_H
#define CARGOSHIPCLASS_H
#include"ShipClass.h"
class CargoShipClass :public Ship {
	int maxCap;
public:
	CargoShipClass() {};
	CargoShipClass(string caNm, int caYr, int cpMc)
		: Ship(caNm, caYr)
		{ maxCap = cpMc; }
	void setMaxCap(int mc)
		{ maxCap = mc; }
	int getMaxCap() const
		{ return maxCap; }
	void setInfo()
		{ int mx;
		  Ship::setInfo();
		  cout << "Please enter the the cargo capacity in tonnage: ";
		  cin >> mx; 
		  setMaxCap(mx); }
	void print()
		{ Ship::print();
		  cout << "Maximum cargo capacity (tonnage): "
			   << getMaxCap() << endl; } 
};
#endif
