#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool landCanBeDividedEqually(int numberOfLand, const vector<int>& landAreas) {
    unsigned long long int sumOfArray = 0;
    for (int area : landAreas) {
        sumOfArray += area;
    }

    if (sumOfArray % 2 != 0) {
        return false;
    }

    int halfProperty = sumOfArray / 2;

    vector<bool> dp(halfProperty + 1, false);
    dp[0] = true;

    for (int area : landAreas) {
        for (int j = halfProperty; j >= area; --j) {
            dp[j] = dp[j] || dp[j - area];
        }
    }

    return dp[halfProperty];
}

int main() {
    int numberOfLand;
    cin >> numberOfLand;

    vector<int> landAreas(numberOfLand);
    for (int i = 0; i < numberOfLand; i++) {
        cin >> landAreas[i];
    }

    if (landCanBeDividedEqually(numberOfLand, landAreas)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
