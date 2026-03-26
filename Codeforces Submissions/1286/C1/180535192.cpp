#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
char an[105];
struct cx{
	int len,tn[26];
}sp[105];
int tn[105][26],tn1[26],tn2[26];
bool zqr(cx a1,cx a2)
{
	return a1.len<a2.len;
}
void solve(int l)
{
	if(l==1)
	{
		printf("? %d %d\n",1,1);fflush(stdout);
		string s;cin>>s;
		an[1]=s[0];
		return;
	}
	multiset<vector<int> >aa;
	printf("? %d %d\n",1,l);fflush(stdout);
	fo(i,1,l*(l+1)>>1)
	{
		vector<int> tn(26,0);
		string s;cin>>s;
		for(auto xx:s)tn[xx-'a']++;
		aa.insert(tn);
	}
	printf("? %d %d\n",1,l-1);fflush(stdout);
	fo(i,1,l*(l-1)>>1)
	{
		vector<int> tn(26,0);
		string s;cin>>s;
		for(auto xx:s)tn[xx-'a']++;
		aa.erase(aa.find(tn));
	}
	int tot=0;
	for(auto xx:aa)
	{
		tot++;
		fo(i,0,25)sp[tot].len+=xx[i],sp[tot].tn[i]=xx[i];
	}
	sort(sp+1,sp+tot+1,zqr);
	fo(i,1,tot)
	{
		fo(j,0,25)if(sp[i].tn[j]-sp[i-1].tn[j])an[tot-i+1]=j+'a';
	}
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen("CF1286C.in","r",stdin);
//	freopen("CF1286C.out","w",stdout);
	int n;scanf("%d",&n);
	if(n==1)
	{
		printf("? %d %d\n",1,1);fflush(stdout);
		string s;cin>>s;
		printf("! %c",s[0]);fflush(stdout);
		return 0;
	}
	solve(n>>1);
	printf("? %d %d\n",1,n);
	fo(i,1,n*(n+1)>>1)
	{
		string s;cin>>s;
		int len=s.size();
		for(auto xx:s)tn[len][xx-'a']++;
	}
	fo(i,1,n-(n>>1))
	{
		fo(j,0,25)tn1[j]=tn[i][j]-tn[i-1][j];
		fo(j,0,25)tn2[j]=tn[i+1][j]-tn[i][j];
		fo(j,0,25)if(tn1[j]-tn2[j])
		{
			if(tn1[j]-tn2[j]==2)an[n-i+1]=j+'a';
			else if(j+'a'!=an[i])an[n-i+1]=j+'a';
		}
	}
	printf("! ");fo(i,1,n)putchar(an[i]); 
	return 0;
}