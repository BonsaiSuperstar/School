//Brian Greaney
//July 24th, 2015
//Sinclair's Got Talent
//This program will calculate totatl scores from judges in a talent competition,
//	get a high, low and average score for each contestant, and finally determine a winner.

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

//Function prototypes
double getScore(double &, int &);
double calcAvgScore(double, double, double, double, double, double&);
double findLowest(double, double, double, double, double, double&);
double findHighest(double, double, double, double, double, double&);

int main()
{
	string contestant;
	ofstream inFile;
	ifstream readFile;
	char again;
	double score1, score2, score3, score4, score5,
		average, highest, lowest;

	cout << "*************************************************************\n"
		<< "*-----------------------------------------------------------*\n"
		<< "*                  Sinclair's Got Talent                    *\n"
		<< "*************************************************************\n";

	inFile.open("scores.txt");
	do
	{
		int i = 1;

		cout << "Enter the name of the contestant: ";
		cin >> contestant;
		getScore(score1, i);
		getScore(score2, i);
		getScore(score3, i);
		getScore(score4, i);
		getScore(score5, i);
		calcAvgScore(score1, score2, score3, score4, score5, average);
		findLowest(score1, score2, score3, score4, score5, lowest);
		findHighest(score1, score2, score3, score4, score5, highest);
		cout << "\t  Lowest score: " << lowest << endl;
		cout << "\t Highest score: " << highest << endl;

		inFile << contestant << ' ' << average << endl;

		cout << "More contestants? 'Y' or 'N': ";
		cin >> again;
	} while (again == 'y' || again == 'Y');
	inFile.close();

	readFile.open("scores.txt");

	string winnerTemp, winner;
	double total, test = 1;
	while (readFile >> winnerTemp >> total)
	{
		if (total > test)
		{
			test = total;
			winner = winnerTemp;
		}
	}

	cout << "\n";
	cout << "*************************************************************\n";
	cout << "\t\tAnd the winner is: " << winner << endl;
	cout << "*************************************************************\n";
	cout << "\n";

	readFile.close();

	system("pause");
	return 0;
}

//Functions

double getScore(double &score, int &i)
{
	cout << "Enter Judge #" << i << "'s score: ";
	cin >> score;
	if (score < 0 || score > 10)
	{
		cout << "Please enter a valid score (1-10). Try again: ";
		cin >> score;
	}
	return i++;
}

double calcAvgScore(double score1, double score2, double score3,
	double score4, double score5, double &average)
{
	double totalScore;
	totalScore = (score1 + score2 + score3 + score4 + score5);
	average = totalScore / 5;
	cout << "\t Average score: " << average << endl;
	return average;
}

double findLowest(double score1, double score2, double score3,
	double score4, double score5, double &lowest)
{
	lowest = score1;

	if (score2 < lowest)
		lowest = score2;
	if (score3 < lowest)
		lowest = score3;
	if (score4 < lowest)
		lowest = score4;
	if (score5 < lowest)
		lowest = score5;

	return lowest;
}

double findHighest(double score1, double score2, double score3,
	double score4, double score5, double &highest)
{
	highest = score1;

	if (score2 > highest)
		highest = score2;
	if (score3 > highest)
		highest = score3;
	if (score4 > highest)
		highest = score4;
	if (score5 > highest)
		highest = score5;

	return highest;
}