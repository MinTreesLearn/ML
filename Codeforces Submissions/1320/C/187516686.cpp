#include <bits/stdc++.h>
 
using namespace std;
 
#define ll              long long
#define l1(i, n)        for (ll i = 1; i <= n; i++)
#define l0(i, n)        for (ll i = 0; i < n; i++)
#define pb              push_back
#define xx              first
#define yy              second
#define sorted(x)       sort(x.begin(), x.end())
#define reversed(x)     reverse(x.begin(), x.end())
#define all(x)          x.begin(), x.end()
#define ms(a, b)        memset(a, b, sizeof(a));
#define cases(tc)       cout<<"Case #"<<tc<<": "
#define nl              cout<<"\n";
#define pi              acos(-1)
#define mod             1000000007
#define inf             1000000000000000001
#define maxn            1000001



ll seg[4*maxn];
ll lazy[4*maxn];
vector <ll> val(maxn, -inf);

void build(ll st, ll en, ll nd){
    if(st==en){
        seg[nd]=val[st];
        return;
    }
    ll mid=(st+en)/2;
    build(st, mid, 2*nd);
    build(mid+1, en, 2*nd+1);
    seg[nd]=max(seg[2*nd], seg[2*nd+1]);
}

void update(ll st, ll en, ll nd, ll l, ll r, ll val){
    if(lazy[nd]!=0){
        ll temp=lazy[nd];
        lazy[nd]=0;
        seg[nd]+=temp;
        if(st!=en){
            lazy[2*nd]+=temp;
            lazy[2*nd+1]+=temp;
        }
    }
    if(st>r || en<l){
        return;
    }
    if(st>=l && en<=r){
        seg[nd]+=val;
        if(st!=en){
            lazy[2*nd]+=val;
            lazy[2*nd+1]+=val;
        }
        return;
    }
    ll mid=(st+en)/2;
    update(st, mid, 2*nd, l, r, val);
    update(mid+1, en, 2*nd+1, l, r, val);
    seg[nd]=max(seg[2*nd], seg[2*nd+1]);
}

ll query(ll st, ll en, ll nd, ll l, ll r){
    if(lazy[nd]!=0){
        ll temp=lazy[nd];
        lazy[nd]=0;
        seg[nd]+=temp;
        if(st!=en){
            lazy[2*nd]+=temp;
            lazy[2*nd+1]+=temp;
        }
    }
    if(st>r || en<l){
        return -inf;
    }
    if(st>=l && en<=r){
        return seg[nd];
    }
    ll mid=(st+en)/2;
    return max(query(st, mid, 2*nd, l, r) , query(mid+1, en, 2*nd+1, l, r));
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 

    ll t;
    t=1;
    while(t--){
        ll n, m, p;
        cin>>n>>m>>p;

        vector<vector<ll>> a(n, vector <ll> (2));
        vector<vector<ll>> b(m, vector <ll> (2));
        vector<vector<ll>> mon(p, vector <ll> (3));

        l0(i, n){
            cin>>a[i][0]>>a[i][1];
        }
        sorted(a);

        l0(i, m){
            cin>>b[i][0]>>b[i][1];
            val[b[i][0]]=max(val[b[i][0]], -b[i][1]);
        }

        l0(i, p){
            cin>>mon[i][0]>>mon[i][1]>>mon[i][2];
        }

        sorted(mon);
        queue <vector<ll>> q;
        l0(i, p){
            q.push(mon[i]);
        }

        ll ans=-inf;

        build(1, maxn-1, 1);

        l0(i, n){
            while(!q.empty() && q.front()[0]<a[i][0]){
                vector <ll> v=q.front();
                q.pop();
                update(1, maxn-1, 1, v[1]+1, maxn-1, v[2]);
            }
            ans=max(ans, query(1, maxn-1, 1, 1, maxn-1)-a[i][1]);
        }

        cout<<ans;
        nl
    }
    return 0;
}