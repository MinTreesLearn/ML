// oooo
/*
 har chi delet mikhad bebar ~
 gitar o ba khodet nabar! ~
 ;Amoo_Hasan;
*/

/*
	link:
*/

#include<bits/stdc++.h>
#pragma GCC optimize("O3,no-stack-protector,unroll-loops,Ofast")
#pragma GCC target("avx2,fma")

using namespace std;

typedef long long ll;
typedef long double ld;

#define Sz(x) int((x).size())
#define All(x) (x).begin(), (x).end()
#define wtf(x) cout<<#x <<" : " <<x <<endl
#define mak make_pair

//constexpr int PRI = 1000696969;
constexpr ll INF = 1e18, N = 5e5 + 10, MOD = 1e9 + 7;

void Clear();

int n, k;
char ns;
int link[N];
bool vis[N];
vector<int> vc[N];

void Add(int x) {
	for(auto j : vc[x]) {
		if(vis[j]) continue;
		cout<<"? " <<j <<endl;
		cin >>ns;
		if(ns == 'Y') {	
			vis[j] = true;
		}
	}
}
void Clear() {
	cout<<"R" <<endl;
}

int main() {
	ios :: sync_with_stdio(0), cin.tie(0); cout.tie(0);
	
	cin >>n >>k;
	
	if(n == k) {
		int ans_t = 0;
		for(int i = 1; i <= n; i++) {
			cout<<"? " <<i <<endl;
			cin >>ns;
			if(ns == 'N')
				ans_t++; 
		}
		cout<<"! " <<ans_t;
		return 0;
	}
	
	int tim = 1;
	for(int i = 1; i <= n; i += (k / 2) + (k & 1)) {
		int tmp = i + (k / 2) + (k & 1);
		link[tim] = i;
		for(int j = i; j < tmp; j++) {
			vc[tim].push_back(j);
		}
		tim++;
	}
	--tim;
	
	for(int i = 1; i <= tim / 2; i++) {
		Add(i);
		int tmp = 0;
		while(tmp < tim - 1) {
			++tmp;
			if((tmp & 1)) {
				int cnt = tmp / 2 + 1;
				cnt += i;
				if(cnt > tim) cnt = cnt - tim;
				Add(cnt);
				continue;
			}
			int cnt = tmp / 2;
			cnt = i - cnt;
			if(cnt <= 0) cnt = tim + cnt;
			Add(cnt);
		}
		Clear();
	}
	
	int ans_t = 0;
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) ans_t++;
	}
	
	cout<<"! " <<ans_t;
	

}









