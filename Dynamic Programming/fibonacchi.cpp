#include <bits/stdc++.h>
using namespace std;
#define SIZE 207
#define NOT_SET -1
typedef long long int;

int cache[SIZE];
int fibonacci(int n)
{    //reuse cache
    if (cache[n] != NOT_SET)
        return cache[n];

    if (n <= 1)
        return n;
    else
    {
        int friend1 = fibonacci(n - 1);
        int friend2 = fibonacci(n - 2);

        int result = friend1 + friend2;
        cache[n] = result;//store
        return result;
    }
}
void printArray(int cache[], int n)
{
    for (int i = 0; i < n; i++)

    {
        cout << cache[i] << " ";
    }
}
int main()
{
    // cout << fibonacci(6) << endl;
    memset(cache, NOT_SET, sizeof(cache));
    printArray(cache, SIZE);
    int result = fibonacci(47);
    printArray(cache, SIZE);

    return 0;
}