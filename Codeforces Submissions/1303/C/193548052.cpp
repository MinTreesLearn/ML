#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<unordered_map>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cstdlib>
#include<stack>
#include<ctime>
#define forin(i,a,n) for(int i=a;i<=n;i++)
#define forni(i,n,a) for(int i=n;i>=a;i--)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
const double eps=1e-7;
const int N=3e5+7 ,M=2*N , INF=0x3f3f3f3f,mod=1e9+7;
inline ll read() {ll x=0,f=1;char c=getchar();while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
while(c>='0'&&c<='9') {x=(ll)x*10+c-'0';c=getchar();} return x*f;}
void stin() {freopen("in_put.txt","r",stdin);freopen("my_out_put.txt","w",stdout);}

template<typename T> T gcd(T a,T b) {return b==0?a:gcd(b,a%b);}
template<typename T> T lcm(T a,T b) {return a*b/gcd(a,b);}

int T;
int n,m,k;
char str[220];
pair<char,char> w[30];
bool sign;
char ans[30];
bool st[30];

bool path(char ch,char t) {
    int p=ch-'a';
    if(w[p].fi==t||w[p].se==t) return true;
    if(w[p].fi==0) {
        w[p].fi=t;
        return true;
    }else if(w[p].se==0) {
        w[p].se=t;
        return true;
    }else return false;
}

void dfs(int u) {
    if(u==3) {
        int res=0;
        if(w[ans[1]-'a'].fi!=0) res++;
        if(w[ans[1]-'a'].se!=0) res++;
        if(res==2) return ;
        if(res==1&&w[ans[1]-'a'].fi!=ans[2]) return ;
    }
    
    if(u>3&&u<=27) {
        char a=w[ans[u-2]-'a'].fi,b=w[ans[u-2]-'a'].se;
        if(a!=0&&b==0) {
            if(!(a==ans[u-3]||a==ans[u-1])) {
                return ;
            }
        }else if(a!=0&&b!=0) {
            if(!((a==ans[u-3]&&b==ans[u-1])||(a==ans[u-1]&&b==ans[u-3]))) {
                return ;
            }
        }
    }
    
    if(u>26) {
        if(w[ans[u-1]-'a'].se!=0) return ;
        if(w[ans[u-1]-'a'].fi!=0&&ans[u-2]!=w[ans[u-1]-'a'].fi) return ;
        sign=true;
        return ;
    }
    
    for(int i='a';i<='z';i++) {
        if(!st[i-'a']) {
            ans[u]=i;
            st[i-'a']=true;
            dfs(u+1);
            if(sign) return ;
            st[i-'a']=false;
        }
    }
}

void solve() {  
    scanf("%s",str+1);
    
    n=strlen(str+1);
    
    if(n==1) {
        printf("YES\n");
        for(int i='a';i<='z';i++) printf("%c",i);
        printf("\n");
        return ;
    }
    
    memset(w,0,sizeof w);
    memset(st,false,sizeof st);
    memset(ans,0,sizeof ans);
    bool flag=true;
    sign=false;
    for(int i=2;i<=n;i++) {
        char a=str[i-1],b=str[i];
        if(!path(a,b)) {
            flag=false;
            break;
        }
        if(!path(b,a)) {
            flag=false;
            break;
        }
    }
    
    int x=0,y=0;
    for(int i=0;i<26;i++) {
        if(w[i].se!=0) x++;
        if(w[i].fi!=0) y++;
    }
    
    if(y-x<2) flag=false;
    
    if(!flag) printf("NO\n");
    else {
        dfs(1);
        if(!sign) printf("NO\n");
        else {
            printf("YES\n");
            for(int i=1;i<=26;i++) printf("%c",ans[i]);
            printf("\n");
        }
    }
}

int main() {
    // init();
    // stin();
    
    scanf("%d",&T);
    // T=1; 
    while(T--) solve();
    
    return 0;       
}          
				 	  		 	  	  		 		 	 			