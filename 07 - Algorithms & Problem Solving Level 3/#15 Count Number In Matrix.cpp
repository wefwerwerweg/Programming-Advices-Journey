// #15 Count Number In Matrix
// https://programmingadvices.com/courses/1869980/lectures/42442216/comments/25839328

#include <iostream>

using namespace std;

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillMatrix(int matrix[3][3], short rows, short cols)
{
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			matrix[i][j] = RandomNumber(1, 10);
}

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

int CountNumInMatrix(int matrix[3][3], int num, short rows, short cols)\
{
	int count = 0;
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			if (matrix[i][j] == num) count++;
	return count;
}

int main()
{
	srand((unsigned)time(NULL));

	int matrix[3][3], num;
	FillMatrix(matrix, 3, 3);

	cout << "Matrix:\n";
	PrintMatrix(matrix, 3, 3);	

	cout << "\nEnter the number to count in matrix: ";
	cin >> num;
	cout << "\nNumber " << num << " count in matrix is " << CountNumInMatrix(matrix, num, 3, 3) << endl;

	return 0;
}
