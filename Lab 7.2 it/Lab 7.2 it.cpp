#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
void SearchEl(int** a, const int n, int& minAboveDiagonal, int& maxBelowDiagonal, int& sum);
int main()
{
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int n;
	cout << "n = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	Create(a, n, Low, High);
	Print(a, n);
	int min, max, sum;
	SearchEl(a, n, min, max, sum);
	cout << "Minimal number: " << min << endl;
	cout << "Maximal number: " << max << endl;
	cout << "Sum of numbers: " << sum;
		for (int i = 0; i < n; i++)
			delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

void SearchEl(int** a, const int n, int& minAboveSecondaryDiagonal, int& maxBelowSecondaryDiagonal, int& sum)
{
	minAboveSecondaryDiagonal = a[0][n - 1];
	maxBelowSecondaryDiagonal = a[n - 1][0];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i + j < n - 1) // Елементи над побічною діагоналлю
			{
				if (a[i][j] < minAboveSecondaryDiagonal)
				{
					minAboveSecondaryDiagonal = a[i][j];
				}
			}
			else if (i + j > n - 1) // Елементи під побічною діагоналлю
			{
				if (a[i][j] > maxBelowSecondaryDiagonal)
				{
					maxBelowSecondaryDiagonal = a[i][j];
				}
			}
		}
	}

	sum = minAboveSecondaryDiagonal + maxBelowSecondaryDiagonal;
}