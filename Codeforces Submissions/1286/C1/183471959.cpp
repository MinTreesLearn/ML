#include <bits/stdc++.h>
using namespace std;
string s;
int vis1[101][26]={},vis2[101][26]={},cur1[26]={},cur2[26]={};
int ans[100];
int main(int argc, char** argv) {
//	ios::sync_with_stdio(false),cin.tie(0);
	int n,i,j;
	cin>>n;
	if(n==1)
	{
		cout<<"? 1 1\n";
		cin>>s;
		cout<<"! "<<s<<'\n';
	}
	else
	{
		cout<<"? 1 "<<n<<'\n';
		for(i=0;i<n*(n+1)/2;i++)
		{
			cin>>s;
			for(j=0;j<s.length();j++)
			{
				vis1[s.length()][s[j]-'a']++; 
			}
		}
		cout<<"? 2 "<<n<<'\n';
		for(i=0;i<n*(n-1)/2;i++)
		{
			cin>>s;
			for(j=0;j<s.length();j++)
			{
				vis2[s.length()][s[j]-'a']++; 
			}
		}
		cout<<"? 1 1\n";
		cin>>s;
		ans[0]=s[0]-'a';
		for(i=1;i<n;i++)
		{
			if(i%2==0)
			{
				for(j=0;j<26;j++)
				{
					vis2[i/2][j]+=vis2[n-1][j];
					if(vis2[i/2][j]-vis2[i/2+1][j]-cur2[j]==2||vis2[i/2][j]-vis2[i/2+1][j]-cur2[j]==1&&ans[n-i/2]!=j)ans[i/2]=j;
					cur2[j]=vis2[i/2][j]-vis2[i/2+1][j];
				}
			}
			else
			{
				for(j=0;j<26;j++)
				{
					vis1[i/2+1][j]+=vis1[n][j];
					if(vis1[i/2+1][j]-vis1[i/2+2][j]-cur1[j]==2||vis1[i/2+1][j]-vis1[i/2+2][j]-cur1[j]==1&&ans[i/2]!=j)ans[n-i/2-1]=j;
					cur1[j]=vis1[i/2+1][j]-vis1[i/2+2][j];
				}
			}
		}
		cout<<"! "; 
		for(i=0;i<n;i++)cout<<(char)(ans[i]+'a');
		cout<<'\n';
	}
	return 0;
}