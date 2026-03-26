#include<bits/stdc++.h>
using namespace std;
int main()
{
int n; string s;
cin>>n>>s;
for(int i='z';i>'a';i--)
for(int k=0;k<s.size();k++)
if(s[k]==i&&(s[k-1]==i-1||s[k+1]==i-1))
s.erase(k,1),k=-1;
cout<<n-s.size()<<endl;
return 0;
}