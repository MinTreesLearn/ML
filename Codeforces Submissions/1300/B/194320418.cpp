#define llt long long i 
using namespace std;       //s  //h
#include<vector>           //w  //a
#include<map>              //a  //r
#include<list>             //r  //s
#include<set>              //a  //h
#include<algorithm>        //j  //i
#include<queue>                 //t
#include<cstring>
#include<cmath>
#include<bitset>
#include<string>
#include<cstdlib>
#include<bits/stdc++.h>
#define ll long long 
#define input(a,n)  for(int i=0;i<n;i++)cin>>a[i];
#define w(t)           while(--t >= 0)nt
#define ss second
#define endl '\n'ios_base::sync_with_stdio(false);
#define pb push_back

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,b;
cin>>n;
ll a[2*n];
input(a,2*n);
sort(a,a+2*n);
b=a[n]-a[n-1];
cout<<b<<'\n';

}
}