#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,q;
	cin >> n >> q;
	map<int,bool> a;
	map<int,bool> b;
	int cnt(0);
	while(q--){
		int x,y;
		cin >> x >> y;
		if(x == 1){
			if(a[y] == false){
				a[y] = true;
				if(b[y-1] == true){
					cnt++;
				}
				if(b[y] == true){
					cnt++;
				}
				if(b[y+1] == true){
					cnt++;
				}
				
			}
			else{
				a[y] = false;
				if(b[y-1] == true){
					cnt--;
				}
				if(b[y] == true){
					cnt--;
				}
				if(b[y+1] == true){
					cnt--;
				}
			}
			
		}
		else{
			if(b[y] == false){
				b[y] = true;
				if(a[y-1] == true){
					cnt++;
				}
				if(a[y] == true){
					cnt++;
				}
				if(a[y+1] == true){
					cnt++;
				}
			}
			else{
				b[y] = false;
				if(a[y-1] == true){
					cnt--;
				}
				if(a[y] == true){
					cnt--;
				}
				if(a[y+1] == true){
					cnt--;
				}
			}
		}
		if(a[1] == true){
			cout << "NO" << endl;
		}
		else if(b[n] == true){
			cout << "NO" << endl;
		}
		else if(cnt == 0){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
		// cout << endl;
	}
	return 0;
}