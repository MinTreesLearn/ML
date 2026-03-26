/******************************************************************************
 
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
 
*******************************************************************************/
 
#include <bits/stdc++.h>
#define int long long 
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
    return a;
    return gcd(b,a%b);
}
int32_t main()
{
int t=1;
//cin>>t;
while(t--)
{
int n,q;
cin>>n>>q;
vector<vector<int>>v(2,vector<int>(n+10,0));
int wall=0;
for(int i=0;i<q;i++)
{
    int a,b;
    cin>>a>>b;
    a--;
    int p=(a+1)%2;
    if(v[a][b])
    {
        
        
        wall-=(v[p][b+1]+v[p][b-1]+v[p][b]);
    }else
    {
          
                wall+=v[p][b+1]+v[p][b-1]+v[p][b];
    }
    v[a][b]^=1;
    if(wall==0)
    cout<<"Yes\n";
    else cout<<"No\n";
    
}
}
    return 0;
}