#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout<<"YES"<<"\n"
#define no cout<<"NO"<<"\n"
#define fori(i, a, n) for (int i = a; i < n; i++)
#define ford(i, n, a) for (int i = n-1; i >= a; i--)
#define mod 1000000007
#define PI 3.141592653589793238462
#define line cout<<"\n"
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#ifndef DataTypeShorthands
typedef vector<int> vi;
typedef vector<string> vs;
typedef unordered_set<int> usi;
typedef unordered_set<char> usc;
typedef unordered_set<string> uss;
typedef unordered_map<int,int> umii;
typedef set<int> si;
typedef set<char> sc;
typedef set<string> ss;
typedef map<int,int> mii;
#endif

#ifndef RegularFunctions
#define pb push_back
#define ppb pop_back
#define mp make_pair
#endif

#ifndef ONLINE_JUDGE
#define debug(x) cout << #x <<" "; _print(x); cout << endl;
#define debugarr(x,s) cout<<#x<<" "; cout<<"[ "; for(int i=0;i<s;i++) cout<<x[i]<<" ";cout<<"]"; cout<<endl;
#else
#define debug(x)
#define debugarr(x,s)
#endif

void _print(ll t) {cout << t;}
void _print(string t) {cout << t;}
void _print(char t) {cout << t;}
void _print(lld t) {cout << t;}
void _print(double t) {cout << t;}
void _print(ull t) {cout << t;}
 
 
template<class T>void _print(vector<T> v){cout<<"[ "; for(T i:v){_print(i); cout<<" ";} cout<<"]";} 
template<class T, class V> void _print(pair<T,V> p){cout<<"{ "; _print(p.first); cout<<","; _print(p.second);cout<<" }";}
template<class T> void _print(set<T> s){cout<<"["; for(T i: s) {_print(i); cout<<" ";} cout<<"]";}
template<class T, class V> void _print(map<T,V> m) {cout<<"[ "; for(auto i: m){_print(i); cout<<" ";}cout<<" ]";}

void arrin(int arr[], int n){for(int i=0;i<n;i++)cin>>arr[i];}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    fori(i,0,n)
    {
        int x;
        cin >> x;
        x-=i;
        v.pb(mp(x,x+i));
    }
    sort(all(v));
    int maxi=INT_MIN,temp=v[0].second;
    fori(i,1,n)
    {
        int x=v[i].first;
        if(x==v[i-1].first)
        {
            temp+=v[i].second;
        }
        else
        {
            maxi=max(maxi,temp);
            temp=v[i].second;
        }
    }
    maxi=max(maxi,temp);
    cout << maxi << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t;
    // cin >> t;
    // for(int p=1;p<=t;p++)
    // {
    //     // cout << "Case #" << p << ": ";
        solve();
    // }

    return 0;
}