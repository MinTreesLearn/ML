#include<bits/stdc++.h>
#define ll long long int
using namespace std;


int main(){
  
   ll t;
   cin>>t;
   while(t--){
      ll n;
      cin>>n;

      vector<ll>v;
      for(int i=1;i<=n;i++){
         int x;
         cin>>x;
         v.push_back(x);
         
      }
      
      sort(v.begin(),v.end());
      reverse(v.begin(),v.end());

      for(int i=0;i<n;i++){
         cout<<v[i]<<" ";
      }
      cout<<endl;

     }

  }
