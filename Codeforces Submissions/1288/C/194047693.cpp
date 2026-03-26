 #include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ss string
#define loop1(i,n) for(ll i=0;i<n;++i)
#define loop2(i,n) for(ll i=n-1;i>=0;--i)
#define loop3(i,a,b) for(ll i=a;i<b;i++)
#define loop4(i,a,b) for(ll i=a;i>=b;i--)
#define NO cout<<"NO"<<endl; 
#define YES cout<<"YES"<<endl;
#define No cout<<"No"<<endl; 
#define Yes cout<<"Yes"<<endl;
#define out(x) cout<<x<<endl;

vector<vector<ll>>dp(2001,vector<ll>(2001,0));

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    ll n,m;cin>>n>>m;
    
    for(ll i=0;i<=2000;i++)
    {
        dp[i][0]=1;dp[i][i]=1;
    }
    for(ll i=1;i<=2000;i++)
    {
        for(ll j=1;j<i;j++)
        {
            dp[i][j]=(dp[i-1][j-1]%1000000007+dp[i-1][j]%1000000007)%1000000007;
        }
    }

    cout<<dp[2*m+n-1][n-1];
    
}
