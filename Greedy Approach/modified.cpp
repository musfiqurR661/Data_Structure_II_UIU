#include <bits/stdc++.h>
using namespace std;

const int A = 125;

struct CandidateVotes {
    int totalVotes, candidateIndex;
};

bool compareCandidates(CandidateVotes a, CandidateVotes b) {
    return (a.totalVotes > b.totalVotes);
}

void cancelPollingStations(int n, int m, int pollingResults[A][A]) {
    CandidateVotes stationVotes[A];
    int canceledStations[A];
    int canceledCount = 0;

    for (int i = 1; i <= m; i++) {
        canceledStations[canceledCount++] = i;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            stationVotes[j].totalVotes = pollingResults[j][i] - pollingResults[j][n];
            stationVotes[j].candidateIndex = j;
        }

        sort(stationVotes, stationVotes + m, compareCandidates);

        long long totalSum = 0;
        int candidateCount = 0;

        for (int j = 1; j <= m; j++) {
            totalSum += stationVotes[j].totalVotes;

            if (totalSum < 0)
                break;

            ++candidateCount;
        }

        if (m - candidateCount < canceledCount) {
            canceledCount = 0;

            for (int j = candidateCount + 1; j <= m; j++) {
                canceledStations[canceledCount++] = stationVotes[j].candidateIndex;
            }
        }
    }

    cout << canceledCount << endl;

    for (int i = 0; i < canceledCount; i++) {
        cout << canceledStations[i] << " ";
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int pollingResults[A][A];
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
            cin >> pollingResults[i][j];
    }

    cancelPollingStations(n, m, pollingResults);

    return 0;
}
