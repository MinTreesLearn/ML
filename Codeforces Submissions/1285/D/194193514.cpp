#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll mod = 998244353;
const int mm = 1e5 + 10;
vector<int>b;
ll dfs(int x,vector<int>v){
	if(v.size()==0||x<0)return 0;
	vector<int>l,r;
	for(auto i:v){
		if((1<<x)&i)l.push_back(i);
		else r.push_back(i);
	}
	if(l.size()==0)return dfs(x-1,r);
	else if(r.size()==0)return dfs(x-1,l);
	else return (1<<x)+min(dfs(x-1,l),dfs(x-1,r));
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		ll x;
		cin>>x;
		b.push_back(x);
	}
	cout<<dfs(30,b);
}
