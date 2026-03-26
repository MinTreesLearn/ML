#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define ll long long
#define all(x) (x).begin(), (x).end()
#define test_case int t;cin>>t;while(t--)
#define endl '\n'
ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
using namespace std;
void Sync() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);      cout.tie(0);
}
int binary_search(int arr[], int size, int value) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == value)
            return mid;
        else if (arr[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
bool isPrime(int n) {
    bool ok = 1;
    if (n < 2)
        return false;
    else {
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                ok = 0;
                break;
            }
        }
        if (ok)
            return true;
        else
            return false;
    }
}
bool ispalindrome(vector<int>vec, int sz){
    bool ok = 1;
    for(int i = 0; i < sz; i++){
        if(vec[i] != vec[sz - i -1]){
            ok = 0;
            break;
        }
    }
    if(ok)
        return true;
    else
        return false;
}
void solve() {
    bool ok = 0;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> *(arr + i);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 2; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                ok = 1;
                break;
            }
        }
    }
    string res =  (ok)  ? "YES" : "NO";
    cout<<res<<'\n';
}
void run(){
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
}
int main()
{
    Sync();
    //run();
    test_case
    solve();
    return 0;
}
