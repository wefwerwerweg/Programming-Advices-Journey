// #45 Convert Record To Line
// https://programmingadvices.com/courses/1869980/lectures/42840484/comments/25857036

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct strClient
{
	string accountNumber;
	string pinCode;
	string name;
	string phone;
	double accountBalance;
};

strClient NewClient()
{
	strClient client;
	cout << "Enter Account Number: ";
	getline(cin, client.accountNumber);
	cout << "Enter Pin Code: ";
	getline(cin, client.pinCode);
	cout << "Enter Name: ";
	getline(cin, client.name);
	cout << "Enter Phone: ";
	getline(cin, client.phone);
	cout << "Enter Account Balance: ";
	cin >> client.accountBalance;
	return client;
}

string ConvertRecordToLine(strClient client, string delim = "#//#")
{
	string recordToLine = "";
	recordToLine += client.accountNumber + delim
		+ client.pinCode + delim
		+ client.name + delim
		+ client.phone + delim
		+ to_string(client.accountBalance);
	return recordToLine;
}

int main()
{
	cout << "Please Enter Client Data:\n\n";
	strClient client = NewClient();
	cout << "\n\nClient Record For Saving Is:\n";
	cout << ConvertRecordToLine(client) << endl;
	return 0;
}
