#include <iostream>
using namespace std;

int main() {
    int n,x;
    cin >> n;
    for (int i=0; i <n; i++){
        cin >> x;
        if (x%2==0){
            while (x>0){
                x-=2;
                cout <<1;
            }
            cout << endl;
        }
        else{
            while (x>0) {
                if (x%2!=0) {
                    x -= 3;
                    cout << 7;
                }
                else if (x%2==0) {
                    cout << 1;
                    x-=2;
                }
            }
        }
        cout << endl;
    }
}