#include <iostream>

//#include <deque>
#include <vector>
using namespace std;

//vector <string> vec_s;
int main() {
    int t; cin >> t;
//    bool f = true;
    for (int i = 1; i <= t; ++i) {

        int n; cin >> n;
        string s; cin >> s;
        int p = 0, ans = 0;

        for (int j = n - 1; j >= 0; --j) {
            if (s[j] == 'P') p++;
            else ans = max(ans, p), p = 0;
        }
        cout << ans << '\n';
    }
    return 0;
}

    	     		  	 	 		 	        	