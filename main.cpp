#include "Deck.hpp"

#include <iostream>

using namespace std;

int main() {
    Deck normal_deck;
    Card card;

    // for(const auto& card : normal_deck.getDeck()) {
    //     cout << card.getSuite() << " " << card.getRank() << " (" << card.getValue() << ")" << endl;
    // };
    
    vector<Card> shuffled = normal_deck.shuffleDeck();
    
    // for(const auto& card: shuffled){
    //     cout << card.getSuite() << " " << card.getRank() << " (" << card.getValue() << ")" << endl;
    
    // }
    
    
    vector<Card> p1;
    vector<Card> p2;
    
    
    normal_deck.dealDeck(shuffled, p1, p2);

    // for(auto & card: p1){
    //     cout << card.getSuite() << " " << card.getRank() << " (" << card.getValue() << ")" << endl;
    // }
    
    // for(auto & card: p2){
    //     cout << card.getSuite() << " " << card.getRank() << " (" << card.getValue() << ")" << endl;
    // }
    // cout << p1.size() << p2.size() << shuffled.size() << endl;

    int k = card.compare(p1[25], p2[25]);
    if(k == 1){
        cout << p1[25].getSuite() << " " << p1[25].getRank() << " is greater than" << p2[25].getSuite() << " " << p2[25].getRank() << endl;
    }else if(k == -1){
        cout << p1[25].getSuite() << " " << p1[25].getRank() << " is smaller than" << p2[25].getSuite() << " " << p2[25].getRank() << endl;
        
    }else{
        cout << p1[25].getSuite() << " " << p1[25].getRank() << " is equal to" << p2[25].getSuite() << " " << p2[25].getRank() << endl;

    }

    return 0;
}