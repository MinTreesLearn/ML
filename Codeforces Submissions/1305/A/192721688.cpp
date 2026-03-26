#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr1[n], arr2[n];
        for(ll i = 0; i < n; i++)
            cin>>arr1[i];
        for(ll i = 0; i < n; i++)
            cin>>arr2[i];
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + n);
        for(ll i = 0; i < n; i++)
            cout<<arr1[i]<<" ";
        cout<<"\n";
        for(ll i = 0; i < n; i++)
            cout<<arr2[i]<<" ";
        cout<<"\n";
    }
}


  	 	  		   					 			  		  				