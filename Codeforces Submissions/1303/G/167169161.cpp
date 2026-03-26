#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define de double
#define o 150005
#define oo 1000000007

using namespace std;

typedef pair<ll,ll> II;

struct node
{
    II line;
    ll l,r;
    int left,right;

    node(II _line= {0,-1e18},ll _l=0,ll _r=1e18)
        : line(_line), l(_l),r(_r)
    {
        left=right=-1;
    }
};

vector<node> lichao;


void inbit()
{
    node nw=node({0,-1e18},0,1e18);
    lichao.clear();
    lichao.push_back(nw);

}

ll f(II p,ll x)
{
    return p.first*x+p.second;
}


void upd(int v,II p)
{
    ll l=lichao[v].l,r=lichao[v].r;

    if(f(p,l)<=f(lichao[v].line,l)&&f(p,r-1)<=f(lichao[v].line,r-1))
        return;
    if(f(p,l)>=f(lichao[v].line,l)&&f(p,r-1)>=f(lichao[v].line,r-1))
    {
        lichao[v].line=p;
        return;
    }

    ll m=(l+r)/2;
    bool lef=f(p,l)>f(lichao[v].line,l);
    bool mid=f(p,m)>f(lichao[v].line,m);
    if(mid)
        swap(lichao[v].line,p);

    if(r-l==1)
        return;

    if(lef!=mid)
    {
        if(lichao[v].left!=-1)
            upd(lichao[v].left,p);
        else
        {
            node cc=node(p,l,m);
            lichao.push_back(cc);
            lichao[v].left=lichao.size()-1;
        }
    }
    else
    {
        if(lichao[v].right!=-1)
            upd(lichao[v].right,p);
        else
        {
            node cc=node(p,m,r);
            lichao.push_back(cc);
            lichao[v].right=lichao.size()-1;
        }
    }
}

ll get(int v,ll x)
{
    ll l=lichao[v].l,r=lichao[v].r;
    ll m=(l+r)/2;
    ll fval=f(lichao[v].line,x);
    if(r-l==1)
        return fval;
    if(x<m)
    {
        if(lichao[v].left==-1)
            return fval;
        return max(fval,get(lichao[v].left,x));
    }
    else
    {
        if(lichao[v].right==-1)
            return fval;
        return max(fval,get(lichao[v].right,x));
    }
}

int n;
vector<int>g[o];
int a[o];
void inp()
{
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1; i<=n; i++)
        cin>>a[i];
}
ll ans=0;
int dep[o];
ll d1[o],d2[o];//d1 :cap so cong  tinh ca node     d2: cap so cong ko tinh node
ll sum[o];  //tong tren dd
vector<int>tv;
int s[o],parent[o],siz;
void dfs_size(int u,int dad)
{
    siz++;
    s[u]=1;
    for(auto&v:g[u])
        if(v!=dad&&!parent[v])
        {
            dfs_size(v,u);
            s[u]+=s[v];
        }
}
int check_centroid(int u,int dad)
{
    for(auto&v:g[u])
        if(v!=dad&&!parent[v])
            if(s[v]>siz/2)return check_centroid(v,u);
    return u;
}
void dfs(int u,int dad)
{
    tv.push_back(u);
    dep[u]=dep[dad]+1;
    sum[u]=sum[dad]+a[u];
    d1[u]=d1[dad]+1ll*dep[u]*a[u];
    d2[u]=d2[dad]+sum[u];
    ans=max(ans,d1[u]);
    for(auto&v:g[u])
        if(v!=dad&&!parent[v])
            dfs(v,u);
}
const int N=150000;
void calc(int r)
{
    inbit();
    upd(0,{a[r],d1[r]});
    for(auto&v:g[r])
        if(!parent[v])
        {
            tv.clear();
            dfs(v,r);
            for(auto&x:tv)
                ans=max(ans,get(0,dep[x]-1)+d2[x]);
            for(auto&x:tv)
            {
                upd(0,{sum[x]+a[r],d1[x]});
            }
        }
}
void build_centroid(int u,int dad)
{
    siz=0;
    dfs_size(u,dad);
    int node=check_centroid(u,dad);

    dep[node]=1;
    d1[node]=a[node];
    d2[node]=0;
    sum[node]=0;

    calc(node);
    reverse(g[node].begin(),g[node].end());
    calc(node);

    if(dad==0)parent[node]=node;
    else parent[node]=dad;
    for(auto&v:g[node])
        if(!parent[v])
            build_centroid(v,node);
}
void oup()
{
    build_centroid(1,0);
    cout<<ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    inp();
    oup();
}
