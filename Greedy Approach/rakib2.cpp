#include<bits/stdc++.h>

using namespace std;



bool ispollStnShouldCancel(int votes[],int n,int OPcandidate){ 
    int mostVotes=votes[OPcandidate];
    for(int i=0;i<n-1;i++){
        if(votes[i]>=votes[OPcandidate]){
            return 0;
        }
    }
    return 1;
}

void findstnToCancel(int votes[][100],int n,int m){
    int OPcandidate=n-1;
    int stnToCancel=0;
    int cancelStn[m];
    for(int i=0; i<m;i++){
             if(ispollStnShouldCancel(votes[i],n,OPcandidate)){
                 cancelStn[stnToCancel]=i+1;
                 stnToCancel++;
          }


    }
cout<<stnToCancel<<endl;
for(int i=0;i<stnToCancel;i++){
    cout<<cancelStn[i]<<" ";

}
}
int main(){
    int n,m;
    cin>>n;
    cin>>m;
    int votes[m][100];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>votes[i][j];
        }
    }
    findstnToCancel(votes,n,m);
    return 0;


}