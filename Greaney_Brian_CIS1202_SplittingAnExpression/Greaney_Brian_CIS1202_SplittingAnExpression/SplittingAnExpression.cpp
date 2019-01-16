//Brian Greaney
//April 18th, 2016
//Splitting an Expression
/*This program will take a string expression
and split it into a vector of strings */
#include<iostream>
#include<vector>	
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

vector<string> split(const string &exp);

int main() {
	string exp;

	cout << "Enter an expression: ";
	getline(cin, exp);
	vector<string> result = split(exp);
	cout << exp << " split into individual entities yields:\n";
	for (int i = 0; i < result.size();i++)
		cout << setw(i+1) << result[i] << endl;
	cout << "\nNow in reverse.....:\n";
	reverse(result.begin(), result.end());
	int c = result.size();
	for (int x = 0; x < result.size(); x++) {
		cout << setw(c) << result[x] << endl;
		c--;
	}
	cout << "\nEnd of program.\n";

	system("pause");
	return 0;
}

vector<string> split(const string &exp) {
	vector<string> vec; 
	string num;
	for (int i = 0; i < exp.length(); i++) {
		if (isdigit(exp[i]))
			num.append(1, exp[i]); 
		else {
			if (num.size() > 0) {
				vec.push_back(num); 
				num.erase();  
			}
			if (!isspace(exp[i])) {
				string s;
				s.append(1, exp[i]);
				vec.push_back(s); 
			}
		}
	}
	if (num.size() > 0)
		vec.push_back(num);

	return vec;
}