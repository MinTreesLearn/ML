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
    int n,d;
    cin >> n >> d;
    if(n==d){
             cout << "YES" << '\n';
            continue;
    }
    int sqr=(int)sqrt(d);
     int maxn = sqr;
     bool f=0;
for(int i=0; i<maxn; i++) {
			if(i+((d+i)/(i+1))<=n){
		   cout << "YES" << '\n';
            f=1;
            break;
			}
}
if(f){
    continue;
}

		cout << "NO" << '\n';
}
 return 0;
}
