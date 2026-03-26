#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define pb push_back
#define pob pop_back()
#define mp make_pair

#define add_m(a, b,mod) (((a % mod) + (b % mod)) % mod)
#define sub_m(a, b,mod) (((a % mod) - (b % mod) + mod) % mod)
#define mul_m(a, b,mod) (((a % mod) * (b % mod)) % mod)


/*
Use pigon hole principle
if (n > m) then there must exist 2 numbers (ai) and (aj) such that ai == aj (modulo m) , i != j
    so the answer is 0
else 
    n <= m i.e. n <= 1e6, we can use O(n*n) brute force
*/

signed main()
{

        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        ll n,m;
          scanf("%lld%lld", &n,&m);
        ll arr[n];
        for (ll i = 0; i < n; i++)
            scanf("%lld", &arr[i]);
        
        if (n > m) cout<< 0<<"\n";
        else 
        { ll p = 1;
         for (ll i = 0 ;i < n ; i++)
            for (ll j = i+1 ; j < n;j++)
                p = mul_m(p,abs(arr[i]-arr[j]),m);


        cout<<p<<'\n';
        }

        return 0;
}