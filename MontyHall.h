
#pragma once

/** @file MontyHall.h
	@brief Header related to Origine.cpp

*/

/** @brief Simulates playing the game without ever changing door
	@param results is the memory location where the result is stored
	@return returns nothing, it directly writes in the memory location
*/

void noChangeDoor(int* results);

/** @brief Simulates playing the game by always changing door
	@param results is the memory location where the result is stored
	@return returns nothing, it directly writes in the memory location
*/
void changeDoor(int* results);

/** @brief Calculates the percentage of successful guesses. The total number of tests is supposed to be a costant.
	@return Returns the percentage
*/
int percentageOfSuccess(int n, int occurrences);

/** @brief Simple menu function, generates the user interface
	@return the return is used to clear the buffer if any unexpected characters get typed
*/
int menu();
