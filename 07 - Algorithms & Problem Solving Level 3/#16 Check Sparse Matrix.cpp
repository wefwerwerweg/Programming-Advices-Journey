// #16 Check Sparse Matrix
// https://programmingadvices.com/courses/1869980/lectures/42442218/comments/25839386

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

bool IsSparseMatrix(int matrix[3][3], short rows, short cols)
{
	int zeroCount = 0;
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			if (matrix[i][j] == 0) zeroCount++;
	
	if (zeroCount > (rows * cols) / 2) return true;
	else return false;
}

int main()
{
	int matrix[3][3] = { {0,0,12},{9,9,0},{0,0,9} };

	cout << "Matrix:\n";
	PrintMatrix(matrix, 3, 3);	

	if (IsSparseMatrix(matrix, 3, 3))
		cout << "\nYes: It is sparse.\n";
	else cout << "\nNo: It is NOT sparse.\n";

	return 0;
}
