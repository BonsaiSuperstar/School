//Brian Greaney
//April 11, 2016
//Ship Class Program
/*This program demonstrates base and 
derived classes*/
#include"ShipClass.h"
#include"CruiseShip.h"
#include"CargoShipClass.h"	
#include<iostream>
using namespace std;

int main() {
	cout << "Ship\n\n";
	Ship boat;
	boat.setInfo();
	cout << "\nShip info\n\n";
	boat.print();
	cout << "\nCruise Ship\n\n";
	CruiseShip cs;
	cs.setInfo();
	cout << "\nCruise Ship info\n\n";
	cs.print();
	cout << "\nCargo Ship\n\n";
	CargoShipClass cg;
	cg.setInfo();
	cout << "\nCargo Ship info\n\n";
	cg.print();
	system("pause");
	return 0;
}