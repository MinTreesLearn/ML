/*
It is code Zhanabergen Abdurroshid :))))
*/
#include<bits/stdc++.h>
#define ll long long
#define int ll
#define m_p make_pair
#define p_b push_back
#define pii pair<int,int>
#define piii pair<int,pii>
#define vi vector<ll>
#define vii vector<pii>
#define viii vector<pair<int,pii> >
#define si set<int>
#define sii set<pii>
#define siii set<pair<int,pii> >
#define F first
#define S second
#define pre precision
#define n_per next_permutation
#define sz size()
#define RUN ios_base::sync_with_stdio(false);cin.tie(0);
#define OPEN freopen("unionday.in","r",stdin);freopen("unionday.out","w",stdout)
using namespace std;
ll fl(){
	ll a;
	cin>>a;
	return a;
}
const ll N = 5e5 + 9, INF = 2e18 + 9, MOD = 1e9 + 7;
int check(vi v){
	for(int i=0;i<v.sz;i++){
		for(int j=i+1;j<v.sz;j++){
			for(int h=j+1;h<v.sz;h++){
				if(v[i]<=v[j]&&v[j]<=v[h]){
					return 0;
				}
				if(v[i]>=v[j]&&v[j]>=v[h]){
					return 0;
				}
			}
		}
	}
	return 1;
}
main(){
	RUN;
	int ti = fl();
	while(ti--){
		int n = fl(), m = fl();
		int all = n*(n+1)/2;
		int ost = n-m;
		int b = ost%(m+1);
		int a = m+1-b;
		int len = ost/(m+1);
		cout<<all-(a*(len*(len+1)/2))-(b*((len+1)*(len+2)/2));
		cout<<'\n';
	}
	return 0;
}