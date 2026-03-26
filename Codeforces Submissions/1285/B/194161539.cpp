#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long min(long long a,long long b){
  if(a<b) return a;
  return b;
}

long long max(long long a,long long b){
  if(a>b) return a;
  return b;
}

bool isPrime(int x){
  int root = sqrt(x+1);
  bool b = true;
  for(int i = 2;i<=root;i++){
    if(x%i==0){
      // cout<<"HrrrI"<<endl;
      b=false;
      break;
    }
  }
  if(b) return true;
  return false;
}

vector<long long> isReal(long long num){
  long long a=-1,b=-1;
  int n=0;
  int pos=0;
  while(num){
    if(num&1) {
      n++;
      if(a==-1)
        a=pos;
      else
        b=pos;
    }
    if(n>2) return {-1,-1};
    num>>=1;
    pos++;
  }
  if(n==2) return {a,b};
  return {-1,-1};
}

void f(unordered_map<int,pair<int,int>> &umap){
  int k=1;
  long long num = 3;
  while(k<=2000000000){
    if(isReal(num)[0]!=-1){
      umap[k]={isReal(num)[0],isReal(num)[1]};
      k++;
    }
    num++;
  }
}

void dfs(vector<vector<bool>> &vis,vector<string> &mat,int i,int j){
  vis[i][j]=true;
  if(i-1>=0 && mat[i-1][j]=='1'){
    dfs(vis,mat,i-1,j);
  }
  if(j-1>=0 && mat[i][j-1]=='1'){
    dfs(vis,mat,i,j-1);
  }
  return;
}

int main()
{
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<long long> arr(n);
    long long sum = 0;
    for(int i=0;i<n;i++){
      cin>>arr[i];
      sum+=arr[i];
    }
    long long currSum = 0;
    long long maxSum = 0;
    int l = 0;
    int r = 0;
    for(int i=0;i<n;i++){
      if(l==0 && i==n-1) break;
      currSum+=arr[i];
      if(currSum<=0){
        currSum = 0;
        l = i+1;
      }
      if(currSum>maxSum){
        if(currSum>=sum){
          r=i;
          maxSum=currSum;
          break;
        }
        r = i;
        maxSum=max(maxSum,currSum);
      }
    }
    if(maxSum>=sum){
      if(l==0 && r==n-1){
        cout<<"YES"<<endl;
      }
      else{
        cout<<"NO"<<endl;
      }
    }
    else{
      cout<<"YES"<<endl;
    }
  }
  return 0;
}