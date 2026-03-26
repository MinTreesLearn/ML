// Akash Singh
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; //Make less_equal for multiset
// find_by_order(k)  returns iterator to kth element || order_of_key(k) returns count of elements smaller than k
#define deb(x) cout << x << "\n";
#define deb2(x,y) cout << x << " " << y << "\n";
#define debv(v) for(auto e: v) cout << e << " "; cout << '\n';
#define int long long
#define ll long long
#define mod 1000000007
#define endl "\n"
const int N = 0;

void solver();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int KitniBar = 1;
    cin >> KitniBar;

    for(int tc = 1; tc <= KitniBar; tc++)
    {
        // cout << "Case #" << tc << ": ";
        solver();
    }
    return 0;
}
void solver()
{
    string s, t; cin >> s >> t;
    vector<int> adj[125];
    for(int i = 0; i < s.size(); i++) adj[s[i]].push_back(i);

    int n = t.size(), indx = -1, ans = 1, i = 0; bool f = true;
    while(i < n) {
        auto it = upper_bound(adj[t[i]].begin(), adj[t[i]].end(), indx);
        if(it == adj[t[i]].end()) {
            if(f) {
                cout << "-1\n";
                return;
            }
            ans++; indx = -1; f = true;
        }
        else {
            // deb2(i, *it);
            f = false;
            indx = *it; i++;
        }
    }
    cout << ans << endl;
}