//Gwen Canos
//Programming languages 4450
//01-30-24
//HW1
// Desc: "Beggar My Neighbor" card game
// in which a user controls gameplay between
// two players.
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


void loaddeck(ifstream& infile, string deckNum[], int size);
void swapdeck (string deckNum[]);

void playerOneMove(vector<string>& vplayerOne, vector<string>& vCenPile);
void playerTwoMove(vector<string>& vplayerTwo, vector<string>& vCenPile);

void centralCardPileOne(vector<string>& vplayerOne, vector<string>& vCenPile);
void centralCardPileTwo(vector<string>& vplayerTwo, vector<string>& vCenPile);

void playerOneRemove(vector<string>& vplayerOne);
void playerTwoRemove(vector<string>& vplayerTwo);

void acePenaltyOne(vector<string>& vplayerOne, vector<string>& vplayerTwo, vector<string>& vCenPile);
void acePenaltyTwo(vector<string>& vplayerTwo, vector<string>& vplayerOne, vector<string>& vCenPile);

void kingPenaltyOne(vector<string>& vplayerOne, vector<string>& vplayerTwo, vector<string>& vCenPile);
void kingPenaltyTwo(vector<string>& vplayerTwo, vector<string>& vplayerOne, vector<string>& vCenPile);

void queenPenaltyOne(vector<string>& vplayerOne, vector<string>& vplayerTwo, vector<string>& vCenPile);
void queenPenaltyTwo(vector<string>& vplayerTwo, vector<string>& vplayerOne, vector<string>& vCenPile);

void jackPenaltyOne(vector<string>& vplayerOne, vector<string>& vplayerTwo, vector<string>& vCenPile);
void jackPenaltyTwo(vector<string>& vplayerTwo, vector<string>& vplayerOne, vector<string>& vCenPile);

int main() {
    string cardDeck[52];
    vector<string> playerOne;
    vector<string> playerTwo;
    vector<string> centralPile;

    string fname = "hw1data.txt";

    ifstream infile(fname);
    if (!infile){
        cout << "File not found" + fname << endl;
        exit (-1);
    }

    loaddeck(infile, cardDeck, 52);
    swapdeck(cardDeck);

    for (int i = 0; i < 26; i++){
        playerOne.push_back(cardDeck[i]);
    }

    for (int i = 26; i < 52; i++){
        playerTwo.push_back(cardDeck[i]);
    }

    char move;
    cout << "press 'y' and then 'enter' to start the game" << endl;
    cin >> move;
    while (move != 'y'){
        cout << "invalid action please press 'm' " << endl;
        cin >> move;
    }

    while(!playerOne.empty() && !playerTwo.empty() && move !='q'){

        playerOneMove(playerOne, centralPile);
        acePenaltyOne(playerOne, playerTwo, centralPile);
        kingPenaltyOne(playerOne, playerTwo, centralPile);
        queenPenaltyOne(playerOne, playerTwo, centralPile);
        jackPenaltyOne(playerOne, playerTwo, centralPile);
        playerOneRemove(playerOne);

        playerTwoMove(playerTwo, centralPile);
        acePenaltyTwo(playerTwo, playerOne, centralPile);
        kingPenaltyTwo(playerTwo, playerOne, centralPile);
        queenPenaltyTwo(playerTwo, playerOne, centralPile);
        jackPenaltyTwo(playerTwo, playerOne, centralPile);
        playerTwoRemove(playerTwo);

        cout << "---------------------------------------" << endl;
        cout<< "press 'q' if you would like to end the game" << endl;
        cout << "or any letter key to continue" << endl;
        cin >> move;
    }
    infile.close();
    return 0;
}

void loaddeck(ifstream& infile, string deckNum[], int size){
    string cardName;
    int slot = 0;
    infile >> cardName;
    while (!infile.eof()){
        deckNum[slot] = cardName;
        infile >> cardName;
        slot++;
    }
}

void swapdeck (string deckNum[]){
    string store;
    for (int i =0; i < rand(); i++ ){
        int slotOne = rand() % 51;
        int slotTwo = rand() % 51;
        store = deckNum[slotOne];
        deckNum[slotOne] = deckNum[slotTwo];
        deckNum[slotTwo] = store;
    }
}

void playerOneMove (vector<string>& vplayerOne, vector<string>& vCenPile){
    char move;
    int moveCtr = 0;
    int moveCtr2 = 1;
    cout << "--------------Player 1's turn ----------------" << endl;
    if (vplayerOne.empty()){
        cout << "PLAYER ONE WINS!!!!!!!!!!!" << endl;
    }else{
        for (int i = moveCtr; i < moveCtr2; i++){
            cout << "player one press 'm' and then 'enter' to make a move " << endl;
            cin >> move;
            cout << "player one card: " <<  vplayerOne[i]<< endl;
        }
        centralCardPileOne(vplayerOne, vCenPile);
    }
}

