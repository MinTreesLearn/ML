//////////////////////////////////////////////////////////////////
//                                                              //
//                                                              //
//                                                              //
//                       CODE BY ILHOM_45                       //
//                                                              //
//                                                              //
//                                                              //
//////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
#define yes cout << "YES" << "\n" ;
#define no cout << "NO" << "\n" ;
#define pb push_back
#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

vector<ll> v;
map<ll, ll> cmp;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
tree_order_statistics_node_update> mul;

int tt = 1;
vector<pair<ll, ll>> pos;
int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    ll x0, y0, a1, a2, b1, b2, x, y, t;
    cin >> x0 >> y0 >> a1 >> a2 >> b1 >> b2 >> x >> y >> t;
    pos.pb({x0, y0});
    while(x0 <= 1e16 && y0 <= 1e16){
        x0 = x0 * a1 + b1;
        y0 = y0 * a2 + b2;
        pos.pb({x0, y0});
    }
//    for(auto i : pos) cout << i.fi << " " << i.se << "\n";
    ll ans = 0;
    for(int i = 0; i < pos.size(); i++){
        ll dop = t, kol = 0;
        dop = dop - abs(pos[i].fi - x) - abs(pos[i].se - y);
        if(dop < 0) continue;
        kol++;
        ans = max(ans, kol);
        int ind = i;
        for(int j = pos.size() - 1; j > i; j--){
            ll dop1 = dop, kol1 = kol;
            dop1 = dop1 - abs(pos[i].fi - pos[j].fi) - abs(pos[i].se - pos[j].se);
            if(dop1 < 0) continue;
            kol1 = kol1 + (j - i);
            ans = max(ans, kol1);
            break;
        }
        for(int j = 0; j < i; j++){
            ll dop1 = dop, kol1 = kol;
            dop1 = dop1 - abs(pos[i].fi - pos[j].fi) - abs(pos[i].se - pos[j].se);
            if(dop1 < 0) continue;
            kol1 = kol1 + (i - j);
            ans = max(ans, kol1);
            break;
        }
    }
    cout << ans;
}

