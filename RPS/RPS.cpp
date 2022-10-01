
// ROCK, PAPER, SCISSORS C++ MINIGAME by LEWIS MOHOLT //

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

void TakeComputerInput();
void TakePlayerInput();

int playerWins = 0, computerWins = 0;

void CalculateOutcome(string& playerInput, int& computerSelection) {
    //CHECK FOR DRAW
    if (playerInput == "r" && computerSelection == 1 || playerInput == "p" && computerSelection == 2 || playerInput == "s" && computerSelection == 3) {
        cout << "|| DRAW! NEXT ROUND!                        ||" << endl;
        cout << "||__________________________________________||" << endl;
        TakePlayerInput();
    }

    else {
        //NO DRAW, CHECK FOR WINNER
        switch (computerSelection) {
            case 1 :
                if (playerInput == "p") {
                    cout << "|| PLAYER WINS! PAPER covers ROCK!          ||" << endl;
                    playerWins += 1;
                }
                else { 
                    cout << "|| COMPUTER WINS! ROCK destroys SCISSORS!   ||" << endl;
                    computerWins += 1;
                }
                break;
            case 2 : 
                if (playerInput == "s") {
                    cout << "|| PLAYER WINS! SCISSORS cuts PAPER!        ||" << endl;
                    playerWins += 1;
                }
                else {
                    cout << "|| COMPUTER WINS! PAPER covers ROCK!        ||" << endl;
                    computerWins += 1;
                }
                break;
            case 3 :
                if (playerInput == "r") {
                    cout << "|| PLAYER WINS! ROCK destroys SCISSORS!     ||" << endl;
                    playerWins += 1;
                }
                else {
                    cout << "|| COMPUTER WINS! SCISSORS cuts PAPER!      ||" << endl;
                    computerWins += 1;
                }
                break;
        }
        
        //SHOW SCORES
        cout << "||__________________________________________||" << endl;
        cout << "|| PLAYER: " << playerWins << "          ||       COMPUTER: " << computerWins << "  ||" << endl;

        //DETERMINE WHETHER THE GAME CONTINUES OR NOT
        if (playerWins == 2) cout << "||         PLAYER IS THE WINNER!            ||\n" << "||-----------------------------------------||" << endl;
        else if (computerWins == 2) cout << "||         COMPUTER IS THE WINNER!          ||\n" << "||------------------------------------------||" << endl;
        else {
            cout << "||__________________________________________||" << endl;
            cout << "|| NEXT ROUND!                              ||" << endl;
            cout << "||__________________________________________||" << endl;
            TakePlayerInput();
        }
    }
}

void TakeComputerInput(string& playerInput) {
    //GENERATE COMPUTER'S ATTACK
    srand(time(0));
    int computerSelection = 1 + (rand() % 3);

    switch (computerSelection) {
    case 1:
        cout << "|| Computer has chosen ROCK!                ||" << endl;
        break;
    case 2:
        cout << "|| Computer has chosen PAPER!               ||" << endl;
        break;
    case 3:
        cout << "|| Computer has chosen SCISSORS!            ||" << endl;
        break;
    }

    CalculateOutcome(playerInput, computerSelection);
}

void TakePlayerInput() {
    string playerInput = "";

    cout << "|| ROCK, PAPER, SCISSORS! Best of 3 wins!   ||\n" << "|| (r) = ROCK, (p) = PAPER, (s) = SCISSORS) ||\n" << "|| Type your move :                         ||" << endl;
    cin >> playerInput;

    //CHECK ONLY FOR CORRECT INPUT, SHOW PLAYER CHOICE
    if (playerInput == "r" || playerInput == "p" || playerInput == "s") {
        if (playerInput == "r") cout << "||__________________________________________||\n" << "|| Player has chosen ROCK!                  ||" << endl;
        else if (playerInput == "p") cout << "||__________________________________________||\n" << "|| Player has chosen PAPER!                 ||" << endl;
        else cout << "||__________________________________________||\n" << "|| Player has chosen SCISSORS!              ||" << endl;

        TakeComputerInput(playerInput);
    }
    else {
        cout << "|| Invalid move! (r), (p), (s)              ||" << endl;
        TakePlayerInput();
    }
}

int main()
{
    TakePlayerInput();

    return 0;
}


//WORK IN PROGRESS
//int computerChoice(vector<int> playerChoices) {
//    int computerChoice; // 1 for Rock, 2 for Paper, 3 for Scissors
//    int playerChoiceRock = 0, playerChoicePaper = 0, playerChoiceScissors = 0;
//    int size = sizeof(playerChoices) / sizeof(playerChoices[0]); // Get size of playerChoice array
//
//    for (int i = 0; i < size; i++) {
//        if (i >= 10) {
//            for (int i : playerChoices) {
//                if (i == 1) { // If player choice is 1 (Rock)
//                    playerChoiceRock += 1;
//                }
//                else if (i == 2) { // If player choice is 2 (Paper)
//                    playerChoicePaper += 1;
//                }
//                else playerChoiceScissors += 1; // If player choice is 3 (Scissors)
//            }
//        }
//    }
//
//    if (playerChoiceRock >= 5) {
//
//    }
//
//    return computerChoice;
//}