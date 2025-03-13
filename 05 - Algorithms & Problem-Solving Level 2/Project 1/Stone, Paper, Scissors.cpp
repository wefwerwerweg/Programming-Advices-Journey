// Project : 🎮 Stone, Paper, Scissors
// Coded By : @X99099

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

enum class Choice { Stone = 1, Paper, Scissors };

enum class Result { Win = 1, Loss, Draw };

struct RoundInfo {
    Choice playerChoice;
    Choice computerChoice;
    Result result;
    string roundWinner;
};

struct GameStats {
    int playerWins = 0;
    int computerWins = 0;
    int drawTimes = 0;
    int totalRounds = 0;
    string winner;
};

void resetScreen() {
    Sleep(2000);
    system("cls");
}

void changeScreenColor(const string& color) {
    if (color == "green") {
        system("color 2F");
    }
    else if (color == "yellow") {
        system("color 6F");
    }
    else if (color == "red") {
        system("color 4F");
        playBallSound();
    }
    else {
        system("color 07");
    }
}

void playBallSound() {
    cout << "\a";  
}

Choice getPlayerChoice() {
    int choice;
    cout << "\n[1] Stone  |  [2] Paper  |  [3] Scissors\n";
    cout << "Your Choice: ";
    cin >> choice;

    if (choice < 1 || choice > 3) {
        cout << "Invalid choice! Please select a valid option.\n";
        return getPlayerChoice();
    }
    return Choice(choice);
}

Choice getComputerChoice() {
    return Choice(randomNumber(3));
}

int randomNumber(int range) {
    return rand() % range + 1;
}

string choiceToString(Choice choice) {
    switch (choice) {
    case Choice::Stone: return "Stone";
    case Choice::Paper: return "Paper";
    case Choice::Scissors: return "Scissors";
    default: return "Unknown";
    }
}

void displayRoundResult(const RoundInfo& roundInfo, int round) {
    cout << "\n=========== ROUND " << round << " ===========\n";
    cout << "Player Choice   : " << choiceToString(roundInfo.playerChoice) << "\n";
    cout << "Computer Choice : " << choiceToString(roundInfo.computerChoice) << "\n";
    cout << "Round Winner    : " << roundInfo.roundWinner << "\n";
    cout << "==========================================\n";
}

void displayFinalResults(const GameStats& stats) {
    resetScreen();
    cout << "\n============== GAME OVER ===============\n";
    cout << "Total Rounds Played: " << stats.totalRounds << "\n";
    cout << "Player Wins        : " << stats.playerWins << "\n";
    cout << "Computer Wins      : " << stats.computerWins << "\n";
    cout << "Draws              : " << stats.drawTimes << "\n";
    cout << "Final Winner       : " << stats.winner << "\n";
    cout << "========================================\n";
}

void determineRoundWinner(RoundInfo& roundInfo, GameStats& gameStats) {
    if ((roundInfo.playerChoice == Choice::Paper && roundInfo.computerChoice == Choice::Stone) ||
        (roundInfo.playerChoice == Choice::Stone && roundInfo.computerChoice == Choice::Scissors) ||
        (roundInfo.playerChoice == Choice::Scissors && roundInfo.computerChoice == Choice::Paper)) {
        roundInfo.roundWinner = "Player";
        gameStats.playerWins++;
        changeScreenColor("green");
    }
    else if (roundInfo.playerChoice == roundInfo.computerChoice) {
        roundInfo.roundWinner = "Draw";
        gameStats.drawTimes++;
        changeScreenColor("yellow");
    }
    else {
        roundInfo.roundWinner = "Computer";
        gameStats.computerWins++;
        changeScreenColor("red");
    }
}

void determineGameWinner(GameStats& gameStats) {
    if (gameStats.playerWins > gameStats.computerWins) {
        gameStats.winner = "Player";
    }
    else if (gameStats.computerWins > gameStats.playerWins) {
        gameStats.winner = "Computer";
    }
    else {
        gameStats.winner = "Draw";
    }
}


bool playAgain() {
    char play;
    cout << "Do you want to play again? (y/n): ";
    cin >> play;
    return (play == 'y' || play == 'Y');
}

void playGame() {
    GameStats gameStats;
    cout << "Enter the number of rounds to play: ";
    cin >> gameStats.totalRounds;

    for (int i = 0; i < gameStats.totalRounds; i++) {
        resetScreen();
        cout << "\n========= ROUND " << i + 1 << " =========\n";

        RoundInfo roundInfo;
        roundInfo.playerChoice = getPlayerChoice();
        roundInfo.computerChoice = getComputerChoice();

        determineRoundWinner(roundInfo, gameStats);
        displayRoundResult(roundInfo, i + 1);

        Sleep(2000);
    }

    determineGameWinner(gameStats);
    displayFinalResults(gameStats);
}

int main() {
    srand(unsigned(time(0)));  
    bool play = true;

    while (play) {
        playGame();
        play = playAgain();
    }

    return 0;
}
