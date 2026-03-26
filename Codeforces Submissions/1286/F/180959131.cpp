#include <bits/stdc++.h>
#include <immintrin.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast,unroll-loops")

#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define chkmin(a,b) (a=min(a,b))
#define chkmax(a,b) (a=max(a,b))
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#define sort_unique(a) sort(all(a)),a.resize(unique(all(a))-a.begin())
//#define inf 1010000000
#define inf 4000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(vector<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(unordered_set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 777771449
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int maxn=1<<20;

const int N=1<<20,LG=__lg(N);

using u32=uint32_t;

void fadd(u32* arr1, u32* arr2, u32* res){
    __m256 reg1=_mm256_loadu_ps((float*)arr1),reg2=_mm256_loadu_ps((float*)arr2);
    __m256i reg3=_mm256_add_epi32((__m256i)reg1,(__m256i)reg2);
    _mm256_storeu_ps((float*)res,(__m256)reg3);
}

void fsub(u32* arr1, u32* arr2, u32* res){
    __m256 reg1=_mm256_loadu_ps((float*)arr1),reg2=_mm256_loadu_ps((float*)arr2);
    __m256i reg3=_mm256_sub_epi32((__m256i)reg1,(__m256i)reg2);
    _mm256_storeu_ps((float*)res,(__m256)reg3);
}

void ma_u32(u32* arr1, u32* arr2, u32* arr3, u32* res){
    __m256 reg1=_mm256_loadu_ps((float*)arr1),reg2=_mm256_loadu_ps((float*)arr2),reg3=_mm256_loadu_ps((float*)arr3);
    __m256i reg4=_mm256_mullo_epi32((__m256i)reg1,(__m256i)reg2);
    __m256i reg5=_mm256_add_epi32((__m256i)reg3,reg4);
    _mm256_storeu_ps((float*)res,(__m256)reg5);
}

void sos(u32* arr){
    for(int i=0; i<3; ++i) for(int j=0; j<N; ++j) if(j>>i&1) arr[j]+=arr[j^(1<<i)];
    for(int i=3; i<LG; ++i) for(int j=0; j<N; j+=8) if(j>>i&1) fadd(&arr[j],&arr[j^(1<<i)],&arr[j]);
}

void sos_rev(u32* arr){
    for(int i=0; i<3; ++i) for(int j=0; j<N; ++j) if(j>>i&1) arr[j]-=arr[j^(1<<i)];
    for(int i=3; i<LG; ++i) for(int j=0; j<N; j+=8) if(j>>i&1) fsub(&arr[j],&arr[j^(1<<i)],&arr[j]);
}

void subset_conv(u32* arr1, u32* arr2, u32* res, int x=0, int y=0){
    alignas(64) u32 f[LG+1][N],g[LG+1][N];
    memset(f,0,sizeof f),memset(g,0,sizeof g),memset(res,0,sizeof res);
    for(int i=0; i<N; ++i){
        int t=__builtin_popcount(i);
        if(t<x) assert(!arr1[t]);
        if(t<y) assert(!arr2[t]);
        f[t][i]=arr1[i],g[t][i]=arr2[i];
    }
    for(int i=x; i<=LG; ++i) sos(f[i]);
    for(int i=y; i<=LG; ++i) sos(g[i]);
    for(int i=x+y; i<=LG; ++i){
        alignas(64) u32 h[N];
        memset(h,0,sizeof h);
        for(int j=x; j<=i-y; ++j) for(int _=0; _<N; _+=8) ma_u32(&f[j][_],&g[i-j][_],&h[_],&h[_]);
        sos_rev(h);
        for(int j=0; j<N; ++j) if(__builtin_popcount(j)==i) res[j]=h[j];
    }
}

//i_am_noob
//#define wiwihorz  
void balbitorz(){}
int n,a[20];
vector<vector<int>> to(maxn);
u32 arr[12][1<<20];

