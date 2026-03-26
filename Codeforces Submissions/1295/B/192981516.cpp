#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void sxseven();
int main() {
ios::sync_with_stdio(false);
int _=1;
cin >> _;
while(_--) {
sxseven();
}
return 0;
}
const int N=1e5+5;
map<ll,ll> mp;
void sxseven() {
ll n,x;
string s;
cin >> n >> x >> s;
mp.clear();
ll k=0;
for(int i=0; i<n; ++i) {
++mp[k];
if(s[i]=='0') ++k;
else --k;
}
if(k==0){
if(mp[x]) cout << -1 << endl;
else cout << 0 << endl;
}
else {
ll an=0;
for(auto it:mp) {
if(abs(x-it.first)%abs(k)==0 && (x-it.first)/k>=0) {
an+=it.second;
}
}
cout << an << endl;
}
}

