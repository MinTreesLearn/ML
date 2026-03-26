#include <bits/stdc++.h>
using namespace std;
char buf[1<<23],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
template <typename T>
inline void read(T &f)
{
    f=0;T fu=1;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-'){fu=-1;}c=getchar();}
    while(c>='0'&&c<='9') {f=(f<<3)+(f<<1)+(c&15);c=getchar();}
    f*=fu;
}
template <typename T> 
void print(T x,char c=0)
{
    if(x<0) putchar('-'),x=-x;
    if(x<10) putchar(x+48);
    else print(x/10),putchar(x%10+48);
    if(c) putchar(c);
}
inline void reads(string &f)
{
    string str="";char ch=getchar();
    while(ch<'!'||ch>'~') ch=getchar();
    while((ch>='!')&&(ch<= '~')) str+=ch,ch=getchar();
    f=str;
}
void prints(string s)
{
    for(int i=0;s[i];++i) 
    putchar(s[i]);
}
typedef long long ll;
const int multicase=0,debug=0,maxn=1e6+50;
struct node
{
    double x;
    int l,r;
};
stack<node> sta;
int n,a[maxn];
double ans[maxn];
void solve()
{
    read(n);
    for(int i=1;i<=n;++i)
    read(a[i]);
    sta.push({1.0*a[1],1,1});
    for(int i=2;i<=n;++i)
    {
        node now={1.0*a[i],i,i};
        while(!sta.empty())
        {
            double sum=now.x*(now.r-now.l+1)+sta.top().x*(sta.top().r-sta.top().l+1);
            int len=now.r-now.l+1+sta.top().r-sta.top().l+1;
            double nx=sum/len;
            int nl=sta.top().l,nr=now.r;
            if(nx<=sta.top().x)
            {
                sta.pop();
                now.x=nx,now.l=nl,now.r=nr;
            }
            else 
            {
                break;
            }
        }
        sta.push(now);
    }   
    while(!sta.empty())
    {
        node t=sta.top();
        sta.pop();
        for(int i=t.l;i<=t.r;++i)
        ans[i]=t.x;
    }
    for(int i=1;i<=n;++i)
    printf("%.9lf\n",ans[i]);
}
int main()
{
    #ifdef AC
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    clock_t program_start_clock=clock();
    int _=1;
    if(multicase) read(_);
    while(_--) solve();
    fprintf(stderr,"\nTotal Time: %lf ms",double(clock()-program_start_clock)/1000);
    return 0;
}