                 /**Bismillahir Rahmanir Rahim.**/
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int   ull;
typedef long long int            ll;
typedef long double              ld;
#define Faster      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi          acos(-1)
#define test        int t; cin>>t; while(t--)
#define dot(x)      fixed<<setprecision(x)
#define eps         0.000000001
#define dbug        cout <<"OK" <<endl;
#define mod         1000000007
#define MAX         100005
#define en          '\n'
#define ff          first
#define ss          second
inline void         yes(){cout<<"YES\n";}
inline void         no(){cout<<"NO\n";}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
//ordered_set variable;
//In order to insert multiple copies of the same element in the ordered set..
using ordered_multiset = tree<ll, null_type ,  less_equal<ll> , rb_tree_tag , tree_order_statistics_node_update>;
//ordered_multiset variable;
using ordered_map = tree<pair<ll,ll>, null_type, less<pair<ll,ll> >,rb_tree_tag, tree_order_statistics_node_update>;
// ordered_map varibale
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).

// priority_queue<int> Q (greatar to smaller)
// priority_queue<int, vector<int>, greater<int> > Q;   (smaller to greater)

// p^e % m
ll bigMod(ll p, ll e, ll M) {ll ret = 1; for (; e > 0; e >>= 1) { if (e & 1) ret = (ret * p) % M; p = (p * p) % M;} return (ll)ret;}
ll modInverse(ll a, ll M) {return bigMod(a, M - 2, M);}
ll gcd(ll a, ll b) {if (b == 0)return a; return gcd(b, a % b);}
ll lcm(ll a, ll b) {a = abs(a); b = abs(b); return (a / gcd(a, b)) * b;}

int chessx[]={-1,-1,1, 1,-2,-2, 2,2}; //knight
int chessy[]={ 2,-2,2,-2, 1,-1,-1,1}; //knight
int xx[]={ 0,0,1,-1,-1,-1,1,1};
int yy[]={-1,1,0, 0,-1,1,1};
const double EPS = 1e-12;
///Bit-Masking.. pos is 0 based index and starts from left to right: [31 30 ... ... ... 3 2 1 0]
ll onbit(ll N, ll pos) {
    return N = N | (1 << pos);
}
ll offbit(ll N, ll pos) {
    return N = N & ~(1 << pos);
    //or return N = N & !(1<<pos);
}
ll flipbit(ll N, ll pos) {
    return N = N ^ (1 << pos);
}
bool checkbit(ll N, ll pos) {
    return (bool)(N & (1 << pos));
}
int main()
{
    int t1=1;
    Faster
    // test
    // {
    ll n,i,j,cnt=0,res=0;
    cin>>n;
    vector<ll> mn,mmx;
    for(i=1;i<=n;i++)
    {
        ll l;
        cin>>l;
        ll a[l+1];
        ll mi=INT_MAX,mx=0;
        for(j=1;j<=l;j++)
        {
            cin>>a[j];
            mi=min(mi,a[j]);
            mx=max(mx,a[j]);
        }
        ll flag=0;
        for(j=1;j<l;j++)
        {
            if(a[j]<a[j+1])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            mn.push_back(mi);
            mmx.push_back(mx);
        }
        else
            cnt++;
    }
    sort(mn.begin(),mn.end());
    sort(mmx.begin(),mmx.end());
    ll ans=0;
    for(i=0;i<mn.size();i++)
    {
        
        auto l1=upper_bound(mmx.begin(),mmx.end(),mn[i])-mmx.begin();
        
        ans+=(mmx.size()-l1);
    }
    //cout<<ans<<en;
    // for(i=0;i<mmx.size();i++)
    // {
    //     auto l1=lower_bound(mn.begin(),mn.end(),mmx[i])-mn.begin();
    //     if(l1>i)
    //         ans+=(l1-i);
    // }
    //
    //cout<<ans<<en;
    ans+=(((n-cnt)*2)*cnt)+cnt+(cnt*(cnt-1));

    cout<<ans<<en;
    //cout<<ans+ +cnt<<en;

    // }
}