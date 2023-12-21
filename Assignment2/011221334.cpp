#include <bits/stdc++.h>
using namespace std;

bool canDivideEqually(int n, vector<int> &lands)
{
    int totalArea = 0;

    for (int i = 0; i < n; i++)
    {
        totalArea += lands[i];
    }
   
     sort(lands.begin(), lands.end()); 
   /*
   for (int i = 0; i < n; i++)
    {
        cout << lands[i] << " ";
    }
   */

    //  if any individual land area is greater than half of the total area
    for (int i = 0; i < n; i++)
    {
        if (lands[i] > totalArea / 2)
        {
            cout << "NO" << endl;
            return false;
        }
    }

    // Check whether even or odd
    if (totalArea % 2 != 0)
    {
        cout << "NO" << endl;
        return false;
    }

    int halfArea = totalArea / 2; 

    vector<vector<int>> dp(n + 1, vector<int>(halfArea + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= halfArea; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (i - 1 == 0)
            {
                if (lands[i - 1] <= j)
                {
                    dp[i][j] = lands[i - 1];
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
            else
            {
                int sumWithCurrentLand = 0;
                if (lands[i - 1] <= j)
                {
                    sumWithCurrentLand = dp[i - 1][j - lands[i - 1]] + lands[i - 1];
                }
                int sumWithoutCurrentLand = dp[i - 1][j];
                if (sumWithCurrentLand > sumWithoutCurrentLand)
                {
                    dp[i][j] = sumWithCurrentLand;
                }
                else
                {
                    dp[i][j] = sumWithoutCurrentLand;
                }
            }
        }
    }
    /*// Print the DP array for visualization
    cout << "DP Array:" << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= halfArea; j++) {                 
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */

    if (dp[n][halfArea] == halfArea)
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
    int n;
    cin >> n;

    vector<int> lands(n);
    for (int i = 0; i < n; i++)
    {
        cin >> lands[i];
    }

    canDivideEqually(n, lands);

    return 0;
}