#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long 
#define sort(v) sort(v.begin(),v.end())
void solve(){
	int n,x;
	cin>>n>>x;
	vector<int> v;
	int ans=1e10;
	int mx=0;
	for(int i=0;i<n ;i++)
	{
		int t;
		cin>>t;
		if (x%t==0)
		{
			ans=min(ans,x/t);
		}
		mx=max(mx,t);
		
		v.push_back(t);
	}
	// cout<<ans<<endl;
	if (ans==1)
	{
		cout<<ans<<endl;
		return;
	}
	int ct=0;
	ct=(x/mx);
	if (ct==0)
	{
		ct+=2;
	}
	else
	{
		ct+=1;
	}
	
	
	
	ans=min(ans,ct);
	cout<<ans<<endl;
	
	
	
	
	
}
signed main(){

	fast
	int t;
	cin>>t;
	while(t--)
	{ solve(); }
	return 0;
}
