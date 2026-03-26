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
const int INF = INT_MAX;
using namespace std;
const int N=4e5+10,M=10;
const int mod=1e9+7;
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
set<int>mex;
void buildmex(){
    for(int i=0;i<N;i++){
        mex.insert(i);
    }
}
void solve(){
    buildmex();
    int q,x;
    cin>>q>>x;
    map<int,int>frq;
    while(q--){
        int n;
        cin>>n;
        frq[n%x]++;
        int k=*mex.begin();
        while(frq[k%x]){
            frq[k%x]--;
            mex.erase(k);
            k=*mex.begin();
        }
        cout<<k<<endl;
    }
}



signed main() {
    emailam
    //READ();
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}