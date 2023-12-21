#include <bits/stdc++.h>
using namespace std;
#define pollingST 100  // row
#define CandidateN 100 // col  of candidate

struct Candidate
{
    int index;
    int votes;
};

// bool cmp(const Candidate &a, const Candidate &b) {
//     return a.votes > b.votes;
// }

bool cmp(Candidate a, Candidate b)
{
    return (a.votes > b.votes);
}

int main()
{
    int n, m;
    cin >> n >> m;
    // int MAX_M=100;
    // int MAX_N=100;
    int votes[pollingST][CandidateN];
    int total_votes[CandidateN] = {0}; // Initialize total_votes array to 0

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> votes[i][j];
            total_votes[j] += votes[i][j]; // i polling // j candidate
        }
    }

    Candidate candidates[CandidateN];
    int Candidates_num = n - 1; // The number of candidates excluding the opposition candidate

    // Populate the candidates array
    for (int i = 0; i < Candidates_num; i++)
    {
        candidates[i].index = i;
        candidates[i].votes = total_votes[i];
    }
    // see the total vote of each candidate
    //  Accessing the data in the candidates array
    //  for (int i = 0; i < numCandidates; i++)
    //  {
    //      cout << "Candidate " << candidates[i].index + 1 << " received " << candidates[i].votes << " votes." << endl;
    //  }

    /*
    5 3
    6 3 4 2 8
    3 7 5 6 7
    5 2 4 7 9
    */
    sort(candidates, candidates + Candidates_num, cmp);

    int canceled_num = 0;
    int canceled_stations[pollingST]; // Assuming you have a maximum number of polling stations

    /*for (int i = 0; i < m; i++)
    {
        bool cancel = true;
        for (int j = 0; j < numCandidates; j++)
        {
             Candidate candidate = candidates[j];
            if (votes[i][candidate.index] > total_votes[candidate.index] / 2)
            {
                cancel = false;
                break;
            }
        }
        if (cancel)
        {
            canceled_stations[num_canceled++] = i;
        }
    }
    */
    // n-1
    for (int i = 0; i < m; i++)
    {
        bool cancel = true;
        for (int j = 0; j < Candidates_num; j++)
        {
            int polStation_vote = votes[i][candidates[j].index];
            int CandidateToT_Votes = total_votes[candidates[j].index];
            if (polStation_vote > CandidateToT_Votes / 2)
            {
                cancel = false;
                break;
            }
        }
        if (cancel)
        {
            canceled_stations[canceled_num++] = i;
        }
    }

    cout << canceled_num << endl;
    for (int i = 0; i < canceled_num; i++)
    {
        cout << canceled_stations[i] + 1;
        if (i < canceled_num - 1)
        {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
