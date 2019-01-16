//Brian P Greaney
//June 6th, 2015
//Tips & Pennies
//This is a program to calculate total tips for a night's work. In addition, this will also break a stash of pennies into the least amount of coinage.

#include <iostream>
#include <string>
using namespace std;

int main()
{
    //Variables
    string name;
    double dollars, quarters, dimes, nickels, pennies;
    double totalTips;
   
    //Part 1
    cout << "Let's see how much we made in tips tonight... \n";
    //Input section
    cout << "Enter your name: ";
    getline (cin, name);
    cout << "Enter number of dollars: ";
    cin >> dollars;
    cout << "Enter number of quarters: ";
    cin >> quarters;
    cout << "Enter number of dimes: ";
    cin >> dimes;
    cout << "Enter Number of nickels: ";
    cin >> nickels;
    cout << "Enter number of pennies: ";
    cin >> pennies;
    totalTips = dollars + (quarters * .25) + (dimes * .10)+ (nickels * .05) + (pennies * .01);
    //Total for the night...
    cout << "Account Name: " << name << endl;
    cout << "The total deposit for this evening is = $" << totalTips << endl;
    
    //Part 2
    int bag, dRemainder, qRemainder, dmRemainder, nRemainder;
    
    cout << "\n";
    cout << "Big 'Ole Bag of Pennies... \n";
    cout << "How many pennies are in that big 'ole bag you got there? :";
    //Input
    cin >> bag;
    cout << "Let me think about that, ah yes. This should give you a lighter pocket.... \n";
    //Output
    cout << "dollar bills = " << bag / 100 << endl;
    dRemainder = bag % 100;
    cout << "quarters = " << dRemainder / 25 << endl;
    qRemainder = dRemainder % 25;
    cout << "dines = " << qRemainder / 10 << endl;
    dmRemainder = qRemainder % 10;
    cout << "nickels = " << dmRemainder / 5 << endl;
    nRemainder = dmRemainder % 5;
    cout << "pennies = " << nRemainder << endl;
    cout << "And now you know, and knowing is half the battle...." << endl;
    
    
    system("pause");
    return 0;
}

