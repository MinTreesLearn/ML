#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll mod = 998244353;
const int mm = 3e5 + 10;
map<string,int>mp;
string a[1505];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			string s;
			for(int x=0;x<k;x++){
				if(a[i][x]=='E'&&a[j][x]=='E')s.push_back('E');
				else if(a[i][x]=='T'&&a[j][x]=='T')s.push_back('T');
				else if(a[i][x]=='S'&&a[j][x]=='S')s.push_back('S');
				else if(a[i][x]=='E'&&a[j][x]=='T')s.push_back('S');
				else if(a[i][x]=='T'&&a[j][x]=='E')s.push_back('S');
				else if(a[i][x]=='E'&&a[j][x]=='S')s.push_back('T');
				else if(a[i][x]=='S'&&a[j][x]=='E')s.push_back('T');
				else if(a[i][x]=='T'&&a[j][x]=='S')s.push_back('E');
				else if(a[i][x]=='S'&&a[j][x]=='T')s.push_back('E');
			}
			if(s==a[i]&&s==a[j])ans+=mp[s]-2;
			else ans+=mp[s];
		}
	}cout<<ans/3;
}
