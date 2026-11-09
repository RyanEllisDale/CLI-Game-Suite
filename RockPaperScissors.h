// Includes :
#pragma once
#include "Game.h"
#include <vector>

// Actions Template :
struct RockPaperScissorsAction
{
	// Member Data :
	std::string Name;
	std::vector<std::string> WinsAgainstActions;
	std::vector<std::string> LosesAgainstActions;

	// Construction : 
	RockPaperScissorsAction() = default;
	~RockPaperScissorsAction() = default;

	RockPaperScissorsAction(const std::string& Name, 
		const std::vector<std::string>& WinsAgainstActions, 
		const std::vector<std::string>& LosesAgainstActions)
		: Name(Name), WinsAgainstActions(WinsAgainstActions), LosesAgainstActions(LosesAgainstActions) {}
};

// Actions : 
struct RockAction : RockPaperScissorsAction { RockAction() : RockPaperScissorsAction("Rock", { "Scissors", "Lizard" }, { "Paper", "Spock" }) {} };
struct ScissorsAction : RockPaperScissorsAction { ScissorsAction() : RockPaperScissorsAction("Scissors", { "Paper", "Lizard" }, { "Rock", "Spock" }) {} };
struct PaperAction : RockPaperScissorsAction { PaperAction() : RockPaperScissorsAction("Paper", { "Rock", "Spok" }, { "Scissors", "Lizard" }) {} };
struct SpockAction : RockPaperScissorsAction { SpockAction() : RockPaperScissorsAction("Spok", { "Rock", "Scissors" }, { "Paper","Lizard" }) {} };
struct LizardAction : RockPaperScissorsAction { LizardAction() : RockPaperScissorsAction("Lizard", { "Spock", "Paper" }, { "Rock", "Scissors" }) {}  };

struct RockPaperScissorsResult
{
	// Member Data : 
	const RockPaperScissorsAction UserAction;
	const RockPaperScissorsAction AIAction;
	const GameResult Result = GameResult::DRAW;

	// Construction :
	RockPaperScissorsResult() = default;
	RockPaperScissorsResult(const RockPaperScissorsAction& aUserAction, const RockPaperScissorsAction& aAIAction,
		const GameResult aResult) : UserAction(aUserAction), AIAction(aAIAction), Result(aResult) {}
};

class RockPaperScissors final : public Game
{
private:
	// Member Data:
	std::vector<RockPaperScissorsResult> History;

	// Member Methods - Private :
	void PrintResults();
	const GameResult CalculateResult(const RockPaperScissorsAction& aAction1, const RockPaperScissorsAction& aAction2) const;

protected:
	// Member Methods - Protected : 
	void GameLoop() override final;
	void SetupGame() override final;
	void CleanupGame() override final {};
	void EscapeGame() override final;

public:
	// Construction :
	RockPaperScissors() {};
	~RockPaperScissors() {};
};

