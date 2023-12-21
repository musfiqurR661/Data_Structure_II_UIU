#include <bits/stdc++.h>

using namespace std;

struct Item
{

    int start, finish, per_unit;
};

bool sortCmp(Item a1, Item a2)
{
    return (a1.per_unit < a2.per_unit);
}

int activity(Item arr[], int n)
{
    sort(arr, arr + n, sortCmp);

    int jobCount = 1;
    int available = arr[0].finish;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].start >= available)
        {
            jobCount++;
            available = arr[i].finish;
        }
    }

    cout << jobCount << endl;
    return 0;
}

int main()
{
    int n;
    cout << "Enter The Item Number: ";
    cin >> n;

    Item arr[n];

    for (int i = 0; i < n; i++)
    {

        cin >> arr[i].start >> arr[i].finish;
    }

    activity(arr, n);

return 0;
}