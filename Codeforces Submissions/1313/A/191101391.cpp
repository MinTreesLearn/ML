#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef float ff;
typedef vector<long long int> vi;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int)x.size()
#define pb(x) push_back(x)
#define endl "\n"

void solve(){
    vector <int> a(3);
    cin>>a[0]>>a[1]>>a[2];
    sort(a.rbegin(), a.rend());
    int sum = 0;
    if(a[0] > 0){
        sum += 1;
        a[0] -= 1;
    }
    if(a[1] > 0){
        sum += 1;
        a[1] -= 1;
    }
    if(a[2] > 0){
        sum += 1;
        a[2] -= 1;
    }
    if(a[0] > 0 && a[1] > 0){
        sum += 1;
        a[0] -= 1; a[1] -= 1;
    }
    if(a[1] > 0 && a[2] > 0){
        sum += 1;
        a[1] -= 1; a[2] -= 1;
    }
    if(a[2] > 0 && a[0] > 0){
        sum += 1;
        a[0] -= 1; a[2] -= 1;
    }
    if(a[0] > 0 && a[1] > 0 && a[2] > 0){
        sum += 1;
        a[0] -= 1; a[1] -= 1; a[2] -= 1;
    }
    cout << sum << endl;    
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t;
    while(t--)
		solve();

    return 0;
}

