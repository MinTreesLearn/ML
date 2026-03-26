#include <bits/stdc++.h>
// يارب أطلع سبسوب
#define BeboDBale ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define e       "\n"
#define sin(a)  sin((a)*PI/180)
#define cos(a)  cos((a)*PI/180)
#define tan(a)  tan((a)*PI/180)
#define inf     1e18
#define pp      push_back
#define pf      push_front
#define ll      long long
#define ld      long double
#define vll     vector<ll>
#define pll     pair<ll,ll>
#define vint    vector<int>
#define vvll    vector<vll>
#define vpll    vector<pll>
#define vbool   vector<bool>
#define ull     unsigned long long
#define sz(x) (int)(x).size()
#define mkp make_pair
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ins insert
#define forn(i, n) for(long long i = 0; i<(n); i++)

#define no          cout << "NO\n"
#define yes         cout << "YES\n"

int dx[] = {+0, +0, -1, +1, +1, +1, -1, -1};
int dy[] = {-1, +1, +0, +0, +1, -1, +1, -1};

using namespace std;

unsigned long long power(int n, int pow) {
    unsigned long long ans = 1;
    for (int i = 0; i < pow; ++i) {
        ans *= n;
    }
    return ans;
}

set<long long> lucky_numbers;

void generate_lucky_number() {
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j < (1 << i); ++j) {
            string s;
            int cnt1 = 0, cnt2 = 0;
            for (int k = 0; k < i; ++k) {
                if ((1 << k) & j) {
                    s += "7";
                    cnt1++;
                } else {
                    s += "4";
                    cnt2++;
                }
            }
            if (!s.empty())lucky_numbers.insert(stoll(s));
        }
    }
}

// v.begin = 0 - v.end = n
const int BASE = 1000000007;
const long double PI = 3.14159265358979323846;
const int N = 1e5 + 5;


void solvingPeopleProblemsIgnoringMine() {
    int n;cin >> n;
    set<int>s;
    for (int i = 2; i <= sqrt(n); ++i) {
        if(n%i==0) {
            s.insert(i);
            s.insert(n/i);
        }
    }
    for(auto it:s){
        for (int i = 2; i <= sqrt(it); ++i) {
            set<int>a;
            a.insert(n/it);
            if(it%i==0){
                a.insert(i);
                a.insert(it/i);
            }
            if(a.size()==3){
                yes;
                for(auto x:a){cout<<x<<' ';}
                cout << e;
                return;
            }
        }
    }
    no;
}

int main() {
    BeboDBale
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--) {
        solvingPeopleProblemsIgnoringMine();
    }
}