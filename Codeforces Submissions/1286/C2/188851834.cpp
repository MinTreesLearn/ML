// LUOGU_RID: 99372543
#include<bits/stdc++.h>
using namespace std;

string s;
multiset<string> st;
string ss[110];

vector<string> v[110]; 
char ans[1000];

bool cmp(string s1,string s2)
{
	return s1.size()<s2.size();
}

int a[1100];
int n;

void branch() 
{
	int n1=n;
	n=(n+1)/2;
	cout<<"? "<<1<<' '<<n<<'\n';
	fflush(stdout);
	for (int i=0;i<n*(n+1)/2;i++)
	{
		cin>>s;
		sort(s.begin(),s.end());
		st.insert(s);	
	} 
	cout<<"? "<<2<<' '<<n<<'\n';
	fflush(stdout);
	for (int i=0;i<n*(n-1)/2;i++)
	{
		cin>>s;
		sort(s.begin(),s.end());
		st.erase(st.find(s));	
	} 
	int cnt=0;
	for (auto p:st)
	{
		ss[cnt++]=p;
	}
	sort(ss,ss+cnt,cmp);
	ans[0]=ss[0][0];
	for (int i=1;i<cnt;i++)
	{
		for (auto p:ss[i-1])
			a[p]--;
		for (auto p:ss[i])
			a[p]++;
		for (int j=0;j<255;j++)
			if (a[j]>0)
			{
				a[j]=0;
				ans[i]=j;
			}
	}
	cout<<"? "<<1<<' '<<n1<<'\n';
	for (int i=0;i<n1*(n1+1)/2;i++)
	{
		cin>>s;
		v[s.size()].push_back(s);
	} 
	for (int i=n1-1;i>=n;i--)
	{
		for (int j='a';j<='z';j++)
			a[j]=0;
		for (auto p:v[i])
			for (auto q:p)
				a[q]++;
		for (int j=0;j<(n1-i);j++)
			a[ans[j]]-=(j+1);
		for (int j=n1-1;j>i;j--)
			a[ans[j]]-=n1-j;
		for (int j='a';j<='z';j++)
			if (a[j]%(n1+1-i)!=0)
				ans[i]=j; 
	}
	cout<<"! ";
	for (int i=0;i<n1;i++)
		cout<<ans[i];
	fflush(stdout);
	exit(0);
}

int main()
{
	cin>>n;
	if (n==1)
	{
		cout<<"? "<<1<<' '<<1<<'\n';
		char c;
		cin>>c;
		cout<<"! "<<c;
		fflush(stdout);
		return 0;
	}
	if (n>=6)
		branch();
	cout<<"? "<<1<<' '<<n<<'\n';
	fflush(stdout);
	for (int i=0;i<n*(n+1)/2;i++)
	{
		cin>>s;
		sort(s.begin(),s.end());
		st.insert(s);	
	} 
	cout<<"? "<<2<<' '<<n<<'\n';
	for (int i=0;i<n*(n-1)/2;i++)
	{
		cin>>s;
		sort(s.begin(),s.end());
		st.erase(st.find(s));	
	} 
	int cnt=0;
	for (auto p:st)
	{
		ss[cnt++]=p;
	}
	sort(ss,ss+cnt,cmp);
	ans[0]=ss[0][0];
	for (int i=1;i<cnt;i++)
	{
		for (auto p:ss[i-1])
			a[p]--;
		for (auto p:ss[i])
			a[p]++;
		for (int j=0;j<255;j++)
			if (a[j]>0)
			{
				a[j]=0;
				ans[i]=j;
			}
	}
	cout<<"! "<<ans;
	return 0;
}