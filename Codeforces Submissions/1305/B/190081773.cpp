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
    string s;
    cin>>s;
    vector<int>v;
    int start=0,end=s.length()-1;
    while(start<end){
        if(s[end]=='(')end--;
        else{
            while(start<end){
                if(s[start]=='('){
                    v.pb(start+1),v.pb(end+1);
                    start++,end--;
                    break;
                }
                else start++;
            }
        }
    }
    sort(v.begin(),v.end());
    if(v.size()==0)cout<<0<<endl;
    else{
    cout<<1<<endl<<v.size()<<endl;
    fa(i,0,v.size())cout<<v[i]<<" ";
    cout<<endl;
}
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