/*	GuessTheNumber.cpp
	Program reads console input and processes the input for a corresponding output

	The game structure is as follows:
	1. The game reveals the range of the magic number to the player.
	2. The player guesses a number in the range
	3. If the player is right, the game concludes.
	   If the player is wrong, the game will ask the player to guess again.	

	Notes: 
	The ceiling for the magic number is randomly generated and has the range [10, 1000]
	The minimum value of the magic number is 1.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

// Globals
int var_MAXIMUM = 1000;
int var_MINIMUM = 10;
int DEBUG = 0;

int var_magicNumber;
int var_magicCeiling;

// Prototypes
void init();
void debug_get_generated_values();
int gameloop();

int main() {
	init();

	if (DEBUG) { debug_get_generated_values(); } // If DEBUG mode, then output the ceiling and magic number

	gameloop();

	return 0;
}

/*	debug_get_generated_values
	Outputs the generated ceiling and magic number
*/
void debug_get_generated_values() {
	std::cout << "Ceiling:\t" << var_magicCeiling << std::endl;
	std::cout << "Magic Num:\t" << var_magicNumber << std::endl;
}

/*	gameloop
	Ask the user for input and repeat until the game is over
*/
int gameloop() {
	// Reveal the bounds for the magic number
	std::cout << "The magic number is between " << 1 << " and " << var_magicCeiling << " inclusive.\n" << std::endl;
	
	int player_guess;
	while (1) {
		
		// Ask the user for input
		std::cout << "What is your guess? ~" << std::endl;
		std::cin >> player_guess;

		// Process the player's guess

		// Is the player guess within the specified range of valid entries?
		if ((player_guess > var_magicCeiling) || (player_guess < 1)) {
			std::cout << "Hey! That's not even a valid guess!" << std::endl;
		}
		// Is the number the answer?
		else if (player_guess == var_magicNumber) {
			std::cout << "You got it! Congrats :D" << std::endl;
			return 0;
		}
		else if (player_guess > var_magicNumber) {
			std::cout << "Nope~ Too large. Try again!" << std::endl;
		}
		else if (player_guess < var_magicNumber) {
			std::cout << "Nope~ Too small. Try again!" << std::endl;
		}
	}
}

/*	init
	Generates a ceiling for the current round and then generates the magic number
*/
void init() {
	// Seed the random generator
	srand(time(0));

	// Generate the ceiling
	// rand() % (var_MAXIMUM - var_MINIMUM) -> returns a number in range [0, 989]
	var_magicCeiling = (rand() % (var_MAXIMUM - var_MINIMUM)) + var_MINIMUM + 1;

	// Generate the magic number
	var_magicNumber = rand() % (var_magicCeiling + 1);
}


