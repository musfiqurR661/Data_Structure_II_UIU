#include<bits/stdc++.h>
using namespace std;

int KnapSack(int w[],int v[],int n,int c){//w=weight,v=value,n=number of items,c=capacity
    int dp[n+1][c+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=c;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(w[i-1]<=j){
                dp[i][j]=max(v[i-1]+dp[i-1][j-w[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][c];

}

int main(){
    
    int n, W;
    cin >> n >> W;
    int wt[n], val[n];

    for(int i=0; i<n; i++){
        cin >> wt[i] >> val[i];
    }

    cout << "Maximum Profit: " << KnapSack(wt, val, n, W) << endl;
    return 0;
}