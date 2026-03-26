#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 1e9;
const int maxn = 3e5 + 10;
typedef pair<int,int> ii;
#define ff first
#define ss second
int n,m,k;
vector <int> adj[maxn],b[maxn];
int a[maxn];
ii e[maxn];
int ans=0;
ii p[maxn],num[maxn];
int s[maxn];
ii get(int x)
{
    if (p[x].ff!=x)
    {
        ii temp = get(p[x].ff);
        p[x].ff=temp.ff;
        p[x].ss^=temp.ss;
    }
    return p[x];
}
void hop(int x, int y, int w)
{
    ii xx = get(x); ii yy = get(y);
    x=xx.ff; y=yy.ff;
//    cout<<x<<' '<<y<<' '<<w<<"!!\n";;
    if (x==y) return;
    if (s[x]>s[y])
    {
        swap(x,y);
        swap(xx,yy);
    }
    ans -= min(num[x].ff,num[x].ss);
    ans -= min(num[y].ff,num[y].ss);
    int val = (xx.ss^yy.ss^w);
    if (val==0)
    {
        num[y].ff+=num[x].ff; num[y].ss+=num[x].ss;
    }
    else
    {
        num[y].ff+=num[x].ss; num[y].ss+=num[x].ff;
    }
    p[x]={y,val};
    s[y]+=s[x];
    ans+=min(num[y].ff,num[y].ss);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    {
        char c; cin>>c;
        a[i]=(c=='1');
    }
    for (int i=1; i<=k; i++)
    {
        int m; cin>>m;
        while (m--)
        {
            int x; cin>>x;
            b[x].push_back(i);
        }
    }
    for (int i=1; i<=k; i++)
    {
        p[i]={i,0};
        s[i]=1;
        num[i]={1,0};
    }
    for (int i=1; i<=n; i++)
    {
        if (b[i].size()==2)
        {
            int u=b[i][0]; int v=b[i][1];
            hop(u,v,a[i]^1);
        }
        else if (b[i].size()==1)
        {
            int u=b[i][0];
            ii uu=get(u);
            u=uu.ff;
            ans-=min(num[u].ff,num[u].ss);
            if (uu.ss==(a[i]^1)) num[u].ff+=inf;
            else num[u].ss+=inf;
            ans+=min(num[u].ff,num[u].ss);
        }
        cout<<ans<<'\n';
    }
}

  	    				    		  		    	  			