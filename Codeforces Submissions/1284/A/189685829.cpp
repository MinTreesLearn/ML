#include <bits/stdc++.h>
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define pb push_back
#define mod 998244353
using namespace std;
mt19937 rng(time(0));
int random(int l, int r) { return rng() % (r - l + 1) + l; }
int main()
{
    int n,m;
    cin>>n>>m;
    string a[n],b[m];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    int k;
    cin>>k;
    while(k--){
    int r;
    cin>>r;
    r--;
    cout<<a[r%n]<<b[r%m]<<endl;
    }
}
