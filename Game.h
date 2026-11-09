// Includes 
#pragma once

class Game
{
protected:
	// Member Data:
	bool Running = false;

	// Member Methods - Protected : 
	virtual void GameLoop() = 0;
	virtual void SetupGame() = 0;
	virtual void CleanupGame() = 0;

public:
	// Construction :
	Game() {};
	~Game() {};

	// Member Methods - Public : 
	virtual void StartGame() = 0;
};

