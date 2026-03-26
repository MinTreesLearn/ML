

using namespace std;




const long double PI = 3.14159265;


#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <queue>
#include <unordered_set>
#include <random>
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
const ll INF = 1e15;
const ll MOD = 1e9 + 7;

const pii ADJ4[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const pii ADJ8[8] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
const int MAX_N = 1e5 + 5;

void solve() {
	int n;
	cin >> n;
	
	int ans[n];
	string s;
	cin >> s;
	
	
	int cur = n;
	int last = 0;
	
	for(int i=0; i < n; i++){
		if(i == n-1 || s[i] == '>'){
			
			for(int j=i; j >= last; j--){
				ans[j] = cur;
				cur--;
				
			}
			last = i+1;
			
			
		}
	}
	for(int i=0; i < n; i++) cout << ans[i] << " ";
	cout << "\n";
	
	cur = 1;
	last = 0;
	
	for(int i=0; i < n; i++){
		if(i == n-1 || s[i] == '<'){
			
			for(int j=i; j >= last; j--){
				ans[j] = cur;
				cur++;
				
			}
			last = i+1;
			
			
		}
	}
	for(int i=0; i < n; i++) cout << ans[i] << " ";
	cout << "\n";
	
	
	
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    
    int t;
    cin >> t;
    while(t--) solve();
}
