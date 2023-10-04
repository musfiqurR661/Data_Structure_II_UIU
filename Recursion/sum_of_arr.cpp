#include<iostream>
using namespace std;

int sumArr(int a[] ,int n )
{
if(n==0)
return 0;

return a[n-1]+sumArr(a,n-1);
}


int binarySearch(int a[], int n, int key)
{
    int result;
    int l=0, h=n-1;
    while(l<h)
    {
        int mid = (h+l)/2;

        if( a[mid] == key){
         return mid;   
        }
         
        else if(a[mid]<key)
        {
            l = mid+1;
        } 

        
        else
        {
            result = mid;
            h = mid-1;
        }
    }
    return result;
}
int main()
{
int n;
cout << "Enter the number of element" << endl;
cin>> n;
int a[n];
for(int i=0;i<n;i++) 
{
    cin>> a[i];
}

    int k; cin >> k;
    cout <<"Element is in " << binarySearch(a, n, k) << " index" << endl;
int sum =sumArr(a,n);
cout<<sum << endl;
}
