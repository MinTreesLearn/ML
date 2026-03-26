#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define ll long long   
#define pb push_back
#define lb(s,x)  lower_bound(s.begin(),s.end(),x)
#define ub(s,x)  upper_bound(s.begin(),s.end(),x)
#define asort(p) sort(p.begin(),p.end())
#define dsort(p) sort(p.begin(),p.end(),greater<int>())
#define count(s,x)  count(s.begin(),s.end(),x)
//ceil function returns least greater or equal value
//floor fucntion returns smaller or equal value to the number
 //upper case aplhabet-(65-90)
 //lower case aplhabet-(97-122)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@___**___@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void killer()
{ ll int n;
cin>>n;
if(n%2==0)
{
   for(ll int i=0;i<n/2;i++)
   cout<<"1";
}
else
{cout<<"7";
   for(ll int i=0;i<(n/2)-1;i++)
   {
    cout<<"1";
   }
   
}
 cout<<endl;
}
 int main()
{
 ll int t;
cin>>t;
while(t--)
{
killer();
}
}