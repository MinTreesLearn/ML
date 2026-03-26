#include <bits/stdc++.h>
#define REP(i,n) for(int i = 0; i< (n);i++)
#define all(x) (x).begin(), (x).end()
#define f first  
#define s second
#define SZ(a) (int)a.size()
#define bit(x,i)(((x)>>(i))&1)
typedef long long ll;
using namespace std; 

// Graph problem

void solve(){
	string s, t; cin >> s >> t;
	int n1 = SZ(s), n2 = SZ(t);
	vector<int> G[26];
	for(int i = 0; i < n1; ++i){
		G[s[i] - 'a'].push_back(i);
	}
	
	int cur = -1, ans = 0; 
	for(int i = 0; i < n2;){
		ans++;
		if(SZ(G[t[i] - 'a']) == 0){
			cout << -1 << endl;
			return;
		}
		while(i < n2){
			if(SZ(G[t[i] - 'a']) == 0){
				cout << -1 << endl;
				return;
			}
			auto it = upper_bound(all(G[t[i] - 'a']), cur);
			if(it == G[t[i] - 'a'].end()){
				cur= -1;
				break;
			}
			i++;
			cur = *it;
		}
	}
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while(tt--){
		solve();
	}
}

