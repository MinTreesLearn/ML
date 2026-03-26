#include <bits/stdc++.h>

using namespace std;

int main (){
	int t;cin >> t;
	while(t--){
		int a,b,c,n;cin >> a>>b>>c>>n;
		int ans = (a+b+c+n)/3;
		if((ans < a || ans < b || ans < c) || ((a+b+c+n) % 3 !=0)) cout << "NO"<<endl;
		else cout << "YES" << endl;
	}
	system("pause");
	return 0;
	
}
 