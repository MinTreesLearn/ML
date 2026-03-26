#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;cin>>n;
    vector<int>x(n+1),y(n+1);
    for(int i=1;i<n+1;i++)cin>>x[i]>>y[i];
    if(n%2==1)cout<<"NO\n";
    else{
       set<pair<int,int>>st;
       for(int i=1;i<=(n/2);i++){
          double X=(x[i]+x[i+(n/2)]);
          double Y=(y[i]+y[i+(n/2)]);
          st.insert({X,Y});
       }
       if(st.size()==1)cout<<"YES";
       else cout<<"NO\n";
    }
}