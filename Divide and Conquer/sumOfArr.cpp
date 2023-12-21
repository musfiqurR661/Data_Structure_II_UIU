#include <iostream>
using namespace std;

int calcSum(int arr[], int left, int right) {
    if (left == right) {
        return arr[left];
    } else {
        int mid = left + (right - left) / 2;
        int leftSum = calcSum(arr, left, mid);
        int rightSum = calcSum(arr, mid + 1, right);
        return leftSum + rightSum;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int array[n];

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int sum = calcSum(array, 0, n - 1);

    cout << "Sum of array elements: " << sum << endl;

    return 0;
}
