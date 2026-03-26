#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        set<ll>st;
        for(ll i = 0; i < n; i++)
        {
            ll x;
            cin>>x;
            st.insert(x);
        }
        cout<<st.size()<<"\n";
    }

}



	   		 	      						  	 			 			