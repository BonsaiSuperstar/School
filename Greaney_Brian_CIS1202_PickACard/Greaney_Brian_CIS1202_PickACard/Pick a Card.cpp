//Brian Greaney
//March 9, 2016
//Pick a Card
/*This program uses an array of structs to
  represent a card deck, where the card values
  and suits are represented by enums. This will
  create and print a 52 card deck, then draw 2
  cards at random, and finally compare the 2.*/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

enum suits { CLUBS, DIAMONDS, HEARTS, SPADES };
enum cardValues { TWO, THREE, FOUR, FIVE, SIX, 
				SEVEN, EIGHT, NINE, TEN, JACK, 
				QUEEN, KING, ACE };

struct cards{suits suit;
			cardValues card;};

cards deck[52];
cards card1, card2;

void createDeck(cards[]);
void printDeck(cards[]);
void printCard(cards);
void deal(cards[], cards&);
void winner(cards, cards);

int main() {
	cards tempDeck;
	createDeck(deck);
	printDeck(deck);
	unsigned seed = time(0);
	srand(seed);
	deal(deck, tempDeck);
	card1 = tempDeck;
	cout << "Card #1: ";
	printCard(card1);
	deal(deck, tempDeck);
	card2 = tempDeck;
	cout << "Card #2: ";
	printCard(card2);
	winner(card1, card2);
	system("pause");
	return 0;
}

void createDeck(cards deck[52]) {
	int i = 0;
	for (suits suit = CLUBS; suit <= SPADES;
		suit = suits(suit + 1)) {
		for (cardValues card = TWO; card <= ACE;
			card = cardValues(card + 1)) {
			deck[i].suit = suit;
			deck[i].card = card;
			i++;
		}
	}
}

void printDeck(cards deck[52]) {
	cout << "The Card Deck\n\n";
	for (int i = 0; i < 52; i++) {
		if (deck[i].card == TWO)
			cout << setw(6) << "Two ";
		else if (deck[i].card == THREE)
			cout << setw(6) << "Three ";
		else if (deck[i].card == FOUR)
			cout << setw(6) << "Four ";
		else if (deck[i].card == FIVE)
			cout << setw(6) << "Five ";
		else if (deck[i].card == SIX)
			cout << setw(6) << "Six ";
		else if (deck[i].card == SEVEN)
			cout << setw(6) << "Seven ";
		else if (deck[i].card == EIGHT)
			cout << setw(6) << "Eight ";
		else if (deck[i].card == NINE)
			cout << setw(6) << "Nine ";
		else if (deck[i].card == TEN)
			cout << setw(6) << "Ten ";
		else if (deck[i].card == JACK)
			cout << setw(6) << "Jack ";
		else if (deck[i].card == QUEEN)
			cout << setw(6) << "Queen ";
		else if (deck[i].card == KING)
			cout << setw(6) << "King ";
		else if (deck[i].card == ACE)
			cout << setw(6) << "Ace ";
		cout << "of ";
		if (deck[i].suit == CLUBS)
			cout << "Clubs\n";
		else if (deck[i].suit == DIAMONDS)
			cout << "Diamonds\n";
		else if (deck[i].suit == HEARTS)
			cout << "Hearts\n";
		else if (deck[i].suit == SPADES)
			cout << "Spades\n";
	}
	cout << "\n";
}

void printCard(cards dex) {
	if (dex.card == TWO)
		cout << setw(6) << "Two ";
	else if (dex.card == THREE)
		cout << setw(6) << "Three ";
	else if (dex.card == FOUR)
		cout << setw(6) << "Four ";
	else if (dex.card == FIVE)
		cout << setw(6) << "Five ";
	else if (dex.card == SIX)
		cout << setw(6) << "Six ";
	else if (dex.card == SEVEN)
		cout << setw(6) << "Seven ";
	else if (dex.card == EIGHT)
		cout << setw(6) << "Eight ";
	else if (dex.card == NINE)
		cout << setw(6) << "Nine ";
	else if (dex.card == TEN)
		cout << setw(6) << "Ten ";
	else if (dex.card == JACK)
		cout << setw(6) << "Jack ";
	else if (dex.card == QUEEN)
		cout << setw(6) << "Queen ";
	else if (dex.card == KING)
		cout << setw(6) << "King ";
	else if (dex.card == ACE)
		cout << setw(6) << "Ace ";
	cout << "of ";
	if (dex.suit == CLUBS)
		cout << "Clubs\n";
	else if (dex.suit == DIAMONDS)
		cout << "Diamonds\n";
	else if (dex.suit == HEARTS)
		cout << "Hearts\n";
	else if (dex.suit == SPADES)
		cout << "Spades\n";
	cout << "\n";
}

void deal(cards deck[52], cards &tempDeck){
	
	int i = rand()%52;
	tempDeck = deck[i];
}

void winner(cards card1, cards card2){
	cout << "And the winner is ........\n";
	if (card1.card > card2.card)
		cout << "\tCard #1 \n";
	else if (card1.card < card2.card)
		cout << "\tCard #2 \n";
	else
		cout << "Draw!!\n";
}
