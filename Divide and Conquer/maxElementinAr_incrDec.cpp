#include <bits/stdc++.h>
using namespace std;

int findMaximum_IncrDecr(int arr[], int high, int low)
{
    if (high == low)
        return arr[high];

    int mid = (high + low) / 2;

    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        return arr[mid];

    else if (arr[mid] < arr[mid + 1])
        return findMaximum_IncrDecr(arr, mid + 1, high);
    else
        return findMaximum_IncrDecr(arr, low, mid - 1);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)

    {

        cin >> arr[i];
    }

    cout << "The maximum element is " << findMaximum_IncrDecr(arr, 0, n - 1);
    return 0;
}