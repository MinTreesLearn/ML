#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
typedef long long ll;
using namespace std;
template<typename T>void read(T &x){
x=0;int f(1);char c(getchar());
for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
for(; isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c-'0');
x*=f;
}
template<typename T>void write(T x){
if(x<0)putchar('-'),x=-x;
if(x/10)write(x/10),x%=10;
putchar(x+'0');
}
const ll mod=1000000007;
ll mo(ll a){
return a>=mod?a-mod:a;
}
const int maxn=5005;
int num[maxn][maxn],slm[maxn],srm[maxn],s[maxn];
int main(){
int n,m;
read(n),read(m);
for(int i=1;i<=n;++i) read(s[i]),++srm[s[i]];
for(int i=1;i<=m;++i){
int f,h; read(f),read(h);
++num[f][h];
}
for(int i=1;i<=n;++i)
for(int j=1;j<=n;++j)
num[i][j]+=num[i][j-1];
ll anssum=1,ansnum=0;
for(int i=0;i<=n;++i){
if(i)++slm[s[i]],--srm[s[i]];
ll testsum=1,testnum=0;int sl,sr;
if(i){
sl=slm[s[i]],sr=srm[s[i]];
sr=num[s[i]][sr]-(sr>=sl);
sl=num[s[i]][sl]-num[s[i]][sl-1];
if(!sl)continue;
if(sr)testsum=testsum*sl*sr%mod,testnum+=2;
else testsum=testsum*sl%mod,testnum++;
}
for(int j=1;j<=n;++j){
if(j==s[i])continue;
sl=slm[j],sr=srm[j];
sr=num[j][sr],sl=num[j][sl];
if(!sl&&!sr)continue;
if(!sl||!sr)testsum=testsum*(sl+sr)%mod,testnum++;
else if(sr==1&&sl==1) testsum=testsum*2%mod,testnum++;
else testsum=testsum*(sl*sr-min(sl,sr))%mod,testnum+=2;
}
if(testnum>ansnum) ansnum=testnum,anssum=testsum;
else if(testnum==ansnum) anssum=mo(anssum+testsum)%mod;
}
write(ansnum),putchar(' ');
if(ansnum)write(anssum),putchar('\n'); else puts("1");
return 0;
}