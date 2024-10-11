#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main() {

	vector<string> questions;
	vector<string> solutions;
	string line;

	ifstream ifsQuestions("QuizQuestions.txt");
	while (getline(ifsQuestions, line)) {
		questions.push_back(line);
	}
	ifsQuestions.close();

	ifstream ifsSolutions("QuizSolutions.txt");
	while (getline(ifsSolutions, line)) {
		solutions.push_back(line);
	}
	ifsSolutions.close();


	const int generatedQuestions = 3;
	int score = 0;

	cout << "Welcome to the Math Quiz!\n\n";
	srand(time(NULL));
	ofstream ofsStudentAnswers("QuizResults.txt");
	for (int i = 0; i < generatedQuestions; i++) {
		string input;
		int randomNumber = rand() % 10 + 1;
		cout << "Question " << (i + 1) << ": " << questions[randomNumber] << " =\nEnter your answer: ";
		cin >> input;
		cout << "\n";

		ofsStudentAnswers << questions[randomNumber] << " = " << input << "\n";

		if (solutions[randomNumber] == input) {
			score++;
		}
	}
	cout << "Results saved to QuizResults.txt";
	ofsStudentAnswers << "\nEstimated Score: " << score;
	ofsStudentAnswers.close();

	(void)_getch();
	return 0;
}
