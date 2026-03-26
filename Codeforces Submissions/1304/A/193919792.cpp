#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define AWM() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    AWM();
    int t;
    cin>>t;
    while(t--)
    {
        ll int x,y,a,b,sum;
        cin>>x>>y>>a>>b;
        sum=abs(x-y);
        if(sum%(a+b)==0) cout<<sum/(a+b)<<endl;
        else cout<<"-1"<<endl;
    }

    return 0;
}

