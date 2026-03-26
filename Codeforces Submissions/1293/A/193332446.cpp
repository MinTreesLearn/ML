#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
     cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    
int t; cin >> t;
while(t--){
int n,s,k;
cin >> n >> s >> k;

vector<int> v;
for(int i=0;i<k;i++){
    int a; cin >> a;
    v.push_back(a);
}
int ans=0;
for (int i=0; i<=k; i++) {
		if (s+i<=n) {
                if(find(v.begin(),v.end(),s+i)==v.end()){
                ans=i; break;
                }
        }

        if (s-i>=1){
            if(find(v.begin(),v.end(),s-i)==v.end()){
               ans=i; break;
        }
		}
	}

cout << ans << '\n';




}
 return 0;
}
