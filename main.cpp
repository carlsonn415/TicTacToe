// Manages a tic tac toe game that allows players to move or undo the most
// recent of their opponents moves when it is their turn.

#include <iostream>
using namespace std;

#include "GameState.h"

int main() {
    GameState game;  // manages the board and undo stack
    
    string command;  // input from user
    int x;  // x coordinate of move
    int y;  // y coordinate of move
    
    bool gameOver = false;  // mnages the game loop

    game.displayBoardState(cout); // output initial board

    while (!gameOver) {
        cout << "Player " << game.getCurrentPlayer() << " make a turn." << endl;
        cin >> command;
        if (command == "move") {
            cin >> x >> y;
            Move move(x,y);
            int result = game.addMove(move); // 1, 0, or -1
            if (result == -1)
                cout << "Incorrect move. Please try again." << endl;
            else
            {
                game.displayBoardState(cout);
                if (game.checkLastPlayerWin()) {
                    cout << "Player " << !game.getCurrentPlayer() << " won!\n";
                    gameOver = true;
                }
                else if (result == 0) {
                    cout << "It's a draw!" << endl;
                    gameOver = true;
                }
            }
        }
        else if (command == "undo") {
            bool undid = game.undoLast();
            if (!undid)
                cout << "No moves to undo." << endl;
            else {
                game.displayBoardState(cout);
            }
        }
        else
            cout << "Invalid command" << endl;
    }
    
}
