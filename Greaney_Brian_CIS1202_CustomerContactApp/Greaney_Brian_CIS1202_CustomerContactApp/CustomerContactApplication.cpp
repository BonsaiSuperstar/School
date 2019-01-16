//Brian Greaney
//February 22, 2016
//Customer Contact Application
/*This program uses an array of
nested structs to store the
addresses for your store’s customer */

#include<iostream>
#include<string>
using namespace std;

struct Address{
	string street,
		city,
		state;
	int zip;
};

struct Customer{
	string lastNm,
		firstNm;
	Address homeAddr;
	Address busAddr;
};

const int SIZE = 10;

int displayMenu();
Customer getCustomer();
void showCustomer(Customer[],int);
Address getAddress();
void findCust(Customer[],int);

int main(){
	Customer info[SIZE];
	int count = 0, choice;
	do{
		choice = displayMenu();
		if (choice == 1){
			info[count] = getCustomer();
			count++;
		}
		if (choice == 2){
			showCustomer(info, count);
		}
		if (choice == 3){
			findCust(info, count);
		}
	} while (choice != 4);
	system("pause");
	return 0;
}

int displayMenu(){
	int choice;
	cout << "Customer Contact Menu\n"
		<< "\n"
		<< "  1. Enter New Customer\n"
		<< "  2. Display all Customers\n"
		<< "  3. Display a particular customer\n"
		<< "  4. EXIT program\n"
		<< "Please enter your choice: ";
	cin >> choice;
	if (choice <= 0 || choice >= 5){
		cout << "Please enter a valid choice: ";
		cin >> choice;
		
	}
	cout << "\n";
	return choice;
}

Customer getCustomer(){
	Customer tempCust;
	cout << "Enter customer first name: ";
	cin >> tempCust.firstNm;
	cout << "Enter cusomer last name: ";
	cin >> tempCust.lastNm;
	cout << "Enter Business Address \n";
	tempCust.busAddr = getAddress();
	cout << "Enter Home Address \n";
	tempCust.homeAddr = getAddress();
	return tempCust;
}

Address getAddress(){
	Address tempAddr;
	cin.ignore();
	cout << "Enter street address: ";
	getline(cin, tempAddr.street);
	cout << "Enter city: ";
	getline(cin, tempAddr.city);
	cout << "Enter state: ";
	getline(cin, tempAddr.state);
	cout << "Enter zip code: ";
	cin >> tempAddr.zip;
	return tempAddr;
}

void showCustomer(Customer cust[], int C){
	for (int i = 0; i < C;i++){
		cout << "Customer name: " << cust[i].lastNm
			<< ", " << cust[i].firstNm << endl;
		cout << "Business address: \n" << "\t"
			<< cust[i].busAddr.street << " " 
			<< cust[i].busAddr.city << ", "
			<< cust[i].busAddr.state << " "
			<< cust[i].busAddr.zip << endl;
		cout << "Home address: \n" << "\t"
			<< cust[i].homeAddr.street << " "
			<< cust[i].homeAddr.city << ", "
			<< cust[i].homeAddr.state << " "
			<< cust[i].homeAddr.zip << endl << endl;
	}
}

void findCust(Customer cust[], int C){
	string fn, ln;
	cout << "Enter customer's first name: ";
	cin >> fn;
	cout << "Enter customer's last name: ";
	cin >> ln;
	for (int i = 0; i < C; i++){
		if (cust[i].firstNm == fn &&
			cust[i].lastNm == ln){
			cout << "Customer found!\n"
				<< "Customer name: " << cust[i].lastNm
				<< ", " << cust[i].firstNm << endl;
			cout << "Business address: \n" << "\t"
				<< cust[i].busAddr.street << " "
				<< cust[i].busAddr.city << ", "
				<< cust[i].busAddr.state << " "
				<< cust[i].busAddr.zip << endl;
			cout << "Home address: \n" << "\t"
				<< cust[i].homeAddr.street << " "
				<< cust[i].homeAddr.city << ", "
				<< cust[i].homeAddr.state << " "
				<< cust[i].homeAddr.zip << endl << endl;
		}
		if (cust[i].firstNm != fn &&
			cust[i].lastNm != ln)
			cout << "ERROR! Customer NOT found!\n";
	}
}