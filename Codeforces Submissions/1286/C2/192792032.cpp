#include<bits/stdc++.h>
#define F(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
#define f(i,r,l) for(int i=(r),i##begin=(l);i>=i##begin;--i)
using namespace std;
const int N=105;
int n,a[N],b[N],c[N];
string s,st;
template<typename T>inline void readmain(T &n){T sum=0,x=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-')x=-1;ch=getchar();}while (ch>='0'&&ch<='9'){sum=sum*10+ch-'0';ch=getchar();}n=sum*x;}
template<typename T>inline T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>inline void read(T &x,Tr&... r){readmain(x);read(r...);}
template<typename T>inline void write(T x){if (x<0){putchar('-');x=-x;}if (x>9)write(x/10);putchar(x%10+'0');return;}
template<typename T>inline void writesc(T x){write(x);putchar(' ');}
template<typename T>inline void writeln(T x){write(x);putchar('\n');}
inline void query(int l,int r,auto &a)
{
cout<<"? "<<l<<" "<<r<<endl;
F(i,l,r)F(j,i,r)
{
cin>>st;
for (char c:st)a[st.size()]+=c;
}
}
int main()
{
read(n);s.resize(n+1);
if (n<=3)
{
F(i,1,n)query(i,i,a),s[i]=a[1]-=s[i-1];
cout<<"! "<<s.substr(1);return 0;
}
query(1,n+1>>1,a);query(2,n+1>>1,b);query(1,n,c);
F(i,1,(n+1)>>1)s[i]=(a[i]-=b[i])-a[i-1];
int j=s[n/2+1];f(i,n>>1,1)s[n-i+1]=c[i]-c[i-1]-j-s[i],j=c[i]-c[i-1];
cout<<"! "<<s.substr(1);return 0;
}