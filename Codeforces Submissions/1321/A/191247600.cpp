#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    
       ll n;
       cin>>n;
       
       ll a[n];
       for(int i=0;i<n;i++)
       {
           cin>>a[i];
       }
       
       ll b[n];
       for(int i=0;i<n;i++)
       {
           cin>>b[i];
       }
       
       ll count1=0;
       ll count2=0;
       for(int i=0;i<n;i++)
       {
           if(a[i]==1 && b[i]==0)
           count1++;
           
           else if(a[i]==0 && b[i]==1)
           count2++;
       }
       
       if(count1!=0 && count2!=0)
       cout<<count2/count1+1<<endl;
       
       else if(count1==0 && count2==0)
       cout<<"-1"<<endl;
       
       else if(count1==0 && count2!=0)
       cout<<"-1"<<endl;
       
       else
       cout<<"1"<<endl;
   
}