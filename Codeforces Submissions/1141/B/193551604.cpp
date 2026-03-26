#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    vector<int> s;
   long long int  l=0;
    vector<int> q;
    for(int i=0;i<n;i++)
    {
        long long int x;
        cin>>x;
        s.push_back(x);
    }
    long long int  c=count(s.begin(),s.end(),0);
    long long int y=0;
    if(n==c)
    cout<<"0"<<endl;
    else if(s[0]==1&&s[n-1]==1)
    {
 long long int r=0,d=0;
     for(auto w:s)
     {
        if(w==1)
        r++;
        else
        break;
     }
     for(int i=n-1;i>=0;i--)
     {
        if(s[i]==1)
        d++;
        else
        break;
     }
      y=d+r;
    }
   long long int mx=0;
    if(c<n)
    {
        
         long long int sum=1;
        for(int i=1;i<n;i++)
        {
           if(s[i]==1&&s[i-1]==1)
           sum=sum+1;
            else
            {
                mx=max(sum,mx);
                sum=1;
            }
         mx=max(mx,sum);
           }
          cout<<max(mx,y)<<endl; 
        }
        
}


    
