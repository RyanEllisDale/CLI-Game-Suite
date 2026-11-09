// Includes :
#pragma once
#include "Game.h"

class RockPaperScissors final : public Game
{
protected: 
	// Member Methods :
	void GameLoop() override final {};
	virtual void SetupGame() override final {};
	virtual void CleanupGame() override final {};

public:
	// Construction :
	RockPaperScissors() {};
	~RockPaperScissors() {};
};

