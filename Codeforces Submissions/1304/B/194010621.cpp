#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define all(v)				((v).begin()), ((v).end())
#define MOD ll(1e9+7)
#define int long long
typedef int ll;
typedef vector<ll> vi;
typedef tree< ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N=2e5+10;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<string> a(n);
    map<string, ll> mp;
    string fir = "", sec = "", mid = "";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]]++;
    }
    for (int i = 0; i < n; ++i) {
        string rno = a[i];
        string no = a[i];
        reverse(all(rno));
        if (rno != no) {
            if (mp[no] && mp[rno]) {
                fir += no;
                sec = rno + sec;
                mp[no]--;
                mp[rno]--;
            }
        } else {
            if (mp[no] > 1) {
                if (mp[no] && mp[rno]) {
                    fir += no;
                    sec = rno + sec;
                    mp[no]--;
                    mp[rno]--;
                }
            } else {
                if (mid.size() < no.size())mid = no;
            }
        }
    }
    string y = fir + mid + sec;
    cout << y.size() << endl;
    cout << y << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}