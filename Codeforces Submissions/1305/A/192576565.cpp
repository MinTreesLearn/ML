#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define pb push_back

using namespace std;

int32_t main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		sort(a,a+n);
		int b[n];
		for(int i=0;i<n;i++)cin>>b[i];
		sort(b,b+n);
		for(int i=0;i<n;i++)cout<<a[i]<<" ";
		cout<<endl;
		for(int i=0;i<n;i++)cout<<b[i]<<" ";
		cout<<endl;
	}
}