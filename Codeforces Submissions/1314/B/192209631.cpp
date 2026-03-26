#ifdef MY_LOCAL
#include "D://competitive_programming/debug/debug.h"
#define debug(x) cerr << "[" << #x<< "]:"<<x<<"\n"
#else
#define debug(x) 
#endif
#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 1e18
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef double ld;
typedef tree<int,null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;cin>>n;
	int k;cin>>k;
	int tot = (1<<n);
	vi favs(tot, 0);
	REP(i, k) {
		int x;cin>>x;x--;
		favs[x] = 1;
	}
	// upper nohave/have, lower have/nohave
	vector<vvi> curbracket(tot/2, vvi(2, vi(2, -INF)));
	vvi curupper(tot/2, vi(2,-INF));
	vvi curlower(tot/2, vi(2,-INF));
	for (int i = 0; i < tot; i+=2) {
		int ct = favs[i] + favs[i+1];
		if (ct == 0) {
			curbracket[i/2][0][0] = 0; 
		}
		if (ct == 1) {
			curbracket[i/2][0][1] = 1; 
			curbracket[i/2][1][0] = 1; 
		}
		if (ct == 2) {
			curbracket[i/2][1][1] = 1;
		}
	}
	int cursz = curbracket.size();
	while (cursz > 1) {
		vector<vvi> newbracket(cursz/2, vvi(2, vi(2, -INF)));
		REP(i, cursz/2) {
			REP(topA, 2) {
				REP(botA, 2) {
					REP(topB, 2) {
						REP(botB, 2) {
							int vA = curbracket[i*2][topA][botA];
							int vB = curbracket[i*2+1][topB][botB];
							int good_games = (topA|topB) + (botA|botB);
							if (vA < 0 || vB < 0) continue;
							REP(Awintop, 2) {
								REP(Awinbot, 2) {
									int remaintop = (Awintop? topA: topB);
									int gobot = (Awintop? topB: topA);
									int havebot = (Awinbot? botA: botB);
									int additional_good = (gobot|havebot);
									REP(topwinbot, 2) {
										int winner = (topwinbot? gobot: havebot);
										newbracket[i][remaintop][winner] = max(newbracket[i][remaintop][winner], 
											additional_good + good_games + vA + vB);
									}

								}
							}
						}
					}
				}
			}
		} 
		cursz/=2;
		swap(newbracket, curbracket);
	}
	int gg1 = max(curbracket[0][1][1], max(curbracket[0][0][1], curbracket[0][1][0]))+1;
	int gg = max(curbracket[0][0][0], gg1);
	cout<<gg<<"\n";
}