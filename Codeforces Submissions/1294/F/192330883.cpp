#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
 
const int M = 1e6+7, MOD = 1e9;
int dist[M], n, par[M];
vector<int> node[M];

void bfs(vector<int> s) {
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    for (int i:s) dist[i] = 0;
 
    queue<int> q;
    for (int i:s) q.push(i);
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        for (int i:node[f]) {
            if (dist[i] == INT_MAX) {
                dist[i] = dist[f]+1;
                q.push(i);
            }
        }
    }
}
    
vector<int> tmp;
void dfs(int s, int p) {
    for (int i:node[s])
        if (i != p) par[i] = s, dfs(i, s);
}
 
signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    srand(time(0));
 
    cin >> n;
 
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
 
        node[a].push_back(b);
        node[b].push_back(a);
    }
    
    bfs({1});
    int a = max_element(dist+1, dist+n+1)-dist;
    bfs({a});
    int x = *max_element(dist+1, dist+n+1);
    int b = max_element(dist+1, dist+n+1)-dist;
    dfs(a, a);
    int k = b;
    while (k) {
        tmp.push_back(k);
        k = par[k];
    }

    bfs(tmp);
    x += *max_element(dist+1, dist+n+1);
    cout << x << endl;
    if (*max_element(dist+1, dist+n+1) == 0) {
        cout << a << ' ' << b << ' ';
        set<int> st;
        for (int i = 1; i <= n; i++) st.insert(i);
        st.erase(a);
        st.erase(b);
        cout << *st.begin() << endl;
    } else {
        cout << a << ' ' << b << ' ' << max_element(dist+1, dist+n+1)-dist << endl;
    }

    return 0;
}
 		   	  			     	 	 		 	   	