#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <string> vs;
typedef pair <int, int> pii;
typedef vector<pii > vpii;

#define MP make_pair
#define F first
#define S second
#define REVERSE(a) reverse (a.begin(), a.end())
#define ALL(a) a.begin(), a.end()
#define ms(x,y) memset (x, y, sizeof (x))
#define pb push_back
#define debug(a,b) cout<<a<<": "<<b<<endl
#define Debug cout<<"Reached here"<<endl
#define prnt(a) cout<<a<<"\n"
#define VecPrnt(v) for(auto i: v) cout<<i<<" "; cout<<endl
#define endl "\n"
#define PrintPair(x) cout<<x.first<<" "<<x.second<<endl
#define ArrPrint(a,st,en) for(int J=st; J<=en; J++) cout<<a[J]<<" "; cout<<endl;

/* Direction Array */

// int fx[]={1,-1,0,0};
// int fy[]={0,0,1,-1};
// int fx[]={0,0,1,-1,-1,1,-1,1};
// int fy[]={-1,1,0,0,1,1,-1,-1};

const int maxn = 2e5+10;
int n, maxh, maxh2, l, mx[2], mark[maxn], hi[maxn];
vi adj[maxn];
vi p;
vi path;
queue<int> q;

void dfs(int v, int par, int h, int t, int en)
{
    p.pb(v);
    if(v == en)
        path = p;

    if(h > maxh)
        mx[t] = v, maxh = h;

    for(int u: adj[v])
        if(u!=par)
            dfs(u, v, h+1, t, en);
    p.pop_back();
}   

void bfs()
{
    for(int i: path)
    {
        q.push(i);
        mark[i] = 1 , hi[i] = 0;
    }
    while(q.size()>0)
    {
        int v = q.front();
        q.pop();
        for(int u: adj[v])
        {
            if(!mark[u])
            {
                mark[u] = 1;
                q.push(u);
                hi[u] = hi[v] + 1;

                if(hi[u]>maxh2)
                {
                    maxh2 = hi[u];
                    l = u;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int u, v, i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    maxh = 0;
    dfs(1, -1, 0, 0, n+1);
    maxh = 0;
    dfs(mx[0], -1, 0, 1, n+1);

    if(maxh == n-1)
        for(int i = 1; i <= n; i++)
            if(i != mx[0] && i != mx[1])
            {
                prnt(maxh);
                cout << mx[0] << " " << mx[1] << " " << i;
                return 0;
            }

    p.clear();
    path.clear();

    // debug(mx[0], mx[1]);
    dfs(mx[0], -1, 0, 2, mx[1]);

    maxh2 = 0;
    bfs();

    prnt(maxh + maxh2);
    cout << mx[0] << " " << mx[1] << " " << l << endl;


    return 0;
}