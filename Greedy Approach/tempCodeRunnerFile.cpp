#include <iostream>
#include <vector>
using namespace std;

void findMinimumCoins(int changeAmount, int coin_back[], int n)
{
    int usedCoins[10] = {0};

    for (int i = 0; i < n; ++i)
    {

        if (changeAmount == 0)
            break;

        usedCoins[i] = changeAmount / coin_back[i];
        changeAmount %= coin_back[i];
    }
    int totalCoins = 0;
    cout << "Minimum number of coins/notes :\n";
    for (int i = 0; i < n; i++)
    {
        if (usedCoins[i] > 0)
        {
            totalCoins += usedCoins[i];
            cout << coin_back[i] << " taka * " << usedCoins[i] << endl;
        }
    }
    cout << "Total coins used = " << totalCoins << endl;
}

int main()
{
    int amountPaid, billAmount; // Use integers instead of floats

    cout << "Enter the amount paid by the buyer: ";
    cin >> amountPaid;

    cout << "Enter the buying bill amount: ";
    cin >> billAmount;

    int changeAmount = amountPaid - billAmount; // Working with integer values

    if (changeAmount >= 0)
    {
        cout << "The change amount is: " << changeAmount << endl;

        int coin_back[10]; // Declare an array to store coin_back

        // take coins
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> coin_back[i];
        }

        // output coin_back

        // for (int i = 0; i < 10; ++i)
        // {
        //     cout << coin_back[i] << endl;
        // }

        findMinimumCoins(changeAmount, coin_back, n);
    }
    else
    {
        cout << "Insufficient amount paid." << endl;
    }

    return 0;
}
