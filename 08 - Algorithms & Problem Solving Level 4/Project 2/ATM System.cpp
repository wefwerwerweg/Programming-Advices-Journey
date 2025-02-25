// Project 2: ATM System
// https://programmingadvices.com/courses/1890122/lectures/43375774/comments/25911143

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

enum enMainMenuOptions
{
	eQuickWithdraw = 1, eNormalWithdraw = 2,
	eDeposit = 3, eCheckBalance = 4,
	eLogout = 5
};

enum enTransactionsTypes { Deposit, Withdraw };

void Login();
void MainMenu();
vector<stClient> LoadClientsDataFromFile(string fileName);

stClient currentLoggedInClient;
const string ClientsFileName = "Clients.txt";
vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

short ReadOptions(short optionsCount)
{
	short option;
	printf("Choose what do you want to do [1 to %d]: ", optionsCount);
	cin >> option;
	while (cin.fail() || option < 1 || option > optionsCount)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid option! Enter a valid option  : ";
		cin >> option;
	}
	return option;
}

vector<string> SplitString(string text, string delim)
{
	string sWord; // define a string variable & delimiter
	vector<string> vWords;
	short pos;

	while ((pos = text.find(delim)) != std::string::npos)
	{
		sWord = text.substr(0, pos); // store the word
		if (sWord != "") vWords.push_back(sWord);
		text.erase(0, pos + delim.length()); // erase() until positon and move to next word.
	}
	if (text != "") vWords.push_back(text); // include last word of the string.
	return vWords;
}

stClient ConvertClientLinetoRecord(string line, string delim = "#//#")
{
	vector<string> vClientData = SplitString(line, delim);
	stClient client;
	client.AccountNumber = vClientData[0];
	client.PinCode = vClientData[1];
	client.Name = vClientData[2];
	client.Phone = vClientData[3];
	client.AccountBalance = stod(vClientData[4]); //Cast string to double
	return client;
}

string ConvertClientRecordToLine(stClient& client, string delim = "#//#")
{
	string recordToLine =
		client.AccountNumber + delim
		+ client.PinCode + delim
		+ client.Name + delim
		+ client.Phone + delim
		+ to_string(client.AccountBalance);
	return recordToLine;
}

void SaveClientsDataToFile()
{
	fstream file;
	file.open(ClientsFileName, ios::out); // Overwrite old data
	if (file.is_open())
	{
		for (stClient& client : vClients)
		{
			if (client.AccountNumber == currentLoggedInClient.AccountNumber)
				file << ConvertClientRecordToLine(currentLoggedInClient) << endl;
			else file << ConvertClientRecordToLine(client) << endl;
		}
		file.close();
	}
}

vector<stClient> LoadClientsDataFromFile(string fileName)
{
	vector <stClient> vClients;
	fstream file;
	file.open(fileName, ios::in);

	if (file.is_open())
	{
		stClient client;
		string line;
		while (getline(file, line))
		{
			client = ConvertClientLinetoRecord(line);
			vClients.push_back(client);
		}
		file.close();
	}

	return vClients;
}

vector<stClient>::iterator FindClientByAccNum(string accNum)
{
	vector<stClient>::iterator iter;
	for (iter = vClients.begin(); iter != vClients.end(); iter++)
		if (iter->AccountNumber == accNum) break;
	return iter;
}

void DoTransaction(stClient& client, double amount, enTransactionsTypes transactionType)
{
	char answer;
	cout << "\n\nAre you sure you want to do this transaction [y/n]? ";
	cin >> answer;
	if (tolower(answer) == 'y')
	{
		if (transactionType == enTransactionsTypes::Deposit)
			client.AccountBalance += amount;
		else client.AccountBalance -= amount;
		SaveClientsDataToFile();
		cout << "\n\nDone successfully. New balance is: " << client.AccountBalance;
	}
}

