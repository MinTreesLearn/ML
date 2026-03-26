#include<bits/stdc++.h>
using namespace std;
int main() {
    int x , s , arr[9000];
    cin >> x ;
    while (x--){
        cin >> s ;
        for (int i = 0; i < s ; ++i) {
            cin >> arr[i];
        }
        bool y = false ;
        for (int i = 0; i < s ; ++i) {
            for (int j = i + 2; j < s; ++j) {
                if (arr[i] == arr[j]) {
                    y = true;
                    break;
                }
            }
            if (y == true) {
                break;
            }
        }
            if (y == true) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
    }
}

 		   	    	 	 	  	   	   	 		