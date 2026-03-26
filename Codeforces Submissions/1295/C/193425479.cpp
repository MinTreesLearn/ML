// Time Limit: 2023-02-13 11:44:50
// Just_Chill

#include<bits/stdc++.h>
#define int long long
#define mod (int)1000000007l
#define nl cout<<"\n";
#define pb push_back
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vvi vector<vector<int>>
#define mii map<int,int>
#define S second
#define F first
#define f(i,a,n) for(int i=a;i<n;i++)
#define fi(i,n,a) for(int i=n-1;i>=a;i--)
#define tcsolve(tcs) while(tcs--) solve();

using namespace std;
template<class T,class S> void print(map<T,S> mp) {for(auto it:mp) cout<<it.first<<" "<<it.second<<"\n";}	template<class T,class S> void print(map<T,vector<S>> mp) {for(auto it:mp){ cout<<it.first<<"\n";	 int l=it.second.size();for(int i=0;i<l;i++) cout<<it.second[i]<<" ";nl;}}	template<class T> void print(vector<vector<T>> &v) {int n=v.size(); for(int i=0;i<n;i++){ cout<<"key : "<<i+1<<"\n";cout<<"val : ";for(auto y:v[i]){ cout<<y<<" ";}cout<<"\n\n";}}	template <class T> void print(const T & c)	 {cout<<c<<"\n";}	template <class T,class K>  void print(const T & c,const K & d)	{cout<<c<<" "<<d<<"\n";}	template <class T,class A,class N>  void print(const T & c,const A & d,const N & e)	{cout<<c<<" "<<d<<" "<<e<<"\n";}	template <class T> void print(vector<T> & v){int l=v.size();for(int i=0;i<l;i++) cout<<v[i]<<" ";nl;}	template <class T,class S> void print(vector<pair<T,S>> & v){int l=v.size();for(int i=0;i<l;i++) cout<<v[i].first<<" "<<v[i].second<<"\n";}
#define arrayinput int n;cin>>n;vector<int> a(n);for(int i=0;i<n;i++)cin>>a[i];

void solve()
{
	string s,t;cin>>s>>t;
	map<char,set<int>> mp;
	int n=s.length();
	f(i,0,n)	mp[s[i]].insert(i);
	int l=t.length();
	int prev=-1;
	int cnt=1;
	f(i,0,l){
		auto it=mp[t[i]].upper_bound(prev);
		if(mp[t[i]].size()==0){
			print(-1);return;
		}
		if(it!=mp[t[i]].end()){
			prev=*it;
		}
		else{
			prev=-1;cnt++;i--;
		}
	}
	print(cnt);
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int tcs=1;
	   cin>>tcs;
	tcsolve(tcs);
}
