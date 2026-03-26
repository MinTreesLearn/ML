#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
int n;
cin >> n;
map<int,int>mp;
int ans = 0;
for(int i = 1; i<=n ; i++) {
int c=i,b;
cin >> b;
int f = c-b;
mp[f]+=b;
ans=max(ans,mp[f]);
}
cout << ans << '\n';
}


