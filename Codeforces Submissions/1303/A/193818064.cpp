/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
   int t;
   cin>>t;
  for(int i=0;i<t;i++){
       string s;
       cin>>s;
     
       int firstnumber=0,secondnumber=0;
       for(int j=0;j<s.size();j++){
           if(s[j]=='1'){
               firstnumber=j;
               break;
           }
       }
       
       for(int k=s.size()-1;k>firstnumber;k--){
           if(s[k]=='1'){
               secondnumber=k;
               break;
           }
       }
      int count=0;
       for(int g=firstnumber;g< secondnumber;g++){
           if(s[g]=='0')
           count++;
       }
       cout<<count<<endl;
      
   }
  

    return 0;
}