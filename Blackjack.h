// Includes :
#pragma once
#include "Game.h"


class Blackjack : public Game
{
private:

protected:
	// Member Methods - Protected : 
	void GameLoop() override final;
	void SetupGame() override final;
	void CleanupGame() override final {};
	void EscapeGame() override final;

public:
	// Construction :
	Blackjack() {};
	~Blackjack() {};
};

