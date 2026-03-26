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
const double eps=1e-10;       
int sgn(double x)
{  
    if(fabs(x)<eps)  return 0;
    else return x<0?-1:1;
}
int n,a[maxn];
double ans[maxn];
struct Point
{
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
    Point operator - (Point B){return Point(x-B.x,y-B.y);}
};
Point ch[maxn],p[maxn];
double Cross(Point A,Point B){return A.x*B.y-A.y*B.x;}
int Convex_hull(Point *p,int n,Point *ch)
{
    int v=0;
    for(int i=0;i<n;++i)
    {
        while(v>1&&sgn(Cross(ch[v-1]-ch[v-2],p[i]-ch[v-2]))<=0)
		v--;
        ch[v++]=p[i];
    }
    return v;   
}
void solve()
{
    read(n);
    for(int i=1;i<=n;++i)
    read(a[i]);
    double sum=0;
    p[0]={0,0};
    for(int i=1;i<=n;++i)
    {
        sum+=a[i];
        p[i]={1.0*i,1.0*sum};
    }
    int cnt=Convex_hull(p,n+1,ch);
    for(int i=1;i<cnt;++i)
    {
        double val=ch[i].y-ch[i-1].y,len=ch[i].x-ch[i-1].x;
        for(int j=ch[i-1].x+1;j<=ch[i].x;++j)
        {
            ans[j]=val/len;
        }
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