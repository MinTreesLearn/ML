/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
   int n;
   cin>>n;
   int count=0,sumb=0,sumr=0;
   int r[n],b[n];
   for(int i=0;i<n;i++)
   {
       cin>>r[i];
   }
   for(int i=0;i<n;i++)
   {
       cin>>b[i];
       if(r[i]==1&&b[i]==0)
       count++;
       else if(r[i]==1)
       sumr++;
       sumb=sumb+b[i];
   }
   if(count==0)
   cout<<-1<<endl;
   else
   {
       int i=1;
       while(true)
       {
         if((i*count+sumr)>sumb)
         {
             cout<<i<<endl;
             break;
         }
         i++;
       }
   }
    return 0;
}

