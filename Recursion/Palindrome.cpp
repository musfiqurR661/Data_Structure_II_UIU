#include <iostream>
using namespace std;

bool isPalindrome(string str, int start, int end) {
    // Base case: If the string has only one character or no characters, it's a palindrome.
    if (start >= end) {
        return true;
    }

    // Check if the characters at the start and end positions are the same.
    if (str[start] != str[end]) {
        return false;
    }

    // Recursive case: Check the substring without the start and end characters.
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int length = input.length();

    bool result = isPalindrome(input, 0, length - 1);

    if (result) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }


return 0;
}
