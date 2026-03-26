#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <map>
using namespace std;
bool sortbysec(const pair<char,int> &a,
              const pair<char,int> &b)
{
    return (a.first > b.first);
}
bool isPalindrome(string S)
{
    // Stores the reverse of the
    // string S
    string P = S;
 
    // Reverse the string P
    reverse(P.begin(), P.end());
 
    // If S is equal to P
    if (S == P) {
        // Return "Yes"
        return true;
    }
    // Otherwise
    else {
        // return "No"
        return false;
    }
}

bool poss(vector<int> &g1,vector<int> &g2,long long int mid){
  long long int sum=0;
  int j=0;
  while(j<g1.size()){
    if(g1[j]>mid){
      sum=sum+g2[j];
    }
    j++;
  }
  if(sum<=mid){
    return true;
  }
  return false;
}
bool isPrime(long long int n)
{
  
    if (n <= 1)
        return false;
 
    
    for (long long int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}

long long int onesComplement(long long  int n)
{
    vector<int> v;
    // convert to binary representation
    while (n != 0) {
        v.push_back(n % 2);
        n = n / 2;
    }
    reverse(v.begin(), v.end());
    // change 1's to 0 and 0's to 1
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0)
            v[i] = 1;
        else
            v[i] = 0;
    }
    // convert back to number representation
    int two = 1;
    for (int i = v.size() - 1; i >= 0; i--) {
        n = n + v[i] * two;
        two = two * 2;
    }
    return n;
}
static bool sortbysec(const vector<int> &a,
              const vector<int> &b)
{
    return (a.size() < b.size());
}
bool ans23(int n,vector<pair<int,int>> g1){
  int j=0;
  while(j<g1.size()){
    if(n<g1[j].first){
      return false;
    }
    else{
      n=n+g1[j].second;
    }
    j++;
  }
  return true;
  



}
int ans(int i,int n,vector<int> &dp,string s, map<char,vector<int>> m1,map<char,int> m2){

  if(i>=n){
    return 0;
  }
  if(dp[i]!=-1){
    return dp[i];
  }
  int r=m1[s[i]].size();
  if(m2[s[i]]<r){
    m2[s[i]]++;
    int r1=(ans(i+1,n,dp,s,m1,m2));
    
    int r2=2+ans(m1[s[i]][m2[s[i]]-1]+1,n,dp,s,m1,m2);
    return dp[i]=max(r1,r2);

  }
  else{
    return dp[i]=ans(i+1,n,dp,s,m1,m2);
  }



 
  
}
  
 
 

int main(){
    int t;
    cin>>t;
    
   
  
    
    int i=0;
  
  while(i<t){
 int a,b,p;
 cin>>a>>b>>p;
 string s;
 cin>>s;
 int j=s.length()-2;
 while(1){
  if(s[j]=='B'){
 
    if(p>=b){
      while(s[j]=='B'&&j>=0){
        j--;
      }
      p=p-b;

    }
    else{
      break;
    }
  }
  if(s[j]=='A'){
    if(p>=a){
      while(s[j]=='A'&&j>=0){
        j--;
      }
      p=p-a;

    }
    else{
      break;
    }
  }
 
  if(j<0){
    break;
  }
 }
  
 if(j<0){
  cout<<1<<"\n";
  i++;
  continue;
 }
 if(j>=s.length()-2){
  cout<<s.length()<<"\n";
  i++;
  continue;
 }
 cout<<j+2<<"\n";
 


i++;
  }


    
      
        

          
            

  
          



        

       
      
    return 0;
}