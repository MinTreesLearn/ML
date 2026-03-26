#include <iostream>
using namespace std;

const int N = 510;

int dp[N][N], one[N][N], a[N];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];

    for(int i=1; i<=n; i++)
        dp[i][i] = 1, one[i][i] = a[i];
    for(int len=2; len<=n; len++)
    {
        for(int i=1; i + len - 1<=n; i++)
        {
            int j = i + len - 1;
            dp[i][j] = 10000;
            for(int k=i+1; k<=j; k++)
            {
                if(one[i][k-1] != 0 && one[i][k-1] == one[k][j])
                    one[i][j] = one[i][k-1] + 1, dp[i][j] =  1;
                dp[i][j] = min(dp[i][j], dp[i][k-1] + dp[k][j]);
            }
        }
    }
    cout<<dp[1][n]<<flush;
    return 0;
}
