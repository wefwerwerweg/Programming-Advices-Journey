// Problem: Multiplication Table from 1 to 10
// Coded By: @X99099

#include <iostream>
using namespace std;

void PrintTableHeader() {
    cout << "\n\n\t\t\t Multiplication Table From 1 to 10\n\n\t";
    
    for (int i = 1; i <= 10; i++)
        cout << i << "\t";

    cout << "\n___________________________________________________________________________________\n";
}

string ColumnSeparator(int i) {
    return (i < 10) ? "   |" : "  |";
}

void PrintMultiplicationTable() {
    PrintTableHeader();

    for (int i = 1; i <= 10; i++) {
        cout << " " << i << ColumnSeparator(i) << "\t";

        for (int j = 1; j <= 10; j++)
            cout << i * j << "\t";

        cout << endl;
    }
}

int main() {
    PrintMultiplicationTable();
    return 0;
}
