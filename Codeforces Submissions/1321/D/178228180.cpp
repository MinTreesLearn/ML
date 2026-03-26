#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vii = vector< vector <int>>;
using vl = vector<ll>;
using vll = vector< vector <ll>>;
using vpi = vector <pair <int, int>>;
using vpl = vector <pair <ll, ll>>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define loop(i,n) for(int i = 0;i<n;i++)
#define loop1(i,n) for(int i = 1;i<n;i++)
#define loopx(i, x, n) for(int i = x; i<n; i++);
using pi = pair<int, int>;
using pl = pair<ll, ll>;
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;




int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vii adj(n + 1);
    loop(i, m) {
        int u, v;
        cin >> u >> v;
        adj[v].pb(u);
    }
    int k;
    cin >> k;
    vi path(k);
    loop(i, k) cin >> path[i];
    int t = path[k - 1];
    vector <unordered_set <int>> v(n + 1);
    vi dist(n + 1, n + 1);
    dist[t] = 0;

    queue <int> q;
    q.push(t);
    while (q.size()) {
        int c = q.front();
        q.pop();
        int d = dist[c] + 1;
        for (auto x : adj[c]) {
            if (dist[x] == d) {
                v[x].insert(c);
            }
            else if (dist[x] > d) {
                v[x].clear();
                v[x].insert(c);
                dist[x] = d;
                q.push(x);
            }
        }
    }

    int ans = 0;
    loop(i, k - 1) {
        int curr = path[i];
        int next = path[i + 1];
        if (v[curr].count(next)) continue;
        else ans++;
    }
    
    

    cout << ans << " ";
    ans = 0;
    loop(i, k-1){
        int curr = path[i];
        int next = path[i + 1];
        auto it = v[curr].begin();
        int x = *it;
        if(v[curr].size() > 1 or x != next) ans++;
    }
    cout << ans << endl;



    return 0;

}





