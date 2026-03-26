#include <bits/stdc++.h>
//#include <atcoder/all>
#define f first
#define s second


# define  FAST()    ios_base::sync_with_stdio(false); cin.tie(NULL);
#define IN()  freopen("collectingofficer.in", "r", stdin);
#define OUT() freopen("output.txt", "w", stdout) ;
/*
                                  وَمَا تَوْفِيقِي إِلَّا بِاللَّهِ
*/
using namespace std;
using ll = long long ;
using ld = long double ;
const int N = 2e5+7 , M = 998244353;
const double  ES = 1e-6;
using vi = deque<int>;
template<class T> using min_heap = priority_queue<T, std::vector<T>, std::greater<T>>;


int dx[] = {0, 0, 1, -1, 1, -1, 1, -1}, dx4[] = {1, 0 , 0 , -1};
int dy[] = {1, -1, 0, 0, 1, -1, -1, 1}, dy4[] = {0, 1, -1 ,0 };


/*Remind pleaseeeee
 * can brute force ? can brute force for specific size ? pleasee ?
 * sum or mult over flow????????
 *
 *
 */

void solve() {
vector<vi>a(27),b(27);
string in;
int n;
cin>>n>>in;
vector<pair<int,int>>res;
    for (int i = 0; i <in.size() ; ++i) {
        if(in[i]=='?')a[26].push_back(i+1);
        else a[in[i]-'a'].push_back(i+1);
    }
    cin>>in;
    for (int i = 0; i <in.size() ; ++i) {
        if(in[i]=='?')b[26].push_back(i+1);
        else b[in[i]-'a'].push_back(i+1);
    }

    for (int i = 0; i <=26 ; ++i) {
        while (!a[i].empty() and !b[i].empty()){
            res.emplace_back(a[i].front(),b[i].front());
            a[i].pop_front();
            b[i].pop_front();
        }
        while (!a[i].empty() and !b[26].empty()){
            res.emplace_back(a[i].front(),b[26].front());
            a[i].pop_front();
            b[26].pop_front();
        }
        while (!a[26].empty() and !b[i].empty()){
            res.emplace_back(a[26].front(),b[i].front());
            b[i].pop_front();
            a[26].pop_front();
        }
    }

    cout<<res.size()<<"\n";
    for (int i = 0; i <res.size() ; ++i) {
        cout<<res[i].f<<" "<<res[i].s<<"\n";
    }
}

int main(){
//    IN();
//    FAST()
    int t=1;
//    cin>>t;
    while (t--){
        solve();
       // cout<<"\n";
    }


    return 0;
}
