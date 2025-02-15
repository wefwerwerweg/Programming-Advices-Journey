// #20 Palindrome Matrix
// https://programmingadvices.com/courses/1869980/lectures/42442226/comments/25839622

#include <iostream>

using namespace std;

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
	for (short i = 0; i < rows; i++)
	{
		cout << " ";
		for (short j = 0; j < cols; j++)
		{
			printf("%02d\t", matrix[i][j]);
		}
		cout << endl;
	}
}

bool IsPalindromeMatrix(int matrix[3][3], short rows, short cols)
{
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols / 2; j++)
			if (matrix[i][j] != matrix[i][cols - j - 1])
				return false;
	return true;
}

int main()
{
	int matrix[3][3] = { {1,2,1},{5,5,5},{7,3,7} };

	cout << "Matrix:\n";
	PrintMatrix(matrix, 3, 3);

	if (IsPalindromeMatrix(matrix, 3, 3))
		cout << "\nYes: Matrix is palindrome.\n";
	else cout << "\nNo: Matrix is NOT palindrome.\n";

	return 0;
}
