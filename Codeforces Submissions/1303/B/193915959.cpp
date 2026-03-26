/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include <bits/stdc++.h>
using namespace std ;
using i64 = long long;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << "->"; god(x); cerr << "\n";
#else 
#define debug(x)
#endif 
void god(i64 UWU) { cerr << UWU;}
void god(int UWU) { cerr << UWU;}
void god(string UWU) { cerr << UWU;}
void god(char UWU) { cerr << UWU;}
void god(double UWU) {cerr << UWU;}
void god(long double UWU) {cerr << UWU;}
template<class T> void god(vector<T> V) {cerr << "["; for(T I:V) {god(I); cerr << " ";} cerr << "]";}

void solve() {
	i64 N, G, B;
    cin >> N >> G >> B;
    i64 min_good_days = (N+1) / 2;
    i64 dx = min_good_days / G * (B + G);
    dx += ((min_good_days % G)?min_good_days%G:-B);
    cout << max(N, dx) << "\n";
    // i64 max_bad_days = N - min_good_days;
    // debug(min_good_days);
    // if(N <= G) {
    //     cout << N << "\n";
    //     return;
    // }
    // i64 dx = ((min_good_days + G - 1) / G); 
    // i64 curr_dx = dx * G;
    // i64 extra_dx = curr_dx - min_good_days;
    // i64 dy = (dx - 1) * B;
    // debug(dx); debug(curr_dx); debug(extra_dx); debug(dy);
    // i64 fill = 0;
    // if(extra_dx + dy < max_bad_days) {
    //     fill += (max_bad_days - (extra_dx + dy) + G + B - 1) / (G + B);
    // }
   
    // cout << max(N, curr_dx + dy + fill) << "\n";
}
int main() {

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
    	solve();
    }
    
    return 0;
}