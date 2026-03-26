#include<bits/stdc++.h>
#define ll long long
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define repin rep(i,0,n)
#define di(a) int a;cin>>a;
#define precise(i) cout<<fixed<<setprecision(i)
#define vi vector<int>
#define si set<int>
#define mii map<int,int>
#define take(a,n) for(int j=0;j<n;j++) cin>>a[j];
#define give(a,n) for(int j=0;j<n;j++) cout<<a[j]<<' ';
#define vpii vector<pair<int,int>>
#define sis string s;
#define sin string s;cin>>s;
#define db double
#define be(x) x.begin(),x.end()
#define pii pair<int,int>
#define pb push_back
#define pob pop_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define bpc(x) __builtin_popcountll(x) 
#define btz(x) __builtin_ctz(x)
using namespace std;

const long long INF=1e18;
const long long M=1e9+7;
const long long MM=998244353;
  
int power( int N, int M){
    int power = N, sum = 1;
    if(N == 0) sum = 0;
    while(M > 0){if((M & 1) == 1){sum *= power;}
    power = power * power;M = M >> 1;}
    return sum;
}

struct segtree{
 
    int size;
    vector<int> operations;
    vector<int> values;
 
    int NEUTRAL_ELEMENT = LONG_MIN;
    int NO_OPERATION = LLONG_MAX-1;
 
    int modify_op(int a,int b,int len){
        if(b==NO_OPERATION)return a;
        if(a==NO_OPERATION)return b;
        return a+b;
    }
 
    int calc_op(int a,int b){
        return max(a,b);
    }
 
    void apply_mod_op(int &a,int b,int len){
        a=modify_op(a,b,len);
    }
 
    void init(int n){
        size=1;
        while(size<n)size*=2;
        operations.assign(2*size,0LL);
        values.assign(2*size,LONG_MIN);
    }
 
    void propogate(int x, int lx, int rx){
        if(rx-lx==1)return;
        int m = (rx+lx)/2;
        apply_mod_op(operations[2*x+1],operations[x],1);
        apply_mod_op(values[2*x+1],operations[x],m-lx);
        apply_mod_op(operations[2*x+2],operations[x],1);
        apply_mod_op(values[2*x+2],operations[x],rx-m);
        operations[x]=NO_OPERATION;
 
    }
    void build(vi &a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<a.size()){
                values[x]=a[lx];
            }
            return;
        }
        int m = (lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        values[x]=(values[2*x+1]+values[2*x+2]);
    }
 
    void build(vi &a){
        build(a,0,0,size);
    }
 
    void modify(int l,int r,int v,int x,int lx,int rx){
        
        propogate(x,lx,rx);
        if(lx>=r || l>=rx)return;
        if(lx>=l && rx<=r){
        apply_mod_op(operations[x],v,1);
        apply_mod_op(values[x],v,rx-lx);
        return;}
        
        int m = (lx+rx)/2;
        modify(l,r,v,2*x+1,lx,m);
        modify(l,r,v,2*x+2,m,rx);
        values[x]=calc_op(values[2*x+1],values[2*x+2]);
        apply_mod_op(values[x],operations[x],rx-lx);
    }
 
    void modify(int l,int r,int v){
        return modify(l,r,v,0,0,size);
    }
 
    int calc(int l,int r,int x,int lx,int rx){
        propogate(x,lx,rx);
        if(lx>=r || l>=rx)return NEUTRAL_ELEMENT;
        if(lx>=l && rx<=r){return values[x];}
        
        int m = (lx+rx)/2;
        int m1=calc(l,r,2*x+1,lx,m);
        int m2=calc(l,r,2*x+2,m,rx);
        auto res = calc_op(m1,m2);
        apply_mod_op(res,operations[x],min(r,rx)-max(l,lx));
        return res;
    }
 
    int calc(int l,int r){
        return calc(l,r,0,0,size);
    }
 
};

 
void solve()
{
    di(n) di(m) di(p)
    vpii v2,v3;
    repin{
        di(x) di(y)
        v2.pb({y,x});
    }
    sort(be(v2));
    vpii v,v1;
    rep(i,0,v2.size()){
        if(v.empty()){v.pb(v2[i]);continue;}
        if(v2[i].ff==(v.back()).ff){
            v.pob();
            v.pb(v2[i]);continue;
        }
        if((v.back()).ss>=v2[i].ss){
            continue;
        }
        v.pb(v2[i]);
    }
    rep(i,0,m){
        di(x) di(y)
        v3.pb({y,x});
    }
    sort(be(v3));
    rep(i,0,v3.size()){
        if(v1.empty()){v1.pb(v3[i]);continue;}
        if(v3[i].ff==(v1.back()).ff){
            v1.pob();
            v1.pb(v3[i]);continue;
        }
        if((v1.back()).ss>=v3[i].ss){
            continue;
        }
        v1.pb(v3[i]);
    }
    // for(auto x : v){cout<<x.ff<<" "<<x.ss<<"\n";}cout<<"\n";
    // for(auto x : v1){cout<<x.ff<<" "<<x.ss<<"\n";}cout<<"\n";
    int ans = v[0].ff+v1[0].ff;
    ans*=-1;
    vector<pair<pii, int>> res;
    rep(i,0,p){
        di(x) di(y) di(z)
        res.pb({{x,y},z});
    }
    sort(be(res));
    segtree st;
    st.init(1000005);
    rep(i,0,v1.size()){
        int dy = LONG_MAX+1LL;
        // cout<<dy<<"\n";
        st.modify(v1[i].ss,v1[i].ss+1,dy-v1[i].ff);
        // cout<<st.calc(v1[i].ss,v1[i].ss+1)<<"\n";
    }
    int l = 0;
    rep(i,0,v.size()){
        int re = -v[i].ff;
        while(l<res.size() && ((res[l].ff.ff) < v[i].ss)){
            st.modify(res[l].ff.ss+1,1000005,res[l].ss);
            l++;
        }
        re+=st.calc(0,1000001);
        // cout<<re<<"\n";
        ans=max(ans,re);
    }
    cout<<ans<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef NCR
        init();
    #endif
    #ifdef SIEVE
        sieve();
    #endif
        solve();
    return 0;
}