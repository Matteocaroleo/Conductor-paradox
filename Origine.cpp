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
		printf("Out of %i iterations, it guessed right %i times. (%i%% )\n\n", N, result, percentageOfSuccess(N, result));
	}
	return;
}









