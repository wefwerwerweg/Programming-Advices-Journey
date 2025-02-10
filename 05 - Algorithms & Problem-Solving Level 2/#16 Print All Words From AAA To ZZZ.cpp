// Print All Words From AAA To ZZZ
// https://programmingadvices.com/courses/1811531/lectures/41359121/comments/25775378

#include <iostream>

using namespace std;

int main()
{
	for (int i = 65; i <= 90; i++)
		for (int j = 65; j <= 90; j++)
			for (int k = 65; k <= 90; k++)
				cout << char(i) << char(j) << char(k) << endl;
}