#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define endl '\n'
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define f(i,a,b) for(ll i = a; i <= b; i++)
#define fr(i,a,b) for(ll i = a; i >= b; i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) ((int)(x).size())
#define llceil(a,b) ceil(((double)a)/((double)b))
#define llfloor(a,b) floor(((double)a)/((double)b))
#define vec vector<ll>
#define dvec vector<vector<ll>>
//////*************Nitin1605***************//////

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    ll n,a=LLONG_MAX,x,ans=-1,mi=LLONG_MAX;
    cin>>n;
    vec v(n);
    f(i,0,n-1)cin >> v[i];
    f(j,0,n-1)
    {
        x=v[j];a=0;
        f(i,j,n-1)
        {
            if(v[i]>x)a+=(v[i]-x);
            else x=v[i];
        }
        x=v[j];
        fr(i,j,0)
        {
            if(v[i]>x)a+=(v[i]-x);
            else x=v[i];
        }
        if(mi>a)
        {
            ans=j;
            mi=a;
        }
    }
    x=v[ans];
    f(i,ans+1,n-1)
    {
        if(v[i]>v[i-1])v[i]=v[i-1];
    }
    x=v[ans];
    fr(i,ans-1,0)
    {
        if(v[i]>v[i+1])v[i]=v[i+1];
    }
    for(auto i:v)
    cout << i << " ";
}