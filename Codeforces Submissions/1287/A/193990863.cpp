#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll mod = 998244353;
const int mm = 3e5 + 10;
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int k;
		cin>>k;
		string a;
		cin>>a;
		int ma=0;
		int bj=0;
		int ans=0;
		for(int i=0;i<k;i++){
			if(a[i]=='A')bj=1;
			if(bj&&a[i]=='P')ans++;
			if(a[i]=='A')ans=0;
			ma=max(ans,ma);
		}cout<<ma<<'\n';
	}
}
