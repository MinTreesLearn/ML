#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
typedef tree<int, null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> TREE;
//tree.find_by_order() / tree.order_of_key();
#define N 2505
using pi = pair<int, int>;
int castle[N][2];
long long int c[N][10];
long long int cmpin(pair<int, int> a, pair<int, int> b){
	long long int ady = a.first, adx = a.second, bdy = b.first, bdx = b.second;
	ady*=bdx;
	bdy*=adx;
	return bdy-ady;
}
bool cmp(pair<int, int> a, pair<int, int> b){
	bool bh1 = a < pi(0, 0);
	bool bh2 = b < pi(0, 0);
	if(bh1 != bh2) return bh1 < bh2;
	return cmpin(a, b) > 0;	
}
long long int comb(int n, int m){
	if(m>n){
		return 0;
	}
	if(n==m){
		return 1;
	}
	if(m==1){
		return n;
	}
	if(c[n][m]>0){
		return c[n][m];
	}
	c[n][m] = comb(n-1, m)+comb(n-1, m-1);
	return c[n][m];
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> castle[i][0] >> castle[i][1];
	}
	long long int ans = comb(n, 5)*5;
	for(int i=0; i<n; ++i){
		vector<pair<int, int>> ang;
		for(int j=0; j<n; ++j){
			if(i==j){
				continue;
			}
			int dx = castle[i][0]-castle[j][0], dy = castle[i][1]-castle[j][1];
			ang.push_back(make_pair(dy, dx));//j to i
		}
		//ang[i].push_back(make_pair(-1, -9));
		sort(ang.begin(), ang.end(), cmp);
		/*for(int j=0; j<ang[i].size(); ++j){
			cout << "ang[" << i << "][" << j << "] = " << ang[i][j].first << ", " << ang[i][j].second << "\n";
		}*/
		int j = 0;
		for(int k=0; k<ang.size(); k++){
			while(j < k + ang.size() && cmpin(ang[k], ang[j % ang.size()]) >= 0) j++;
			ans -= comb(j - k - 1, 3);
		}	
	}
	cout << ans << '\n';
	return 0;
}
