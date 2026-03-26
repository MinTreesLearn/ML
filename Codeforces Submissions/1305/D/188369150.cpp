#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e6 + 10;
vector<int>h[N];
int ask(int u, int v) {
	cout << "? " << u << " " << v << '\n';
	int t;
	cin >> t;
	return t;
}
int ans, st[N];
int p[10], ok;
void dfs(int u, int d) {
	if (ok)return;
	p[d] = u;
	st[u] = 1;
	if (d == 3) {
		int x = ask(p[1], p[3]);
		dfs(x,1);
		return;
	}
	for (auto j : h[u]) {
		if (st[j])continue;
		dfs(j, d + 1);
		return;
	}
}
int d[N];
int main() {
//	std::ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	cout<<fixed<< setprecision(2);
	int n;
	cin >> n;
	int l=1;
	queue<int>q;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		h[a].push_back(b);
		h[b].push_back(a);
		d[a]++;
		d[b]++;
	}
	for(int i=1;i<=n;i++){
		if(d[i]==1)q.push(i);
	}
	int ans=0;
	while(q.size()>1){
		auto t=q.front();q.pop();
		auto v=q.front();q.pop();
		int d1=ask(t,v);
		if(d1==t||d1==v){
			ans=d1;
			break;
		}else{
			for(auto j:h[t]){
				d[j]--;
				if(d[j]==1)q.push(j);
			}
			for(auto j:h[v]){
				if(--d[j]==1)q.push(j);
			}
		}
	}
	if(!ans)ans=q.front();
	cout<<"! "<<ans;
	return 0;
}
