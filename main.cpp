/*
* filename: main.cpp
* project: COP3003-HW1
* author: Alex M Patterson
* purpose: create a deck of cards and deal out hands to players, handmax = 10 and playermax = 5
*/

#include <iostream>

#include <cstdlib>
#include <ctime>
//*******************************************************************
// Global Defines

const int MAX_CARDS = 10;
const int MAX_PLAYERS = 5;
#define byte unsigned char

//*******************************************************************
// Globally Defined Structures

class CARD{

public:
    byte suit;
    byte face;
    int value;
    bool inDeck;

};

class PLAYER{

public:
    CARD cards[MAX_CARDS];

};
//-------------------------------------------------------------------
// main starts
int main() {
//-------------------------------------------------------------------
// generally used variables
    int NumberOfPlayers;
    int NumberOfCardsDealt;
    int deckindex; // used to reference either of the deck arrays
    CARD theDeck[52];
    CARD theShuffledDeck[52];
    PLAYER players[MAX_PLAYERS];


    //-------------------------------------------------------------------
// build the deck and initialize the shuffle deck

    int Face; //for loop counter face
    char suit; //assign char suit to card
    char faceface; //assign char face to card
    int suitscount; //for loop counter - suits

    for (suitscount = 0; suitscount < 4; suitscount++){

        if(suitscount == 0){
            suit = 'D';
        }else if(suitscount == 1){
            suit = 'H';
        }else if(suitscount == 2){
            suit = 'C';
        }else{
            suit = 'S';
        }

        for (Face = 0; Face < 14; Face++){

            deckindex = (suitscount * 13) + Face;

            theShuffledDeck[deckindex].value = 0;
            theShuffledDeck[deckindex].suit = 'Q';
            theShuffledDeck[deckindex].face = 'M';
            theShuffledDeck[deckindex].inDeck = true;

            if(Face == 0){
                faceface = 'A';
                theDeck[deckindex].face = faceface;
                theDeck[deckindex].suit = suit;
                theDeck[deckindex].value = 11;
                theDeck[deckindex].inDeck = true;
            }else if(Face == 9){
                faceface = 'T';
                theDeck[deckindex].face = faceface;
                theDeck[deckindex].suit = suit;
                theDeck[deckindex].value = 10;
                theDeck[deckindex].inDeck = true;
            }else if(Face == 10){
                faceface = 'J';
                theDeck[deckindex].face = faceface;
                theDeck[deckindex].suit = suit;
                theDeck[deckindex].value = 10;
                theDeck[deckindex].inDeck = true;
            }else if(Face == 11){
                faceface = 'Q';
                theDeck[deckindex].face = faceface;
                theDeck[deckindex].suit = suit;
                theDeck[deckindex].value = 10;
                theDeck[deckindex].inDeck = true;
            }else if(Face == 12){
                faceface = 'K';
                theDeck[deckindex].face = faceface;
                theDeck[deckindex].suit = suit;
                theDeck[deckindex].value = 10;
                theDeck[deckindex].inDeck = true;
            }else{
                faceface = Face + 49;
                theDeck[deckindex].face = faceface;
                theDeck[deckindex].suit = suit;
                theDeck[deckindex].value = Face + 1;
                theDeck[deckindex].inDeck = true;
            }

        }

    }
    //-------------------------------------------------------------------
// randomize the shuffle deck

    int RandomPlace;
    char whatface; // adding these variables helped with debugging the following loop and condition
    char whatsuit;
    int whatvalue;


    for(deckindex = 0; deckindex < 52; deckindex++) {

        srand(time(0));
        RandomPlace = (rand() + 85 * deckindex) % 52;
        // don't know why rand() needed to be more than 52 to be modded correctly but that's what it needed
        whatface = theDeck[deckindex].face;
        whatvalue = theDeck[deckindex].value;
        whatsuit = theDeck[deckindex].suit;

        if (theShuffledDeck[RandomPlace].value == 0) {
            // if the value is 0 it hasn't had a card assigned to that place yet
            theShuffledDeck[RandomPlace].inDeck = true;
            theShuffledDeck[RandomPlace].face = whatface;
            theShuffledDeck[RandomPlace].value = whatvalue;
            theShuffledDeck[RandomPlace].suit = whatsuit;
        }
    }

    //-------------------------------------------------------------------
// get user values

    std::cout << "Please enter number of players: ";
    std::cin >> NumberOfPlayers;
    std::cout << "\nPlease enter number of cards to be dealt: ";
    std::cin >> NumberOfCardsDealt;

    //-------------------------------------------------------------------
// deal the deck

    deckindex = 0;
    int dealcounter;
    for(dealcounter = 0; dealcounter < NumberOfCardsDealt; dealcounter++){
        //player 1 this is assuming there must be at least one player
        theShuffledDeck[deckindex].inDeck = false;
        players[0].cards[dealcounter].suit = theShuffledDeck[deckindex].suit;
        players[0].cards[dealcounter].face = theShuffledDeck[deckindex].face;
        players[0].cards[dealcounter].value = theShuffledDeck[deckindex].value;
        deckindex = 1 + deckindex;

        if (NumberOfPlayers > 1){
            theShuffledDeck[deckindex].inDeck = false;
            players[1].cards[dealcounter].suit = theShuffledDeck[deckindex].suit;
            players[1].cards[dealcounter].face = theShuffledDeck[deckindex].face;
            players[1].cards[dealcounter].value = theShuffledDeck[deckindex].value;
            deckindex = 1 + deckindex;
            if (NumberOfPlayers > 2){
                theShuffledDeck[deckindex].inDeck = false;
                players[2].cards[dealcounter].suit = theShuffledDeck[deckindex].suit;
                players[2].cards[dealcounter].face = theShuffledDeck[deckindex].face;
                players[2].cards[dealcounter].value = theShuffledDeck[deckindex].value;
                deckindex = 1 + deckindex;

                if (NumberOfPlayers > 3){
                    theShuffledDeck[deckindex].inDeck = false;
                    players[3].cards[dealcounter].suit = theShuffledDeck[deckindex].suit;
                    players[3].cards[dealcounter].face = theShuffledDeck[deckindex].face;
                    players[3].cards[dealcounter].value = theShuffledDeck[deckindex].value;
                    deckindex = 1 + deckindex;

                    if(NumberOfPlayers > 4){
                        theShuffledDeck[deckindex].inDeck = false;
                        players[4].cards[dealcounter].suit = theShuffledDeck[deckindex].suit;
                        players[4].cards[dealcounter].face = theShuffledDeck[deckindex].face;
                        players[4].cards[dealcounter].value = theShuffledDeck[deckindex].value;
                        deckindex = 1 + deckindex;

                    }
                }
            }
        }
    }

    //-------------------------------------------------------------------
// print the stuff

    int handindex;
    std::cout << "\nPlayer One's hand contains: ";
    for(handindex = 0; handindex < 10; handindex++){
        if (handindex < NumberOfCardsDealt){
            std::cout << players[0].cards[handindex].face << players[0].cards[handindex].suit << " ";
        }
    }
    std::cout << "\n";
    if (NumberOfPlayers > 1){
        std::cout << "Player Two's hand contains: ";
        for(handindex = 0; handindex < 10; handindex++){
            if (handindex < NumberOfCardsDealt){
                std::cout << players[1].cards[handindex].face << players[1].cards[handindex].suit << " ";
            }
        }
        std::cout << "\n";
        if (NumberOfPlayers > 2){
            std::cout << "Player Three's hand contains: ";
            for(handindex = 0; handindex < 10; handindex++){
                if (handindex < NumberOfCardsDealt){
                    std::cout << players[2].cards[handindex].face << players[2].cards[handindex].suit << " ";
                }
            }
            std::cout << "\n";
            if (NumberOfPlayers > 3){
                std::cout << "Player Four's hand contains: ";
                for(handindex = 0; handindex < 10; handindex++){
                    if (handindex < NumberOfCardsDealt){
                        std::cout << players[3].cards[handindex].face << players[3].cards[handindex].suit << " ";
                    }
                }
                std::cout << "\n";
                if(NumberOfPlayers > 4){
                    std::cout << "Player Five's hand contains: ";
                    for(handindex = 0; handindex < 10; handindex++){
                        if (handindex < NumberOfCardsDealt){
                            std::cout << players[4].cards[handindex].face << players[4].cards[handindex].suit << " ";
                        }
                    }
                    std::cout << "\n";
                }
            }
        }
    }

    std::cout << "The deck still contains: ";
    for(deckindex = 0;deckindex < 52; deckindex++){
        if (theShuffledDeck[deckindex].inDeck){
            std::cout << theShuffledDeck[deckindex].face << theShuffledDeck[deckindex].suit << " ";
        }

    }

    return 0;
}