#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb push_back
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll t; cin >> t;
    while (t--)
    {
        ll n; cin >> n; vector<ll> e, o;
        for (int i = 0; i < n; i++) {
            ll x; cin >> x; if (x%2) o.pb(i+1); else e.pb(i+1);
        }
        if (e.size() || o.size() > 1) {
            cout << e.size()+(o.size()-(o.size()%2)) << '\n';
            if (o.size()%2) o.pop_back();
            for (auto i : e) cout << i << ' ';
            for (auto i : o) cout << i << ' ';
        } else cout << -1;
        cout << '\n';
    }
    return 0;
}

 				 			 	  		   	  	 	 		 	