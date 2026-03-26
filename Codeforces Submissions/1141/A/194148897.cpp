#include<bits/stdc++.h>
using namespace std;
int
main () 
{
int t=1;
//cin>>t;
while (t--)
    {
    int n,m;
    cin>>n>>m;
    if (m%n!= 0) 
        cout<<-1<<endl;
    else if (m==n) 
        cout<<0<<endl;
        else{
    int a = m / n, ans = 0;
    while (a!=1) {
        if (a%2==0) {
            a/=2;
            ans++;
        } else if (a%3==0) {
            a/=3;
            ans++;
        } else {
            ans=-1;
            break;
        }
    }
   cout<<ans<<endl; 
        }
}
return 0;
}


 
 
