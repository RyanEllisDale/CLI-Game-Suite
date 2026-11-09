// Includes : 
#include "RockPaperScissors.h"
#include <iostream>
#include <string>
#include <map>


void RockPaperScissors::StartGame()
{
	SetupGame();

	while (Running == true)
	{
		GameLoop();
	}

	CleanupGame();
}

void RockPaperScissors::PrintResults()
{
	const std::string ResultStrings[3] = { "Win", "Draw", "Loss" };

	std::cout << "\nHere are your collected results : \n" << LINE_BREAK << std::endl;
	for (int i = 0; i < History.size(); i = i + 1)
	{
		std::cout << "Match : " << i
			<< " | Player : " << History[i].UserAction.Name
			<< " | Enemy : " << History[i].AIAction.Name
			<< " | Result : " << ResultStrings[History[i].Result]
			<< std::endl;
	}
	std::cout << LINE_BREAK << "\n" << std::endl;
}

// https://stackoverflow.com/questions/6277646/in-c-check-if-stdvectorstring-contains-a-certain-value
const GameResult RockPaperScissors::CalculateResult(const RockPaperScissorsAction& aAction1, const RockPaperScissorsAction& aAction2) const
{
	// Player Win
	if (std::find(aAction1.WinsAgainstActions.begin(), aAction1.WinsAgainstActions.end(), aAction2.Name) != aAction1.WinsAgainstActions.end())
	{
		std::cout << "You Win" << std::endl;
		return GameResult::WIN;
	}

	// Player Loss
	if (std::find(aAction1.LosesAgainstActions.begin(), aAction1.LosesAgainstActions.end(), aAction2.Name) != aAction1.LosesAgainstActions.end())
	{
		std::cout << "You Lost" << std::endl;
		return GameResult::LOSS;
	}

	// Draw / No Interaction
	std::cout << "You Drew" << std::endl;
	return GameResult::DRAW;
}


// https://stackoverflow.com/questions/4263640/find-mapped-value-of-map
void RockPaperScissors::GameLoop()
{
	std::map<std::string, RockPaperScissorsAction> ActionMap =
	{
		{"rock", RockAction()},
		{"scissors", ScissorsAction()},
		{"paper", PaperAction()},
		{"spock", SpockAction()},
		{"lizard", LizardAction()}
	};

	// Player Choice :
	std::cout << "\nPlease Choose 'Rock', 'Paper', 'Scissors', 'Spock', or 'Lizard' :" << std::endl;
	std::string Input;
	std::getline(std::cin, Input);

	while (ActionMap.find(FormatStringToLowerCase(Input)) == ActionMap.end())
	{
		Input.clear();
		std::cout << "Please make sure you enter either 'Rock', 'Paper', 'Scissors', 'Spock', or 'Lizard' to play the game" << std::endl;
		std::cout << "or you can enter 'exit' to escape the game" << std::endl;
		std::getline(std::cin, Input);
	}

	// Exit : 
	if (Input == "exit")
	{
		EscapeGame();
		return;
	}


	// Game Logic : 
	RockPaperScissorsAction PlayerAction = ActionMap[Input];
	auto RandomAction = ActionMap.begin();
	std::advance(RandomAction, std::rand() % 2);
	RockPaperScissorsAction AIAction = RandomAction->second;

	std::cout << "\nYou Chose : " << PlayerAction.Name << std::endl;
	std::cout << "They Chose : " << AIAction.Name << std::endl;

	GameResult Result = CalculateResult(PlayerAction, AIAction);
	History.push_back(RockPaperScissorsResult(PlayerAction, AIAction, Result));

	// Input : 
	Input.clear();
	std::cout << "\nContinue ?" << " y or n" << std::endl;
	std::getline(std::cin, Input);
	while (FormatStringToLowerCase(Input) != "y" && FormatStringToLowerCase(Input) != "n")
	{
		Input.clear();
		std::cout << "Please make sure to enter either y to continue or n to stop." << std::endl;
		std::cout << "Continue ?" << " y or n" << std::endl;
		std::getline(std::cin, Input);
	}

	// Exit : 
	if (Input == "n")
	{
		PrintResults();
		EscapeGame();
		return;
	}
}

void RockPaperScissors::SetupGame()
{
	Running = true;
	srand(NULL);
	std::cout << "Welcome To Rock Paper Scissors" << std::endl;
}

void RockPaperScissors::EscapeGame()
{
	Running = false;
	std::cout << "Thank you for Playing Rock, Paper, Scissors" << std::endl;
	std::cout << "Returning To Selection Screen" << std::endl;
}

