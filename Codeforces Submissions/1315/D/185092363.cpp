#include<bits/stdc++.h>
using namespace std;
#define AC return
#define Please 0
#define itn int
#define enld '\n'       //IO?
#define endl '\n'       //IO?
#define Endl '\n'       //IO?
#define esle else
#define ciN cin
#define YES "YES"
#define NO "NO"
#define eb emplace_back
#define wide(x,ch) setw(x)<<setfill(ch)
#define DEC(x) fixed<<setprecision(x)
#define show "ans-------------> "<<
class MyCpiise{public:bool operator()(pair<int,int> a,pair<int,int> b){return a.second<b.second;}};
MyCpiise Mcse;
#define dbg(x...) do{cout<<#x<<" -> ";err(x);}while (0)
void err(){cout<<'\n';}
template<class T, class... Ts>
void err(T arg, Ts... args) {
    cout<<arg<< ' ';
    err(args...);
}
template<typename T>
T read(T judge){
    T x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
    return f*x;
}
inline void reads(){return;}
template<class T,class... Ts>
inline void reads(T &x,Ts&... xs) {
    x=0;
    char c=getchar();
    while('0'<=c&&c<='9') {
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    reads(xs...);
}
template<typename T>
void print(T x){
    if (x<0) putchar('-'),x=-x;
    if (x/10) print(x/10);
    putchar(x%10+'0');
}
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
long long rng(long long l, long long r) {
    uniform_int_distribution<long long> uni(l, r);
    return uni(mt);
}

#define int long long                        //int main()->signed main()?
#define INF 0x3f3f3f3f
#define LLINF 9223372036854775807
#define pii pair<int,int>
#define pip pair<int,pii >
#define ppi pair<pii ,int>
#define ppp pair<pii ,pii >
#define tiii tuple<int,int,int>
const int MOD1=998244353;
const int MOD2=1e9+7;
const int N4=1e4+10;
const int N5=1e5+10;
const int NN5=2e5+10;
const int N6=1e6+10;
const int N7=1e7+10;
const int N8=1e8+10;
const int N9=1e9+10;
int dr[4]={0,1,0,-1};
int dc[4]={1,0,-1,0};
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define is_odd(x) (x&1)
#define lowbit(x) (x&(-x))
void bin_print(int now,int cnt){
    if(!cnt) return;
    bin_print(now>>1,cnt-1);
    cout<<(now&1);
}
int fast_pow(int x,int n=MOD2-2,int mod=MOD2,int ret=1){
    while(n){
        if(n&1) ret=ret*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return ret;
}
long long fast_ll_pow(long long x,long long n,long long ret=1){
    while(n){
        if(n&1) ret=ret*x;
        x=x*x;
        n>>=1;
    }
    return ret;
}
int exgcd(int a,int b,int &x,int &y){
    if(!b){x=1;y=0;return a;}
    else{int ret=exgcd(b,a%b,y,x);y-=a/b*x;return ret;}
}
typedef long long ll;
int arr[NN5];
int w[NN5];
void run()
{
    int n;
    cin>>n;
    vector<pii>v;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n;i++) v.eb(pii(w[i],arr[i]));
    sort(v.begin(),v.end(),greater<pii>());
    map<int,int>fa,sz;
    function<int(int)> find = [&](int x) -> int{
        return (fa.count(x)==0) ? x : fa[x]=find(fa[x]);
    };
    int ans=0;
    for(auto x : v){
        if(fa.count(x.second)==0) fa[x.second]=x.second+1;
        else{
            int tar=find(x.second);
            ans+=(tar-x.second)*x.first;
            fa[tar]=tar+1;
        }
    }
    cout<<ans<<endl;





/*------------------------dbg----------------------------*/


    return;
    //T==1?
}
signed main()
{
//    freopen("D:\\MY_std_input\\std_input.txt", "r", stdin);
//    freopen("D:\\MY_std_input\\std_output1.txt", "w", stdout);
//    freopen("D:\\MY_std_input\\std_output2.txt", "w", stdout);
//    system("cls");
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int T=1;
//    cin>>T;
    while(T--)
    {
        run();
    }



    AC Please;
}
// "str.size()-num" --> "(int)str.size()-num" ?
