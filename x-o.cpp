// x-o.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void drawTheReactangle(char choices[]) {//Draw the rectangle
	int width{ 25 }, height{ 25 };
	int fistverticleLine{ width / 3 };
	int secondverticleLine{ fistverticleLine + (width / 3) };
	//t drawPlacex1{ 0 }, drawPlacey1{ 0 }, drawPlacex2{ 0 }, drawPlacey2{ 0 }, drawPlacex3{ 0 }, drawPlacey3{ 0 }, drawPlacex4{ 0 }, drawPlacey4{ 0 }, drawPlacex5{ 0 }, drawPlacey5{ 0 }, drawPlacex6{ 0 }, drawPlacey6{ 0 }, drawPlacex7{ 0 }, drawPlacey7{ 0 }, drawPlacex8{ 0 }, drawPlacey8{ 0 }, drawPlacex9{ 0 }, drawPlacey9{ 0 };
	int drawPlacex[9];
	int drawPlacey[9];
	for (int c = 0; c <= 9; c++) {
		int pos = { c + 1 };
		if (c == 0 && choices[c] != ' ') {
			drawPlacex[c] = (fistverticleLine / 2) * pos;
			drawPlacey[c] = (fistverticleLine / 2) * pos;
		}
		else if (c == 1 && choices[c] != ' ') {
			drawPlacex[c] = (width / 2);
			drawPlacey[c] = (fistverticleLine / 2);
		}
		else if (c == 2 && choices[c] != ' ') {
			drawPlacex[c] = secondverticleLine + (fistverticleLine / 2);
			drawPlacey[c] = (fistverticleLine / 2);
		}
		else if (c == 3 && choices[c] != ' ') {
			drawPlacex[c] = (fistverticleLine / 2);
			drawPlacey[c] = (width / 2);
		}
		else if (c == 4 && choices[c] != ' ') {
			drawPlacex[c] = (width / 2);
			drawPlacey[c] = (width / 2);
		}
		if (c == 5 && choices[c] != ' ') {
			drawPlacex[c] = secondverticleLine + (fistverticleLine / 2);
			drawPlacey[c] = (width / 2);
		}
		if (c == 6 && choices[c] != ' ') {
			drawPlacex[c] = (fistverticleLine / 2);
			drawPlacey[c] = (width / 6) * 5;
		}
		if (c == 7 && choices[c] != ' ') {
			drawPlacex[c] = (width / 2);
			drawPlacey[c] = (width / 6) * 5;
		}
		if (c == 8 && choices[c] != ' ') {
			drawPlacex[c] = secondverticleLine + (fistverticleLine / 2);
			drawPlacey[c] = (width / 6) * 5;
		}

	}

	for (int i{ 0 }; i <= height; i++) {
		for (int j{ 0 }; j <= width; j++) {

			if (i == 0 || i == height || j == 0 || j == width || j == fistverticleLine || j == secondverticleLine || i == fistverticleLine || i == secondverticleLine) {
				std::cout << "*";
			}
			else {

				if (i == drawPlacey[0] && j == drawPlacex[0]) {
					std::cout << choices[0];
				}
				else if (i == drawPlacey[1] && j == drawPlacex[1]) {
					std::cout << choices[1];
				}
				else if (i == drawPlacey[2] && j == drawPlacex[2]) {
					std::cout << choices[2];
				}
				else if (i == drawPlacey[3] && j == drawPlacex[3]) {
					std::cout << choices[3];
				}
				else if (i == drawPlacey[4] && j == drawPlacex[4]) {
					std::cout << choices[4];
				}
				else if (i == drawPlacey[5] && j == drawPlacex[5]) {
					std::cout << choices[5];
				}
				else if (i == drawPlacey[6] && j == drawPlacex[6]) {
					std::cout << choices[6];
				}
				else if (i == drawPlacey[7] && j == drawPlacex[7]) {
					std::cout << choices[7];
				}
				else if (i == drawPlacey[8] && j == drawPlacex[8]) {
					std::cout << choices[8];
				}
				else {
					std::cout << " ";
				}
			}
		}
		std::cout << endl;
	}
}


