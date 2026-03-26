#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long int
#define vi vector<int>
int gcd(int a,int b) {if (b==0) return a; return gcd(b, a%b);}
int lcm(int a,int b) { return a/gcd(a,b)*b; }
bool prime(int a) { if (a==1) return 0;  for (int i=2;i<=round(sqrt(a));i++) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
int ModExp(int x,int y){if(y==0) return 1;int p=ModExp(x,y/2);if(y&1)return (x*(p*p)%MOD)%MOD; return (p*p)%MOD;}

// *******************SOLVE START**************

void solve(){
    int n;
    cin>>n;
    vi arr(n);
    vi pref(n+1,0);
    int maxpref=0,minpref=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        pref[i+1]=pref[i]+arr[i];
    }
    for(int i=1;i<=n;i++){
        if(pref[i]>pref[maxpref]){
            maxpref=i;
        }
        if(pref[i]<=pref[minpref]){
            minpref=i;
        }
    }
    if((maxpref==n&&minpref==0)||(pref[n]>pref[maxpref]-pref[minpref])) yes();
    else no();
}

// *******************SOLVE END****************

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in","r",stdin);
    freopen("outputf.out","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}