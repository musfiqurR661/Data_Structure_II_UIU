#include <bits/stdc++.h>
using namespace std;

int KthElement(int *arr1, int *arr2, int *end1, int *end2, int k)
{
    if (arr1 == end1)
        return arr2[k];
    if (arr2 == end2)
        return arr1[k];
    int mid1 = (end1 - arr1) / 2;
    int mid2 = (end2 - arr2) / 2;
    if (mid1 + mid2 < k)
    {
        if (arr1[mid1] > arr2[mid2])
            return KthElement(arr1, arr2 + mid2 + 1, end1, end2,
                              k - mid2 - 1);
        else
            return KthElement(arr1 + mid1 + 1, arr2, end1, end2,
                              k - mid1 - 1);
    }
    else
    {
        if (arr1[mid1] > arr2[mid2])
            return KthElement(arr1, arr2, arr1 + mid1, end2, k);
        else
            return KthElement(arr1, arr2, end1, arr2 + mid2, k);
    }
}

int main()
{
    int n;
    cin >> n;
    int ar1[n];
    for (int i = 0; i < n; i++)

    {
        cin >> ar1[i];
    }

    int m;
    cin >> m;
    int ar2[m];
    for (int i = 0; i < m; i++)

    {
        cin >> ar2[i];
    }
    int k;
    cin >> k;
    cout << KthElement(ar1, ar2, ar1 + n, ar2 + m, k - 1);
    return 0;
}