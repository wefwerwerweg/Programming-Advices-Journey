// #1 3x3 Random Matrix

#include <iostream>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillMatrix(int matrix[3][3], short rows, short columns)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matrix[i][j] = RandomNumber(1, 100);
}

void PrintMatrix(int matrix[3][3], short rows, short columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << setw(3) << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}


int main()
{
	srand((unsigned)time(NULL));
	int matrix[3][3];
	FillMatrix(matrix, 3, 3);
	cout << "The Following Is A 3x3 Matrix:\n";
	PrintMatrix(matrix, 3, 3);
	return 0;
}