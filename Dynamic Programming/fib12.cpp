#include <bits/stdc++.h>
using namespace std;
#define SIZE 207
#define NOT_SET -1
// typedef long long int;

int cache[SIZE];
int fibonacci(int n)
{ // reuse cache
    if (cache[n] != NOT_SET)
        return cache[n]; 

    if (n <= 1)
    {
        cache[n] = n;
        return n;
    }
    else
    {
        int friend1 = fibonacci(n - 1);
        int friend2 = fibonacci(n - 2);

        int result = friend1 + friend2;
        cache[n] = result; // store
        return result;
    }
}

int main()
{
    
    memset(cache, NOT_SET, sizeof(cache));
    int n; 
    cin >> n;
    int result = fibonacci(n);
    cout << result << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << cache[i] << " ";
    }
    cout << endl;
    return 0;
}