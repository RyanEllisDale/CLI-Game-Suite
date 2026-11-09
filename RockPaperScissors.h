// Includes :
#pragma once
#include "Game.h"

class RockPaperScissors final : public Game
{
protected:
	// Member Methods - Protected : 
	void GameLoop() override final;
	void SetupGame() override final;
	void CleanupGame() override final {};

public:
	// Construction :
	RockPaperScissors() {};
	~RockPaperScissors() {};

	// Member Methods - Public :
	void StartGame() override final;
};

