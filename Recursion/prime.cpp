#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
       return false;
       //return true;
    }
    if (n <= 3) {
        return true;
       // return false;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
      //  return true;
    }
    
    int i = 5;
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
           // return true;
        }
        i ++;
    }
    
    //return false;
    return true;
}

int sumOfPrimesInRange(int start, int end) {
    if (start > end) {
        return 0;
    }
    
    if (isPrime(start)) {
        return start + sumOfPrimesInRange(start + 1, end);
    } else {
        return sumOfPrimesInRange(start + 1, end);
    }
}

int main() {
    int start, end;
    cout << "Enter the range (start and end): ";
    cin >> start >> end;
    
    int sum = sumOfPrimesInRange(start, end);
    
    cout << "Sum of prime numbers in the range [" << start << ", " << end << "] is: " << sum << endl;
    
return 0;
}
