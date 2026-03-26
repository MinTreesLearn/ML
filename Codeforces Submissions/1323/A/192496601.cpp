/*
* created by Mohamed hossam
 ####        ####                  ##                                                ##
 ## ##      ## ##      #####       ##         ##                  ######             ##
 ##  ##    ##  ##    ##     ##     #######    ##############     ##    ##      ########
 ##   ######   ##   ##       ##    #######    ##############    #########     ##     ##
 ##            ##    ##     ##     ##   ##    ##    ##    ##     ##           ##     ##
 ###          ###      #####       ##   ##    ##    ##    ##      #######      ########
*/
#include <bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    fast;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n],x=0;
        vector<pair<ll,ll>>v;
        for(ll i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i]%2==0)x=i+1;
            else v.push_back({a[i],i+1});
        }
        if(x!=0)cout<<1<<"\n"<<x<<"\n";
        else if(x==0&&v.size()>=2)cout<<2<<"\n"<<v[0].second<<" "<<v[1].second<<"\n";
        else cout<<"-1\n";
    }
}

		      	 		 	 			 												