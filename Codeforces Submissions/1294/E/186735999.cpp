#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,R=1e6;
const int mod=1e9+7,inf=1e9;


void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int> >a(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    long long ans=0;
    for(int j=0;j<m;j++){
        map<int,int>cnt;
        for(int i=0;i<n;i++){
            if((a[i][j]-j-1)%m==0){
                int x=(a[i][j]-j-1)/m;
                if(x>=0&&x<n){
                    if(i>=x)cnt[i-x]++;
                    else cnt[i-x+n]++;
                }
            }
        }
        int tmp=n;
        for(auto [k,v]:cnt)tmp=min(tmp,(n-v)+k);
        ans+=tmp;
    }
    cout<<ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T=1;
    while(T--) {
        solve();
    }
    return 0;
}
/*
99 5 2 3 100 101 6 7
x 5 1 1 x x 1 1
1 1

*/