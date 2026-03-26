#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int n; 
    cin >> n;
    vector<int>arr(n);
    char ch;
    for (int i = 0; i < n; i++) {
        cin >> ch ;
        arr[i] = ch - 'a';
    }
    for (int i = 25; i > 0; i--) {
        for (int j = 0; j < arr.size(); j++) {
            if (arr[j] == i && j > 0 && arr[j - 1] == i - 1 || arr[j] == i && j < arr.size() - 1 && arr[j + 1] == i - 1) {
                arr.erase(arr.begin()+j);
                j = -1;
            }
        }
    }
    cout << n - arr.size();
}
