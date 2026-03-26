#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=405;
bitset<maxn> dp[maxn][maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        string s1,s2;cin>>s1>>s2;
        int m=s2.size();s2.push_back('$');
        bool ok=false;
        {
            for(int i=0;i<=m;++i) for(int j=0;j<=m;++j) dp[i][j]=0;
            for(int i=0;i<=m;++i) dp[0][i][i]=1;
            for(char c:s1)
            {
                for(int i=m;i>=0;--i)
                {
                    for(int j=m;j>=i;--j)
                    {
                        if(c==s2[i]) dp[i+1][j]|=dp[i][j];
                        if(c==s2[j]) dp[i][j+1]|=dp[i][j];
                    }
                }
            }
            for(int i=0;i<m;++i){
            if(dp[i][m][i])
            {
                ok=true;
                break;
            }}
        }
        puts(ok ? "YES" : "NO");
    }
    return 0;
}
