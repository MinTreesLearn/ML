#pragma optimize("Bismillahirrahmanirrahim")
//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█■█
//█─█─█▄─█▄─█─█─█─█
//Allahuekber
//FatihSultanMehmedHan
//YavuzSultanSelimHan
//AbdulhamidHan
//Sani buyuk Osman Pasa Plevneden cikmam diyor.
//ahmet23 orz...
#define author tolbi
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define deci(x) int x;cin>>x;
#define decstr(x) string x;cin>>x;
#define cinarr(x) for (auto &it : x) cin>>it;
#define coutarr(x) for (auto &it : x) cout<<it<<" ";cout<<endl;
#define vint(x) vector<int> x
#define sortarr(x) sort(x.begin(),x.end())
#define sortrarr(x) sort(x.rbegin(), x.rend())
#define tol(bi) (1ll<<((int)(bi)))
#define revarr(x) reverse(x.begin(), x.end())
#define det(x) cout<<"NO\0YES"+(!!(x))*3<<endl;
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int MOD = 1e9+7;
mt19937 ayahya(chrono::high_resolution_clock().now().time_since_epoch().count());
struct Trie{
	struct Node{
		int lnode, rnode;
		int kac;
		int dept;
		Node():lnode(-1),rnode(-1),kac(0){}
	};
	vector<Node> trie;
	Trie(){trie.push_back(Node());}
	void insert(int val){
		int node = 0ll;
		for (int bit = 31; bit >= 0; bit--){
			if (val&tol(bit)){
				if (trie[node].rnode==-1) {
					trie[node].rnode=trie.size();
					trie.push_back(Node());
					trie.back().dept=bit;
				}
				node=trie[node].rnode;
			}
			else {
				if (trie[node].lnode==-1){
					trie[node].lnode=trie.size();
					trie.push_back(Node());
					trie.back().dept=bit;
				}
				node=trie[node].lnode;
			}
			trie[node].kac++;
		}
	}
	int query(int node = 0){
		if (trie[node].lnode==-1 && trie[node].rnode==-1){
			return 0ll;
		}
		if (trie[node].lnode!=-1 && trie[node].rnode!=-1){
			return tol(trie[trie[node].lnode].dept)+min(query(trie[node].lnode),query(trie[node].rnode));
		}
		else if (trie[node].lnode==-1){
			return query(trie[node].rnode);
		}
		else {
			return query(trie[node].lnode);
		}
	}
};
int32_t main(){
	ios;
	int T = 1;
	if (!T) cin>>T;
	int tno = 0;
	while (T-(tno++)){
		Trie trie;
		deci(n);
		for (int i = 0; i < n; ++i)
		{
			deci(x);
			trie.insert(x);
		}
		cout<<trie.query()<<endl;
	}
}