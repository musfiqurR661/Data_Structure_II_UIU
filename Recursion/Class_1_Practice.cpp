#include<bits/stdc++.h>
using namespace std;
int factorial(int n);
int fibonacchi( int n);
int sumOfSeris(int N,int i, int num1, int num2 );
int GCD(int a, int b);
int LMC(int a,int b);

int main()
{

    int n,a,b;
   cin>> n;
    /*cout<<factorial(n) << endl;
    for(int i =1 ;i<=n;i++)
    {
        cout<<fibonacchi(i)<<" ";
    }

  cout <<   sumOfSeris(n,1,1,3);
  */
  cin>> a>> b;
  cout<< GCD(a,b) <<endl;
  cout<< LMC(a,b);
    return 0;

}
int factorial(int n)
{

    if(n==0 || n==1)
        return 1;


    return n*factorial(n-1);

}
int fibonacchi(int n)
{

    if(n==1)
        return 0;
    if(n==2)
        return 1;

    return fibonacchi(n-1) +fibonacchi(n-2);

}
int sumOfSeris(int N,int i, int num1, int num2 )
{
    if(i==N)
        return num1*num2;


        return num1*num2+sumOfSeris(N, i+1, num1+1, num2+2);




}
int GCD(int a, int b)
{
    if(a==0)
    return b;
    if(b==0)
        return a;
    if(a>b)
        return GCD(a-b,b);
    else
        return GCD(a, b-a);
}
int LMC(int a,int b)
{
    return (a*b)/GCD(a,b);

}
