#include <bits/stdc++.h>

using namespace std; 

long long n, m, k, c, x, a, resn=0, resm=0, ans=0, cnt;
vector<int>an;
vector<int>am;
vector<int>v;

int main(){
  cin >> n >> m >> k;
  for(long long i=0; i<n; i++){
    cin >> a;
    an.push_back(a);
  }
  for(long long i=0; i<m; i++){
    cin >> a;
    am.push_back(a);
  }
  for(long long i=1; i*i<=k; i++){
    if(k%i == 0){
      x=k/i;
      if(x == i){
        v.push_back(i);
      }
      else{
        v.push_back(i);
        v.push_back(x);
      }
    }
  }
  for(long long i=0; i<v.size(); i++){
    cnt=0;
    resn=0;
    for(long long j=0; j<n; j++){
      if(an[j]==1){
        cnt++;
      }
      else{
        if(cnt>=v[i]){
          resn+=cnt-v[i]+1; 
        }
        cnt=0;
      }
    }
    if(cnt>=v[i]){
      resn+=cnt-v[i]+1;
    }
    c=k/v[i];
    cnt=0;
    resm=0;
    for(long long j=0; j<m; j++){
      if(am[j]==1){
        cnt++;
      }
      else{
        if(cnt>=c){
          resm+=cnt-c+1;
        }
        cnt=0;
      }
    }
    if(cnt>=c){
      resm+=cnt-c+1;
    }
    ans+=resn*resm;
  }
  cout << ans << endl;
}