void playerTwoMove(vector<string>& vplayerTwo, vector<string>& vCenPile){
    char move;
    int moveCtr = 0;
    int moveCtr2 = 1;
    cout << "--------------Player 2's turn ----------------" << endl;
    if (vplayerTwo.empty()){
        cout << "PLAYER TWO WINS!!!!!!!!!!!" << endl;
    }else{
        for (int i = moveCtr; i < moveCtr2; i++){
            cout << "player two press 'm' and then 'enter' to make a move " << endl;
            cin >> move;
            cout << "player two card: " <<  vplayerTwo[0]<< endl;
        }
        centralCardPileTwo(vplayerTwo, vCenPile);
    }
}

void centralCardPileOne(vector<string>& vplayerOne, vector<string>& vCenPile){
    vCenPile.push_back(vplayerOne[0]);
    cout << vCenPile.size() << " cards in central pile" << endl;
}

void centralCardPileTwo(vector<string>& vplayerTwo, vector<string>& vCenPile){
    vCenPile.push_back(vplayerTwo[0]);
    cout << vCenPile.size() << " cards in central pile" << endl;
}

void playerOneRemove(vector<string>& vplayerOne){
    vplayerOne.erase(vplayerOne.begin());
    cout << vplayerOne.size() << " cards remaining in player one hand" << endl;
}

void playerTwoRemove(vector<string>& vplayerTwo){
    vplayerTwo.erase(vplayerTwo.begin());
    cout << vplayerTwo.size() << " cards remaining in player two hand" << endl;
}

void acePenaltyOne(vector<string>& vplayerOne,vector<string>& vplayerTwo, vector<string>& vCenPile ){
    char ace = 'A';
    if (vplayerOne[0].at(0) == ace ){
        playerOneRemove(vplayerOne);
        cout << "ACE ---PENALTY---" << endl;
        cout << "Player 2 put down 4 cards" << endl;
        for (int i = 0; i < 4; i++){
            playerTwoMove(vplayerTwo, vCenPile);
            acePenaltyTwo(vplayerTwo, vplayerOne, vCenPile);
            kingPenaltyTwo(vplayerTwo, vplayerOne, vCenPile);
            queenPenaltyTwo(vplayerTwo, vplayerOne, vCenPile);
            jackPenaltyTwo(vplayerTwo, vplayerOne, vCenPile);
            playerTwoRemove(vplayerTwo);
        }
        for (int i = 0; i < vCenPile.size(); i++){
            vplayerOne.push_back(vCenPile[i]);
        }
        vCenPile.clear();
    }
}

void acePenaltyTwo(vector<string>& vplayerTwo,vector<string>& vplayerOne, vector<string>& vCenPile){
    char ace = 'A';
    if (vplayerTwo[0].at(0) == ace ){
        playerTwoRemove(vplayerTwo);
        cout << "ACE ---PENALTY---" << endl;
        cout << "Player 1 put down 4 cards" << endl;
        for (int i = 0; i < 4; i++){
            playerOneMove(vplayerOne, vCenPile);
            acePenaltyOne(vplayerOne, vplayerTwo, vCenPile);
            kingPenaltyOne(vplayerOne, vplayerTwo, vCenPile);
            queenPenaltyOne(vplayerOne, vplayerTwo, vCenPile);
            jackPenaltyOne(vplayerOne, vplayerTwo, vCenPile);
            playerOneRemove(vplayerOne);
        }
        for (int i = 0; i < vCenPile.size(); i++){
            vplayerTwo.push_back(vCenPile[i]);
        }
        vCenPile.clear();
    }
}

void kingPenaltyOne(vector<string>& vplayerOne, vector<string>& vplayerTwo, vector<string>& vCenPile){
    char king = 'K';
    if (vplayerOne[0].at(0) == king ){
        playerOneRemove(vplayerOne);
        cout << "KING ---PENALTY---" << endl;
        cout << "Player 2 put down 3 cards" << endl;
        for (int i = 0; i < 3; i++){
            playerTwoMove(vplayerTwo, vCenPile);
            acePenaltyTwo(vplayerTwo, vplayerOne, vCenPile);
            kingPenaltyTwo(vplayerTwo, vplayerOne, vCenPile);
            queenPenaltyTwo(vplayerTwo, vplayerOne, vCenPile);
            jackPenaltyTwo(vplayerTwo, vplayerOne, vCenPile);
            playerTwoRemove(vplayerTwo);
        }
        for (int i = 0; i < vCenPile.size(); i++){
            vplayerOne.push_back(vCenPile[i]);
        }
        vCenPile.clear();
    }
}

