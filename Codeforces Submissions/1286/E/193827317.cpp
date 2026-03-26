// LUOGU_RID: 102268817
#include<bits/stdc++.h>
#define int __int128
#define N 600005
using namespace std;
int read(){
	int w=0,h=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')h=-h;ch=getchar();}
	while(ch>='0'&&ch<='9'){w=w*10+ch-'0';ch=getchar();}
	return w*h;
}
void write(int x){if(x>9)write(x/10);putchar(x%10+'0');}
int n,w[N],nxt[N],fail[N],stk[N],top;
map<int,int>s;vector<int>del;
char S[N],ch[2];
signed main(){
	n=read();
	int ans=0,sum=0;
	for(int i=1,j=0;i<=n;i++){
		scanf("%s",ch+1);w[i]=read();
		S[i]=(ch[1]-'a'+ans)%26+'a';
		w[i]^=(ans&((1<<30)-1));
		while(j&&S[i]!=S[j+1])j=nxt[j];
		if(i>1&&S[i]==S[j+1])j++;nxt[i]=j;
		fail[i-1]=(S[i]==S[nxt[i-1]+1])?fail[nxt[i-1]]:nxt[i-1];
		for(int k=i-1,val;k;)
			if(S[i]==S[k+1])k=fail[k];
			else{
				sum-=(val=w[*lower_bound(stk+1,stk+top+1,i-k)]);
				if(--s[val]==0)s.erase(val);k=nxt[k];
			}
		while(top&&w[stk[top]]>=w[i])top--;stk[++top]=i;
		int cnt=0;del.clear();
		for(auto it=s.upper_bound(w[i]);it!=s.end();it++)
			cnt+=it->second,sum+=(w[i]-it->first)*it->second,del.push_back(it->first);
		for(auto u:del)s.erase(u);s[w[i]]+=cnt;
		if(i>1&&S[i]==S[1])sum+=w[i],s[w[i]]++;
		ans+=sum+w[stk[1]];
		write(ans);putchar('\n');
	}
	return 0;
}
