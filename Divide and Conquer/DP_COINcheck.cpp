#include <bits/stdc++.h>

using namespace std;
void printDPTable(int **dp, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (dp[i][j] == INT_MAX) {
                cout << "INF ";
            } else {
                cout << dp[i][j] << "   ";
            }
        }
        cout << endl;
    }
}

int minCoins(int coins[], int numCoins, int amount) {
    int dp[numCoins + 1][amount + 1];
    int selectedCoins[numCoins + 1][amount + 1];

    // Initialize the DP table
    for (int i = 0; i <= numCoins; ++i) {
        dp[i][0] = 0;
        selectedCoins[i][0] = 0;
    }
    for (int i = 1; i <= amount; ++i) {
        dp[0][i] = INT_MAX;
        selectedCoins[0][i] = -1;
    }

    for (int i = 1; i <= numCoins; ++i) {
        for (int j = 1; j <= amount; ++j) {
            if (coins[i - 1] <= j) {
                if (dp[i][j - coins[i - 1]] != INT_MAX && dp[i][j - coins[i - 1]] + 1 < dp[i - 1][j]) {
                    dp[i][j] = dp[i][j - coins[i - 1]] + 1;
                    selectedCoins[i][j] = i - 1;
                } else {
                    dp[i][j] = dp[i - 1][j];
                    selectedCoins[i][j] = selectedCoins[i - 1][j];
                }
            } else {
                dp[i][j] = dp[i - 1][j];
                selectedCoins[i][j] = selectedCoins[i - 1][j];
            }
        }
    }

    // Output the coins used
    int i = numCoins;
    int j = amount;
    cout << "Coins used: ";
    while (j > 0 && i > 0) {
        if (selectedCoins[i][j] != selectedCoins[i - 1][j]) {
            cout << coins[i - 1] << " ";
            j -= coins[i - 1];
        } else {
            --i;
        }
    }
    cout << endl;
// Initialize the DP table
for (int i = 0; i <= numCoins; ++i) {
    dp[i][0] = 0;  // Set the first column to 0
    selectedCoins[i][0] = 0;
    for (int j = 1; j <= amount; ++j) {
        dp[i][j] = INT_MAX;  // Initialize other columns to INT_MAX
        selectedCoins[i][j] = -1;
    }
}



   printDPTable((int **)dp, numCoins + 1, amount + 1);

    if (dp[numCoins][amount] == INT_MAX) {
        return -1;
    } else {
        return dp[numCoins][amount];
    }
}

int main() {
    int numCoins;
    cout << "Enter the number of coin denominations: ";
    cin >> numCoins;

    int coinDenominations[numCoins];
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < numCoins; ++i) {
        cin >> coinDenominations[i];
    }

    int changeAmount;
    cout << "Enter the amount for which change is needed: ";
    cin >> changeAmount;

    int result = minCoins(coinDenominations, numCoins, changeAmount);
    cout << "The minimum number of coins needed for " << changeAmount << " cents is " << result << "." << endl;

    return 0;
}
