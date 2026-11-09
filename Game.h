// Includes 
#pragma once
#include <string>

enum GameResult
{
	WIN = 0,
	DRAW = 1,
	LOSS = 2
};

class Game
{
protected:
	// Member Data:
	bool Running = false;

	// Member Methods - Protected : 
	virtual void GameLoop() = 0;
	virtual void SetupGame() = 0;
	virtual void CleanupGame() = 0;

	const std::string FormatStringToLowerCase(std::string aString) const;

public:
	// Construction :
	Game() {};
	~Game() {};

	// Member Methods - Public : 
	virtual void StartGame() = 0;
};

