#ifndef DECK_HPP
#define DECK_HPP

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Card{
    public:
        Card(string &suite, string &rank, int value) : suite(suite), rank(rank), value(value) {};

        string getSuite() const {return suite;};
        string getRank() const {return rank;};
        int getValue() const {return value;};

        // no settters as the cards are immutable and thus should not change after creation and are made const.

    private:
        const string suite;
        const string rank;
        const int value;


};

class Deck {
    private:
        const vector<Card> deck;      // cannot have the size defined to 52 here as it is not defined but declared here. will do so in the constructor.
        const int deck_size = 52;

        const vector<string> suites_types = {"Hearts", "Diamonds", "Clubs", "Spades"};
        const vector<string> rank_types = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
        const vector<int> value_types = {2,3,4,5,6,7,8,9,10,11,12,13,14};


    public:
        Deck() : deck(createDeck()) {};

        vector<Card> createDeck();

};

#endif