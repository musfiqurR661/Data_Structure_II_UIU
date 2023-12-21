#include <iostream>
#include <climits>

using namespace std;

int minCoins(int coins[], int numCoins, int amount) {
    int dp[amount + 1];
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        dp[i] = INT_MAX;
        for (int j = 0; j < numCoins; ++j) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    if (dp[amount] == INT_MAX) {
        return -1;
    } else {
        return dp[amount];
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
