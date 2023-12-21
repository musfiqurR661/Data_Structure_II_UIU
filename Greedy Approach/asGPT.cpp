#include <bits/stdc++.h>
using namespace std;

#define pollingST 100  // row
#define CandidateN 100 // col of candidate

struct Candidate {
    int index;
    int votes;
};

bool cmp(Candidate a, Candidate b) {
    return (a.votes > b.votes);
}

// Function to prevent the election of the opposition candidate
void preventOppositionElection(int n, int m, int votes[pollingST][CandidateN]) {
    // Initial total votes calculation
    int total_votes[CandidateN] = {0};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            total_votes[j] += votes[i][j];
        }
    }

    Candidate candidates[CandidateN];
    int Candidates_num = n - 1;
    for (int i = 0; i < Candidates_num; i++) {
        candidates[i].index = i;
        candidates[i].votes = total_votes[i];
    }

    sort(candidates, candidates + Candidates_num, cmp);

    int canceled_num = 0;
    int canceled_stations[pollingST] = {0};

    // Active selection approach
    while (canceled_num < m) {
        bool cancel_found = false;

        for (int i = 0; i < m; i++) {
            if (canceled_stations[i] == 1) 
            
            continue; // Skip already canceled stations

            bool cancel = true;
            for (int j = 0; j < Candidates_num; j++) {
                int polStation_vote = votes[i][candidates[j].index];
                int CandidateToT_Votes = total_votes[candidates[j].index];
                if (polStation_vote > CandidateToT_Votes / 2) {
                    cancel = false;
                    break;
                }
            }
            if (cancel) {
                canceled_stations[i] = 1;
                canceled_num++;
                cancel_found = true;
            }
        }

        if (!cancel_found) {
            break; // No more polling stations to cancel
        }
    }

    cout << canceled_num << endl;
    for (int i = 0; i < m; i++) {
        if (canceled_stations[i] == 1) {
            cout << i + 1;
            if (canceled_num > 1) {
                cout << " ";
            }
        }
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    int votes[pollingST][CandidateN];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> votes[i][j];    // i polling row // j candidate column
        }
    }

    preventOppositionElection(n, m, votes);

    return 0;
}
