#ifndef DECK_HPP
#define DECK_HPP

#include <string>
#include <vector>

using namespace std;

class Card{
    public:
        Card() : suite(""), rank(""), value(0) {};

        Card(const string &suite,const string &rank,const int value) 
            : suite(suite), rank(rank), value(value) {};

        string getSuite() const {return suite;};
        string getRank() const {return rank;};
        int getValue() const {return value;};

        void swap(Card &a, Card &b);        // as the shuffle calls to swap the cards and as Card dt is not standard so have to define it.

        int compare(Card &a, Card &b);

        // no settters as the cards are immutable and thus should not change after creation and are made const.

    private:                    // removing the const from the class members as they need to be swapped :/
        string suite;
        string rank;
        int value;


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

        vector<Card> shuffleDeck() const;

        void dealDeck(vector<Card> &shuffled_deck, vector<Card> &player1, vector<Card> &player2);

};

#endif