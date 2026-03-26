#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  for(int k=0;k<t;k++)
  {
     long long int a,b,x,y;
    cin>>x>>y>>a>>b;
    if((y-x)%(a+b)!=0)
    {
      cout<<-1<<endl;
    }
    else
    {
      cout<<(y-x)/(a+b)<<endl;
    }
    
  }
  return 0;
}