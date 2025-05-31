#include "Deck.hpp"     // here we dont need to give the path as the include directory is already set in the CMakeLists.txt file.


const vector<string> Deck::suites_types = {"Hearts", "Diamonds", "Clubs", "Spades"};
const vector<string> Deck::rank_types = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"}; 
const vector<int> Deck::value_types = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}; // Jack is 11, Queen is 12, King is 13 and Ace is 14.

vector<Card> Deck::createDeck(){
    vector<Card> new_deck;

    for (const string& suite: suites_types) {
        for(int i = 0; i < rank_types.size(); i++) {
            new_deck.emplace_back(suite, rank_types[i], value_types[i]);
        }
    }
    return new_deck;
};