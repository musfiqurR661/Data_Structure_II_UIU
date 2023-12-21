#include <iostream>

using namespace std;

struct PollingStation {
    int votes[101]; // Assuming a maximum of 100 candidates
    int difference;
};

int main() {
    int n, m;
    cin >> n >> m;

    PollingStation stations[m];

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> stations[i].votes[j];
        }

        // Calculate the difference in votes for the opposition candidate and others
        int sumOtherCandidates = 0;
        for (int j = 0; j < n - 1; ++j) {
            sumOtherCandidates += stations[i].votes[j];
        }
        stations[i].difference = stations[i].votes[n - 1] - sumOtherCandidates;
    }

    // Printing the stored data for each polling station
    for (int i = 0; i < m; ++i) {
        cout << "Polling Station " << i + 1 << ": ";
        for (int j = 0; j < n; ++j) {
            cout << stations[i].votes[j] << " ";
        }
        cout << "Difference: " << stations[i].difference << endl;
    }

    // Continue with the rest of your algorithm to solve the problem using the 'stations' array of structures

    return 0;
}
