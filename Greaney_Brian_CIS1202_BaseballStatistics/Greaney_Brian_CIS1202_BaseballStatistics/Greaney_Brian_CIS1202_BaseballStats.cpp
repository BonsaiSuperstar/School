//Brian Greaney
//January 17, 2016
//Baseball Statistics 
/*This program will look at a set of stats from
a file and will then use those stats to determine
the team's strengths and weaknesses. */

#include<iostream>
#include<fstream>
using namespace std;

int loadArrays(int[], int[], int[], int[], int[]);
void calcBatAvg(int[], int[], int[], int);
void printStats(int[], int[], int[], int[], int[], int[], int);

int main()
{
	const int SIZE = 20;
	int playerNum[SIZE], runs[SIZE], rbis[SIZE],
		hits[SIZE], atBats[SIZE], batAvg[SIZE],
		numberOfPlayers;

	numberOfPlayers = loadArrays(playerNum, atBats, hits, runs, rbis);

	calcBatAvg(batAvg, hits, atBats, numberOfPlayers);
	
	printStats(playerNum, atBats, hits, runs, rbis, batAvg, numberOfPlayers);

	system("pause");
	return (0);
}

int loadArrays(int playerNum[], int atBats[], int hits[], int runs[], int rbis[])
{
	int i = 0;
	ifstream inFile;
	inFile.open("BaseballStats.txt");
	if (inFile.fail())
		cout << "There was an error opening the file.\n";
	while (inFile >> playerNum[i])
	{
		inFile >> atBats[i];
		inFile >> hits[i];
		inFile >> runs[i];
		inFile >> rbis[i];

		i++;
	}

	inFile.close();
	return i;
}

void calcBatAvg(int batAvg[], int hits[], int atBats[], int numberOfPlayers)
{
	for (int i = 0; i < numberOfPlayers; i++)
	{
		batAvg[i] = (1000 * hits[i]) / atBats[i];
	}
}

void printStats(int player[], int bat[], int hit[], int run[], int rbi[], int bavg[], int count)
{
	int teamAvg = 0;
	int mn = bavg[0];
	int mx = bavg[0];
	int pnMn = player[0];
	int pnMx = player[0];

	cout << "\n" 
		 << "Baseball Stats\n"
		 << "\n";
	cout << "\t   Player Num  At Bat  Hits    Runs    RBIs   Bat Avg    Comment\n";

	for (int i = 0; i < count; i++)
	{
		cout << "\t\t" << player[i] << "\t" << bat[i]
			<< "\t" << hit[i] << "\t" << run[i]
			<< "\t" << rbi[i] << "\t" << bavg[i];
		if (bavg[i] > 499)
			cout << "    World Series\n";
		else if (bavg[i] > 299)
			cout << "    Farm League\n";
		else
			cout << "    Little League\n";
		teamAvg += bavg[i];
	}
	cout << "The team batting average is " << (teamAvg / count) << endl;
	for (int i = 0; i<10; i++)
	{
		if (mn>bavg[i])
		{
			mn = bavg[i];
			pnMn = player[i];
		}
		else if (mx<bavg[i])
		{
			mx = bavg[i];
			pnMx = player[i];
		}
	}

	cout << "The best player is number: " << pnMx << " with a hitting average of: " << mx << endl;
	cout << "The worst player is number: "<< pnMn <<" with a hitting average of: " << mn << endl;
	cout << "\n";
	
}