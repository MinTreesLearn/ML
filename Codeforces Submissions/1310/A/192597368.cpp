#include<bits/stdc++.h>
using namespace std;
long long  n,cnt,k,num,ans;
priority_queue<int>q;
struct  ono{
	int  x,y;
	bool  operator <(const ono &W)const
	{
		return  x<W.x;
	}
}a[1000000];
int main()
{
	cin>>n;
	
	for(int  i=1;i<=n;i++)
	cin>>a[i].x;
	
	for(int  i=1;i<=n;i++)
	cin>>a[i].y;
	
	sort(a+1,a+1+n);
	
	while(q.size()||cnt<n)
	{
	  k++;
	  if(!q.size())
	  {
	  	k=a[cnt+1].x;
	  	while(k==a[cnt+1].x&&cnt<n)
	  	{
	  	  cnt++;
	  	  num+=a[cnt].y;
	  	  q.push(a[cnt].y);
		}
	  }
	  else
	  {
	  	while(k==a[cnt+1].x&&cnt<n)
	  	{
	  	  cnt++;
	  	  num+=a[cnt].y;
	  	  q.push(a[cnt].y);
		}
	  }
	  num-=q.top();
	  q.pop();
	  ans+=num;
	}
	
	cout<<ans;
	return 0;
} 
		     		  	 		  		  	 			 	 	