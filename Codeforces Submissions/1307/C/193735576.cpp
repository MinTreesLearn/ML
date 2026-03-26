#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long 
#define sort(v) sort(v.begin(),v.end())
void solve(){
	
	string s;
	cin>>s;
	map<char,int> mp;
	map<string,int> mp1;
	vector<int> v;
	int mx=0;
	int mx1=0;
	for (int i = 0; i <s.size(); i++)
	{
		for (int j = 97; j <=122; j++)
		{
			
			if (mp[char(j)]!=0)
			{
				string s1=string(1,char(j))+s[i];
				// cout<<s1<<endl;
				mp1[s1]+=mp[char(j)];
				if (mp1[s1]>mx1)
				{
					mx1=mp1[s1];
				}
				
			}
			
		}
		
		mp[s[i]]++;
		if (mp[s[i]]>mx)
		{
			mx=mp[s[i]];
		}
		
		
	}
	cout<<max(mx,mx1);
	
	
}
signed main(){

	fast
	int t=1;
	// cin>>t;
	while(t--)
	{ solve(); }
	return 0;
}
