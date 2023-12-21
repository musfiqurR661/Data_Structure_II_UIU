#include <bits/stdc++.h>

using namespace std;

struct Item
{
    string Prod_name;
    float price, weight, value;
};

bool sortCmp(Item a1, Item a2)
{
    return (a1.value > a2.value);
}

int Frac_knapSack(Item arr[], int w, int n)
{
    sort(arr, arr + n, sortCmp);

    float total = 0;

    for (int i = 0; i < n; i++)
    {
        if (w >= arr[i].weight)
        {
            total += arr[i].price;
            w -= arr[i].weight;
            cout << arr[i].Prod_name << " " << arr[i].price << endl;
        }
        else
        {
            cout << arr[i].Prod_name << " " << arr[i].value * w << endl;
            total += arr[i].value * w;
            break;
        }
    }

    cout << "MaxProfit Profit: " << total << endl;
    return 0;
}

int main()
{
    int n;
    cout << "Enter The Item : ";
    cin >> n;

    Item arr[n];

    for (int i = 0; i < n; i++)
    {

        cin >> arr[i].Prod_name >> arr[i].price >> arr[i].weight;

        arr[i].value = arr[i].price / arr[i].weight;
    }

    int w;
    cout << "KnapSack Capacity: ";
    cin >> w;

    Frac_knapSack(arr, w, n);

    return 0;
}
