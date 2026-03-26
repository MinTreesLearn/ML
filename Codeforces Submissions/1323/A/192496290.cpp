#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n];
    int x=0,y,z=0,c[2];
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
        if(a[i]%2==0)
        {
         x=1;
         y=i;
        }
        else
        {
             if(z==0)
             {
               c[0]=i;
               z++;
             }
             else if(z==1)
             {
               c[1]=i;
               z++;
             }
        }
    }
    if(x==1)
    {
      cout<<1<<"\n"<<y+1;
    }
    else if(z>=2)
    {
      cout<<2<<"\n"<<c[0]+1<<" "<<c[1]+1;
    }
    else
    {
      cout<<-1;
    }
    cout<<"\n";
  }
}

	  	  	 		 	 			  	 				   			