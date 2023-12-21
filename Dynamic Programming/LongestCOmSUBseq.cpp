#include <bits/stdc++.h>
using namespace std;
// #define SIZE 1000
// #define int [100+1][100+1]

int LongestCS(string C, string D, int m, int n)
{
    int LS[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                LS[i][j] = 0;
            }
            else if (C[i-1] == D[j-1])
            {
                LS[i][j] = LS[i - 1][j - 1] + 1;
            }
            else
                LS[i][j] = max(LS[i - 1][j], LS[i][j - 1]);
        }
    }
   

    cout << "DP Array:" << endl;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << LS[i][j] << " ";
        }
        cout << endl;
    }
    return LS[m][n];
}
int main()
{
        string A, B;
        getline(cin, A); 
        getline(cin, B); 
        int m = A.size();
        int n = B.size();
        cout << m << endl;
        cout << n << endl;
    
    cout << "Length is" << LongestCS(A, B, m, n);

    return 0;
}

// let X = "AGGTAB";
// let Y = "GXTXAYB"
