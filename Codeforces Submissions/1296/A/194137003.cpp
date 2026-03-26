#include <bits/stdc++.h>
using namespace std;
int main() {

    int n; cin >> n;
    for(int i=0;i<n;i++){
        int even = 0,odd = 0;
        // vector<int> arr;
        int m; cin >> m;
        for(int j=0;j<m;j++){
            int num; cin >> num;
            // arr.push_back(num);
            if(num & 1) odd++;
            else even++;
        }
        if(odd & 1) cout << "YES" << endl;
        else{
            if(odd == 0 || even == 0 ) cout << "NO" << endl;
            else  cout << "YES" << endl;
        }
    }
}
 		  		  				 	  		 	  	 	 		 	