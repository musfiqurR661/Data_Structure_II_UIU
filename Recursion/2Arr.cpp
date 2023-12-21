// C++ program to count total number 
// of special sequences of length n where
#include <iostream>
using namespace std;

// Recursive function to find the number of special
// sequences
int getTotalNumberOfSequences(int m, int n)
{
	
	// A special sequence cannot exist if length
	// n is more than the maximum value m.
	if (m < n)
		return 0;

	// If n is 0, found an empty special sequence
	if (n == 0)
		return 1;

	// There can be two possibilities : (1) Reduce
	// last element value (2) Consider last element
	// as m and reduce number of terms
	return getTotalNumberOfSequences(m - 1, n) +
		getTotalNumberOfSequences(m / 2, n - 1);
} 

// Driver code
int main()
{
	int m = 10;
	int n = 4;
	cout << "Total number of possible sequences "
		<< getTotalNumberOfSequences(m, n);
	return 0;
}

// This code is contributed by shivanisinghss2110
