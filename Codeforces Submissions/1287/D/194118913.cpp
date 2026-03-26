#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll mod = 998244353;
const int mm = 3e5 + 10;
vector<int>v[2005];
int a[2005];
vector<int> dfs(int x,int y){
	vector<int>ans;
	for(auto i:v[x]){
		if(i==y)continue;
		vector<int>di=dfs(i,x);
		for(auto p:di)ans.push_back(p);
	}
	if(a[x]>ans.size()){
		cout<<"NO";
		exit(0);
	}ans.insert(ans.begin()+a[x],x);
	return ans;
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	cin>>n;
	int fa;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x>>a[i];
		if(x){
			v[x].push_back(i),
			v[i].push_back(x);
		}else fa=i;
	}
	vector<int>ans=dfs(fa,0);
	for(int i=0;i<ans.size();i++){
		a[ans[i]]=i;
	}cout<<"YES\n";
	for(int i=1;i<=n;i++){
		cout<<a[i]+1<<' ';
	}
}
