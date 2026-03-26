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
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<pair<int,int>,int>m;
    int ans = INT_MAX;
    m[{0,0}]=0;
    int x=0,y=0,co1,co2;
    fa(i,0,n){
        if(s[i]=='R')x++;
        else if(s[i]=='L')x--;
        else if(s[i]=='U')y++;
        else y--;
        if(m[{x,y}] || x==0 && y==0){
           // cout<<i+1<<" "<<m[{x,y}]<<endl;
            if(i+1-m[{x,y}]<ans){
                co1=m[{x,y}]+1;
                co2=i+1;
                ans = i+1-m[{x,y}];
            }
        }
        m[{x,y}]=i+1;
    }
    if(ans==INT_MAX)cout<<-1<<endl;
    else cout<<co1<<" "<<co2<<endl;
    return;
}
signed main()
{
    Utaval;
    int t=1;
    cin>>t;
    while(t--)
    solve();
}