//#include<bits/stdc++.h>
#include<algorithm>
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include<deque>
#include<climits>
#include<complex>

#define EPS          1E-9
#define PI           acos(-1)
#define SQR(n)       (n*n)
using namespace std;
#define M            1000000007
#define INF          (1<<30)-1+(1<<30)
#define fast         ios::sync_with_stdio();cin.tie(nullptr)
#define all(v)       (v).begin(), (v).end()
#define ll           long long
#define f0(i, n)     for(int (i) = 0; i <  (n); i++)
#define f1(i, n)     for(int (i) = 1; i <= (n); i++)
#define fn0(i, n)    for(int (i) = (n)-1;(i)>=0;i--)
#define fn1(i, n)    for(int (i) = (n);(i)>=1;i--)
#define endl         "\n"
#define pb           push_back
#define UNIQUE(v)    (v).erase(unique(all(v)), (v).end())
#define sz()         size()
#define UB           upper_bound
#define LB           lower_bound
#define pll          pair<ll, ll>
#define mxe(a,n)     (*max_element(a,a+n))
#define mne(a,n)     (*min_element(a,a+n))
#define countbit(x)  __builtin_popcount(x)
#define P            printf
//moves
int dx[] = { -1,+0,+1,+0,-1,-1,+1,+1};
int dy[] = { +0,-1,+0,+1,+1,-1,+1,-1};
//bit
int     Set(int N,int pos){ return N=N | (1<<pos);}
int     Reset(int N,int pos){ return N= N & ~(1<<pos);}
bool    Check(int N,int pos){ return (bool)(N & (1<<pos));}
template< class T, class X > inline T   togglebit(T a, X i) { T t=1;return (a^(t<<i)); }
//fn
template <typename T> T     BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T     ModInv (T b,T m){return BigMod(b,m-2,m);}
template <typename T> T     POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
template <typename T> T     Dis(T x1,T y1,T x2, T y2){return sqrt( SQR(x1-x2) + SQR(y1-y2) );}
template <typename T> T     Angle(T x1,T y1,T x2, T y2){ return atan( double(y1-y2) / double(x1-x2));}
template <typename T> T     DIFF(T a,T b) { T d = a-b;if(d<0)return -d;else return d;}
template <typename T> T     gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <typename T> T     lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template <typename T> void  pall(T a){for(int i=0;i<a.size();i++){cout<<a[i]<<" ";}cout<<endl;}
template <typename T> void  pall(T a[], T n){for(int i=0;i<n;i++){cout<<a[i]<<" ";}cout<<endl;}
template <typename T> void  yes(T a){if(a==1)printf("YES\n");else printf("Yes\n");}
template <typename T> void  no(T a){if(a==1)printf("NO\n");else printf("No\n");}



string s, str;





void solve(int tc){
    ll n, m, x;
    cin >> n >> m;
    ll arr[n+1][26];
    memset(arr, 0, sizeof(arr));
    cin >> s;
    ll tot[26];
    memset(tot, 0, sizeof(tot));
    f0(i, n){
        ll x = s[i] - 'a';
        tot[x]++;
        f0(j, 26){
            arr[i+1][j] = tot[j];
        }
    }
    ll ans[26];
    memset(ans, 0ll, sizeof(ans));
    for(int i=0;i<m;i++){
        cin >> x;
        for(int j=0;j<26;j++){
            ans[j] += arr[x][j];
        }
    }
    for(int i=0;i<n;i++){
        ll x = s[i]-'a';
        ans[x]++;
    }
    for(int i=0;i<26;i++){
        cout << ans[i] <<" ";
    }

    cout << endl;


}


int main(){
    int tc = 1, cas_no = 0;
    cin >> tc;
    while(tc--){cas_no++;
        solve(cas_no);
    }
    return 0;
}