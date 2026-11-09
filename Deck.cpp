// Includes : 
#include "Deck.h"
#include <algorithm>
#include <random>

Deck::Deck(void)
{
	FillDeck();
	ShuffleDeck();
}

// https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
void Deck::ShuffleDeck(void)
{
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(Cards), std::end(Cards), rng);
}

void Deck::FillDeck(void)
{
	Cards.clear();

	for (int i = 0; i < 4; i = i + 1) // Suits
	{
		for (int j = 0; j < 8; j = j + 1) // Numbers
		{
			Cards.push_back(Card(CardFace::NUMBER, static_cast<CardSuit>(i), j + 2));
		}

		// Faces :
		Cards.push_back(Card(CardFace::ACE, static_cast<CardSuit>(i), 1));
		Cards.push_back(Card(CardFace::KING, static_cast<CardSuit>(i), 10));
		Cards.push_back(Card(CardFace::QUEEN, static_cast<CardSuit>(i), 10));
		Cards.push_back(Card(CardFace::JACK, static_cast<CardSuit>(i), 10));
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
