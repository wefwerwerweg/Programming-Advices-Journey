// Project 1: Bank Extension 2
// https://programmingadvices.com/courses/1890122/lectures/43372534/comments/25910588

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct stUser
{
	string UserName;
	string Password;
	int Permissions;
};

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
	eListClients = 1, eAddNewClient = 2,
	eDeleteClient = 3, eUpdateClient = 4,
	eFindClient = 5, eTransactions = 6,
	eManageUsers = 7, eLogout = 8
};

enum enTransactionsOptions
{
	eDeposit = 1, eWithdraw = 2,
	eTotalBalances = 3, eMainMenu = 4
};

enum enTransactionsTypes { Deposit, Withdraw };

enum enManageUsersOptions {
	eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
	eUpdateUser = 4, eFindUser = 5, eShowMainMenu = 6
};

enum enMainMenuPermissions {
	pAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
	pUpdateClient = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64
};

void Login();
void MainMenu();
void TransactionsMenu();
void ManageUsersMenu();
vector<stUser> LoadUsersDataFromFile(string fileName);
vector<stClient> LoadClientsDataFromFile(string fileName);

const string UsersFileName = "Users.txt";
const string ClientsFileName = "Clients.txt";
stUser currentLoggedInUser;
vector<stUser> vUsers = LoadUsersDataFromFile(UsersFileName);
vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

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

