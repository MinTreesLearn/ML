#include <bits/stdc++.h>
#define ll __int128
#define int long long
#define fi first
#define se second
using namespace std;
void write(ll x){
if(x>9)write(x/10);
putchar(x%10+48);
}
const int _=6e5+7;
int n,top,st[_],fa[_],w[_],ne[_];
char s[_];
map<int,int>g;
signed main(){
scanf("%lld",&n);
cin>>s[1]>>w[1];
st[++top]=1;
ll ans=w[1],sum=0;
write(w[1]);putchar('\n');
for(int i=2,j=0;i<=n;i++){
cin>>s[i]>>w[i];
s[i]=(s[i]-'a'+ans)%26+'a',w[i]=w[i]^(int)(ans&((1<<30)-1));
while(j&&s[i]!=s[j+1])j=ne[j];
if(s[i]==s[j+1])j++;
ne[i]=j,fa[i]=s[i]!=s[ne[i-1]+1]?ne[i-1]+1:fa[ne[i-1]+1];
for(int j=i;j>1;){
if(s[j]==s[i]){j=fa[j];continue;}
int v=w[*lower_bound(st+1,st+top+1,i-j+1)];
if(!--g[v])g.erase(v);
sum-=v,j=ne[j-1]+1;
}
int num=0;
for(auto it=g.upper_bound(w[i]);it!=g.end();g.erase(it++))
num+=it->se,sum-=(int)(it->fi-w[i])*it->se;
if(s[1]==s[i])num++,sum+=w[i];
g[w[i]]+=num;
while(top&&w[st[top]]>=w[i])top--;
st[++top]=i;
write(ans+=sum+w[st[1]]),putchar('\n');;
}
return 0;
}