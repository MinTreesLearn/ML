#include<bits/stdc++.h>
using namespace std;

int main()
{
int t;
cin>>t;
while(t--)
{
string a,b="";
cin>>a;
bitset<26>mp;
int i=0;
bool flag=true;
for(auto c:a)
if(mp[c-'a']==1)
{
if(i<b.size()-1&&b[i+1]==c)
i++;
else if(i!=0 &&b[i-1]==c)
i--;
else
flag=false;
}
else
{
mp[c-'a']=1;
if(i==b.size()-1)
b+=c,i++;
else if(i==0)
b=c+b;
else
flag=false;
}
if(flag)
{
cout<<"YES"<<endl<<b;
for(int i=0;i<26;i++)
if(!mp[i])
cout<<char(i+'a');
cout<<endl;
}
else cout<<"NO"<<endl;
}
}