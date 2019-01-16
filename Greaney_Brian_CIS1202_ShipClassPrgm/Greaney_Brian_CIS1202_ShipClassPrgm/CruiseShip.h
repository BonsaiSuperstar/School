#ifndef CRUISESHIP_H
#define CRUISESHIP_H
#include"ShipClass.h"
class CruiseShip :public Ship {
	int maxPass;
	public:
		CruiseShip() {};
		CruiseShip(string csNm, int csYr, int csMp) 
			: Ship(csNm, csYr)
			{ maxPass = csMp; }
		void setMaxPass(int mp)
			{ maxPass = mp; }
		int getMaxPass() const
			{ return maxPass; }
		void setInfo()
			{ int mx;
			  Ship::setInfo();
			  cout << "Please enter the maximum number of passengers: ";
			  cin >> mx; 
			  setMaxPass(mx); }
		void print()
			{ Ship::print();
			  cout << "Maximum passengers: "
				   << getMaxPass() << endl; }
};
#endif
