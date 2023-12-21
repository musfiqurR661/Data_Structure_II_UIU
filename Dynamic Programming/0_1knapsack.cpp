#include <iostream>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n) {
    int K[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    
    // Print the DP array for visualization
    // Print the DP array for visualization
    cout << "DP Array:" << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            cout << K[i][j] << " ";
        }
        cout << endl;
    }

    return K[n][W];
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    int profit[n], weight[n];
    cout << "Enter profits for each item: ";
    for (int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    cout << "Enter weights for each item: ";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    int W;
    cout << "Enter the knapsack capacity: ";
    cin >> W;

    cout << "Maximum value in knapsack: " << knapSack(W, weight, profit, n);

    return 0;
}
