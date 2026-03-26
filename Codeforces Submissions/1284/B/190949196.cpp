#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod = 1e9 + 7;
const ll mm = 1e5 + 10;
int mi[mm],ma[mm],bj[mm];
int mii[mm*10],maa[mm*10];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		mi[i]=1000000;
	}
	for(int i=1;i<=n;i++){
		int l;
		cin>>l;
		vector<int>ana;
		for(int j=1;j<=l;j++){
			int x;
			cin>>x;ana.push_back(x);
			mi[i]=min(x,mi[i]);
			ma[i]=max(x,ma[i]);
		}
		for(int j=1;j<ana.size();j++){
			if(ana[j-1]<ana[j])bj[i]=1;
		}
		if(bj[i]==0)maa[ma[i]]++;
	}
	for(int i=1000000;i>=0;i--){
		maa[i]+=maa[i+1];
	}
	ll ans=0;
	ll x=0;
	for(int i=1;i<=n;i++){
		if(bj[i])x++;
		else ans+=maa[mi[i]+1];
	}
	ans+=x*(n*2-1)-(x-1)*x;
	cout<<ans;
}
