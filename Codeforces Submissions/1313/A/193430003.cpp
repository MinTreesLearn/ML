#include<bits/stdc++.h>
using namespace std;

#define str(t) ll t; cin>>t;while(t--)
#define ll long long int
#define vll vector<ll> 
#define g(n) ll n;cin>>n
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fin(i,a,b) for(int i=a;i<b;i++)
#define vsort(a) sort(a.begin(),a.end())
#define vrsort(a) sort(a.begin(),a.end(),greater< ll >())
#define mll map<ll,ll>
#define vin vector <int>
#define sll set <ll>
#define pb push_back
#define all(a) a.begin(),a.end()
#define get(a,n) vll a(n); f(i,0,n) cin>>a[i]
#define put(a) f(i,0,a.size()) cout<<a[i]<<' '; cout<<endl

int main() {
    std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    str(t) {
        vector<ll> a(3);
        for (auto& it : a) {
            cin >> it;
        }
        sort(a.begin(), a.end());

        if (a[0] == 0 && a[1] == 0 && a[2] == 0) cout << 0 << endl;
        else if (a[0] == 0 && a[1] == 0 && a[2] > 0) cout << 1 << endl;
        else if (a[0] == 0 && a[1] == 1 && a[2] > 0) cout << 2 << endl;
        else if (a[0] == 0 && a[1] >= 2 && a[2] >= 2) cout << 3 << endl;
        else if (a[0] == 1 && a[1] == 1 && a[2] >= 1) cout << 3 << endl;
        else if (a[0] == 1 && a[1] >= 2 && a[2] >= 2) cout << 4 << endl;
        else if (a[0] == 2 && a[1] == 2 && a[2] == 2) cout << 4 << endl;
        else if (a[0] == 2 && a[1] >= 2 && a[2] >= 2) cout << 5 << endl;
        else if (a[0] == 3 && a[1] >= 3 && a[2] >= 3) cout << 6 << endl;
        else cout << 7 << endl;
    }
    return 0;
}