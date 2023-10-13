#include <bits/stdc++.h>
using namespace std;

pair<int, int> divideAndConquerMinMax(int arr[], int low, int high) {
    if (low == high) {
        return {arr[low], arr[low]}; // Base case: Single element in the array
    }

    if (high - low == 1) {
        return (arr[low] < arr[high]) ? make_pair(arr[low], arr[high]) : make_pair(arr[high], arr[low]);
    }

    int mid = (low + high) / 2;

    // Divide the array into two parts and recursively find min and max
    pair<int, int> leftMinMax = divideAndConquerMinMax(arr, low, mid);
    pair<int, int> rightMinMax = divideAndConquerMinMax(arr, mid + 1, high);

    // Merge the results to find the overall min and max
    return {min(leftMinMax.first, rightMinMax.first), max(leftMinMax.second, rightMinMax.second)};
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    pair<int, int> result = divideAndConquerMinMax(arr, 0, n - 1);
    printf("Minimum: %d\nMaximum: %d\n", result.first, result.second);

    return 0;
}
