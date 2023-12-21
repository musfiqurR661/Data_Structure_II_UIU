#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return isPalindrome(str, start + 1, end - 1);
}

int main()
{
    string a;
   // cin >> a;
    getline(cin,a);
     int length = a.length();

    bool result = isPalindrome(a, 0, length - 1);
    if(result)
    {
        cout << "Palindrome"<< endl;
    }
    else{
        cout << "Not a Palindrome"<< endl;
    }
}