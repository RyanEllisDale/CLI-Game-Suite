// Includes :
#pragma once
#include "Game.h"

class RockPaperScissors final : public Game
{
protected: 
	// Member Methods :
	void StartGame() override final {};
	void GameLoop() override final {};
	void SetupGame() override final {};
	void CleanupGame() override final {};

public:
	// Construction :
	RockPaperScissors() {};
	~RockPaperScissors() {};
};

