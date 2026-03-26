#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) { 
        string a, b, c;
        cin >> a >> b >> c;
        int check = 0;
        for(int i = 0; i < int(a.size()); i++) {
            if(c[i] != a[i] && c[i] != b[i]) {
                check = 1;
                break;
            }
        }
        if(check) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

}