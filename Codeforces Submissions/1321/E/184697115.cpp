#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// template<class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization("unroll-loops")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("fast-math")
// #pragma GCC optimize("no-stack-protector")
// #define ll __int128
#define ll long long
// #define ll int
#define f(i,a,b) for(ll i=a;i<b;i++)
#define mod 1000000007
// #define mod 998244353 
#define mp make_pair
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define ff first
#define ss second
#define rf(i,a,b) for(ll i=a;i>=b;i--)
#define sc(a) scanf("%lld",&a)
#define pf printf
#define sz(a) (int)(a.size())
#define psf push_front
#define ppf pop_front
#define ppb pop_back
#define pb push_back
#define pq priority_queue
#define all(s) s.begin(),s.end()
#define sp(a) setprecision(a)
#define rz resize
#define ld long double
#define inf (ll)1e18
#define ub upper_bound
#define lb lower_bound
#define bs binary_search
#define eb emplace_back
const double pi = acos(-1);
ll binpow(ll a, ll b){ll res=1;while(b!=0){if(b&1)res*=a;a*=a;b>>=1;}return res;}
ll binpow(ll a, ll b, ll md){ll res=1;a%=md;if(a==0)return 0;while(b!=0){if(b&1)res*=a,res%=md;a*=a,a%=md;b>>=1;}return res%md;}
 
using namespace std;

const int N=1e6+2;
vector<ll> v(N+1,-inf);

struct node
{
    ll val,lazy;
    node()
    {
        val=-inf,lazy=0;
    }
};

ll n,q,m,p;
vector<node> t(4*N+69);

node merge(node a, node b)
{
    node ans;
    ans.val=max(a.val,b.val);
    return ans;
}

void build(int id, int l, int r)
{
    if(l==r)
    {
        t[id].val=v[l];
        return;
    }
    int mid=(l+r)/2;
    build(id<<1,l,mid),build(id<<1|1,mid+1,r);
    t[id]=merge(t[id<<1],t[id<<1|1]);
}

void push(int id, int l, int r)
{
    if(t[id].lazy==0)
        return;
    if(l==r)
    {
        t[id].val+=t[id].lazy,t[id].lazy=0;
        return;
    }
    t[id<<1].lazy+=t[id].lazy,t[id<<1|1].lazy+=t[id].lazy;
    t[id].val+=t[id].lazy,t[id].lazy=0;
}

void update(int id, int l, int r, int lq, int rq, ll p)
{
    push(id,l,r);
    if(l>rq || r<lq)
        return;
    if(l>=lq && r<=rq)
    {
        t[id].lazy+=p;
        push(id,l,r);
        return;
    }
    int mid=(l+r)/2;
    update(id<<1,l,mid,lq,rq,p),update(id<<1|1,mid+1,r,lq,rq,p);
    t[id]=merge(t[id<<1],t[id<<1|1]);
}

node query(int id, int l, int r, int lq, int rq)
{
    push(id,l,r);
    node def_val;
    if(l>rq || r<lq)
        return def_val;
    if(l>=lq && r<=rq)
        return t[id];
    int mid=(l+r)/2;
    return merge(query(id<<1,l,mid,lq,rq),query(id<<1|1,mid+1,r,lq,rq));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("xortransform.in","r",stdin);
    // freopen("xortransform.out","w",stdout);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
// #endif
    int z=1;
    // cin>>z;
    f(ilu,1,z+1)
    {
        // cout<<"Case #"<<ilu<<": ";
        cin>>n>>m>>p;
        vector<array<ll,2> > a(n),b(m);
        vector<array<ll,3> > c(p);
        ll mx=-inf,ans=0;

        f(i,0,n)
        {
            f(j,0,2)
                cin>>a[i][j];
            mx=max(mx,-a[i][1]);
        }
        ans+=mx,mx=-inf;

        f(i,0,m)
        {
            f(j,0,2)
                cin>>b[i][j];
            v[b[i][0]]=max(v[b[i][0]],-b[i][1]);
            mx=max(mx,-b[i][1]);
        }
        ans+=mx;
        

        build(1,1,N);

        f(i,0,p)
        {
            f(j,0,3)
                cin>>c[i][j];
            update(1,1,N,c[i][1]+1,N,c[i][2]);
        }

        sort(all(c)),sort(all(a));
        ll r=p-1,l=n-1;

        while(r>=0)
        {
            while(r>=0 && c[r][0]>=a[l][0])
                update(1,1,N,c[r][1]+1,N,-c[r][2]),r--;
            if(r>=0)
                ans=max(ans,-a[l][1]+query(1,1,N,1,N).val);
            l--;
        }

        cout<<ans<<"\n";
    }
}