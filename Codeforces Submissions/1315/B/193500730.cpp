#include<bits/stdc++.h>
#define int long long int
#define rep(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
#define vll vector<long long int>
using namespace std;
bool isPossible(int num,string &str,int a,int b,int have){
	int total_cost = 0;
	char prev = 'Z';
	for(int i=num;i<str.length();i++){
		if(str[i] != prev){
			prev = str[i];
			if(str[i] == 'A') total_cost += a;
			else total_cost += b;
		}
	}
	return total_cost<=have;
}
void solve()
{
	int a,b,p;cin>>a>>b>>p;
	string str;cin>>str;
	int n = str.length();
	str = str.substr(0,n-1);
	int lo = 0, hi = 1e9;
	while(lo < hi){
		int mid = (lo + hi)/2;
		if(isPossible(mid,str,a,b,p)){
			hi = mid;
		}
		else{
			lo = mid + 1;
		}
	}
	cout<<lo+1<<endl;
}

signed main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}