void kingPenaltyTwo(vector<string>& vplayerTwo, vector<string>& vplayerOne, vector<string>& vCenPile){
    char king = 'K';
    if (vplayerTwo[0].at(0) == king ){
        playerTwoRemove(vplayerTwo);
        cout << "KING ---PENALTY---" << endl;
        cout << "Player 1 put down 3  cards" << endl;
        for (int i = 0; i < 3; i++){
            playerOneMove(vplayerOne, vCenPile);
            acePenaltyOne(vplayerOne, vplayerTwo, vCenPile);
            kingPenaltyOne(vplayerOne, vplayerTwo, vCenPile);
            queenPenaltyOne(vplayerOne, vplayerTwo, vCenPile);
            jackPenaltyOne(vplayerOne, vplayerTwo, vCenPile);
            playerOneRemove(vplayerOne);
        }
        for (int i = 0; i < vCenPile.size(); i++){
            vplayerTwo.push_back(vCenPile[i]);
        }
        vCenPile.clear();
    }
}

void queenPenaltyOne(vector<string>& vplayerOne, vector<string>& vplayerTwo, vector<string>& vCenPile){
    char queen = 'Q';
    if (vplayerOne[0].at(0) == queen ){
        playerOneRemove(vplayerOne);
        cout << "QUEEN ---PENALTY---" << endl;
        cout << "Player 2 put down 2 cards" << endl;
        for (int i = 0; i < 2; i++){
            playerTwoMove(vplayerTwo, vCenPile);
            acePenaltyTwo(vplayerTwo, vplayerOne, vCenPile);
            kingPenaltyTwo(vplayerTwo, vplayerOne, vCenPile);
            queenPenaltyTwo(vplayerTwo, vplayerOne, vCenPile);
            jackPenaltyTwo(vplayerTwo, vplayerOne, vCenPile);
            playerTwoRemove(vplayerTwo);
        }
        for (int i = 0; i < vCenPile.size(); i++){
            vplayerOne.push_back(vCenPile[i]);
        }
        vCenPile.clear();
    }
}

void queenPenaltyTwo(vector<string>& vplayerTwo, vector<string>& vplayerOne, vector<string>& vCenPile){
    char queen = 'Q';
    if (vplayerTwo[0].at(0) == queen){
        cout << "QUEEN ---PENALTY---" << endl;
        cout << "Player 1 put down 2 cards" << endl;
        for (int i = 0; i < 2; i++){
            playerOneMove(vplayerOne, vCenPile);
            acePenaltyOne(vplayerOne, vplayerTwo, vCenPile);
            kingPenaltyOne(vplayerOne, vplayerTwo, vCenPile);
            queenPenaltyOne(vplayerOne, vplayerTwo, vCenPile);
            jackPenaltyOne(vplayerOne, vplayerTwo, vCenPile);
            playerOneRemove(vplayerOne);
        }
        for (int i = 0; i < vCenPile.size(); i++){
            vplayerTwo.push_back(vCenPile[i]);
        }
        vCenPile.clear();
    }
}

void jackPenaltyOne(vector<string>& vplayerOne, vector<string>& vplayerTwo, vector<string>& vCenPile){
    char jack = 'J';
    if (vplayerOne[0].at(0) == jack ){
        playerOneRemove(vplayerOne);
        cout << "JACK ---PENALTY---" << endl;
        cout << "Player 2 put down 1 card" << endl;
        for (int i = 0; i < 1; i++){
            playerTwoMove(vplayerTwo, vCenPile);
            acePenaltyTwo(vplayerTwo, vplayerOne, vCenPile);
            kingPenaltyTwo(vplayerTwo, vplayerOne, vCenPile);
            queenPenaltyTwo(vplayerTwo, vplayerOne, vCenPile);
            jackPenaltyTwo(vplayerTwo, vplayerOne, vCenPile);
            playerTwoRemove(vplayerTwo);
        }
        for (int i = 0; i < vCenPile.size(); i++){
            vplayerOne.push_back(vCenPile[i]);
        }
        vCenPile.clear();
    }
}

void jackPenaltyTwo(vector<string>& vplayerTwo, vector<string>& vplayerOne, vector<string>& vCenPile){
    char jack = 'J';
    if (vplayerTwo[0].at(0) == jack){
        playerTwoRemove(vplayerTwo);
        cout << "JACK ---PENALTY---" << endl;
        cout << "Player 1 put down 1 card" << endl;
        for (int i = 0; i < 2; i++){
            playerOneMove(vplayerOne, vCenPile);
            acePenaltyOne(vplayerOne, vplayerTwo, vCenPile);
            kingPenaltyOne(vplayerOne, vplayerTwo, vCenPile);
            queenPenaltyOne(vplayerOne, vplayerTwo, vCenPile);
            jackPenaltyOne(vplayerOne, vplayerTwo, vCenPile);
            playerOneRemove(vplayerOne);
        }
        for (int i = 0; i < vCenPile.size(); i++){
            vplayerTwo.push_back(vCenPile[i]);
        }
        vCenPile.clear();
    }
}


