#include <bits/stdc++.h>

using namespace std;

int main()
{
    long int t,n,k,i,l;
    
    cin>>t;
    while(t--)
    {  vector< int> arr;
        cin>>n;
        for ( i = 0; i < 2*n; i++)
        {
           cin>>l;
           arr.push_back(l);
        }
        sort(arr.begin(),arr.end());
        k= arr[n]-arr[n-1];
        cout<<k<<'\n';
    }
    return 0;
}