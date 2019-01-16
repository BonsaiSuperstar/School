//Brian Greaney
//July 11th, 2015
//Averaging Quizz Grades
/*This program will uses files and nested loops to create a file from the quiz grades
	entered by the user, then read the grades from the file and calculates 
	the average quiz grade for a class. */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


int main()
{
	int student, studentNum, quizGradeNum, quizGrade;
	student = 1;
	ofstream inFile;
	inFile.open("Grades.txt");
	while (student != 0)
	{
		double quizTotal = 0;
		cout << "Enter student ID number:  \n";
		cin >> studentNum;
		inFile << studentNum;
		for (quizGradeNum = 1; quizGradeNum < 5; quizGradeNum++)
		{
			cout << "Enter a grade for quiz # " << quizGradeNum << ":  ";
			cin >> quizGrade;
			while (quizGrade < 0 || quizGrade >100)
			{
				cout << "Please use a number between 0 and 100.\t";
				cin >> quizGrade;
			}
			inFile << ' ' << quizGrade;
			quizTotal += quizGrade;
		}
		cout << "\n";
		inFile << endl;
		cout << "Enter 0 for no more students to enter. Enter 1 for more students.\n";
		cin >> student;
		cout << "\n";
	}
	inFile.close();

	ifstream readFile;
	readFile.open("Grades.txt");
	float /*fLoop,*/ grade1, grade2, grade3, grade4;
	double classAverage, classTotal = 0, count = 0;
	while (readFile >> studentNum >> grade1 >> grade2 >> grade3 >> grade4)
	{
		count++;
		double qAverage = (grade1 + grade2 + grade3 + grade4) / 4;
		cout << "Student ID# " << studentNum << "'s average is = " << qAverage << endl;
		//for (fLoop = 0; fLoop < count; fLoop++)
		//{
		classTotal += qAverage;
		//cout << "runTotal " << classTotal << endl;
		//}

	}
	//cout << "The class total = " << classTotal << endl;
	//cout << "Total Students = " << count << endl;
	classAverage = classTotal / count;
	cout << "\n" << "\n";
	cout << fixed << showpoint << setprecision(2);
	cout << "The class average = " << classAverage << endl;
	cout << "\n";
	system("pause");
	return 0;
}
/*So, in the instructions it said to use a 'for' loop in the 2nd half of this program.
I tried my damnedest to get that to work out to zero avail. I 'commented' the lines out
and would like to discuss them with you in class. As it is, this runs flawlessly.
Thanks 
Brian */