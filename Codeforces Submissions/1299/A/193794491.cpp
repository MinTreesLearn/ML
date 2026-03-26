// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define whatis1(x) cout<<#x<<"="<<x<<'\n'
#define whatis2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define whatis3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define whatisArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++)  cout<<arr[m]<<" ";cout<<'\n';
#define whatArray2D(arr,m,n) cout<<#arr<<", Size: "<<m<<","<<n<<'\n';for(int mm=0;mm<m;mm++){for(int nn=0;nn<n;nn++)cout<<arr[mm][nn]<<" ";cout<<'\n';} 
#define caseprint(caseno,ans) cout<<"Case "<<caseno<<": "<<ans<<'\n'
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mod 1000000007
#define MX 200005

using namespace std;
using ll = long long;

void solve(int caseno){
    int n;
    cin>>n;
    ll xr= 0;;
    vector<ll> v(n);
    vector<int> pos[35];
    for(int i=0;i<n;i++) {
        cin>>v[i];
        for(int j=0; j<32; j++) {
            if((v[i]>>j)&1LL){
                pos[j].push_back(i);
            }
        }
    }

    //sort(v.begin(),v.end(),greater<ll>());  
    bool taken[n+5]={0};
    for(int i=32; i>=0; i--) {
        if(pos[i].size()==1 && !taken[pos[i][0]]){
            cout<<v[pos[i][0]]<<' ';
            taken[pos[i][0]]=true;
        }
    }
    for(int i=0; i<n; i++) {
        if(!taken[i])cout<<v[i]<<' ';
    }
    cout<<'\n';
    return;
    
}
int main()
{
    ios::sync_with_stdio(0);
    int cases,caseno=0;
    cases=1;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}       