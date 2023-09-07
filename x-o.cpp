// x-o.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void drawTheReactangle(char choices[]) {//Draw the rectangle
	int width{ 25 }, height{ 25 };
	int fistverticleLine{ width / 3 };
	int secondverticleLine{ fistverticleLine + (width / 3) };
	int drawPlacex1{ 0 }, drawPlacey1{ 0 }, drawPlacex2{ 0 }, drawPlacey2{ 0 }, drawPlacex3{ 0 }, drawPlacey3{ 0 }, drawPlacex4{ 0 }, drawPlacey4{ 0 }, drawPlacex5{ 0 }, drawPlacey5{ 0 }, drawPlacex6{ 0 }, drawPlacey6{ 0 }, drawPlacex7{ 0 }, drawPlacey7{ 0 }, drawPlacex8{ 0 }, drawPlacey8{ 0 }, drawPlacex9{ 0 }, drawPlacey9{ 0 };
	for (int c = 0; c <= 9; c++) {
		int pos = { c + 1 };
		if (c == 0 && choices[c] != ' ') {
			drawPlacex1 = (fistverticleLine / 2) * pos;
			drawPlacey1 = (fistverticleLine / 2) * pos;
		}
		else if (c == 1 && choices[c] != ' ') {
			drawPlacex2 = (width / 2);
			drawPlacey2 = (fistverticleLine / 2);
		}
		else if (c == 2 && choices[c] != ' ') {
			drawPlacex3 = secondverticleLine + (fistverticleLine / 2);
			drawPlacey3 = (fistverticleLine / 2);
		}
		else if (c == 3 && choices[c] != ' ') {
			drawPlacex4 = (fistverticleLine / 2);
			drawPlacey4 = (width / 2);
		}
		else if (c == 4 && choices[c] != ' ') {
			drawPlacex5 = (width / 2);
			drawPlacey5 = (width / 2);
		}
		if (c == 5 && choices[c] != ' ') {
			drawPlacex6 = secondverticleLine + (fistverticleLine / 2);
			drawPlacey6 = (width / 2);
		}
		if (c == 6 && choices[c] != ' ') {
			drawPlacex7 = (fistverticleLine / 2);
			drawPlacey7 = (width / 6) * 5;
		}
		if (c == 7 && choices[c] != ' ') {
			drawPlacex8 = (width / 2);
			drawPlacey8 = (width / 6) * 5;
		}
		if (c == 8 && choices[c] != ' ') {
			drawPlacex9 = secondverticleLine + (fistverticleLine / 2);
			drawPlacey9 = (width / 6) * 5;
		}

	}

	for (int i{ 0 }; i <= height; i++) {
		for (int j{ 0 }; j <= width; j++) {

			if (i == 0 || i == height || j == 0 || j == width || j == fistverticleLine || j == secondverticleLine || i == fistverticleLine || i == secondverticleLine) {
				std::cout << "*";
			}
			else {

				if (i == drawPlacey1 && j == drawPlacex1) {
					std::cout << choices[0];
				}
				else if (i == drawPlacey2 && j == drawPlacex2) {
					std::cout << choices[1];
				}
				else if (i == drawPlacey3 && j == drawPlacex3) {
					std::cout << choices[2];
				}
				else if (i == drawPlacey4 && j == drawPlacex4) {
					std::cout << choices[3];
				}
				else if (i == drawPlacey5 && j == drawPlacex5) {
					std::cout << choices[4];
				}
				else if (i == drawPlacey6 && j == drawPlacex6) {
					std::cout << choices[5];
				}
				else if (i == drawPlacey7 && j == drawPlacex7) {
					std::cout << choices[6];
				}
				else if (i == drawPlacey8 && j == drawPlacex8) {
					std::cout << choices[7];
				}
				else if (i == drawPlacey9 && j == drawPlacex9) {
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


bool isGameFinished(char choice) {
	return false;
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



	if (userChoice == 'x') {
		drawTheReactangle(choices);
		std::cout << "Enter the position you want to place your " << userChoice << " : ";
		cin >> userChoicePosition;
		choices[userChoicePosition - 1] = userChoice;
		drawTheReactangle(choices);
	}
	else {
		choices[0] = computerChoice;
		//Draw the rectangle
		drawTheReactangle(choices);
		while (!isGameFinished) {
			std::cout << "Enter the position you want to place your " << userChoice << " : ";
			std::cin >> userChoicePosition;
			if (choices[userChoicePosition - 1] == ' ') {
				choices[userChoicePosition - 1] = userChoice;
				drawTheReactangle(choices);
			}
			else {
				std::cout << "This position is reserved" << endl;
				drawTheReactangle(choices);
			}
		}
	}

}
