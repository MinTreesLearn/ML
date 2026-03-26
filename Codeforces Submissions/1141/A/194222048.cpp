#include<bits/stdc++.h>

using ll = long long;
using namespace std;
ll del(ll n, ll m) {ll a=0;if(n%m>0)a++;a+=n/m;return a;}

#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define all(v) (v.begin(), v.end())
#define inf 1e9 + 1e5
#define watch(x) cout << (#x) << " => " << (x) << endl

void solve(){
ll n, m;
cin >> n >> m;
ll ans = 0;
if(m % n != 0)
{
    cout<<-1;
    return;
}
m/=n;
while(m % 2 == 0)
{
    ans++;
    m/=2;
}
while(m % 3 == 0)
{
    ans++;
    m/=3;
}
if(m != 1)
{
    cout<<ans / ans * -1;
    return;
}
cout<<ans;
}
int main()
{
IOS
//ll _; cin>>_; while(_--)
solve();
return 0;
}
