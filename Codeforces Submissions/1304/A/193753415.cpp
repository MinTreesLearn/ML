#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll x,y,a,b;
        cin>>x>>y>>a>>b;
        ll k,n;
        k=y-x;
        n=a+b;
        if((k<n)||(k%n!=0))
        {
            cout<<"-1"<<endl;
        }
        else
        {
            cout<<k/n<<endl;
        }
    }
    return 0;
}
