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
const int multicase=0,debug=0,maxn=4e5+50;
int n,a[maxn];
bitset<26> bs[maxn];
int val[maxn];
bool check(int pos)
{
    for(int i=1;i<=n;++i)
    {
        bs[i]=a[i];
        for(int j=pos+1;j<=25;++j)
        bs[i][j]=0;
        val[i]=bs[i].to_ullong();
    }
    int l1=pow(2,pos),r1=pow(2,pos+1)-1;
    int l2=3*l1,r2=2*r1;
    sort(val+1,val+1+n);
    int cnt=0;
    //[l1,r1]
    for(int i=1;i<n;++i)
    {
        int pos1=lower_bound(val+i+1,val+1+n,l1-val[i])-val;
        int pos2=upper_bound(val+i+1,val+1+n,r1-val[i])-val-1;
        
        cnt+=pos2-pos1+1;
    }
    //cout<<"cnt="<<cnt<<'\n';
    //[l2,r2]
    for(int i=1;i<n;++i)
    {
        int pos1=lower_bound(val+i+1,val+1+n,l2-val[i])-val;
        int pos2=upper_bound(val+i+1,val+1+n,r2-val[i])-val-1;
        cnt+=pos2-pos1+1;
    }
    //cout<<"cnt="<<cnt<<'\n';
    return cnt&1;
}
void solve()
{
    read(n);
    for(int i=1;i<=n;++i)
    read(a[i]);
    int ans=0;
    /* check(0);
    check(1);
    return ; */
    for(int i=0;i<=25;++i)
    {
        if(check(i))
        ans+=(1<<i);
    }
    print(ans);
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