#include "Deck.hpp"

#include <iostream>

using namespace std;

int main() {
    Deck normal_deck;

    for(const auto& card : normal_deck.getDeck()) {
        cout << card.getSuite() << " " << card.getRank() << " (" << card.getValue() << ")" << endl;
    };

    return 0;
}