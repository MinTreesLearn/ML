                                        //Your worst fear owns this
#include <bits/stdc++.h>
#define ll long long int
#define srv(v) sort(v.begin(),v.end())
#define rrv(s1) sort(s1.begin(),s1.end(),greater<ll>())
#define str string
#define sz size()
#define dv(v) vector<ll> v
#define ds(s) set<ll> s
#define dm(mp) map<ll,ll> mp
#define MOD 1000000007
#define debug(x)  cout<<#x<<" "<<x<<endl
int binpow(int a, int b){if (b==1){return a;}else if (b==0){return 1;}ll one = binpow(a,b/2);if (b%2==0){return one*one;}else{return a*one*one;}}
using namespace std;
int dp[2001][2001];
int knap(vector<int> &v, int st,int cur, int h,int l, int r){


    if (st>=v.sz)
    {
       if (l<=cur&&cur<=r)
       {
          return 1;
       }

        return 0;
    }
    if (dp[st][cur]!=-1)
    {
        return dp[st][cur];
    }
    
    int tot=0;
    if (l<=cur&&cur<=r&&st!=0)
    {
        tot++;
    }

    int ne1 = cur+v[st];
        ne1%=h;

    int ne2 = cur+(v[st]-1);

        ne2%=h;

    tot+=max(knap(v,st+1,ne1,h,l,r),knap(v,st+1,ne2,h,l,r));
    return dp[st][cur] = tot;



}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
            int n,h,l,r;
             cin>>n>>h>>l>>r;
            vector<int> v;
            memset(dp,-1,sizeof(dp));
              for (int i = 0; i < n; i++)
               {
                     int x;
                    cin>>x;
                     v.push_back(x);
                }

                knap(v,0,0,h,l,r);



                cout<<dp[0][0]<<endl;



                        
                              
return 0;
}