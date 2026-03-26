#include<iostream>
#include<cstdio>
#include<cassert>
#define N 50
using namespace std;
int read()
{
char c=0;
int sum=0;
while (c<'0'||c>'9') c=getchar();
while ('0'<=c&&c<='9') sum=sum*10+c-'0',c=getchar();
return sum;
}
int t,n,k,p[N+1];
string s1,s2,s3,s4,s5,s6,s7,divs,zero;
bool guess(string s)
{
cout<<'?'<<' '<<s<<endl,fflush(stdout);
k=read();
if (k==-1) exit(0);
for (int i=1;i<=k;++i) p[i]=read();
return k;
}
bool s_guess(string s,int x)
{
cout<<'?'<<' '<<s<<endl,fflush(stdout);
k=read();
if (k==-1) exit(0);
for (int i=1;i<=k;++i) p[i]=read();
for (int i=1;i<=k;++i)
if (p[i]==x)
return 1;
return 0;
}
void bfs(string s)
{
int ft=p[1];
for (int i=ft-1;i>=1;--i)
{
if (s_guess('H'+s,i)) s='H'+s;
else if (s_guess('O'+s,i)) s='O'+s;
else s='C'+s;
}
for (int i=ft+2;i<=n;++i)
{
if (s_guess(s+'H',1)) s=s+'H';
else if (s_guess(s+'O',1)) s=s+'O';
else s=s+'C';
}
cout<<'!'<<' '<<s<<endl,fflush(stdout);
return;
}
void exbfs(string s)
{
int ft=p[k];
for (int i=ft-1;i>=1;--i)
{
if (s_guess('H'+s,i)) s='H'+s;
else s='O'+s;
}
bool op=0;
for (int i=ft+2;i<=n;++i)
{
if (!op)
{
if (s_guess(s+'H',1)) s=s+'H';
else if (s_guess(s+'O',1)) s=s+'O',op=1;
else s=s+'C',op=1;
}
else
{
if (s_guess(s+'O',1)) s=s+'O';
else s=s+'C';
}
}
cout<<'!'<<' '<<s<<endl,fflush(stdout);
return;
}
void exbfs2(string s)
{
int ft=p[1];
for (int i=ft-1;i>=1;--i) s='H'+s;
for (int i=ft+3;i<=n;++i)
{
if (s_guess(s+'O',1)) s=s+'O';
else s=s+'C';
}
cout<<'!'<<' '<<s<<endl,fflush(stdout);
return;
}
void exbfs3(string s)
{
int ft=p[1];
for (int i=ft+3;i<=n;++i) s=s+'C';
for (int i=ft-1;i>=1;--i)
{
if (s_guess('H'+s,i)) s='H'+s;
else s='O'+s;
}
cout<<'!'<<' '<<s<<endl,fflush(stdout);
return;
}
void work(string s)
{
cout<<'!'<<' ';
for (int i=1;i<=p[1]-1;++i) cout<<'H';
cout<<s;
for (int i=p[1]+3;i<=n;++i) cout<<'C';
cout<<endl;
fflush(stdout);
return;
}
int main()
{
t=read();
while (t--)
{
n=read(),s1=s2=s3=s4=s5=s6=s7=divs=zero;
for (int i=1;i<=n;++i)
{
s1=s1+'H',s2=s2+'O',s3=s3+'C';
if (i==1) s4=s4+'H',s5=s5+'H',s6=s6+'O',s7=s7+'H';
else
{
s4=s4+'O',s5=s5+'C',s6=s6+'C',divs=divs+'C';
if (i==2) s7=s7+'O';
else s7=s7+'C';
}
}
if (guess("CO")) bfs("CO");
else if (guess("CH")) bfs("CH");
else if (guess("OH")) exbfs("OH");
else if (guess("HHO")) exbfs2("HHO");
else if (guess("OOC")) exbfs3("OOC");
else if (guess("HHC")) work("HHC");
else if (guess(divs))
{
if (guess(s3)) cout<<'!'<<' '<<s3<<endl,fflush(stdout);
else if (guess(s5)) cout<<'!'<<' '<<s5<<endl,fflush(stdout);
else cout<<'!'<<' '<<s6<<endl,fflush(stdout);
}
else
{
if (guess(s1)) cout<<'!'<<' '<<s1<<endl,fflush(stdout);
else if (guess(s2)) cout<<'!'<<' '<<s2<<endl,fflush(stdout);
else if (guess(s4)) cout<<'!'<<' '<<s4<<endl,fflush(stdout);
else cout<<'!'<<' '<<s7<<endl,fflush(stdout);
}
int st=read();
if (st==0) break;
}
return 0;
}
