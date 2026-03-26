#include<bits/stdc++.h>
#define int long long
#define fa(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define bp pop_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define Utaval  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

void solve(){
    int n,a,b,k;
    cin>>n>>a>>b>>k;
    vector<int>v(n),temp;
    fa(i,0,n)cin>>v[i];
    fa(i,0,n){
        int kar = v[i]%(a+b);
        if(!kar)temp.pb(b);
        else if(kar>a)temp.pb(kar-a);
    }
    int ct=0;
    sort(temp.begin(),temp.end());
    ct+=(n-temp.size());
    fa(i,0,temp.size()){
        int ans = temp[i]/a;
        if(temp[i]%a)ans++;
        if(ans>k)break;
        k-=ans;
        ct++;
    }
    cout<<ct<<endl;
    return;
}
signed main()
{
    Utaval;
    int t=1;
   // cin>>t;
    while(t--)
    solve();
}