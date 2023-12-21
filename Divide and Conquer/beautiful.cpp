#include <iostream>
using namespace std;

void generateBeautifulArray(int arr[], int n, int start, int step) {
    if (n == 1) {
        arr[0] = start;
        return;
    }

    int idx = 0;
    for (int i = start; i <= n; i += step) {
        arr[idx] = i;
        idx++;
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int beautifulArr[n];
    generateBeautifulArray(beautifulArr, n, 1, 2);
    generateBeautifulArray(beautifulArr + (n + 1) / 2, n - (n + 1) / 2, 2, 2);

    cout << "Beautiful array of length " << n << " : ";
    for (int i = 0; i < n; i++) {
        cout << beautifulArr[i] << " ";
    }
    cout << endl;

    return 0;
}
