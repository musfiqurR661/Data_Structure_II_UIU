#include <bits/stdc++.h>

using namespace std;

int funtion(int coin[], int n, int amount)
{

  sort(coin,coin+n);
  
    int DP[n + 1][amount + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (i == 0 || j == 0)
            {
                DP[i][j] = 0;
            }
            else if(j < coin[i - 1])
            {
            
                DP[i][j] = DP[i - 1][j];
                
            }

            else
            {
                DP[i][j] = max(DP[i - 1][j], 1 + DP[i - 1][j - coin[i - 1]]);
            }
        }
    }
    return DP[n][amount];
}

int main()
{
    int n, amount;
    cout << "How many coins amount: ";
    cin >> n >> amount;
    //cin >> n;
    int coin[n];
    cout<<endl<<"coins are: ";
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
  
    //cout<<endl<<"amount: ";
    //cin>>amount;
    for (int i = 0; i < n; i++)
    {
        cout<< coin[i]<<" ";
    }

    
    cout << "print: " << funtion(coin, n, amount);

    return 0;
}
