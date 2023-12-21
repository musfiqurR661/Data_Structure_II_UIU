#include<bits/stdc++.h>
using namespace std;


void sumODD_EVEN(int start, int end, int &evenSUm, int &oddSum)
{

if(start>end) return;

if(start%2==0)
  evenSUm+=start;
else
  oddSum+=start;

  sumODD_EVEN(start+1, end, evenSUm, oddSum);

}

int main()
{
    int start, end;
    cin>> start >> end;

    int evenSUm=0;
    int oddSum=0;

    sumODD_EVEN(start, end, evenSUm, oddSum);
    cout<<"Even SUM: "<<evenSUm<<endl;
    cout<<"odd SUM: "<<oddSum<<endl;
    return 0;
}