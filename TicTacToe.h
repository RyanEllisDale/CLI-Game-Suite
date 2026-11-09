// Includes :
#pragma once
#include "Game.h"
#include <vector>

enum TileState
{
	EMPTY = 0,
	CROSS = 1,
	DOT = 2
};

class TicTacToe final : public Game
{
private:
	// Member Data : 
	std::vector<GameResult> History;
	TileState Board[9];
	
	// Member Methods - Private :
	void PrintResults();
	void PrintBoard();

protected:
	// Member Methods - Protected : 
	void GameLoop() override final;
	void SetupGame() override final;
	void CleanupGame() override final {};
	void EscapeGame() override final;

public:
	// Construction :
	TicTacToe() {};
	~TicTacToe() {};
};