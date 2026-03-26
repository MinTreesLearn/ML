// Problem: B. Navigation System
// Contest: Codeforces - Codeforces Round #625 (Div. 1, based on Technocup 2020 Final Round)
// URL: https://codeforces.com/problemset/problem/1320/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include<bits/stdc++.h>
#define pb push_back
#define endl '\n'
#define mod 1000000007
#define N 500005
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define control ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int long long int
#define ffor(i, n) for(int i=0; i<n; i++)
#define fforr(i, n) for(int i=1; i<=n; i++)
#define rfor(i, n) for(int i=n-1; i>=0; i--)
#define rforr(i, n) for(int i=n; i>0; i--)
#define all(x) x.begin(), x.end()
#define F  first
#define S  second
#define inf 9223372036854775807
using namespace std;
void setIO()
{	
	control;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
void print(bool chk){
	if(chk){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}
int min(int a, int b){
	return a>b?b:a;
}
int max(int a, int b){
	return a<b?b:a;
}
int power(int x,int y,int p)
{
    int ans=1;
    x=x%p;
    if(x==0)
    {
    	return 0;
    }
    while(y>0)
    {
        if(y&1)
        {
        	ans=(ans*x)%p;
        }
        y=y>>1;
        x=(x*x)%p;
    }
    return ans;
}
vvi graph;
vvi matrix;
vvi level;
vi lev;
int32_t main(){
	int n, m; cin >> n >> m;
	graph.resize(n+1);
	level.resize(n+1);
	lev.resize(n+1, -1);
	matrix.resize(n+1);
	ffor(i, m){
		int u, v;
		cin >> u >> v;
		graph[v].pb(u);
		matrix[u].pb(v);
	}
	int k; cin >> k;
	int s, t;
	vi path(k);
	ffor(i, k){
		cin >> path[i];
	}
	s = path[0];
	t = path[k-1];
	queue<int> q;
	level[0].pb(t);
	lev[t] = 0;
	q.push(t);
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int x:graph[node]){
			if(lev[x] == -1){
				q.push(x);
				lev[x] = lev[node] + 1;
				level[lev[x]].pb(x);
			}
		}
	}
	int curr = lev[s];
	int mxans = 0;
	int mnans = 0;
	for(int i=1; i<k; i++){
		if(lev[path[i]] < curr){
			int cnt = 0;
			for(int x:matrix[path[i-1]]){
				if(lev[x] == lev[path[i]])cnt++;
			}
			curr = lev[path[i]];
			if(cnt > 1){
				mxans += 1;
			}
		}else{
			curr = lev[path[i]];
			mxans += 1;
			mnans += 1;
		}
	}
	cout << mnans << " " << mxans << endl;
}