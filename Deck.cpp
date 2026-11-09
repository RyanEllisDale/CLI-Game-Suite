// Includes : 
#include "Deck.h"
#include <algorithm>
#include <random>
#include <iostream>

Deck::Deck(void)
{
	srand(NULL);
	FillDeck();
	ShuffleDeck();
}

// https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
void Deck::ShuffleDeck()
{
	static std::mt19937 rng{ std::random_device{}() };
	std::shuffle(std::begin(Cards), std::end(Cards), rng);
}

void Deck::FillDeck(void)
{
	Cards.clear();

	for (int i = 0; i < 4; i = i + 1) // Suits
	{
		for (int j = 0; j < 8; j = j + 1) // Numbers
		{
			Cards.push_back(Card(CardFace::NUMBER, static_cast<CardSuit>(i), j + 2, false));
		}

		// Faces :
		Cards.push_back(Card(CardFace::ACE, static_cast<CardSuit>(i), 1, false));
		Cards.push_back(Card(CardFace::KING, static_cast<CardSuit>(i), 10, false));
		Cards.push_back(Card(CardFace::QUEEN, static_cast<CardSuit>(i), 10, false));
		Cards.push_back(Card(CardFace::JACK, static_cast<CardSuit>(i), 10, false));
	}
}

Card Deck::DrawCard(void)
{
	if (Cards.size() > 0)
	{
		Card LastCard = Cards.back();
		Cards.pop_back();
		return LastCard;
	}

	return Card();
}

std::vector<Card> Deck::DrawCards(int AmountToDraw)
{
	if (Cards.size() > AmountToDraw)
	{
		std::vector<Card> DrawCards;
		for (int i = 0; i < AmountToDraw; i = i + 1)
		{
			Card LastCard = Cards.back();
			DrawCards.push_back(LastCard);
			Cards.pop_back();
		}

		return DrawCards;
	}
	
	return std::vector<Card>();
}

void Card::PrintOneline(void) const
{
	std::string SuitStringTranslation[4] = { "Hearts", "Clubs", "Diamonds", "Spades" };

	switch (Face)
	{
	case NUMBER:
		std::cout << Value << " of " << SuitStringTranslation[Suit] << std::endl;
		break;
	case ACE:
		std::cout << "Ace of " << SuitStringTranslation[Suit] << std::endl;
		break;
	case KING:
		std::cout << "King of " << SuitStringTranslation[Suit] << std::endl;
		break;
	case QUEEN:
		std::cout << "Queen of " << SuitStringTranslation[Suit] << std::endl;
		break;
	case JACK:
		std::cout << "Jack of " << SuitStringTranslation[Suit] << std::endl;
		break;
	default:
		std::cerr << "Unhandled Suit Case" << std::endl;
		break;
	}
}
