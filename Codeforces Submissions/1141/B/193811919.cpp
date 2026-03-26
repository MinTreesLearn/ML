#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

void working()
{
    // ll n;
    // cin >> n;

    // vll a(n);
    // for(ll i=0; i<n; i++){
    //     cin>>a[i];
    // }

    // sort(a.begin(), a.end());

    ll n;
    cin >> n;

    vll a(n);
    for(ll i=0; i<n; i++){
        cin>>a[i];
    }

    ll i=1, cnt=0, mx=0;
    while(i<2*n){
        mx = max(mx,cnt);
        if(a[i%n]==1) cnt++;
        else cnt=0;
        i++;
    }
    
    cout<<mx;

    cout << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif

    ll t = 1;
    // cin >> t;

    while (t--)
    {
        working();
    }
}
