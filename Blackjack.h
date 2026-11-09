// Includes :
#pragma once
#include "Game.h"
#include "Deck.h"

enum BlackJackResult
{
	WON = 0,
	LOSE = 1,
	BUST = 2,
	DEALERBUST = 3
};

class Blackjack final : public Game
{
private:
	// Member Data :
	Deck BlackjackDeck;
	std::vector<Card> PlayerCards;
	std::vector<Card> DealerCards;
	std::vector<BlackJackResult> History;

protected:
	// Member Methods - Protected : 
	void GameLoop(void) override final;
	void SetupGame(void) override final;
	void CleanupGame(void) override final {};
	void EscapeGame(void) override final;

	void PrintPlayerHand(void) const;
	void PrintDealerHand(void) const;
	int CalculateTotal(std::vector<Card> aHand) const;

	void PrintResults(void) const;

public:
	// Construction :
	Blackjack() {};
	~Blackjack() {};
};

