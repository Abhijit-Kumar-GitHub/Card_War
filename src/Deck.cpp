#include "Deck.hpp"     // here we dont need to give the path as the include directory is already set in the CMakeLists.txt file.

vector<Card> Deck::createDeck(){
    vector<Card> new_deck(52); // initialize the vector with size 52
    
    for (const string& suite: suites_types) {
        for(int i = 0; i < rank_types.size(); i++) {
            new_deck.emplace_back(suite, rank_types[i], value_types[i]);
        }
    }
    return new_deck;
};