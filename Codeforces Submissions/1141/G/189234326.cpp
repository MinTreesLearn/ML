#include<bits/stdc++.h>
#define ll long long int
#define pa pair<int,int>
#define f first
#define s second
#define sz 200005
#define vec array<int,4>
using namespace std;
std::vector<int> adj[sz];
int deg[sz],ans[sz],deg1[sz];
int r;
map<pa,int>mp;
void solve(int node,int par,int clr) {
    for(int u:adj[node]) {
        if(u == par)
            continue;
        clr = (clr%r)+1;
        ans[mp[{node,u}]] = (clr)%r+1;
        solve(u,node,clr);
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int test_case = 1;
    //cin >> test_case;
    for(int cs = 1;cs <= test_case; cs++) {
        int n,k;
        cin >> n >> k;
        for(int i = 1;i<n;i++) {
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            deg[a]++;
            deg[b]++;
            mp[{a,b}]=mp[{b,a}] = i;
        }
        for(int i = 1;i<=n;i++)
            deg1[deg[i]]++;
        for(int i = n;i >= 1; i--) {
            deg1[i] += deg1[i+1];
            if(deg1[i] <= k)
                r = i-1;
        }
        solve(1,0,0);
        cout << r <<"\n";
        for(int i = 1;i<n;i++)
            cout << ans[i] <<" ";
        cout <<"\n";
    }
    return 0;
}


 						 	    		 			    	 	 	  	