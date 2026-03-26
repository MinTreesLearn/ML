#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,R=1e6;
const int mod=1e9+7;
typedef long long LL;

LL c[N][2],n;
int lowbit(int x){
	return x&(-x);
}
pair<LL,LL> query(int x){
	pair<LL,LL> res={0,0};
	for(int i=x;i>=1;i-=lowbit(i)){
		res.first+=c[i][0];
		res.second+=c[i][1];
	}
	return res;
}
void update(int x,int k){
	for(int i=x;i<=n;i+=lowbit(i)){
		c[i][0]+=k;
		c[i][1]++;
	}
}
void solve() {
	cin>>n;
	vector<pair<int,int> >a(n);
	vector<int>b(n);
	for(int i=0;i<n;i++)cin>>a[i].first;
	for(int i=0;i<n;i++){
		cin>>a[i].second;
		b[i]=a[i].second;
	}
	sort(b.begin(),b.end());
	for(int i=0;i<n;i++)a[i].second=lower_bound(b.begin(),b.end(),a[i].second)-b.begin()+1;
	long long ans=0;
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++){
		ans+=query(a[i].second).second*a[i].first-query(a[i].second).first;
		update(a[i].second,a[i].first);
	}
	cout<<ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	while(T--) {
		solve();
	}
	return 0;
}
/*

*/