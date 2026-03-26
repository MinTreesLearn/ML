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
    string s; cin >> s;
    string ans = ""; char cur = '$';
    set<char> adj[125]; vector<bool> vis(125, false);

    if(s.size() == 1) {
        cout << "YES\n";
        for(int i = 'a'; i <= 'z'; i++) {
            if(!vis[i]) ans += i;
        }
        cout << ans << endl;
        return;
    }
    for(int i = 0; i < s.size()-1; i++) {
        adj[s[i]].insert(s[i+1]);
        adj[s[i+1]].insert(s[i]);
    }
    for(int i = 'a'; i <= 'z'; i++) {
        if(adj[i].size() > 2) {
            cout << "NO\n";
            return;
        }
        else if(adj[i].size() == 1) cur = i;
    }
    if(cur == '$') {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    queue<char> q; q.push(cur);
    while(!q.empty()) {
        cur = q.front(); q.pop();
        vis[cur] = true; ans += cur;
        for(char ch: adj[cur]) {
            if(!vis[ch]) q.push(ch);
        }
    }
    for(int i = 'a'; i <= 'z'; i++) {
        if(!vis[i]) ans += i;
    }
    cout << ans << endl;
}