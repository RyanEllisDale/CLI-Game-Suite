// Include :
#pragma once
#include <vector>

enum CardSuit
{
	HEARTS = 0,
	CLUBS = 1,
	DIAMONDS = 2,
	SPADES = 3
};

enum CardFace
{
	NUMBER = 0,
	ACE = 1,
	KING = 2,
	QUEEN = 3,
	JACK = 4
};

struct Card
{
	// Member Data :
	CardFace Face = CardFace::NUMBER;
	CardSuit Suit = CardSuit::DIAMONDS;
	int value = 0;

	// Construction :
	Card(void) = default;
	Card(const CardFace& Face, const CardSuit& Suit, int value) : Face(Face), Suit(Suit), value(value) {}
};

class Deck
{
public:
	// Member Data :
	std::vector<Card> Cards;

	// Construction : 
	Deck(void);
	~Deck(void) = default;

	// Member Methods :
	void ShuffleDeck(void);
	void FillDeck(void);
	Card DrawCard(void);
	std::vector<Card> DrawCards(int AmountToDraw = 2);
};