#include <bits/stdc++.h>
#define ll long long int
#define srv(v) sort(v.begin(),v.end())
#define rrv(s1) sort(s1.begin(),s1.end(),greater<int>())
#define str string
#define sz size()
#define dv(v) vector<ll> v
#define ds(s) set<ll> s
#define dm(mp) map<ll,ll> mp
#define debug(x)  cout<<#x<<" "<<x<<endl
#define MOD 1000000007
int binpow(int a, int b){if (b==1){return a;}else if (b==0){return 1;}ll one = binpow(a,b/2);if (b%2==0){return one*one;}else{return a*one*one;}}
using namespace std;
int main()
{
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n,x;
    cin>>n>>x;

    int st=0;
    vector<int> v(x,0);
    // dm(mp);
  //  0 1 2
    //  2


    for (int i = 0; i < n; i++)
    {
        int y;
        cin>>y;
        if (y%x==st%x)
        {
            st++;
        }
        else
        {
            // mp[(y%x)]++;
            v[(y%x)]++;

            
            
        }

        while (v[st%x]>0)
        {
            v[st%x]--;
            st++;
        }
        

        cout<<st<<endl;
        
        
        
    }
    







    return 0;
}