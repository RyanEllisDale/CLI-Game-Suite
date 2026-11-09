// Includes : 
#include "Game.h"
#include <algorithm>
#include <cctype>

// https://stackoverflow.com/questions/313970/how-to-convert-an-instance-of-stdstring-to-lower-case
const std::string Game::FormatStringToLowerCase(std::string aString) const
{
    std::transform(aString.begin(), aString.end(), aString.begin(),
        [](unsigned char c) { return std::tolower(c); });

    return aString;
}

void Game::StartGame()
{
	SetupGame();

	while (Running == true)
	{
		GameLoop();
	}

	CleanupGame();
}