bool checkIfGameFinished(char choices[]) {

	if ((choices[0] == choices[1]) && (choices[1] == choices[2]) && choices[1] != ' ') {
		return true;
	}
	else if ((choices[0] == choices[3]) && (choices[3] == choices[6]) && choices[3] != ' ') {
		return true;
	}
	else if ((choices[0] == choices[4]) && (choices[4] == choices[8]) && choices[4] != ' ') {
		return true;
	}
	else if ((choices[1] == choices[4]) && (choices[4] == choices[7]) && choices[4] != ' ') {
		return true;
	}
	else if ((choices[2] == choices[4]) && (choices[4] == choices[6]) && choices[4] != ' ') {
		return true;
	}
	else if ((choices[3] == choices[4]) && (choices[4] == choices[5]) && choices[4] != ' ') {
		return true;
	}
	else if ((choices[6] == choices[7]) && (choices[7] == choices[8]) && choices[7] != ' ') {
		return true;
	}
	else {
		return false;
	}
}
/*
* If it returns 10 means that there is no empty choice, we should end the same at this case.
*/
int findTheClosestEmptyPosition(char choices[]) {
	for (int i = 0; i <= 9; i++) {
		if (choices[i] == ' ') {
			return i;
		}
	}
	return 10;
}
int checkTheBestPosition(char choices[]) {
	if ((choices[0] == choices[1]) && (choices[1] == choices[2]) && choices[1] == ' ') {
		return 1;
	}
	else if ((choices[0] == choices[1]) && (choices[1] == choices[2]) && choices[0] == ' ') {
		return 0;
	}
	else if ((choices[0] == choices[1]) && (choices[1] == choices[2]) && choices[2] == ' ') {
		return 2;
	}
	else if ((choices[0] == choices[3]) && (choices[3] == choices[6]) && choices[3] == ' ') {
		return 3;
	}
	else if ((choices[0] == choices[3]) && (choices[3] == choices[6]) && choices[6] == ' ') {
		return 6;
	}
	else if ((choices[0] == choices[3]) && (choices[3] == choices[6]) && choices[0] == ' ') {
		return 0;
	}
	else if ((choices[0] == choices[4]) && (choices[4] == choices[8]) && choices[8] == ' ') {
		return 8;
	}
	else if ((choices[0] == choices[4]) && (choices[4] == choices[8]) && choices[4] == ' ') {
		return 4;
	}
	else if ((choices[1] == choices[4]) && (choices[4] == choices[7]) && choices[4] == ' ') {
		return 4;
	}
	else if ((choices[1] == choices[4]) && (choices[4] == choices[7]) && choices[7] == ' ') {
		return 7;
	}
	else if ((choices[1] == choices[4]) && (choices[4] == choices[7]) && choices[1] == ' ') {
		return 1;
	}
	else if ((choices[2] == choices[4]) && (choices[4] == choices[6]) && choices[4] == ' ') {
		return 4;
	}
	else if ((choices[2] == choices[4]) && (choices[4] == choices[6]) && choices[6] == ' ') {
		return 6;
	}
	else if ((choices[2] == choices[4]) && (choices[4] == choices[6]) && choices[2] == ' ') {
		return 2;
	}
	else if ((choices[3] == choices[4]) && (choices[4] == choices[5]) && choices[4] == ' ') {
		return 4;
	}
	else if ((choices[3] == choices[4]) && (choices[4] == choices[5]) && choices[5] == ' ') {
		return 5;
	}
	else if ((choices[3] == choices[4]) && (choices[4] == choices[5]) && choices[3] == ' ') {
		return 3;
	}
	else if ((choices[6] == choices[7]) && (choices[7] == choices[8]) && choices[7] == ' ') {
		return 7;
	}
	else if ((choices[6] == choices[7]) && (choices[7] == choices[8]) && choices[8] == ' ') {
		return 8;
	}
	else if ((choices[6] == choices[7]) && (choices[7] == choices[8]) && choices[6] == ' ') {
		return 6;
	}
	else {
		int pos = findTheClosestEmptyPosition(choices);
		return pos + 1;
	}
}
void runTheGame(char userChoice, char choices[], char compChoice) {
	bool isGameFinished{ false };
	int userChoicePosition{ 0 };
	int compChoicePosition{ 0 };
	bool isUserTurn{ true };
	while (!isGameFinished) {
		if (isUserTurn) {
			std::cout << "Enter the position you want to place your " << userChoice << " : ";
			std::cin >> userChoicePosition;
			if (choices[userChoicePosition - 1] == ' ') {
				choices[userChoicePosition - 1] = userChoice;
				drawTheReactangle(choices);
				isUserTurn = false;
			}
			else {
				std::cout << "This position is reserved, Please enter another position" << endl;
				drawTheReactangle(choices);
				isUserTurn = true;
			}


		}
		else {
			//Computer Turn
			compChoicePosition = checkTheBestPosition(choices);
			if (compChoicePosition == 10) {
				isGameFinished = true;
			}
			else {
				choices[compChoicePosition - 1] = compChoice;
				drawTheReactangle(choices);
				isGameFinished = checkIfGameFinished(choices);
			}
			isUserTurn = true;
		}
		isGameFinished = checkIfGameFinished(choices);

	}
	drawTheReactangle(choices);

	std::cout << "Game Over, Thank You" << endl;

}

int main()
{
	char userChoice{ 'o' }, computerChoice{ 'x' };
	char choices[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	int userChoicePosition{ 0 }, computerChoicePosition{ 0 };

	bool isGameFinished{ false };
	std::cout << "You want to play with X or O: ";
	cin >> userChoice;
	if (userChoice == 'x') {
		computerChoice = 'o';
	}
	else if (userChoice == 'o') {
		computerChoice = 'x';
	}
	else {
		std::cout << "Invalid choice" << endl;
		return 0;
	}
	std::cout << "You are playing with " << userChoice << endl;
	std::cout << "Computer is playing with " << computerChoice << endl;
	std::cout << "Let's start the game" << endl;


	if (userChoice == 'o') {
		choices[0] = computerChoice;

	}
	drawTheReactangle(choices);
	runTheGame(userChoice, choices, computerChoice);

}
