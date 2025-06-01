#include "Deck.hpp"     // here we dont need to give the path as the include directory is already set in the CMakeLists.txt file.
#include <algorithm>    // for shuffle  =============> this shuffle here will be using fisher yates algo.
#include <random>       // for mt19937 and random_device
#include <utility>      // for swap as we have to define it for swapping 2 cards manually as it will be used by the shuffle to swap two cards as per fisher-yates algo.

using namespace std;

void Card::swap(Card &a, Card &b){
    using std::swap;        // to ensure that the ADL(arg dependent lookup) finds my defined swap.
    
    swap(a.suite, b.suite);
    swap(a.rank, b.rank);
    swap(a.value, b.value);
}

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


vector<Card> Deck::shuffleDeck() const {
    vector<Card> shuffled_deck = Deck::getDeck();

    // creating a random number but not with rand as it aint truly random, not thread safe, not uniformly distributed.
    // this shuffle needs URBG uniform random bit generator such as mt19937.

    random_device rd;       // makes non-deterministic seed from h/w if possible.
    mt19937 g(rd());        // Mersenne-Twister engine, a fast, uniformly-distributed pseudo-rng

    shuffle(shuffled_deck.begin(), shuffled_deck.end(), g);
    
    return shuffled_deck;
}

void Deck::dealDeck(vector<Card> &shuffled_deck, vector<Card> &player1, vector<Card> &player2){
    for(int i = 0; i < 26; i++){
        player1.push_back(shuffled_deck[2*i]);
        player2.push_back(shuffled_deck[2*i + 1]);
    }
    return;
}