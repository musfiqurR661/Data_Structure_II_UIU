#include <iostream>
using namespace std;

string ComPrefix(string str1, string str2) {
    int n1 = str1.length(), n2 = str2.length();
    string result;
    for (int i = 0, j = 0; i < n1 && j < n2; i++, j++) {
        if (str1[i] != str2[j]) {
            break;
        }
        result += str1[i];
    }
    return result;
}

string longestCommonPrefix(string strs[], int left, int right) {
    if (left == right) {
        return strs[left];
    } else {
        int mid = left + (right - left) / 2;
        string leftPrefix = longestCommonPrefix(strs, left, mid);
        string rightPrefix = longestCommonPrefix(strs, mid + 1, right);
        return ComPrefix(leftPrefix, rightPrefix);
    }
}

string longestCommonPrefix(string strs[], int n) {
    if (n == 0) {
        return "";
    }
    return longestCommonPrefix(strs, 0, n - 1);
}

int main() {
    int n;
    cin >> n;
    string strings[n];

    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    string result = longestCommonPrefix(strings, n);

    if (result.empty()) {
        cout << "No common prefix" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
