//trgovac-berti grindset
#include<bits/stdc++.h>
//#pragma GCC optimize("O3")
using namespace std;
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int n, dp[101][101][101][2];
bool b[101];
vector<int> v;

int f(int x, int prv, int drug, int zadnji){
	//cout << x << " " << prv << " " << drug << endl;
	if (x>=n) return 0;
	if (v[x] != 0) return f(x+1, prv, drug, v[x]%2)+(zadnji == v[x]%2 ? 0 : 1);
	if (dp[x][prv][drug][zadnji] != -1) return dp[x][prv][drug][zadnji];
	dp[x][prv][drug][zadnji] = mod;
	int sol;
	if (prv>0){
		sol = f(x+1, prv-1, drug, 0);
		if (x>0) sol+=(zadnji == 0 ? 0 : 1);
		dp[x][prv][drug][zadnji] = min(dp[x][prv][drug][zadnji], sol);

	}
	if (drug>0){
		sol = f(x+1, prv, drug-1, 1);
		if (x>0) sol+=(zadnji == 1 ? 0 : 1);
		dp[x][prv][drug][zadnji] = min(dp[x][prv][drug][zadnji], sol);
	}
	return dp[x][prv][drug][zadnji];
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); 
  memset(dp, -1, sizeof dp);
  cin >> n;
  v.resize(n);
  
  for(int &u : v){
  	cin >> u;
  	b[u]=1;
  }
  int parni = 0, neparni = 0;
  for (int i = 1; i <= n; i++)
  {
  	//cout << b[i] << " ";
  	if (i%2==0 && !b[i]) parni++;
  	if (i%2==1 && !b[i]) neparni++;
  }
  //cout << endl;
  cout << f(0, parni, neparni, v[0]%2);
  
  	
  




  return 0;
}