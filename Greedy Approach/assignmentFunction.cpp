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

void Election(int n, int m, int votes[pollingST][CandidateN])
{
    Candidate candidates[CandidateN];
    int Candidates_num = n;

    for (int i = 0; i < Candidates_num; i++)
    {
        candidates[i].index = i;
        candidates[i].votes = 0;
    }

    int canceled_num = 0;
    int canceled_stations[pollingST];

    for (int i = 0; i < m; i++)
    {
        //bool cancel = true;

        for (int j = 0; j < Candidates_num; j++)
        {
            candidates[j].votes += votes[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        bool cancel = true;
        for (int j = 0; j < Candidates_num; j++)
        {
            if (votes[i][j] > candidates[j].votes / 2)
            {
                cancel = false;
                break;
            }
        }

        if (cancel)
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

    Election(n, m, votes);

    return 0;
}
