#ifndef DECK_HPP
#define DECK_HPP

#include <string>
#include <vector>

using namespace std;

class Card{
    public:
        Card(const string &suite,const string &rank,const int value) 
            : suite(suite), rank(rank), value(value) {};

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
        const vector<Card> deck; 

        static const vector<string> suites_types;
        static const vector<string> rank_types;
        static const vector<int> value_types;


    public:
        Deck() : deck(createDeck()) {};

        vector<Card> createDeck();

        vector<Card> getDeck() const {return deck;};

};

#endif