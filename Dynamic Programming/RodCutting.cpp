#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rodCut(vector<int> P, int n) {
    vector<int> r(n + 1);
    r[0] = 0;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); // 2D vector for DP table

    for (int rodlen = 1; rodlen <= n; rodlen++) {
        r[rodlen] = INT_MIN;
        for (int cutlen = 1; cutlen <= rodlen; cutlen++) {
            if (cutlen <= P.size()) {
                r[rodlen] = max(r[rodlen], P[cutlen - 1] + r[rodlen - cutlen]);
              //  dp[rodlen][cutlen] = r[rodlen]; // Store the values in the DP table
            }
        }
    }

    // // Print the DP table
    // cout << "DP Table:" << endl;
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return r[n];
}

int main() {
    int Rl;
    cout << "Enter the Length of Rod: ";
    cin >> Rl;

    int k;
    cout << "Enter the number of cut points: ";
    cin >> k;

    vector<int> Pices(k);
    cout << "Enter the cut points: ";
    for (int i = 0; i < k; i++) {
        cin >> Pices[i];
    }

    sort(Pices.begin(), Pices.end()); // Sort the cut points

    int maxProfit = rodCut(Pices, Rl);
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
