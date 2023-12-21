#include <bits/stdc++.h>
using namespace std;

typedef struct Structure
{
	int eachLandArea = 0;
} Str;

Str dpTable[100000];
bool compare(const Str &a, const Str &b)
{
	return a.eachLandArea < b.eachLandArea;
}

bool landCanBeDividedEqually(int numberOfLand, int sumOfArray)
{
	if (sumOfArray % 2 != 0)
	{
		cout << "NO" << endl;
		return false;
	}

	int halfProperty = sumOfArray / 2;

	sort(dpTable, dpTable + numberOfLand, compare);

	vector<vector<bool>> dp;
	for (int i = 0; i <= numberOfLand; ++i)
	{
		vector<bool> row;
		for (int j = 0; j <= halfProperty; ++j)
		{
			row.push_back(false);
		}
		dp.push_back(row);
	}
	// Fill the DP array
	for (int i = 0; i <= numberOfLand; i++)
	{
		dp[i][0] = true; // 0 sum is possible with an empty set
	}

	for (int i = 1; i <= numberOfLand; i++)
	{
		for (int j = 1; j <= halfProperty; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= dpTable[i - 1].eachLandArea)
			{
				if (dp[i - 1][j - dpTable[i - 1].eachLandArea])
				{
					dp[i][j] = true;
				}
				else
				{
					dp[i][j] = dp[i][j];
				}
			}
		}
	}

	if (dp[numberOfLand][halfProperty])
	{
		cout << "YES" << endl;
		return true; 
	}
	else
	{
		cout << "NO" << endl;
		return false; 
	}
}

int main()
{
	int numberOfLand;
	cin >> numberOfLand;

	unsigned long long int sumOfArray = 0;
	for (int i = 0; i < numberOfLand; i++)
	{
		int temp;
		cin >> temp;
		dpTable[i].eachLandArea = temp;
		sumOfArray += temp;
	}

	landCanBeDividedEqually(numberOfLand, sumOfArray);

	return 0;
}
