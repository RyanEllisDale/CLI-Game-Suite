// Includes : 
#include "TicTacToe.h"
#include <iostream>

void TicTacToe::PrintResults()
{
	std::string EnumTranslation[3] = {"Win", "Draw", "Loss"};

	for (int i = 0; i < History.size(); i = i + 1)
	{
		std::cout << "Match : " << i << " | " << EnumTranslation[History[i]];
	}
}

void TicTacToe::PrintBoard()
{






}

void TicTacToe::GameLoop()
{

}

void TicTacToe::SetupGame()
{
	Running = true;
	srand(NULL);
	std::cout << "Welcome To Tic Tac Toe" << std::endl;
}

void TicTacToe::EscapeGame()
{
	Running = false;
	std::cout << "Thank you for Tic Tac Toe" << std::endl;
	std::cout << "Returning To Selection Screen" << std::endl;
}
