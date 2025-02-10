// Stone, Paper, Scissors
// https://programmingadvices.com/courses/1811531/lectures/41411121/comments/25797491

#include <iostream>

using namespace std;

enum Choices { Stone = 1, Paper = 2, Scissors = 3 };

struct Results
{
	int rounds;
	int plrChoice;
	int pcChoice;
	int plrWins;
	int pcWins;
	int draws;
};

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void ResetGame(Results& GameResults)
{
	GameResults.plrWins = 0;
	GameResults.pcWins = 0;
	GameResults.draws = 0;
	system("color 0F");
	system("cls");
}

void GetRounds(int& rounds)
{
	do
	{
		cout << "How Many Rounds From 1 To 10?: ";
		cin >> rounds;
	} while (rounds < 1 || rounds > 10);
}

void MakeChoices(int& plrChoice, int& pcChoice)
{
	do
	{
		cout << "Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
		cin >> plrChoice;
	} while (plrChoice < 1 || plrChoice > 3);

	pcChoice = RandomNumber(1, 3);
}

string CheckChoice(int choice)
{
	switch (choice)
	{
	case Choices::Stone:
		return "Stone";
		break;
	case Choices::Paper:
		return "Paper";
		break;
	case Choices::Scissors:
		return "Scissors";
		break;
	}
}

string RoundWinner(Results& GameResults)
{
	int result = GameResults.plrChoice - GameResults.pcChoice;
	if (result == 0)
	{
		GameResults.draws++;
		system("color 6F");
		return "[No Winner]";
	}
	else if (result == 1 || result == -2)
	{
		GameResults.plrWins++;
		system("color 2F");
		return "[Player]";
	}
	else
	{
		GameResults.pcWins++;
		system("color 4F");
		cout << '\a';
		return "[Computer]";
	}
}

string GameWinner(Results GameResults)
{
	if (GameResults.plrWins == GameResults.pcWins)
	{
		system("color 6F");
		return "No Winner";
	}
	else if (GameResults.plrWins > GameResults.pcWins)
	{
		system("color 2F");
		return "Player";
	}
	else
	{
		system("color 4F");
		cout << '\a';
		return "Computer";
	}
}

void PrintResults(Results GameResults)
{
	cout << "\n\t\t__________________________________________________________\n\n";
	cout << "\t\t\t\t[[[ G A M E | O V E R ]]]\n";
	cout << "\t\t__________________________________________________________\n\n";
	cout << "\t\t_____________________[ Game Results ]_____________________\n\n";
	cout << "\t\tGame Rounds   : " << GameResults.rounds << endl;
	cout << "\t\tPlayer Wins   : " << GameResults.plrWins << endl;
	cout << "\t\tComputer Wins : " << GameResults.pcWins << endl;
	cout << "\t\tDraws Times   : " << GameResults.draws << endl;
	cout << "\t\tFinal Winner  : " << GameWinner(GameResults) << endl;
	cout << "\t\t__________________________________________________________\n\n";
}

bool PlayAgain()
{
	char again;
	cout << "\t\tDo You Want To Play Again? Y/N? ";
	cin >> again;

	if (again == 'Y' || again == 'y') return true;
	else return false;
}

void StartGame(Results& GameResults)
{
	ResetGame(GameResults);
	GetRounds(GameResults.rounds);

	for (int i = 1; i <= GameResults.rounds; i++)
	{
		cout << "\nRound [" << i << "] Begins:\n\n";
		MakeChoices(GameResults.plrChoice, GameResults.pcChoice);
		cout << "\n____________Round [" << i << "]____________\n";
		cout << "\nPlayer   Choice: " << CheckChoice(GameResults.plrChoice);
		cout << "\nComputer Choice: " << CheckChoice(GameResults.pcChoice);
		cout << "\nRound    Winner: " << RoundWinner(GameResults);
		cout << "\n_________________________________\n";
	}

	PrintResults(GameResults);
}

int main()
{
	srand((unsigned)time(NULL));
	Results GameResults;

	do StartGame(GameResults);
	while (PlayAgain());
}