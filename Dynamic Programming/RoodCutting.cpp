// #include<bits/stdc++.h>
// using namespace std;
// #define MAX_SIZE 50

// int calculateMinCost(int rodLength, int numCuts, int cuts[]) {
//     sort(cuts, cuts + numCuts); // Sort cut positions

//     int totalCost = rodLength; // Initialize with rod's length

//     // Calculate the cost for each segment and accumulate the total cost
//     for (int i = 0; i < numCuts; i++) {
//         if (i == 0) {
//             totalCost += cuts[i]; // Add the cost for the first segment
//         } else {
//             totalCost += cuts[i] - cuts[i - 1]; // Add the cost for segments between cuts
//         }
//     }

//     // Add the cost for the last segment
//     totalCost += rodLength - cuts[numCuts - 1];

//     return totalCost;
// }

// int main() {
//     int rodLength, numCuts;
//     cin >> rodLength >> numCuts;
//     int cuts[MAX_SIZE];

//     for (int i = 0; i < numCuts; i++) {
//         cin >> cuts[i];
//     }

//     // Calculate the minimum cost for cutting the rod
//     int minCost = calculateMinCost(rodLength, numCuts, cuts);

//     cout << "Minimum cost for cutting the rod: " << minCost << endl;

//     return 0;
// }


#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

#define MAX_SIZE 50

int calculateMinCost(int rodLength, int numCuts, int cuts[]) {
    sort(cuts, cuts + numCuts); // Sort cut positions

    int dp[MAX_SIZE][MAX_SIZE]; // DP array for memoization
    for (int i = 0; i <= numCuts; i++) {
        for (int j = 0; j <= numCuts; j++) {
            dp[i][j] = INT_MAX; // Initialize with maximum value
        }
    }

    // Calculate the cost for each segment and store the minimum cost in dp
    for (int len = 1; len <= numCuts + 1; len++) {
        for (int i = 0; i + len <= numCuts + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = 0;

            int left = (i == 0) ? 0 : cuts[i - 1];
            int right = (j == numCuts) ? rodLength : cuts[j];

            for (int k = i; k <= j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + right - left);
            }
        }
    }

    return dp[0][numCuts];
}

int main() {
    int rodLength, numCuts;
    cin >> rodLength >> numCuts;
    int cuts[MAX_SIZE];

    for (int i = 0; i < numCuts; i++) {
        cin >> cuts[i];
    }

    // Calculate the minimum cost for cutting the rod
    int minCost = calculateMinCost(rodLength, numCuts, cuts);

    cout << "Minimum cost for cutting the rod: " << minCost << endl;

    return 0;
}
