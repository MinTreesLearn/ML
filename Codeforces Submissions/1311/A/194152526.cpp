#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin >> test;

    while(test--){
        int a, b;
        cin >> a >> b;

        if(a == b) cout << 0 << endl;
        else if(a<b){
            if((a%2 != 0 && b%2 == 0) || (a%2 == 0 && b%2 != 0)) cout << 1 << endl;
            else if((a%2 != 0 && b%2 != 0) || (a%2 == 0 && b%2 == 0)) cout << 2 << endl;
        }
        else{
            if((a%2 != 0 && b%2 == 0) || (a%2 == 0 && b%2 != 0)) cout << 2 << endl;
            else if((a%2 != 0 && b%2 != 0) || (a%2 == 0 && b%2 == 0)) cout << 1 << endl;
        }
    }

    return 0;
}
