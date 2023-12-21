#include<bits/stdc++.h>
using namespace std;

// Function to preprocess the string (remove spaces, punctuation, convert to lowercase)
string preprocessString(string str) {
    string processed;
    for (char c : str) {
        if (isalpha(c)) { // Check if the character is an alphabet
            processed += tolower(c); // Convert to lowercase
        }
    }
    return processed;
}

bool isPalindrome(string str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    string a;
    getline(cin, a);

    // Preprocess the string
    string processedString = preprocessString(a);

    int length = processedString.length();

    if (length == 0) {
        cout << "Empty string" << endl;
        return 0;
    }

    bool result = isPalindrome(processedString, 0, length - 1);

    if(result) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not a Palindrome" << endl;
    }

    return 0;
}
