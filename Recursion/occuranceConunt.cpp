#include <iostream>
using namespace std;

int countOccurrences(int arr[], int n, int target, int currentIndex = 0) {
    // Base case: If the currentIndex reaches the end of the array or n is non-positive, stop recursion.
    if (n <= 0 || currentIndex == n) {
        return 0;
    }

    // Recursive case: Count occurrences in the remaining part of the array.
    int count = countOccurrences(arr, n, target, currentIndex + 1);

    // Check if the current element is equal to the target element.
    if (arr[currentIndex] == target) {
        count++;
    }

    return count;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size." << endl;
        return 1;
    }

    int arr[n];
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the element to count occurrences: ";
    cin >> target;

    int count = countOccurrences(arr, n, target);

    cout << "The number of occurrences of " << target << " in the array is: " << count << endl;

    return 0;
}
