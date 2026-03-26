#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    int a[t+2];
    for(int i=0; i<t; i++)
    {
        int n,m;
        cin>>n>>m;
        if(n%m == 0)a[i]=1;
        else a[i] =0;
    }
    for(int i=0; i<t; i++)
    {
        if(a[i] == 1)cout<<"YES\n";
        else cout<<"NO\n";
    }
}