bool UserHavePermission(int userPermissions, enMainMenuPermissions permission)
{
	if (userPermissions == -1) return true;
	if ((userPermissions & permission) == permission) return true;
	return false;
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

stUser ConvertUserLinetoRecord(string line, string delim = "#//#")
{
	vector<string> vUserData = SplitString(line, delim);
	stUser user;
	user.UserName = vUserData[0];
	user.Password = vUserData[1];
	user.Permissions = stoi(vUserData[2]); //Cast string to int
	return user;
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

string ConvertUserRecordToLine(stUser& user, string delim = "#//#")
{
	string recordToLine =
		user.UserName + delim
		+ user.Password + delim
		+ to_string(user.Permissions);
	return recordToLine;
}

void PrintClientRecord(stClient& client)
{
	cout << "\nThe Following Are The Client Details:\n";
	cout << "------------------------------------";
	cout << "\nAccout Number  : " << client.AccountNumber;
	cout << "\nPin Code       : " << client.PinCode;
	cout << "\nName           : " << client.Name;
	cout << "\nPhone          : " << client.Phone;
	cout << "\nAccount Balance: " << client.AccountBalance;
	cout << "\n------------------------------------\n";
}

void PrintUserCard(stUser& user)
{
	cout << "\nThe Following Are The User Details:\n";
	cout << "-----------------------------------";
	cout << "\nUsername : " << user.UserName;
	cout << "\nPassword : " << user.Password;
	cout << "\nPermissions : " << user.Permissions;
	cout << "\n-----------------------------------\n";
}

void PrintAllUsersData(vector<stUser>& vUsers)
{
	cout << "\n\t\t\t\tUsers List (" << vUsers.size() << ") Client(s).";
	cout << "\n____________________________________________________";
	cout << "____________________________________________\n" << endl;
	cout << "| " << left << setw(20) << "UserName";
	cout << "| " << left << setw(20) << "Password";
	cout << "| " << left << setw(20) << "Permissions";
	cout << "\n____________________________________________________";
	cout << "____________________________________________\n" << endl;

	for (stUser& user : vUsers)
	{
		cout << "| " << setw(20) << left << user.UserName;
		cout << "| " << setw(20) << left << user.Password;
		cout << "| " << setw(20) << left << user.Permissions;
		cout << endl;
	}

	cout << "____________________________________________________";
	cout << "____________________________________________\n";
}

void PrintAllClientsData(vector<stClient>& vClients)
{
	cout << "\n\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout << "\n____________________________________________________";
	cout << "____________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n____________________________________________________";
	cout << "____________________________________________\n" << endl;

	for (stClient& client : vClients)
	{
		cout << "| " << setw(15) << left << client.AccountNumber;
		cout << "| " << setw(10) << left << client.PinCode;
		cout << "| " << setw(40) << left << client.Name;
		cout << "| " << setw(12) << left << client.Phone;
		cout << "| " << setw(12) << left << client.AccountBalance;
		cout << endl;
	}

	cout << "____________________________________________________";
	cout << "____________________________________________\n";
}

void SaveClientsDataToFile()
{
	fstream file;
	file.open(ClientsFileName, ios::out); // Overwrite old data
	if (file.is_open())
	{
		for (stClient& client : vClients)
			file << ConvertClientRecordToLine(client) << endl;
		file.close();
	}
}

void SaveUsersDataToFile()
{
	fstream file;
	file.open(UsersFileName, ios::out); // Overwrite old data
	if (file.is_open())
	{
		for (stUser& user : vUsers)
			file << ConvertUserRecordToLine(user) << endl;
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

vector<stUser> LoadUsersDataFromFile(string fileName)
{
	vector <stUser> vUsers;
	fstream file;
	file.open(fileName, ios::in);

	if (file.is_open())
	{
		stUser user;
		string line;
		while (getline(file, line))
		{
			user = ConvertUserLinetoRecord(line);
			vUsers.push_back(user);
		}
		file.close();
	}

	return vUsers;
}

vector<stClient>::iterator FindClientByAccNum(string accNum)
{
	vector<stClient>::iterator iter;
	for (iter = vClients.begin(); iter != vClients.end(); iter++)
		if (iter->AccountNumber == accNum) break;
	return iter;
}

vector<stUser>::iterator FindUser(string username)
{
	vector<stUser>::iterator iter;
	for (iter = vUsers.begin(); iter != vUsers.end(); iter++)
		if (iter->UserName == username) break;
	return iter;
}

stClient NewClient()
{
	stClient client;

	cout << "Adding New Client:\n\n";
	cout << "Enter Account Number: ";
	cin >> ws >> client.AccountNumber;
	while (FindClientByAccNum(client.AccountNumber) != vClients.end())
	{
		cout << "Client with account number (" << client.AccountNumber << ") already exists!\n";
		cout << "Enter Account Number: ";
		cin >> client.AccountNumber;
	}
	cout << "Enter Pin Code: ";
	cin >> client.PinCode;
	cout << "Enter Name: ";
	getline(cin >> ws, client.Name);
	cout << "Enter Phone: ";
	cin >> client.Phone;
	cout << "Enter Account Balance: ";
	cin >> client.AccountBalance;

	return client;
}

int AssignMainMenuPermissions()
{
	int permissions = 0;
	char answer;

	cout << "\nDo you want to give full access? y/n? ";
	cin >> answer;
	if (tolower(answer) == 'y') return -1;

	cout << "\nDo you want to give access to:\n";
	cout << "\nShow Clients List? y/n? ";
	cin >> answer;
	if (tolower(answer) == 'y')
		permissions |= enMainMenuPermissions::pListClients;

	cout << "\nAdd New Client? y/n? ";
	cin >> answer;
	if (tolower(answer) == 'y')
		permissions |= enMainMenuPermissions::pAddNewClient;

	cout << "\nDelete Client? y/n? ";
	cin >> answer;
	if (tolower(answer) == 'y')
		permissions |= enMainMenuPermissions::pDeleteClient;

	cout << "\nUpdate Client? y/n? ";
	cin >> answer;
	if (tolower(answer) == 'y')
		permissions |= enMainMenuPermissions::pUpdateClient;

	cout << "\nFind Client? y/n? ";
	cin >> answer;
	if (tolower(answer) == 'y')
		permissions |= enMainMenuPermissions::pFindClient;

	cout << "\nTransactions? y/n? ";
	cin >> answer;
	if (tolower(answer) == 'y')
		permissions |= enMainMenuPermissions::pTransactions;

	cout << "\nManage Users? y/n? ";
	cin >> answer;
	if (tolower(answer) == 'y')
		permissions |= enMainMenuPermissions::pManageUsers;

	return permissions;
}

stUser NewUser()
{
	stUser user;

	cout << "Adding New User:\n\n";
	cout << "Enter UserName: ";
	cin >> ws >> user.UserName;
	while (FindUser(user.UserName) != vUsers.end())
	{
		cout << "User with UserName (" << user.UserName << ") already exists!\n";
		cout << "Enter UserName: ";
		cin >> user.UserName;
	}
	cout << "Enter Password: ";
	cin >> ws >> user.Password;

	user.Permissions = AssignMainMenuPermissions();

	return user;
}

void DelClientByAccNum(string accNum)
{
	vector<stClient>::iterator iter = FindClientByAccNum(accNum);
	char confirmDel;

	if (iter != vClients.end())
	{
		PrintClientRecord(*iter);
		cout << "\nAre You Sure You Want To Delete This Client [y/n]? ";
		cin >> confirmDel;
		if (tolower(confirmDel) == 'y')
		{
			vClients.erase(iter);
			SaveClientsDataToFile();
			cout << "\nClient Deleted Successfully.\n";
		}
	}
	else cout << "\nThe Client With Account Number (" << accNum << ") Is Not Found.\n";
}

void DelUserByUserName(string username)
{
	vector<stUser>::iterator iter = FindUser(username);
	char confirmDel;

	if (iter != vUsers.end())
	{
		if (username == "Admin")
			cout << "\nThis User Can't Be Deleted!\n";
		else
		{
			PrintUserCard(*iter);
			cout << "\nAre You Sure You Want To Delete This User [y/n]? ";
			cin >> confirmDel;
			if (tolower(confirmDel) == 'y')
			{
				vUsers.erase(iter);
				SaveUsersDataToFile();
				cout << "\nUser Deleted Successfully.\n";
			}
		}
	}
	else cout << "\nThe User With UserName (" << username << ") Is Not Found.\n";
}

void UpdClientByAccNum(string accNum)
{
	vector<stClient>::iterator iter = FindClientByAccNum(accNum);
	char confirmUpd;

	if (iter != vClients.end())
	{
		PrintClientRecord(*iter);
		cout << "\nAre You Sure You Want To Update This Client [y/n]? ";
		cin >> confirmUpd;

		if (tolower(confirmUpd) == 'y')
		{
			cout << "\nEnter Pin Code: ";
			cin >> iter->PinCode;
			cout << "Enter Name: ";
			getline(cin >> ws, iter->Name);
			cout << "Enter Phone: ";
			cin >> iter->Phone;
			cout << "Enter Account Balance: ";
			cin >> iter->AccountBalance;

			SaveClientsDataToFile();
			cout << "\nClient Updated Successfully.\n";
		}
	}
	else cout << "\nThe Client With Account Number (" << accNum << ") Is Not Found.\n";
}

void UpdUserByUserName(string username)
{
	vector<stUser>::iterator iter = FindUser(username);
	char confirmUpd;

	if (iter != vUsers.end())
	{
		PrintUserCard(*iter);
		cout << "\nAre You Sure You Want To Update This User [y/n]? ";
		cin >> confirmUpd;

		if (tolower(confirmUpd) == 'y')
		{
			cout << "\nEnter New Password: ";
			cin >> ws >> iter->Password;
			iter->Permissions = AssignMainMenuPermissions();

			SaveUsersDataToFile();
			cout << "\nUser Updated Successfully.\n";
		}
	}
	else cout << "\nThe User With UserName (" << username << ") Is Not Found.\n";
}

void AddClientsScreen()
{
	stClient client;
	char addMore;

	do
	{
		system("cls");
		cout << "-----------------------------------\n";
		cout << "      Add New Clients Screen";
		cout << "\n-----------------------------------\n";
		vClients.push_back(NewClient());
		cout << "\nClient added successfully, do you want to add more clients [y/n]? ";
		cin >> addMore;
	} while (tolower(addMore) == 'y');

	SaveClientsDataToFile();
}

void AddUsersScreen()
{
	char addMore;

	do
	{
		system("cls");
		cout << "-----------------------------------\n";
		cout << "      Add New Users Screen";
		cout << "\n-----------------------------------\n";
		vUsers.push_back(NewUser());
		cout << "\nUser added successfully, do you want to add more users [y/n]? ";
		cin >> addMore;
	} while (tolower(addMore) == 'y');

	SaveUsersDataToFile();
}

void DeleteClientScreen()
{
	string accNum;
	cout << "-----------------------------------\n";
	cout << "\tDelete Client Screen";
	cout << "\n-----------------------------------\n";
	cout << "\nEnter Account Number: ";
	cin >> accNum;
	DelClientByAccNum(accNum);
}

void DeleteUserScreen()
{
	string username;
	cout << "-----------------------------------\n";
	cout << "\tDelete User Screen";
	cout << "\n-----------------------------------\n";
	cout << "\nEnter UserName: ";
	cin >> username;
	DelUserByUserName(username);
}

void UpdateClientScreen()
{
	string accNum;
	cout << "-----------------------------------\n";
	cout << "\tUpdate Client Info Screen";
	cout << "\n-----------------------------------\n";
	cout << "\nEnter Account Number: ";
	cin >> accNum;
	UpdClientByAccNum(accNum);
}

void UpdateUserScreen()
{
	string username;
	cout << "-----------------------------------\n";
	cout << "\tUpdate User Screen";
	cout << "\n-----------------------------------\n";
	cout << "\nEnter UserName: ";
	cin >> username;
	UpdUserByUserName(username);
}

void FindClientScreen()
{
	string accNum;
	vector<stClient>::iterator iter;
	cout << "-----------------------------------\n";
	cout << "\tFind Client Screen";
	cout << "\n-----------------------------------\n";
	cout << "\nEnter Account Number: ";
	cin >> accNum;
	iter = FindClientByAccNum(accNum);
	if (iter != vClients.end()) PrintClientRecord(*iter);
	else cout << "\nThe Client With Account Number (" << accNum << ") Is Not Found.\n";
}

void FindUserScreen()
{
	string username;
	vector<stUser>::iterator iter;
	cout << "-----------------------------------\n";
	cout << "\tFind User Screen";
	cout << "\n-----------------------------------\n";
	cout << "\nEnter UserName: ";
	cin >> username;
	iter = FindUser(username);
	if (iter != vUsers.end()) PrintUserCard(*iter);
	else cout << "\nThe User With UserName (" << username << ") Is Not Found.\n";
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

void DoTransactionsScreen(enTransactionsTypes transactionType)
{
	string accNum;
	vector<stClient>::iterator iter;

	cout << "-----------------------------------\n";
	if (transactionType == enTransactionsTypes::Deposit)
		cout << "\tDeposit Screen";
	else cout << "\tWithdraw Screen";
	cout << "\n-----------------------------------\n";
	cout << "\nEnter Account Number: ";
	cin >> accNum;
	while ((iter = FindClientByAccNum(accNum)) == vClients.end())
	{
		cout << "\nThe Client With Account Number (" << accNum << ") Is Not Found.\n";
		cout << "\nEnter Account Number: ";
		cin >> accNum;
	}
	stClient client = *iter;
	PrintClientRecord(client);

	double amount;
	if (transactionType == enTransactionsTypes::Deposit)
		cout << "\nEnter deposit amount: ";
	else cout << "\nEnter withdraw amount: ";
	cin >> amount;
	while (cin.fail() || amount < 1
		|| ((transactionType == enTransactionsTypes::Withdraw)
			&& (client.AccountBalance < amount)))
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid amount! Enter valid amount: ";
		cin >> amount;
	}
	DoTransaction(client, amount, transactionType);
}

void TotalBalancesScreen()
{
	cout << "\n\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
	cout << "\n____________________________________________________";
	cout << "____________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n____________________________________________________";
	cout << "____________________________________________\n" << endl;

	double TotalBalances = 0;
	if (vClients.size() == 0)
		cout << "\t\t\t\tNo Clients Available In The System!";
	else
		for (stClient& client : vClients)
		{
			cout << "| " << setw(15) << left << client.AccountNumber;
			cout << "| " << setw(40) << left << client.Name;
			cout << "| " << setw(12) << left << client.AccountBalance;
			TotalBalances += client.AccountBalance;
			cout << endl;
		}
	cout << "\n____________________________________________________";
	cout << "____________________________________________\n" << endl;
	cout << "\t\t\t\t\t\t\t\tTotal Balances = " << TotalBalances;
}

void AccessDenied()
{
	cout << "\n------------------------------------\n";
	cout << "Access Denied,\n";
	cout << "You Don't Have Permission To Do This,\n";
	cout << "Please Contact Your Admin.";
	cout << "\n------------------------------------\n";
}

enManageUsersOptions ReadManageUsersOption()
{
	cout << "Choose what do you want to do [1 to 6]: ";
	short option;
	cin >> option;
	while (cin.fail() || option < 1 || option > 6)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid option! Enter a valid option  : ";
		cin >> option;
	}
	return (enManageUsersOptions)option;
}

enTransactionsOptions ReadTransactionsOption()
{
	cout << "Choose what do you want to do [1 to 4]: ";
	short option;
	cin >> option;
	while (cin.fail() || option < 1 || option > 4)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid option! Enter a valid option  : ";
		cin >> option;
	}
	return (enTransactionsOptions)option;
}

enMainMenuOptions ReadMainMenuOption()
{
	cout << "Choose what do you want to do [1 to 8]: ";
	short option;
	cin >> option;
	while (cin.fail() || option < 1 || option > 8)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid option! Enter a valid option  : ";
		cin >> option;
	}
	return (enMainMenuOptions)option;
}

void GoBackToManageUsersMenu()
{
	cout << "\n\nPress any key to go back to manage users menu...";
	system("pause>0");
	ManageUsersMenu();
}

void GoBackToTransactionsMenu()
{
	cout << "\n\nPress any key to go back to transactions menu...";
	system("pause>0");
	TransactionsMenu();
}

void GoBackToMainMenu()
{
	cout << "\n\nPress any key to go back to main menu...";
	system("pause>0");
	MainMenu();
}

void PerfromTranactionsOption(enTransactionsOptions option)
{
	system("cls");

	switch (option)
	{
	case enTransactionsOptions::eDeposit:
	{
		DoTransactionsScreen(enTransactionsTypes::Deposit);
		GoBackToTransactionsMenu();
		break;
	}
	case enTransactionsOptions::eWithdraw:
	{
		DoTransactionsScreen(enTransactionsTypes::Withdraw);
		GoBackToTransactionsMenu();
		break;
	}
	case enTransactionsOptions::eTotalBalances:
	{
		TotalBalancesScreen();
		GoBackToTransactionsMenu();
		break;
	}
	case enTransactionsOptions::eMainMenu:
	{
		MainMenu();
		break;
	}
	}
}

void PerfromManageUsersOption(enManageUsersOptions option)
{
	system("cls");

	switch (option)
	{
	case enManageUsersOptions::eListUsers:
	{
		PrintAllUsersData(vUsers);
		GoBackToManageUsersMenu();
		break;
	}
	case enManageUsersOptions::eAddNewUser:
	{
		AddUsersScreen();
		GoBackToManageUsersMenu();
		break;
	}
	case enManageUsersOptions::eDeleteUser:
	{
		DeleteUserScreen();
		GoBackToManageUsersMenu();
		break;
	}
	case enManageUsersOptions::eUpdateUser:
	{
		UpdateUserScreen();
		GoBackToManageUsersMenu();
		break;
	}
	case enManageUsersOptions::eFindUser:
	{
		FindUserScreen();
		GoBackToManageUsersMenu();
		break;
	}
	case enManageUsersOptions::eShowMainMenu:
	{
		MainMenu();
		break;
	}
	}
}

void PerfromMainMenuOption(enMainMenuOptions option)
{
	system("cls");

	switch (option)
	{
	case enMainMenuOptions::eListClients:
	{
		if (UserHavePermission(currentLoggedInUser.Permissions,
			enMainMenuPermissions::pListClients))
			PrintAllClientsData(vClients);
		else AccessDenied();
		GoBackToMainMenu();
		break;
	}
	case enMainMenuOptions::eAddNewClient:
		if (UserHavePermission(currentLoggedInUser.Permissions,
			enMainMenuPermissions::pAddNewClient))
			AddClientsScreen();
		else AccessDenied();
		GoBackToMainMenu();
		break;
	case enMainMenuOptions::eDeleteClient:
		if (UserHavePermission(currentLoggedInUser.Permissions,
			enMainMenuPermissions::pDeleteClient))
			DeleteClientScreen();
		else AccessDenied();
		
		GoBackToMainMenu();
		break;
	case enMainMenuOptions::eUpdateClient:
		if (UserHavePermission(currentLoggedInUser.Permissions,
			enMainMenuPermissions::pUpdateClient))
			UpdateClientScreen();
		else AccessDenied();
		
		GoBackToMainMenu();
		break;
	case enMainMenuOptions::eFindClient:
		if (UserHavePermission(currentLoggedInUser.Permissions,
			enMainMenuPermissions::pFindClient))
			FindClientScreen();
		else AccessDenied();
		
		GoBackToMainMenu();
		break;
	case enMainMenuOptions::eTransactions:
		if (UserHavePermission(currentLoggedInUser.Permissions,
			enMainMenuPermissions::pTransactions))
			TransactionsMenu();
		else
		{
			AccessDenied(); 
			GoBackToMainMenu();
		}
		
		break;
	case enMainMenuOptions::eManageUsers:
		if (UserHavePermission(currentLoggedInUser.Permissions,
			enMainMenuPermissions::pManageUsers))
			ManageUsersMenu();
		else
		{
			AccessDenied();
			GoBackToMainMenu();
		}
		break;
	case enMainMenuOptions::eLogout:
		Login();
		break;
	}
}

void ManageUsersMenu()
{
	system("cls");
	cout << "===========================================\n";
	cout << "\tManage Users Menu Screen\n";
	cout << "===========================================\n";
	cout << "\t[1] List Users.\n";
	cout << "\t[2] Add New User.\n";
	cout << "\t[3] Delete User.\n";
	cout << "\t[4] Update User.\n";
	cout << "\t[5] Find User.\n";
	cout << "\t[6] Main Menu.\n";
	cout << "===========================================\n";
	PerfromManageUsersOption(ReadManageUsersOption());
}

void TransactionsMenu()
{
	system("cls");
	cout << "===========================================\n";
	cout << "\tTransactions Menu Screen\n";
	cout << "===========================================\n";
	cout << "\t[1] Deposit.\n";
	cout << "\t[2] Withdraw.\n";
	cout << "\t[3] Total Balances.\n";
	cout << "\t[4] Main Menu.\n";
	cout << "===========================================\n";
	PerfromTranactionsOption(ReadTransactionsOption());
}

void MainMenu()
{
	system("cls");
	cout << "=========================================\n";
	cout << "\t    Main Menu Screen\n";
	cout << "=========================================\n";
	cout << "\t[1] Show Clients List.\n";
	cout << "\t[2] Add New Client.\n";
	cout << "\t[3] Delete Client.\n";
	cout << "\t[4] Update Client Info.\n";
	cout << "\t[5] Find Client.\n";
	cout << "\t[6] Transactions.\n";
	cout << "\t[7] Manage Users.\n";
	cout << "\t[8] Logout.\n";
	cout << "=========================================\n";
	PerfromMainMenuOption(ReadMainMenuOption());
}

void Login()
{
	bool loginFailed = false;
	//string username, password;
	string username = "Admin", password = "1234";
	do
	{
		system("cls");
		cout << "-------------------------------\n";
		cout << "\tLogin Screen";
		cout << "\n-------------------------------\n";
		if (loginFailed) cout << "Invalid Username/Password!\n";
		cout << "\nEnter Username: ";
		//cin >> username;
		cout << "\nEnter Password: ";
		//cin >> password;

		vector<stUser>::iterator iter = FindUser(username);
		if (iter == vUsers.end()) loginFailed = true; //user not found
		else if (iter->Password != password) loginFailed = true;
		else
		{
			currentLoggedInUser = *iter;
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
