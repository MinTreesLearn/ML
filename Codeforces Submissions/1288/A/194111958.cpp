#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
ll q,n,x,d,y,z,r;

int main()
{
    fast
    cin>>q;
    while(q--)
    {
        cin>>n>>d;
        if(n>=d)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            ll mi=1e13;
            x=1e7;
            while(x>0)
            {
               ll ans=x+ceil(((double )d)/(x+1));
                mi=min(mi,ans);
                x--;
            }


        if(mi<=n)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }}
    }

return 0;
}

