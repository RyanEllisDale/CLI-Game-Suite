// Includes : 
#include "TicTacToe.h"
#include <iostream>
#include <stdexcept>

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
	std::string Tile[3] = { " ", "X", "O" };


	std::cout << "-------------" << std::endl;
	std::cout << "| " << Tile[Board[0]] << " | " << Tile[Board[1]] << " | " << Tile[Board[2]] << " | " << std::endl;
	std::cout << "| " << Tile[Board[3]] << " | " << Tile[Board[4]] << " | " << Tile[Board[5]] << " | " << std::endl;
	std::cout << "| " << Tile[Board[6]] << " | " << Tile[Board[7]] << " | " << Tile[Board[8]] << " | " << std::endl;
	std::cout << "-------------" << std::endl;

}

bool TicTacToe::CheckWin(bool Player) const
{
	TileState Checking = DOT;
	if (Player == true)
	{
		Checking = CROSS;
	}
	
	// Horizontal and Vertical :
	for (int i = 0; i < 3; i = i + 1)
	{
		// Horizontal : 
		if (Board[(i * 3)] == Checking &&
			Board[(i * 3) + 1] == Checking &&
			Board[(i * 3)+ 2] == Checking)
		{
			return true;
		}

		// Vertical :
		if (Board[i] == Checking &&
			Board[i + 3] == Checking &&
			Board[i + 6] == Checking)
		{
			return true;
		}
	}

	// Diagnols : 
	if (Board[0] == Checking && Board[4] == Checking && Board[8] == Checking
		|| Board[2] == Checking && Board[4] == Checking && Board[6] == Checking)
	{
		return true;
	}

	return false;
}

bool TicTacToe::CheckDraw() const
{
	bool draw = true;
	for (int i = 0; i < 9; i = i + 1)
	{
		if (Board[i] == EMPTY)
		{
			draw = false;
		}
	}

	return draw;
}

void TicTacToe::GameLoop()
{
	// Input : 
	bool PlayerWin = false;
	bool draw = false;
	bool AIWin = false;
	std::string Input;

	while (PlayersTurn == true)
	{
		std::cout << "Please Chose a Tile (1-9)" << std::endl;
		std::getline(std::cin, Input);

		try
		{
			int Tile = std::stoi(Input);

			// Range Validation : 
			if (Tile < 1 || Tile > 9)
			{
				throw std::invalid_argument("Please Make sure you pick the range '0-9'\n");
				continue;
			}

			// Empty Validation 
			if (Board[Tile - 1] != EMPTY)
			{
				throw std::invalid_argument("Please Chose an empty tile\n");
			}

			// Valid Choice : 
			Board[Tile - 1] = CROSS;

			std::cout << "You've chosen spot : " << Tile << " Here is the board : " << std::endl;
			PrintBoard();
			PlayerWin = CheckWin(true);
			draw = CheckDraw();
		}
		catch (const std::invalid_argument& e) 
		{
			std::cout << "Invalid input!" << std::endl;
			continue;
		}
		catch (const std::out_of_range& e) 
		{
			std::cout << "Number out of range!" << std::endl;
			continue;
		}


		PlayersTurn = false;
	}

	// Player Win : 
	if (PlayerWin == true)
	{
		std::cout << "You've won !" << std::endl;
		History.push_back(GameResult::WIN);
	}
	else if (draw != true)
	{
		// AI : 
		int Count = 0;
		std::vector<int> indexs;

		for (int i = 0; i < 9; i = i + 1)
		{
			if (Board[i] == TileState::EMPTY)
			{
				indexs.push_back(i);
				Count = Count + 1;
			}
		}

		int AIChoice = indexs[rand() % Count];
		std::cout << "The AI has chosen spot : " << AIChoice << " here is the board : " << std::endl;
		Board[AIChoice] = DOT;
		AIWin = CheckWin(false);
		draw = CheckDraw();
		PrintBoard();

		if (AIWin == true)
		{
			std::cout << "The AI Won, How Terrible." << std::endl;
			History.push_back(GameResult::LOSS);
		}

		PlayersTurn = true;
	}

	// Draw : 
	if (draw == true)
	{
		std::cout << "A total Draw." << std::endl;
		History.push_back(GameResult::DRAW);
	}

	if (PlayerWin == true || AIWin == true || draw == true)
	{
		// Reset
		for (int i = 0; i < 9; i = i + 1)
		{
			Board[i] = TileState::EMPTY;
		}

		PlayersTurn = true;

		// Input : 
		Input.clear();
		std::cout << "\nContinue ?" << " y or n" << std::endl;
		std::getline(std::cin, Input);
		Input = FormatStringToLowerCase(Input);
		while (Input != "y" && Input != "n")
		{
			Input.clear();
			std::cout << "Please make sure to enter either y to continue or n to stop." << std::endl;
			std::cout << "Continue ?" << " y or n" << std::endl;
			std::getline(std::cin, Input);
			Input = FormatStringToLowerCase(Input);
		}

		// Exit : 
		if (Input == "n")
		{
			PrintResults();
			EscapeGame();
			return;
		}
	
	}



}




void TicTacToe::SetupGame()
{
	Running = true;
	srand(NULL);
	std::cout << "\nWelcome To Tic Tac Toe" << std::endl;
	std::cout << "When it's your turn please select which tile you'd like to fill (1-9 top left, to bottom right)" << std::endl;

	PrintBoard();
}

void TicTacToe::EscapeGame()
{
	Running = false;
	std::cout << "Thank you for Tic Tac Toe" << std::endl;
	std::cout << "Returning To Selection Screen" << std::endl;
}
