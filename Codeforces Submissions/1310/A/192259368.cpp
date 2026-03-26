#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
  int n,i,it=0;
  long long int sum=0,ans=0;
  cin>>n;
  pair<int,int>a[n];
  for(i=0;i<n;i++)cin>>a[i].first;
  for(i=0;i<n;i++)cin>>a[i].second;
  sort(a,a+n);
  multiset<int>st;
  for(i=1;;i++)
  {
      while(a[it].first==i&&it!=n)st.insert(a[it].second),sum+=a[it].second,it++;
      if(st.empty())
      {
          if(it!=n)i=a[it].first-1;
          else break;
          continue;
      }
      auto x=st.end();
      x--;
      sum-=*x;
      ans+=sum;
      st.erase(x);
  }
  cout<<ans;
}