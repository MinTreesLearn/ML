#include<bits/stdc++.h>
using namespace std;
#define ll long long

// void decToBinary(int n)
// {
//     int binaryNum[32] = {0};
 
//     int i = 0;
//     while (n > 0) {
//      binaryNum[i] = n % 2;
//         n = n / 2;
//         i++;
//     }
//     for (int j = 30; j >= 0; j--)
//         cout << binaryNum[j]<<" ";
// }

void solve()
{
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(auto &i: v)
    {
        cin>>i;
        // cout<<i<<" ";
        // decToBinary(i);
        // cout<<endl;
    }
    ll ind = 0;
    for(ll i=30; i>=0; i--)
    {
        ll cnt = 0;
        for(ll j=0; j<n; j++)
        {
            if((v[j]&(1LL<<i))!=0)
            {
                cnt++;
            }
        }
        if(cnt==1)
        {
            for(ll j=0; j<n; j++)
            {
                if((v[j]&(1LL<<i))!=0)
                {
                    ind = j;
                }
            }
            break;
        }
    }
    cout<<v[ind]<<" ";
    for(ll i=0; i<n; i++)
    {
        if(ind!=i)
        cout<<v[i]<<" ";
    }
}

int main()
{
    ll t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
}