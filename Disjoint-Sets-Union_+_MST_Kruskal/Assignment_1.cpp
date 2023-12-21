

#include <bits/stdc++.h>
using namespace std;

#define pollingST 100  // row
#define CandidateN 100 // col of candidate

struct Candidate
{
    int index;
    int votes;
};

bool cmp(Candidate a, Candidate b)
{
    return (a.votes > b.votes);
}

bool isPollStion_Cancel(int stationVotes[CandidateN], int n, int oponentCandidate)
{
    for (int i = 0; i < n; i++)
    {
        if (i != oponentCandidate && stationVotes[i] >= stationVotes[oponentCandidate])
        {
            return false;
        }
    }
    return true;
}

void Check_stionTo_cancle(int n, int m, int votes[pollingST][CandidateN])
{
    Candidate candidates[CandidateN];
    int Candidates_num = n;

    // for (int i = 0; i < Candidates_num; i++)
    // {
    //     candidates[i].index = i;
    //     candidates[i].votes = 0;
    // }

    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < Candidates_num; j++)
    //     {
    //         candidates[j].votes += votes[i][j];
    //     }
    // }

    int canceled_num = 0;
    int canceled_stations[pollingST];
    for (int i = 0; i < m; i++)
    {
        if (isPollStion_Cancel(votes[i], Candidates_num, Candidates_num - 1))
        {
            canceled_stations[canceled_num] = i;
            canceled_num++;
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
}

int main()
{
    int n, m;
    cin >> n >> m;
    int votes[pollingST][CandidateN];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> votes[i][j];
        }
    }

    Check_stionTo_cancle(n, m, votes);

    return 0;
}
