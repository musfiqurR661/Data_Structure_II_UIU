#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> votes(m, vector<int>(n));
    vector<int> totalVotes(n);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> votes[i][j];
            totalVotes[j] += votes[i][j];
        }
    }

    vector<int> cancelledStations;
    int oppositionVotes = totalVotes[n - 1];

    for (int i = 0; i < m; ++i) {
        bool cancel = false;

        for (int j = 0; j < n - 1; ++j) {
            if (totalVotes[j] + votes[i][n - 1] > oppositionVotes) {
                cancel = true;
                break;
            }
        }

        if (cancel) {
            cancelledStations.push_back(i + 1);
        }
    }

    cout << cancelledStations.size() << endl;
    for (int i = 0; i < cancelledStations.size(); ++i) {
        cout << cancelledStations[i] << " ";
    }
    cout << endl;

    return 0;
}
