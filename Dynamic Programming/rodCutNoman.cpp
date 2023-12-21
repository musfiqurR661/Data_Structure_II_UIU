#include <bits/stdc++.h>

using namespace std;

int funtion(int weight[], int value[], int n, int capacity)
{
    int DP[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
            {
                DP[i][j] = 0;
            }
            else if (j < weight[i - 1])
                DP[i][j] = DP[i - 1][j];

            else
            {
                DP[i][j] = max(DP[i - 1][j], value[i - 1] + DP[i ][j - weight[i - 1]]);
            }
        }
    }
    return DP[n][capacity];
}

int main()
{
    int n, capacity;
    cout << "How many weight: ";
    cin >> n;
    cout << endl
         << "capacity: ";
    cin >> capacity;
    int weight[n], value[n];

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
    }
    cout << "print: " << funtion(weight, value, n, capacity);

    return 0;
}