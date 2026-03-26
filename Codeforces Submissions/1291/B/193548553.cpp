#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long int
#define vi vector<int>
int gcd(int a,int b) {if (b==0) return a; return gcd(b, a%b);}
int lcm(int a,int b) { return a/gcd(a,b)*b; }
bool prime(int a) { if (a==1) return 0;  for (int i=2;i<=round(sqrt(a));i++) if (a%i==0) return 0; return 1; }
void yes() { cout<<"Yes\n"; }
void no() { cout<<"No\n"; }
int ModExp(int x,int y){if(y==0) return 1;int p=ModExp(x,y/2);if(y&1)return (x*(p*p)%MOD)%MOD; return (p*p)%MOD;}

// *******************SOLVE START**************

void solve(){
    int n;
    cin>>n;
    vi arr(n);
    int ele=INT_MIN,maxi=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int a=INT_MAX,b=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<i){
            a=i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(arr[i]<n-i-1){
            b=i;
            break;
        }
    }
    // cout<<a<<" "<<b<<endl;
    if(a==INT_MAX||b==INT_MAX){
        yes();
        return ;
    }
    b++;
    a--;
    // cout<<a<<" "<<b<<endl;
    int r1=1,r2=1;
    for(int i=a+1;i<n;i++){
        if(i>=arr[a]||arr[i]<n-i-1){
            r1=0;
            break;
        }
    }
    for(int i=0;i<b;i++){
        if(i>=arr[b]||arr[i]<i){
            r2=0;
            break;
        }
    }
    if(r1||r2){
        yes();
    }
    else{
        no();
    }
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