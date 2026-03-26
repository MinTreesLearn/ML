#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<long long>dp(n+1,0);
    dp[n]=1;
    for(int i=1;i<=2*m+1;++i){
      for(int j=n-1;j>0;--j){
         dp[j]+=dp[j+1];
         dp[j]%=1000000007;
        
      }
    }
    cout<<dp[1];
    
}
