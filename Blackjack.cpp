// Includes :
#include "Blackjack.h"
#include <vector>
#include <string>
#include <iostream>
#include <random>

void Blackjack::SetupGame()
{
	Running = true;
	srand(time(NULL));
	std::cout << "Welcome To BlackJack\n" << std::endl;
}

void Blackjack::GameLoop()
{
	// Reset :
	BlackjackDeck.FillDeck();
	BlackjackDeck.ShuffleDeck();
	
	// Initial Scene :
	std::cout << "\nCards Are Being Dealt\n" << std::endl;
	PlayerCards = BlackjackDeck.DrawCards(2);
	DealerCards = BlackjackDeck.DrawCards(2);
	DealerCards[0].Shown = true;
	PrintPlayerHand();
	PrintDealerHand();

	// Player Action : 
	bool PlayerAction = true;
	std::string Input;

	while (PlayerAction == true)
	{
		std::cout << "\nWould you like to 'Hit' or 'Stand' ?" << std::endl;
		Input.clear();
		std::getline(std::cin, Input);

		// Input : 
		while (FormatStringToLowerCase(Input) != "hit" 
			&& FormatStringToLowerCase(Input) != "stand"
			&& FormatStringToLowerCase(Input) != "exit")
		{
			Input.clear();
			std::cout << "Please make sure you enter either 'Hit' or 'Stand' to play the game" << std::endl;
			std::cout << "or you can enter 'Exit' to escape the game" << std::endl;
			std::getline(std::cin, Input);
		}

		// Exit : 
		if (FormatStringToLowerCase(Input) == "exit")
		{
			EscapeGame();
			return;
		}


		// Stand : 
		if (FormatStringToLowerCase(Input) == "stand")
		{
			PlayerAction = false;
			break;
		}
		 
		 
		// Hit : 
		Card NewCard = BlackjackDeck.DrawCard();
		PlayerCards.push_back(NewCard);

		std::cout << "\nYou Drew : ";
		NewCard.PrintOneline();
		PrintPlayerHand();

		// Player Loss : 
		if (CalculateTotal(PlayerCards) > 21)
		{
			std::cout << "\nYou have busted and lost the gamble" << std::endl;
			std::cout << "Play Again ? " << " y or n" << std::endl;

			History.push_back(BlackJackResult::BUST);

			Input.clear();
			std::getline(std::cin, Input);

			while (FormatStringToLowerCase(Input) != "y" && FormatStringToLowerCase(Input) != "n")
			{
				Input.clear();
				std::cout << "Please make sure to enter either 'y' to try again or 'n' to stop." << std::endl;
				std::cout << "Continue ?" << " y or n" << std::endl;
				std::getline(std::cin, Input);
			}

			// Exit : 
			if (FormatStringToLowerCase(Input) == "n")
			{
				EscapeGame();
				return;
			}

			// Retry 
			return;
		}

		PrintDealerHand();
	}

	// Game Logic : 
	int PlayerValue = CalculateTotal(PlayerCards);
	int DealerValue = CalculateTotal(DealerCards);

	// Dealer Cards :
	std::cout << "\nThe Dealer's hidden card was : ";
	DealerCards[1].Shown = true;
	DealerCards[1].PrintOneline();
	std::cout << "Giving the Dealer a value of : " << DealerValue << std::endl;

	while (DealerValue < 17 || DealerValue < PlayerValue)
	{
		std::cout << "\nThe Dealer Must Draw An Additional Card" << std::endl;
		
		Card NewCard = BlackjackDeck.DrawCard();
		NewCard.Shown = true;
		DealerCards.push_back(NewCard);

		std::cout << "Dealer Drew : ";
		NewCard.PrintOneline();
		DealerValue = CalculateTotal(DealerCards);
		std::cout << "The dealers new Value is : " << DealerValue << std::endl;
	}
	
	// Win / Loss :
	if (DealerValue > 21)
	{
		std::cout << "The Dealer has bust and thus you have won the gamble !" << std::endl;
		History.push_back(BlackJackResult::DEALERBUST);
	}
	else if (DealerValue == 21 || DealerValue > PlayerValue)
	{
		std::cout << "The house always wins." << std::endl;
		History.push_back(BlackJackResult::LOSE);
	}
	else
	{
		std::cout << "You Outwitted the Dealer, Congratulations !" << std::endl;
		History.push_back(BlackJackResult::WON);
	}

	// End :
	std::cout << "\nContinue ?" << " y or n" << std::endl;
	Input.clear();
	std::getline(std::cin, Input);

	while (FormatStringToLowerCase(Input) != "y" && FormatStringToLowerCase(Input) != "n")
	{
		Input.clear();
		std::cout << "Please make sure to enter either y to continue or n to stop." << std::endl;
		std::cout << "Continue ?" << " y or n" << std::endl;
		std::getline(std::cin, Input);
	}

	// Exit : 
	if (FormatStringToLowerCase(Input) == "n")
	{
		PrintResults();
		EscapeGame();
		return;
	}

}

void Blackjack::EscapeGame()
{
	Running = false;
	std::cout << "Thank you for Playing Blackjack" << std::endl;
	std::cout << "Returning To Selection Screen" << std::endl;
}

void Blackjack::PrintPlayerHand(void) const
{
	std::cout << LINE_BREAK << std::endl;
	std::cout << "Player Cards : " << std::endl;
	for (const Card& CurrentCard : PlayerCards)
	{
		CurrentCard.PrintOneline();
	}
	std::cout << "Current Value : " << CalculateTotal(PlayerCards) << std::endl;
}

void Blackjack::PrintDealerHand(void) const
{
	std::cout << LINE_BREAK << std::endl;
	std::cout << "The Dealer is Showing :" << std::endl;
	for (const Card& CurrentCard : DealerCards)
	{
		if (CurrentCard.Shown == true)
		{
			CurrentCard.PrintOneline();
		}
	}
}

int Blackjack::CalculateTotal(std::vector<Card> aHand) const
{

	int Value = 0;
	std::vector<Card> CachedAces;

	for (const Card& CurrentCard : aHand)
	{
		// Aces :
		if (CurrentCard.Face == CardFace::ACE)
		{
			CachedAces.push_back(CurrentCard);
			continue;
		}

		// Else :
		Value = Value + CurrentCard.Value;
	}

	// Aces :
	for (const Card& CurrentAce : CachedAces)
	{
		if (Value + 11 < 22)
		{
			Value = Value + 11;
			continue;
		}

		Value = Value + 1;
	}

	return Value;
}

void Blackjack::PrintResults(void) const
{
	const std::string ResultStrings[4] = { "Won", "Lost", "Bust", "Dealer Bust"};

	std::cout << "\nHere are your collected results : \n" << LINE_BREAK << std::endl;
	for (int i = 0; i < History.size(); i = i + 1)
	{
		std::cout << "Match : " << i << "| " << ResultStrings[History[i]] << std::endl;
	}
	std::cout << LINE_BREAK << "\n" << std::endl;
}

