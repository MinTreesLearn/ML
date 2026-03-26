#include <bits/stdc++.h>
using namespace std;



int main(){

	int n;
	cin >> n;
	pair<int, int> sc, dp;
	vector<int> areas(4,0);
	for(int i=0; i<n; i++){
		cin >> sc.first >> sc.second >> dp.first >> dp.second;
		areas[0] = (dp.first * sc.second);
		areas[1] = (sc.first * (sc.second - dp.second - 1));
		areas[2] = (dp.second * sc.first);
		areas[3] = ((sc.first - dp.first - 1) * sc.second);
		
		int max = areas[0];
		for(int j =1; j<4; j++){
			if(max < areas[j]) max = areas[j];
		}
		cout << max << endl;
	}
	
}
