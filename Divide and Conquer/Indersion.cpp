#include <iostream>
using namespace std;

long long countInversions(int arr[], int left, int mid, int right) {
    int sizeLeft = mid - left + 1;
    int sizeRight = right - mid;

    int leftArr[sizeLeft], rightArr[sizeRight];

    for (int i = 0; i < sizeLeft; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < sizeRight; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    long long inversions = 0;

    while (i < sizeLeft && j < sizeRight) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
            inversions += (sizeLeft - i);
        }
        k++;
    }

    while (i < sizeLeft) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < sizeRight) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    return inversions;
}

long long mergeSort(int arr[], int left, int right) {
    long long inversions = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        inversions += mergeSort(arr, left, mid);
        inversions += mergeSort(arr, mid + 1, right);

        inversions += countInversions(arr, left, mid, right);
    }
    return inversions;
}

int main() {
    int n;
    cin >> n;
    int array[n];

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    long long result = mergeSort(array, 0, n - 1);

    cout << "#inversions: " << result << endl;

    return 0;
}