bool check(u32* arr){
	bool res=0;
	for(int i=0; i<(1<<n); ++i) res|=arr[i];
	return res;
}

void orzck(){
    cin >> n;
    int cur=0;
    rep(n){
    	int x; cin >> x;
    	if(x) a[cur++]=x;
    }
    n=cur;
    for(int s=0; s<(1<<n); ++s){
    	int x=__builtin_popcount(s);
    	int tot=0;
    	for(int i=0; i<n; ++i) if(s>>i&1) tot+=a[i];
    	if(!((tot+x)&1)) continue;
    	int y=(x+1)/2;
    	int s1=0;
    	for(int i=0; i<n; ++i) if(s>>i&1){
    		if(y==0) break;
    		s1|=1<<i,y--;
    	}
    	to[s^s1].pb(s1);
    }
    for(int s=1; s<(1<<n); ++s) if(!to[s].empty()){
    	//cout << "a " << s << endl;
    	int x=__builtin_popcount(s);
    	vector<array<int,3>> vec;
    	for(int ss=s; ; ss=(ss-1)&s){
    		int tot=0;
    		for(int i=0; i<n; ++i) if(s>>i&1){
    			if(ss>>i&1) tot+=a[i];
    			else tot-=a[i];
    		}
    		vec.pb({tot,s,ss});
    		if(!ss) break;
    	}
    	for(auto s2: to[s]) for(int ss=s2; ; ss=(ss-1)&s2){
    		int tot=0;
    		for(int i=0; i<n; ++i) if(s2>>i&1){
    			if(ss>>i&1) tot+=a[i];
    			else tot-=a[i];
    		}
    		vec.pb({tot,s2,ss});
    		if(!ss) break;
    	}
    	sort(all(vec));
    	deque<pii> dq;
    	for(auto [val,s2,ss]: vec){
    		if(s2==s){
    			dq.pb({val,ss});
    			if(dq.size()>3) dq.pop_front();
    		}
    		else{
    			for(auto [i,j]: dq) if(val-i<=x*2&&(j!=0||ss!=s2)&&(j!=s||ss!=0)) arr[1][s|s2]=1;
    		}
    	}
    	reverse(all(vec));
    	dq.clear();
    	for(auto [val,s2,ss]: vec){
    		if(s2==s){
    			dq.pb({val,ss});
    			if(dq.size()>3) dq.pop_front();
    		}
    		else{
    			for(auto [i,j]: dq) if(i-val<=x*2&&(j!=0||ss!=s2)&&(j!=s||ss!=0)) arr[1][s|s2]=1;
    		}
    	}
    }
    //for(int s=0; s<(1<<n); ++s) cout << s << ' ' << arr[1][s] << endl;
    if(!check(arr[1])){
    	cout << n << "\n";
    	return;
    }
    for(int i=1; i<8; i<<=1){
    	subset_conv(arr[i],arr[i],arr[i*2],i*2,i*2);
    	if(!check(arr[i*2])){
    		int cur=i;
    		for(int j=i/2; j; j>>=1){
    			subset_conv(arr[cur],arr[j],arr[cur+j],cur*2,j*2);
    			if(check(arr[cur+j])) cur+=j;
    		}
    		cout << n-cur << "\n";
    		return;
    	}
    	if(i==4){
    		int cur=8;
    		for(int j=2; j; j>>=1){
    			subset_conv(arr[cur],arr[j],arr[cur+j],cur*2,j*2);
    			if(check(arr[cur+j])) cur+=j;
    		}
    		cout << n-cur << "\n";
    		return;
    	}
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    // #ifdef i_am_noob
    // freopen("input1.txt","r",stdin);
    // freopen("output1.txt","w",stdout);
    // freopen("output2.txt","w",stderr);
    // #endif
    cout << fixed << setprecision(15);
    ld start=clock();
    balbitorz();
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) orzck();
    bug((clock()-start)/CLOCKS_PER_SEC);
    return 0;
}