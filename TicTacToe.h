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
	bool PlayersTurn = true;
	
	// Member Methods - Private :
	void PrintResults();
	void PrintBoard();

	bool CheckWin(bool Player = true) const;
	bool CheckDraw() const;

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