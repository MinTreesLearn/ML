#include <bits/stdc++.h>
#define hello ios_base::sync_with_stdio(false);
#define world cin.tie(NULL);
using namespace std;

int main(){
  hello world
  int n;
  cin>>n;
  int A[n];
  for (int i = 0; i < n; i++)
  {
    int a,b;
    cin>>a>>b;
    if (a==b)
    {
      A[i]=0;
    }
    else if (a>b)
    {
      if (a%2==0 && b%2==0)
      {
        A[i]=1;
      }
      else if (a%2==1 && b%2==1)
      {
        A[i]=1;
      }
      else
      {
        A[i]=2;
      }
      

    }
   else{
    if (a%2==0 && b%2==0)
      {
        A[i]=2;
      }
      else if (a%2==1 && b%2==1)
      {
        A[i]=2;
      }
      else
      {
        A[i]=1;
      }
   }
  }
  for (int i = 0; i < n; i++)
  {
    cout<<A[i]<<endl;
  }
  
  return 0;
}