#include<bits/stdc++.h>
using namespace std;

int multiply(int n1, int n2)
{
    if(n1==0 || n2==0)
    return 0;

    if(n2>0)
     return n1+multiply(n1,n2-1);
    else
      return -n1+multiply(n1,n2+1);




}




int main()
{
    int n1, n2;
    cin >> n1 >> n2;


    int result= multiply(n1,n2);

    cout << result << endl;
}