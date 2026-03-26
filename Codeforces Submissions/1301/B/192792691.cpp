#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100005];
vector<int>sb;
int main()
{int t,n,m,k,h=-1;
cin>>t;
while(t--)
{sb.clear();k=0;
cin>>n;
for(int i=1;i<=n;i++)
cin>>a[i];
for(int i=1;i<=n;i++)
if(a[i]!=-1&&(a[i-1]==-1||a[i+1]==-1))
sb.push_back(a[i]);
sort(sb.begin(),sb.end());
if(sb.empty())m=42;
else m=(sb[0]+sb[sb.size()-1])/2;
for(int i=1;i<=n;i++)
{if(a[i]==-1)a[i]=m;
if(i>=2)k=max(k,abs(a[i]-a[i-1]));}
cout<<k<<" "<<m<<endl;
}
}