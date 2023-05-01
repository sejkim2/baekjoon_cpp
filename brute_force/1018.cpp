#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int compareWithBlack(char ** arr, string blackBoard[8], int n, int m)
{
	int count = 0;
	int col = n, row = m;

	for (int i = 0, col = n; i < 8; i++, col++)
	{
		for (int j = 0, row = m; j < 8; j++, row++)
		{
			if (blackBoard[i][j] != arr[col][row])
				count++;
		}
	}

	return count;
}

int compareWithWhite(char** arr, string whiteBoard[8], int n, int m)
{
	int count = 0;
	int col = n, row = m;

	for (int i = 0, col = n; i < 8; i++, col++)
	{
		for (int j = 0, row = m; j < 8; j++, row++)
		{
			if (whiteBoard[i][j] != arr[col][row])
				count++;
		}
	}

	return count;
}

int main()
{
	int n, m, Min = 99999, count = 0;
	cin >> n >> m;

	string startBlackBoard[8] = {
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB"
	};

	string startWhiteBoard[8] = {
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW"
	};

	char** arr = new char* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new char[m];
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	for (int i = 8; i <= n; i++)
	{
		for (int j = 8; j <= m; j++)
		{
			int black = compareWithBlack(arr, startBlackBoard, i - 8, j - 8);
			int white = compareWithWhite(arr, startWhiteBoard, i - 8, j - 8);

			int tmp = min(black, white);
			Min = min(tmp, Min);
		}
	}

	cout << Min;

	for (int i = 0; i < n; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}