#include <bits/stdc++.h>
using namespace std;

int binSearchDnC(int arr[], int l, int r, int x)
{

    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
        {
            return mid;
        }
        if (arr[mid] > x)
        {
            return binSearchDnC(arr, l, mid - 1, x);
        }
        return binSearchDnC(arr, mid + 1, r, x);
    }
    return -1;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main()
{
    int n;
    cin >> n;
    int ar[100];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    int x;
    cin >> x;
    quickSort(ar, 0, n - 1);

    int result = binSearchDnC(ar, 0, n - 1, x);

    if (result == -1)
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << x << "found at index " << result << endl;
    }
    return 0;
}