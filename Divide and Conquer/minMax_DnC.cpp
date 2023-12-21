// #include <bits/stdc++.h>
// using namespace std;

// pair<int, int> divideAndConquerMinMax(int arr[], int low, int high) {
//     if (low == high) {
//         return {arr[low], arr[low]}; // Base case: Single element in the array
//     }

//     if (high - low == 1) {
//         return (arr[low] < arr[high]) ? make_pair(arr[low], arr[high]) : make_pair(arr[high], arr[low]);
//     }

//     int mid = (low + high) / 2;

//     // Divide the array into two parts and recursively find min and max
//     pair<int, int> leftMinMax = divideAndConquerMinMax(arr, low, mid);
//     pair<int, int> rightMinMax = divideAndConquerMinMax(arr, mid + 1, high);

//     // Merge the results to find the overall min and max
//     return {min(leftMinMax.first, rightMinMax.first), max(leftMinMax.second, rightMinMax.second)};
// }

// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     pair<int, int> result = divideAndConquerMinMax(arr, 0, n - 1);
//     printf("Minimum: %d\nMaximum: %d\n", result.first, result.second);

//     return 0;
// }

#include <iostream>
#include <limits>

using namespace std;

void RMaxMin(double A[], int i, int j, double &fmax, double &fmin) {
    if (i == j) {
        fmax = A[i];
        fmin = A[i];
    } else if (j - i == 1) {
        fmax = max(A[i], A[j]);
        fmin = min(A[i], A[j]);
    } else {
        int mid = (i + j) / 2;
        double max1, min1, max2, min2;
        RMaxMin(A, i, mid, max1, min1);
        RMaxMin(A, mid + 1, j, max2, min2);

        fmax = max(max1, max2);
        fmin = min(min1, min2);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    double A[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    double maxVal, minVal;
    RMaxMin(A, 0, n - 1, maxVal, minVal);
    cout << "Minimum: " << minVal << endl;
    cout << "Maximum: " << maxVal << endl;

    return 0;
}
