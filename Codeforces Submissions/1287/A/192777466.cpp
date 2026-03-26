#include<bits/stdc++.h>
#define eps 1e-9
#define emailam  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll              long long
#define ull             unsigned long long
#define MAX 200010
#define pb push_back
#define all(a)  a.begin(),a.end()
#define pf push_front
#define fi first
#define se second
#define pii pair<int,int>
const long long  INF = LLONG_MAX;
using namespace std;
const int N=3e5+10,M=10;
const int mod=998244353;
#define int long long
/*----------------------------------------------------------------*/
int dx[] = {+0, +0, -1, +1, +1, +1, -1, -1};
int dy[] = {-1, +1, +0, +0, +1, -1, +1, -1};
/*----------------------------------------------------------------*/
void READ(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='P'){
            for(int j=i-1;j>=0;j--){
                if(s[j]=='A'){
                    ans=max(ans,i-j);
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;
}



signed main() {
    emailam
    //READ();
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}