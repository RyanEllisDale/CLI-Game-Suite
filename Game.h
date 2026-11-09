// Includes 
#pragma once

class Game
{
protected:
	// Member Methods : 
	virtual void GameLoop() = 0;
	virtual void SetupGame() = 0;
	virtual void CleanupGame() = 0;

public:
	// Construction :
	Game() {};
	~Game() {};
};