void QuickWithdrawScreen()
{
	cout << "===========================================\n";
	cout << "\t  Quick Withdraw\n";
	cout << "===========================================\n";
	cout << "\t[1] 20\t\t[2] 50\n";
	cout << "\t[3] 100\t\t[4] 200\n";
	cout << "\t[5] 400\t\t[6] 600\n";
	cout << "\t[7] 800\t\t[8] 1000\n";
	cout << "\t[9] Exit\n";
	cout << "===========================================\n";
	cout << "Your Balance is " << currentLoggedInClient.AccountBalance;
	cout << endl;

	short option = ReadOptions(9);
	if (option == 9) return;

	short withdrawAmounts[] = {20, 50, 100, 200, 400, 600, 800, 1000};
	if (withdrawAmounts[option - 1] > currentLoggedInClient.AccountBalance)
	{
		cout << "\nThe amount exceeds your balance! Make anothe choice.\n";
		return;
	}
	DoTransaction(currentLoggedInClient, withdrawAmounts[option - 1], enTransactionsTypes::Withdraw);
}

void NormalWithdrawScreen()
{
	cout << "===========================================\n";
	cout << "\t  Normal Withdraw\n";
	cout << "===========================================\n";
	cout << "Account Balance: " << currentLoggedInClient.AccountBalance;

	double amount;
	cout << "\n\nEnter Amount Multiple of 5's: ";
	cin >> amount;

	while (cin.fail() || amount < 1 || (int)amount % 5
		|| currentLoggedInClient.AccountBalance < amount)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid! Enter Amount Multiple of 5's: ";
		cin >> amount;
	}

	DoTransaction(currentLoggedInClient, amount, enTransactionsTypes::Withdraw);
}

void DepositScreen()
{
	cout << "===========================================\n";
	cout << "\t  Deposit\n";
	cout << "===========================================\n";
	cout << "Account Balance: " << currentLoggedInClient.AccountBalance;

	double amount;
	cout << "\n\nEnter Amount To Deposit: ";
	cin >> amount;

	while (cin.fail() || amount < 1)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Amount! Enter Amount To Deposit: ";
		cin >> amount;
	}

	DoTransaction(currentLoggedInClient, amount, enTransactionsTypes::Deposit);
}

void BalanceScreen()
{
	cout << "===========================================\n";
	cout << "\t\tBalance\n";
	cout << "===========================================\n";
	cout << "\nAccount Balance: " << currentLoggedInClient.AccountBalance;
}

void GoBackToMainMenu()
{
	cout << "\n\nPress any key to go back to main menu...";
	system("pause>0");
	MainMenu();
}

void PerfromMainMenuOption(enMainMenuOptions option)
{
	system("cls");

	switch (option)
	{
	case enMainMenuOptions::eQuickWithdraw:
	{
		QuickWithdrawScreen();
		GoBackToMainMenu();
		break;
	}
	case enMainMenuOptions::eNormalWithdraw:
	{
		NormalWithdrawScreen();
		GoBackToMainMenu();
		break;
	}
	case enMainMenuOptions::eDeposit:
	{
		DepositScreen();
		GoBackToMainMenu();
		break;
	}
	case enMainMenuOptions::eCheckBalance:
	{
		BalanceScreen();
		GoBackToMainMenu();
		break;
	}
	case enMainMenuOptions::eLogout:
	{
		Login();
		break;
	}
	}
}

void MainMenu()
{
	system("cls");
	cout << "=========================================\n";
	cout << "\tATM Main Menu Screen\n";
	cout << "=========================================\n";
	cout << "\t[1] Quick Withdraw.\n";
	cout << "\t[2] Normal Withdraw.\n";
	cout << "\t[3] Deposit.\n";
	cout << "\t[4] Check Balance.\n";
	cout << "\t[5] Logout.\n";
	cout << "=========================================\n";
	PerfromMainMenuOption((enMainMenuOptions)ReadOptions(5));
}

void Login()
{
	bool loginFailed = false;
	string accNum, pinCode;
	do
	{
		system("cls");
		cout << "-------------------------------\n";
		cout << "\tLogin Screen";
		cout << "\n-------------------------------\n";
		if (loginFailed) cout << "Invalid AccountNumber/PinCode!\n";
		cout << "\nEnter Account Number: ";
		cin >> accNum;
		cout << "\nEnter Pin Code: ";
		cin >> pinCode;

		vector<stClient>::iterator iter = FindClientByAccNum(accNum);
		if (iter == vClients.end()) loginFailed = true; //user not found
		else if (iter->PinCode != pinCode) loginFailed = true;
		else
		{
			currentLoggedInClient = *iter;
			loginFailed = false;
		}
	} while (loginFailed);

	MainMenu();
}

int main()
{
	Login();
	return 0;
}
