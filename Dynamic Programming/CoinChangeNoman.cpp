// ///.................*** بسم الله الرحمن الرحيم ***.................///

#include<bits/stdc++.h>
using namespace std;

typedef struct structure
{
    int coin;
    int requiredCoin[100000];
} str;

void Merge(str A[], int p, int q, int r)
{
    int n1 = q-p+1;
    int n2 = r-q;
    str L[n1+1], R[n2+1];

    for(int i=0; i<n1; i++)
        L[i].coin = A[p+i].coin;
    L[n1].coin = INT_MIN;

    for(int i=0; i<n2; i++)
        R[i].coin = A[q+1+i].coin;
    R[n2].coin = INT_MIN;

    int i=0, j=0, k=p;
    while(k<=r)
    {
        if(L[i].coin >= R[j].coin)
        {
            A[k].coin = L[i].coin;
            i++;
        }
        else
        {
            A[k].coin = R[j].coin;
            j++;
        }
        k++;
    }
}
void mergeSortDescendingOrder(str A[], int p, int r)
{
    if(p<r)
    {
        int q = (p+r)/2;
        mergeSortDescendingOrder(A, p, q);
        mergeSortDescendingOrder(A, q+1, r);
        Merge(A, p, q, r);
    }
}

void coinChange(str A[], int n, int totalAmount)
{
    mergeSortDescendingOrder(A, 0, n-1);

    for(int coinIndex=0; coinIndex<n; coinIndex++)
    {
        for(int currentAmount=0; currentAmount<=totalAmount; currentAmount++)
        {
            if(currentAmount==0){
                A[coinIndex].requiredCoin[currentAmount] = 0;
                continue;
            }
            if(coinIndex==0)
            {
                if((currentAmount % A[coinIndex].coin) != 0)
                    A[coinIndex].requiredCoin[currentAmount] = INT_MAX;
                else
                    A[coinIndex].requiredCoin[currentAmount] = (currentAmount / A[coinIndex].coin);
            }
            else
            {
                if(currentAmount > A[coinIndex].coin)
                    A[coinIndex].requiredCoin[currentAmount] = A[coinIndex-1].requiredCoin[currentAmount];
                else
                {
                    int notTake = A[coinIndex-1].requiredCoin[currentAmount];
                    int take = A[coinIndex].requiredCoin[currentAmount - A[coinIndex].coin] + 1;
                    if(take <= notTake)
                        A[coinIndex].requiredCoin[currentAmount] = take;
                    else
                        A[coinIndex].requiredCoin[currentAmount] = notTake;
                }
            }
        }
    }

    if(A[n-1].requiredCoin[totalAmount] == INT_MAX)
        cout << "It is not possible to give the change using available notes/coins!" << endl;
    else
    {
        cout << "Total notes/coins needed: " << A[n-1].requiredCoin[totalAmount] << endl;
        cout << "Notes/Coins: ";

        bool flag = true;
        int i = totalAmount, j=n-1;
        while(i>0)
        {
            if(A[j].requiredCoin[i] == A[j-1].requiredCoin[i]) j--;
            else
            {
                int count = 0;
                while(i>0)
                {
                    if(A[j].requiredCoin[i] == A[j-1].requiredCoin[i])
                    {
                        j--;
                        break;
                    }
                    count++;
                    i -= A[j].coin;
                }
                if(flag)
                {
                    cout << A[j].coin << " -> " << count;
                    flag = false;
                }
                else
                    cout << ", " << A[j].coin << " -> " << count;
            }
        }
        cout << endl;
    }
    return;
}

int main()
{
    int numberOfAvailableNotes;
    cout << "Number of available notes/coins: ";
    cin >> numberOfAvailableNotes;

    str availableNotes[20];
    cout << "The notes/coins are: ";
    for (int i = 0; i < numberOfAvailableNotes; i++)
    {
        int temp;
        cin >> temp;
        availableNotes[i].coin = temp;
    }

    while (true)
    {
        int payableAmount = 0;
        cout << "Payable amount: ";
        cin >> payableAmount;

        int receivedAmount = 0;
        cout << "Received amount: ";
        cin >> receivedAmount;

        if (receivedAmount == 0)
        {
            cout << "Received amount is zero. Exiting..." << endl;
            break;
        }

        int changeAmount = receivedAmount - payableAmount;
        cout << "Change amount: " << changeAmount << endl;
        if (changeAmount == 0)
            continue;

        coinChange(availableNotes, numberOfAvailableNotes, changeAmount);
    }

    return 0;
}
