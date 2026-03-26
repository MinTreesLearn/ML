#include<bits/stdc++.h>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
double ans=0.0;
 for(int i=1;i<=n;i++)
 {
    ans+=1.0/i;
 }
 cout<<setprecision(12)<<ans;
return 0;
}