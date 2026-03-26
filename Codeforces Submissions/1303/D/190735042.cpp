#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
using namespace std;
const int maxn = 1e6 + 10;
typedef long long ll;
#define tbl ios::sync_with_stdio(false), cin.tie(0),cout.tie(0);
int main() {
	int t;
	cin >> t;
	while (t--) {
		vector<int>q(64, 0);
		ll m,n,sum=0,cnt=0;
		cin >> m >> n;
		for (int i = 0; i < n; i++) {
			int h;
			cin >> h;
			sum += h;
			q[log2(h)]++;
		}
		if (sum < m) {
			cout << "-1" << endl;
			continue;
		}
		for (int i = 0; i < 63&&m; i++) {
			if (m % 2 == 1) {
				int j = i;
				while (q[j] == 0) {
					j++; 
					cnt++;
				}
				while (j != i) {
					q[j--]--;
					q[j] += 2;
				}
				q[i]--;
			}
			m /= 2;
			q[i + 1] += q[i] / 2;
		}
		cout << cnt << endl;
	}
}
  			 		 	 	   		   	      	 	
			   						 	 					    	 	  		