#include<bits/stdc++.h>
#define int long long
#define fa(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define bp pop_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
 
void solve(){
    int a,b;
    cin >> a >> b;
    int cnt=0,ans;
    map<int,int> m;
    while(b>0)
    {
        m[b%10]++;
        b/=10;
        cnt++;
    }
    if(m[9]==cnt)
    {
        ans=cnt;
    }
    else
    {
        ans=cnt-1;
    }
    cout << (a*ans) << endl;
    return;
}
signed main()
{
    faster;
    int t=1;
    cin>>t;
    while(t--)
    solve();
}