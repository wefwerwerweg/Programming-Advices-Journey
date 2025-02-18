// #46 Add Clients To File
// https://programmingadvices.com/courses/1869980/lectures/42845426/comments/25857271

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
const string ClientsFileName = "Clients.txt";

struct strClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

strClient NewClient()
{
	strClient client;
	cout << "Enter Account Number: ";
	getline(cin >> ws, client.AccountNumber);
	cout << "Enter Pin Code: ";
	getline(cin, client.PinCode);
	cout << "Enter Name: ";
	getline(cin, client.Name);
	cout << "Enter Phone: ";
	getline(cin, client.Phone);
	cout << "Enter Account Balance: ";
	cin >> client.AccountBalance;
	return client;
}

string ConvertRecordToLine(strClient client, string delim = "#//#")
{
	string recordToLine =
		client.AccountNumber + delim
		+ client.PinCode + delim
		+ client.Name + delim
		+ client.Phone + delim
		+ to_string(client.AccountBalance);
	return recordToLine;
}

void SaveClientToFile(string clientLine)
{
	fstream file;
	file.open(ClientsFileName, ios::out | ios::app);
	if (file.is_open())
	{
		file << clientLine << endl;
		file.close();
	}
}

int main()
{
	char addMore;
	do
	{
		system("cls");
		cout << "Adding New Client:\n\n";
		SaveClientToFile(ConvertRecordToLine(NewClient()));
		cout << "\nClient added successfully, do you want to add more clients [y/n]? ";
		cin >> addMore;
	} while (tolower(addMore) == 'y');
	return 0;
}
