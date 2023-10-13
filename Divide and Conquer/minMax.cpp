#include<bits/stdc++.h>
using namespace std;

int minMax(int arr[],int n)
{
    int min =arr[0];
    int max =arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i <n; i++)
      {
        cin >> arr[i];
      }
      int arz=minMax(arr,n);
      printf("%d %d\n", min,max);
      return 0;
}
