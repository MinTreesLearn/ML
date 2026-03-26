#include <iostream>
#include <vector>

using namespace std;

int main()
{
   int n;
   vector<int> r;
   vector<int> b;
   int rw=0;
   int bw=0;
   int ans;
   cin>>n;
   for(int i = 0; i<n; i++){
       int r_i;
       cin>>r_i;
       r.push_back(r_i);
   }
    for(int i = 0; i<n; i++){
       int b_i;
       cin>>b_i;
       b.push_back(b_i);
   }
   for(int i = 0; i<n; i++){
       if(r[i]>b[i]){
           rw+=1;
           
       }
        if(b[i]>r[i]){
           bw+=1;
           
       }
    }
   
   bw+=1;
 if(rw==0){
      ans=-1;
   }
   else{
   if(bw%rw==0){
       ans=bw/rw;
    }
    else{
     ans=bw/rw+1;
     }
     }
     cout<<ans;

    return 0;
}
