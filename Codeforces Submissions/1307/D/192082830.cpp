#include<bits/stdc++.h>

 #define f first
#define s second
  #define pb push_back
 #define read(x) for(auto& qw : (x)) cin >> qw;
 #define endl "\n"; //para problemas iterativos comentar essa linha
 #define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll MOD = 1000000007;
const ll NO_OPERTATION = -1;

vector<int> graph [200009];
int dist1[200009];
int dist2[200009];

void bfs(int a)
{

    if(a==0)
    {
        memset(dist1,-1,sizeof(dist1));
        dist1[a]=0;
        queue<int> fila;
        fila.push(a);
        while(fila.empty()==false)
        {
            int u = fila.front();
            fila.pop();
            for(auto x: graph[u])
            {
                if(dist1[x]==-1){dist1[x]=dist1[u]+1; fila.push(x);}
            }
        }
    }
    else
    {
        memset(dist2,-1,sizeof(dist2));
        dist2[a]=0;
        queue<int> fila;
        fila.push(a);
        while(fila.empty()==false)
        {
            int u = fila.front();
            fila.pop();
            for(auto x: graph[u])
            {
                if(dist2[x]==-1){dist2[x]=dist2[u]+1; fila.push(x);}
            }
        }
    }
    return;
}

int main ()
{
    ios::sync_with_stdio(0);
cin.tie(0);

ll n;
ll m;
ll k;
cin>>n>>m>>k;
vector<ll> special (k);
for(int i=0;i<k;i++)
{
    cin>>special[i];
    special[i]--;
}
for(int i=0;i<m;i++)
{
    int a;
    int b;
    cin>>a>>b;
    a--;
    b--;
    graph[a].pb(b);
    graph[b].pb(a);
}

bfs(0);
bfs(n-1);
vector<pii> dif;
sort(all(special));
for(int i=0;i<k;i++)
{
    dif.pb({dist1[special[i]]-dist2[special[i]],special[i]});
}
sort(all(dif));
int ans = 0;
int melhor = dist1[dif[0].s];
for(int i=1;i<special.size();i++)
{
    ans = max(ans,melhor+dist2[dif[i].s]+1);
    melhor=max(melhor,dist1[dif[i].s]);
}
cout<<min(ans,dist1[n-1])<<endl;


 return 0;
}
