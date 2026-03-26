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
const int N=1e7+3,M=10;
const int mod=998244353;
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
    int n,a,b;
    cin>>n>>a>>b;
    int x=a+b;
    if(x>n){
        int y=n-x%(n+1);
        cout<<min(n,n-y+2)<<" "<<n<<endl;
    }
    else{
        cout<<1<<" "<<min(n,x-1)<<endl;
    }
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