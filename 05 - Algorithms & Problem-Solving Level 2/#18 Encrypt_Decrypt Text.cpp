// Encrypt/Decrypt Text
// https://programmingadvices.com/courses/1811531/lectures/41359655/comments/25775864

#include <iostream>

using namespace std;

string Encrypt(string text)
{
	string encrypted = "";
	for (int i = 0; i < text.length(); i++)
		encrypted += (text[i] + 1);
	return encrypted;
}

string Decrypt(string text)
{
	string decrypted = "";
	for (int i = 0; i < text.length(); i++)
		decrypted += (text[i] - 1);
	return decrypted;
}

int main()
{
	string text;
	cout << "Enter Text: ";
	cin >> text;
	string encrypted = Encrypt(text);

	cout << "\nText Before Encryption: " << text << endl;
	cout << "Text After  Encryption: " << encrypted << endl;
	cout << "Text After  Decryption: " << Decrypt(encrypted) << endl;
}