// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <random>
#include <iostream>
using namespace std;

int roomSize[100][100];
int spacing() { //Function that spaces out the updated room
	cout << endl;
	cout << endl;
	cout << "--Roomba Placement is Shown Below--";
	cout << endl;
	cout << endl;
	return 0;

}

int print(int x, int y) { //Function that prints out if the room is cleaned or dirty
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << roomSize[i][j] << "  ";
		}
		cout << endl;
	}
	return 0;
}

int main()
{
	int row;
	int col;
	cout << "Enter the Room Width: ";
	cin >> row;
	cout << "Enter the Room Length: ";
	cin >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			roomSize[i][j] = 0;
		}
	}
	int robotX;
	int robotY;
	cout << "Enter Roomba X Location" << "(0-" << row << "): ";
	cin >> robotX;
	cout << "Enter Roomba Y Location" << "(0-" << col << "): ";
	cin >> robotY;
	print(row, col); //shows how dirty or clean the room is
	if (robotX >= row || robotY >= col) {
		while (robotX >= row || robotY >= col) { 
			cout << "Invalid Placement. Try Again!";
			cout << "Enter Roomba X Location" << "(0-" << row-1 << "): ";
			cin >> robotX;
			cout << "Enter Roomba Y Location" << "(0-" << col-1 << "): ";
			cin >> robotY;
		}
	}
	roomSize[robotX][robotY] = 1;
	spacing();
	print(row, col);
	int moves;
	cout << "Enter the Number of Moves the Roomba is allowed to make: ";
	cin >> moves;
	char start;
	cout << "Start Cleaning, y or n: ";
	cin >> start;
	if (start == 'y') {
		int movement;
		
		while (moves > 0) {
			movement = rand() % 4 + 1;
			if (movement == 1) { //Robot Moves Up
				robotY -= 1;
				if (robotY < 0) {
					robotY += 1;
				}
				roomSize[robotX][robotY] = 1;
			}
			else if (movement == 2) { //Robot Moves Down
				robotY += 1;
				if (robotY > col) {
					robotY -= 1;
				}
				roomSize[robotX][robotY] = 1;
			}
			else if (movement == 3) { //Robot Moves Left
				robotX -= 1;
				if (robotX < 0) {
					robotX += 1;
				}
				roomSize[robotX][robotY] = 1;
			}
			else if (movement == 4) { //Robot Moves Right
				robotX += 1;
				if (robotX > row) {
					robotX -= 1;
				}
				roomSize[robotX][robotY] = 1;
			}

			moves -= 1;
		}
		spacing();
		print(row, col);
	}
	else {
		cout << "I guess you love dirty rooms.";
	}
	return 0;
}
