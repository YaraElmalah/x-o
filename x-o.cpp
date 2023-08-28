// x-o.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void drawTheReactangle(char choice, int pos) {//Draw the rectangle
	int width{ 25 }, height{ 25 };
	int fistverticleLine{ width / 3 };
	int secondverticleLine{ fistverticleLine + (width / 3) };
	int drawPlacex{ 0 }, drawPlacey{ 0 };
	if (pos == 1) {
		drawPlacex = (fistverticleLine / 2) * pos;
		drawPlacey = (fistverticleLine / 2) * pos;
	}
	else if (pos == 2) {
		drawPlacex = (width / 2);
		drawPlacey = (fistverticleLine / 2);
	}
	else if (pos == 3) {
		drawPlacex = secondverticleLine + (fistverticleLine / 2);
		drawPlacey = (fistverticleLine / 2);
	}
	else if (pos == 4) {
		drawPlacex = (fistverticleLine / 2);
		drawPlacey = (width / 2);
	}
	else if (pos == 5) {
		drawPlacex = (width / 2);
		drawPlacey = (width / 2);
	}
	else if (pos == 6) {
		drawPlacex = secondverticleLine + (fistverticleLine / 2);
		drawPlacey = (width / 2);
	}
	else if (pos == 7) {
		drawPlacex = (fistverticleLine / 2);
		drawPlacey = (width / 6) * 5;
	}
	else if (pos == 8) {
		drawPlacex = (width / 2);
		drawPlacey = (width / 6) * 5;
	}
	else if (pos == 9) {
		drawPlacex = secondverticleLine + (fistverticleLine / 2);
		drawPlacey = (width / 6) * 5;
	}
	else {
		std::cout << "Invalid position" << endl;
		return;
	}



	for (int i{ 0 }; i <= height; i++) {
		for (int j{ 0 }; j <= width; j++) {

			if (i == 0 || i == height || j == 0 || j == width || j == fistverticleLine || j == secondverticleLine || i == fistverticleLine || i == secondverticleLine) {
				std::cout << "*";
			}
			else if (i == drawPlacey && j == drawPlacex) {
				std::cout << choice;
			}

			else {
				std::cout << " ";
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
	int choice1{ 0 }, choice2{ 0 }, choice3{ 0 }, choice4{ 0 }, choice5{ 0 }, choice6{ 0 }, choice7{ 0 }, choice8{ 0 }, choice9{ 0 };
	char board1{ ' ' }, board2{ ' ' }, board3{ ' ' }, board4{ ' ' }, board5{ ' ' }, board6{ ' ' }, board7{ ' ' }, board8{ ' ' }, board9{ ' ' };
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
	int userChoicePosition{ 0 }, computerChoicePosition{ 0 };


	if (userChoice == 'x') {
		drawTheReactangle(userChoice, choice1);
		std::cout << "Enter the position you want to place your " << userChoice << " : ";
		cin >> userChoicePosition;
		choice1 = userChoicePosition;
		board1 = userChoice;
		drawTheReactangle(userChoice, choice1);
	}
	else {
		//Draw the rectangle
		drawTheReactangle(computerChoice, 1);
		choice1 = computerChoicePosition;
		board1 = userChoice;
		while (!isGameFinished) {
			std::cout << "Enter the position you want to place your " << userChoice << " : ";
			cin >> userChoicePosition;
			drawTheReactangle(userChoice, userChoicePosition);
			choice2 = userChoicePosition;
			board2 = userChoice;
		}
	}

}
