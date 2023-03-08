/** @file Origine.cpp
	@brief Demonstrating the conductor paradox (or Monty Hall paradox)

*/

/** @mainpage Index Page
	@section intro_sec Introduction
	The programs aims at demostrating via simple cpu power the Monty Hall paradox.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "MontyHall.h"

/** @short This is the number of iteration that the program simulates
	
*/
#define N 1000000	//is how many times the test is done



void main()
{
	printf("This program demonstrates the conductor paradox in an empirical way.\n");
	int result;
	srand(time(NULL));
	while (true) {
		int result = 0;
		switch (menu())
		{
		case 1:
			for (int i = 0; i < N; i++)
			{
				noChangeDoor(&result);

			}
			break;
		case 2:
			for (int i = 0; i < N; i++)
			{
				changeDoor(&result);

			}
			break;
		case 3:
			return;
		default:
			printf("Out of range, look at the choices in the menu\n");
			return;
			break;

		}
		printf("Out of %i iterations, it guessed right %i times. (%i%% )\n\n", N, result, percentageOfSuccess(result));
	}
	return;
}

int menu()
{	
	int c = 0;
	printf("Enter 1 for playing without ever changing door : \
			\nEnter 2 for playing changing door:\
			\nEnter 3 to close the program: ");
	scanf_s("%i", &c);
	return c;
}

void noChangeDoor(int* results)
{


	int doors[3]= {0,0,0};
	doors[rand() % 3] = 1; //Set the car in a random door (1=car, 0=goat)
	int choice = rand() % 3; //Set the choice
	if (doors[choice] == 1)
	{
		(* results)++;
	}
	return;

}

void changeDoor(int* results)
{
	int doors[3] = { 0,0,0 };
	doors[rand() % 3] = 1; //Set the car in a random door (1=car, 0=goat)
	int firstChoice = rand() % 3; //Set the first choice
	int reveal = rand() % 3; //The conductor chooses which door to reveal 
	while (doors[reveal] == 1 || reveal == firstChoice)
	{
		reveal = rand() % 3;
	}//the conductor can't reveal the car or the first choice
	doors[reveal] = 2; //2 means that the door has been revealed
	int secondChoice = rand() % 3;
	while (doors[secondChoice] == 2 || secondChoice == firstChoice) { //cannot chose the revealed door or the first guess
		secondChoice = rand() % 3;
	}// the second choice can't be the revealed door
	if (doors[secondChoice] == 1) {	
		(*results)++;
	}
	return;
}

int percentageOfSuccess(int result)
{
	return (result * 100) / N;

}



