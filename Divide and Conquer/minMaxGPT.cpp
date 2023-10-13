#include<bits/stdc++.h>
using namespace std;

pair<int, int> minMax(int arr[], int n)
{
    int min_val = arr[0];
    int max_val = arr[0];
    
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max_val)
        {
            max_val = arr[i];
        }
        if(arr[i] < min_val)
        {
            min_val = arr[i];
        }
    }
    
    return make_pair(min_val, max_val);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    pair<int, int> result = minMax(arr, n);
    printf("%d %d\n", result.first, result.second);
    
    return 0;
}
