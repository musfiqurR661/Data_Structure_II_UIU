#include <bits/stdc++.h>

using namespace std;

struct Item
{

    int start, finish;
};
bool sortCmp(Item a1, Item a2)
{
    return (a1.finish < a2.finish);
}

int activitySelection(Item tsk[], int n)
{

    sort(tsk, tsk + n, sortCmp);
    // for(int i=0;i<n;i++)
    // {

    //     cout<<tsk[i].finish<<endl;
    //  }
    int picked = 1;
    int availibily = tsk[0].finish;
    for (int i = 1; i < n; i++)
    {

        if (tsk[i].start >= availibily)
        {

            picked++;
            availibily = tsk[i].finish;
        }
    }
    return picked;
}
int main()
{
    // int n;
    // cin >> n;
    Item tsk[] = {{0, 7}, {6, 8}, {9, 12}, {7, 10}, {13, 15}};
    int n = sizeof(tsk) / sizeof(tsk[0]);

    cout << activitySelection(tsk, n);
}
/*
5 3
6 3 4 2 8
3 7 5 6 7
5 2 4 7 9

2 1
1 1


*/