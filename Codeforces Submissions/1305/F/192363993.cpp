#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353



int check(int a[],int p,int n)
{
    int ans=0;
    for(int i=0;i<n;i++)
        {
            if(a[i]<p){ans+=(p-a[i]);continue;}
            int x=a[i];
            ans+=min(x%p,p-x%p);
        }
    return ans;
}


vector<int> primes(int x)
{
    vector<int> v;

    for(int i=2;i*i<=x;i++)
        {
            if(x%i==0)
                {
                    v.push_back(i);
                    while(x%i==0){x=x/i;}
                }
        }
    if(x>1){v.push_back(x);}

    return v;
}


std::mt19937 rng((unsigned int) std::chrono::steady_clock::now().time_since_epoch().count());



int32_t main()
{

//   ios::sync_with_stdio(0);
  // cin.tie(0);


   int n;
   cin>>n;

   int a[n];
   for(int i=0;i<n;i++){cin>>a[i];}


   int ans=1e15;
   for(int i=0;i<25;i++)
    {
        int ind=rng()%n;
        vector<int> v;
        for(int x=a[ind]-1;x<=a[ind]+1;x++)
            {
                for(auto y:primes(x)){v.push_back(y);}
            }

     /*   for(auto x:v)
            {
                if(check(a,x,n)==3){cout<<x<<"P\n";}
            }*/

        for(auto x:v){ans=min(ans,check(a,x,n));}
    }

    cout<<ans;

}
