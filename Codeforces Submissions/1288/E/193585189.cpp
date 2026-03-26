#include <bits/stdc++.h>
using namespace std;

const int N=310000, NN=710000;
int n, m, bit[NN]={0}, a, mn[N], mx[N], now[N]={0}, cur;

void update(int i, int x){
  for(;i<NN;i+=i&(-i))bit[i]+=x;
}

int query(int i){
  int res=0;
  for(;i>0;i-=i&(-i))res+=bit[i];
return res;}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> m;
  for(int i=1; i<=n; i++){
    now[i]=i+N, mn[i]=mx[i]=i;
    update(now[i],1);
  }

  cur=N;
  while(m--){
    cin >> a;
    mn[a]=1, mx[a]=max(query(now[a]), mx[a]);
    update(now[a], -1);
    now[a]=cur--;
    update(now[a], 1); }

  for(int i=1; i<=n; i++){
    a=i;
    int z=query(now[a]);
    mn[a]=min(z, mn[a]), mx[a]=max(z, mx[a]);
    cout << mn[i] << ' ' << mx[i] << '\n';  
  }
  
return 0;}