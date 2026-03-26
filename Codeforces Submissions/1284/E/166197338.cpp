#include <bits/stdc++.h>
#include <random>
#include <chrono>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
//typedef pair<double,double> pdd;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T> void _do(T x){cerr<<x<<"\n";}
template<typename T,typename ...U> void _do(T x,U ...y){cerr<<x<<", ";_do(y...);}
#define dbg(...) cerr<<#__VA_ARGS__<<" = ";_do(__VA_ARGS__);
 
const int MOD1=1e9+7;
const int MOD2=998244353;
const ll INF=3e18;
const ld PI=3.14159265358979323846;
ll gcd(ll a,ll b){if(b==0) return a; return gcd(b,a%b);}
ll fpow(ll a,ll b,ll m)
{
    if(!b) return 1;
    ll ans=fpow(a*a%m,b/2,m);
    return (b%2?ans*a%m:ans);
}
ll inv(ll a,ll m) {return fpow(a,m-2,m);}
 
#define MottoHayaku ios::sync_with_stdio(false);cin.tie(0);
//#define int ll
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define repk(i,m,n) for(int i=m;i<n;i++)
#define F first
#define S second
#define pb push_back
#define uni(c) c.resize(distance(c.begin(),unique(c.begin(),c.end())))
#define unisort(c) sort(c.begin(),c.end()),uni(c)
 
#define X first
#define Y second
typedef pair<ll,ll> pdd;
 
const double eps=1e-9;
pdd operator+(pdd a,pdd b){return pdd(a.X+b.X,a.Y+b.Y);}
pdd operator-(pdd a,pdd b){return pdd(a.X-b.X,a.Y-b.Y);}
pdd operator*(pdd a,double b){return pdd(a.X*b,a.Y*b);}
pdd operator/(pdd a,double b){return pdd(a.X/b,a.Y/b);}
double dot(pdd a,pdd b){return a.X*b.X+a.Y*b.Y;}
double cross(pdd a,pdd b){return a.X*b.Y-a.Y*b.X;}
double abs2(pdd a){return dot(a,a);}
double abs(pdd a){return sqrt(dot(a,a));}
int sign(double a){return fabs(a)<eps?0:a>0?1:-1;}
int ori(pdd a,pdd b,pdd c){return sign(cross(b-a,c-a));}
 
bool collinear(pdd a,pdd b,pdd c){return sign(cross(a-c,b-c))==0;}
bool btw(pdd a,pdd b,pdd c){return !collinear(a,b,c)?0:sign(dot(a-c,b-c))<=0;}//is C between AB
pdd proj(pdd a,pdd b,pdd c){return (b-a)*dot(c-a,b-a)/abs2(b-a);}//ac projection on ab
double dist(pdd a,pdd b,pdd c){return abs(cross(c-a,b-a))/abs(b-a);}//distance from C to AB
 
bool cmp(pdd a,pdd b)//polar angle sort
{
    #define is_neg(k) (sign(k.Y)<0||(sign(k.Y)==0&&sign(k.X)<0))
    int A=is_neg(a),B=is_neg(b);
    if(A!=B) return A<B;
    if(sign(cross(a,b))==0) return abs2(a)<abs2(b);
    return sign(cross(a,b))>0;
}
 
vector<pdd> convex_hull(vector<pdd> dots)
{
    sort(dots.begin(),dots.end());
    vector<pdd> hull(1,dots[0]);
    for(int ct=0;ct<=1;ct++)
    {
        int t=hull.size();
        for(int i=1;i<dots.size();i++)
        {
            while(hull.size()>t&&ori(hull[hull.size()-2],hull.back(),dots[i])<=0) hull.pop_back();
            hull.pb(dots[i]);
        }
        reverse(dots.begin(),dots.end());
    }
    hull.pop_back();
    return hull;
}
bool seg_sect(pdd p1,pdd p2,pdd p3,pdd p4)//does p1p2 intersect p3p4
{
    int a123=ori(p1,p2,p3);
    int a124=ori(p1,p2,p4);
    int a341=ori(p3,p4,p1);
    int a342=ori(p3,p4,p2);
    if(a123==0&&a124==0) return btw(p1,p2,p3)||btw(p1,p2,p4)||btw(p3,p4,p1)||btw(p3,p4,p2);
    else return a123*a124<=0&&a341*a342<=0;
}
 
signed main()
{
    MottoHayaku
    ll n;
    cin>>n;
    vector<pll> p(n);
    rep(i,n) cin>>p[i].F>>p[i].S;
    ll ans=0;
    rep(i,n)
    {
        //dbg(i);
        vector<pll> tmp;
        rep(j,n) if(i!=j) tmp.pb(p[j]-p[i]);
        sort(tmp.begin(),tmp.end(),cmp);
        rep(j,n-1) tmp.pb(tmp[j]);
        vector<ll> pos(n-1,0);
        ll cur=0;
        rep(j,n-1)
        {
            //dbg(tmp[j].F,tmp[j].S);
            cur=max(cur,(ll)j);
            while(cur+1<j+(n-1)&&cross(tmp[j],tmp[(cur+1)])>=0) cur++;
            pos[j]=cur;
            //dbg(pos[j]);
        }
        ll tot=0;
        rep1(j,pos[0]) tot+=pos[j%(n-1)]-pos[0];
        rep(j,n-1)
        {
            //dbg(j,tot);
            ans+=tot;
            if(j==n-2) break;
            ll d=pos[j]-j;
            //dbg(d);
            tot-=d*(pos[j+1]-pos[j]);
            for(int k=pos[j]+1;k<=pos[j+1];k++)
            {
                if(k>=n-1) tot+=pos[k%(n-1)]+n-1-pos[j+1];
                else tot+=pos[k]-pos[j+1];
            }
        }
        //dbg(ans);
    }
    cout<<ans*(n-4)/6<<"\n";
}