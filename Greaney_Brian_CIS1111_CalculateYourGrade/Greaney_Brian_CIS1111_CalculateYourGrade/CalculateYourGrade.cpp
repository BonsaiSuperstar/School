//Brian Greaney
//July 3rd,2015
//Calculate Your Grade
//This program will use input and find the average for quiz and assignment grades, then calculate the overall average and letter grade. 

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int quizGradeNumber, assignmentGradeNumber = 1;
	int quizGrade, assignmentGrade;
	double qGradeTotal = 0.0;
	double quizGradeAverage = 0.0;
	double aGradeTotal = 0.0;
	double assignmentGradeAverage = 0.0;
	char again;

	cout << "This program will accumulate your quiz and assignment scores\nto determin your grade. \n";
	cout << "First let me get some input... \n";
	cout << "\tQuizzes are worth 10 points. \n";
	cout << "\n";

	while (again == 'Y' || again == 'y')
	{

		for (quizGradeNumber = 1; quizGradeNumber < 5; quizGradeNumber++)
		{
			cout << "\tEnter a grade for quiz # " << quizGradeNumber << ":  ";
			cin >> quizGrade;
			//Input validation!
			while (quizGrade < 0 || quizGrade >10)
			{
				cout << "Please use a number between 0 and 10.\t";
				cin >> quizGrade;
			}
			qGradeTotal += quizGrade;

		}
		cout << "\n";
		cout << "Quiz Grade Total = " << qGradeTotal << endl;
		quizGradeAverage = qGradeTotal / 4;
		cout << fixed << showpoint << setprecision(1);
		cout << "Quiz Grade Average = " << quizGradeAverage << endl;
		cout << "\n";

		cout << "\tAssignments are worth 20 points. \n";
		cout << "\n";

		while (assignmentGradeNumber < 9)
		{
			cout << "\tEnter a grade for assignment # " << assignmentGradeNumber << ":  ";
			cin >> assignmentGrade;
			//Input validation!
			while (assignmentGrade < 0 || assignmentGrade > 20)
			{
				cout << "Please use a number between 0 and 20.\t";
				cin >> assignmentGrade;
			}
			aGradeTotal += assignmentGrade;
			++assignmentGradeNumber;
		}
		cout << "\n";
		cout << "Assignment Grade Total = " << aGradeTotal << endl;
		assignmentGradeAverage = aGradeTotal / 8;
		cout << fixed << showpoint << setprecision(1);
		cout << "Assignment Grade Average = " << assignmentGradeAverage << endl;
		cout << "\n";

		float percentage = ((quizGradeAverage + assignmentGradeAverage) / 3) * 10;
		char letterGrade;

		cout << fixed << showpoint << setprecision(1);
		cout << "Overall percentage grade is = " << percentage << "% \n";

		if (percentage >= 90)
			letterGrade = 'A';
		else if (percentage >= 80)
			letterGrade = 'B';
		else if (percentage >= 70)
			letterGrade = 'C';
		else if (percentage >= 60)
			letterGrade = 'D';
		else
			letterGrade = 'F';

		cout << "The letter grade is = " << letterGrade << endl;
		cout << "\n";
		cout << "Would you like to run this program again? (Y/N) ";
		cin >> again;

	} 

	cout << "Thanks for using this program.\n'Live long, and prosper.'\n";
	cout << "\n";
		system("pause");
		return (0);
}