#include<bits/stdc++.h>

using namespace std;
void printDPTable(int dp[][11], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (dp[i][j] == INT_MAX)
            {
                cout << "INF ";
            }
            else
            {
                cout << dp[i][j] << "   ";
            }
        }
        cout << endl;
    }
}
//int dp[1000][1000];
int minCoins(int coins[], int numCoins, int amount)
{
   int dp[numCoins + 1][amount + 1];

    // Initialize the DP table
    for (int i = 0; i <= numCoins; ++i)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= amount; ++i)
    {
        dp[0][i] = INT_MAX;
    }

    for (int i = 1; i <= numCoins; ++i)
    {
        for (int j = 1; j <= amount; ++j)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] != INT_MAX ? dp[i][j - coins[i - 1]] + 1 : INT_MAX);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
   // cout << "DP Table:" << endl;
   printDPTable(dp, numCoins + 1, amount + 1);
    if (dp[numCoins][amount] == INT_MAX)
    {
        return -1;
    }
    else
    {
        return dp[numCoins][amount];
    }
}

int main()
{
    int numCoins;
    cout << "Enter the number of coin denominations: ";
    cin >> numCoins;

    int coinDenominations[numCoins];
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < numCoins; ++i)
    {
        cin >> coinDenominations[i];
    }

    int changeAmount;
    cout << "Enter the amount for which change is needed: ";
    cin >> changeAmount;

    int result = minCoins(coinDenominations, numCoins, changeAmount);
    cout << "The minimum number of coins needed for " << changeAmount << " cents is " << result << "." << endl;

    return 0;
}
