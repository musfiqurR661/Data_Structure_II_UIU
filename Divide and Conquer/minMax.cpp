#include<bits/stdc++.h>
using namespace std;

int findMin(int ar[], int s, int f) {
    if (s == f) {
        return ar[s];
    }
    int mid = (s + f) / 2;
    int min1 = findMin(ar, s, mid);
    int min2 = findMin(ar, mid + 1, f);
    return (min1 < min2) ? min1 : min2;
}

int findMax(int ar[], int s, int f) {
    if (s == f) {
        return ar[s];
    }
    int mid = (s + f) / 2;
    int max1 = findMax(ar, s, mid);
    int max2 = findMax(ar, mid + 1, f);
    return (max1 > max2) ? max1 : max2;
}

int main() {
    int n;
    cin >> n;
    int ar[n]; 

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    int max = findMax(ar, 0, n - 1);
    int min = findMin(ar, 0, n - 1);

    cout << "maxelement: " << max << endl;
    cout << "minelement: " << min << endl;

    return 0;
}
