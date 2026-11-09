// Includes :
#include <iostream>
#include "RockPaperScissors.h"
#include "Blackjack.h"
#include "TicTacToe.h"
#include <algorithm>
#include <cctype>

int main()
{
	bool MainLoop = true;
	while (MainLoop == true)
	{
		// Welcome
		std::cout << "Welcome to the C++ CLI Suite, Please pick your game : " << std::endl;
		std::cout << "'bj' - Blackjack\n'ttt' - Tic Tac Toe\n'rps' - Rock Paper Scissors" << std::endl;

		// Input : 
		std::string Input;
		std::getline(std::cin, Input);

		std::transform(Input.begin(), Input.end(), Input.begin(),
			[](unsigned char c) { return std::tolower(c); });

		// Validation : 
		while (Input != "exit" && Input != "bj" && Input != "ttt" && Input != "rps")
		{
			std::cout << "Please chose either 'bj', 'ttt', or 'rps'\nYou can also chose 'exit' to end the suite." << std::endl;

			Input.clear();
			std::getline(std::cin, Input);

			std::transform(Input.begin(), Input.end(), Input.begin(),
				[](unsigned char c) { return std::tolower(c); });
		}


		// Exit : 
		if (Input == "exit")
		{
			MainLoop = false;
			break;
		}

		// Play : 

		// Blackjack : 
		if (Input == "bj")
		{
			Blackjack BlackJackInstance;
			BlackJackInstance.StartGame();
			continue;
		}

		// Tic Tac Toe :
		if (Input == "ttt")
		{
			TicTacToe TicTacToeInstance;
			TicTacToeInstance.StartGame();
			continue;
		}

		// Rock Paper Scissors + :
		if (Input == "rps")
		{
			RockPaperScissors RockPaperScissorsInstance;
			RockPaperScissorsInstance.StartGame();
			continue;
		}
		
	}


	std::cout << "Thank you for playing in the CLI Game Suite." << std::endl;
	return 0;
}