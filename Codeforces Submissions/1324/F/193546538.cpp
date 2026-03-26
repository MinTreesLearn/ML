#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll, ll> ii;
#define eps 1e-9
#define MOD 998244353
#define pi 3.141592653589793
const int INF = 1e9 + 5;

int t = 0;
vector<int> dp1, dp2;
vector<int> adjList[200005];
vector<int> A;

void dfs1(int u, int parent){
    dp1[u] = A[u];
//    cout << "u = " << u << "     " << dp1[u] << endl;
    for(int v: adjList[u]){
        if(v == parent) continue;
        dfs1(v, u);
        dp1[u] += max(dp1[v], 0);
    }
//    cout << "u = " << u << "     " << dp1[u] << endl;
}

void dfs2(int u, int parent){
    if(u != 1){
        if(dp1[u] > 0){
            int x = dp2[parent] - dp1[u];
            dp2[u] = dp1[u] + max(x, 0);
        }
        else{
            dp2[u] = dp1[u] + max(dp2[parent], 0);
        }
    }
    for(int v: adjList[u]){
        if(v == parent) continue;
        dfs2(v, u);
    }
}


int main()
{
    int n;
    cin >> n;
    A.resize(n + 1);
    for(int i = 1; i <= n; i++) cin >> A[i];
    for(int i = 1; i <= n; i++){
        if(A[i] == 0) A[i] = -1;
    }
//    vector<vector<int>> adjList(n+1);
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
//    for(int i = 1; i <= n; i++) cout << A[i] << " ";
//    cout << endl;
    dp1.resize(n + 1);
    dp2.resize(n + 1);
    dfs1(1, 1);
//    for(int i = 1; i <= n; i++) cout << dp1[i] << " ";
//    cout << endl;
    dp2[1] = dp1[1];
    dfs2(1, 1);
    for(int i = 1; i <= n; i++) cout << dp2[i] << " ";


    return 0;
}
