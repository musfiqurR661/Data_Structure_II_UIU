#include <iostream>
using namespace std;

int calcEvenSum(int arr[], int left, int right) {
    if (left == right) {
        if (arr[left] % 2 == 0) {
            return arr[left];
        } else {
            return 0; // Return 0 if the element is odd
        }
    } else {
        int mid = left + (right - left) / 2;
        int leftSum = calcEvenSum(arr, left, mid);
        int rightSum = calcEvenSum(arr, mid + 1, right);
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

    int sum = calcEvenSum(array, 0, n - 1);

    cout << "Sum of even numbers in the array: " << sum << endl;

    return 0;
}
