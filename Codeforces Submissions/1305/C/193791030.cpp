// Time Limit: 2023-02-16 11:21:42
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
#define arrayinput int n,m;cin>>n>>m;vector<int> a(n);for(int i=0;i<n;i++)cin>>a[i];

void solve()
{
	arrayinput;
	if(n<=m){
		int p=1;
		f(i,0,n){
			f(j,i+1,n){
					p=p*(abs(a[i]-a[j]));
					p=p%m;
			}
		}
		print(p);
	}
	else{
		print(0);
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int tcs=1;
	tcsolve(tcs);
}
