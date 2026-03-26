#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod = 1e9 + 7;
const ll mm = 2e5 + 10;
string s[25],t[25];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i-1];
	for(int i=1;i<=m;i++)cin>>t[i-1];
	int q;
	cin>>q;
	while(q--){
		ll y;
		cin>>y;
		cout<<s[(y-1)%n]<<t[(y-1)%m]<<'\n';
	}
}
