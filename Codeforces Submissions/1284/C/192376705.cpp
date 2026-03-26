#include<bits/stdc++.h>       
using namespace std;          
#define int long long  
#define fr(i, a, b) for (int i = a; i < b; i++)   
#define frr(i, a, b) for (int i = a; i >= b; i--)  
#define pb push_back  
#define ff first
#define ss second    
#define pr pair<int,int> 
// #define M 1000000007
#define lld long double          
#define timetaken cerr<<"Time : "<<1000*(long double)clock()/(long double)CLOCKS_PER_SEC<<"ms\n"       
int oo=999999999999999999;
int no=-999999999999999999;
//vector<vector<int>> vec(n,vector<int>(m,0));

const int N=250005;
void solve()
{
    int n,M;
    cin>>n>>M;
    int fact[N];
    fact[0]=fact[1]=1;
    fr(i,2,N)
    fact[i]=(fact[i-1]*i)%M;
    int ans=0;
    fr(j,0,n)
    {
        int x=((n-j)*(n-j))%M;
        x=(x*fact[j+1])%M;
        x=(x*fact[n-j-1])%M;
        ans=(ans+x)%M;
    }
    cout<<ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);  cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
        cout<<"\n";
    }
    timetaken;
}