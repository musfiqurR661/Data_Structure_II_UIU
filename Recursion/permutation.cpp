#include <iostream>
using namespace std;

void generatePermutations(string str, int left, int right) {
    if (left == right) {
        cout << str << endl; // Found a permutation
    } else {
        for (int i = left; i <= right; i++) {
            // Swap characters at positions left and i
            swap(str[left], str[i]);

            // Recursively generate permutations for the remaining characters
            generatePermutations(str, left + 1, right);

            // Restore the original order for backtracking
            swap(str[left], str[i]);
        }
    }
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int n = input.length();

    cout << "All permutations of " << input << " are:" << endl;
    generatePermutations(input, 0, n - 1);

return 0;
}
