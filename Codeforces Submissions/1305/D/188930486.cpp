//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,abm,mmx,popcnt")
#define _CRT_SECURE_NO_WARNINGS
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,abm,mmx,avx,avx2,popcnt,tune=native")
//#pragma comment(linker,"/STACK:256777216")
/*
MMMMMMMMNNNNNNNNNNNNNNNNNNmNNNNNNNNNNNmmmmmmmmNNMMMMNMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMMMMMMMMMMMMMMMMNNMMMNMMMMMMMMMMMMMMMMMMMMMMNNMMNNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMNNNNNNNNNNNmNNNMMMMMMMMMMMMNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMNNNNNNNNNNNNNNNNmmNNNNNNNNMMMMMMMMNmNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMNNNNNMMNNNNNNNNNNNNNNNNNNNNNMMMMMMMMNmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMNNNNNMMNNNNNNmNNNNNNNMMMMMMMMMMMMMMMMNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMNNNNNNNNNNNNNmNNNNNNNNNNMMMMMMMMMMMMMMmMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMNNNNNNNNNNNNNmNNNmNMMMMmMMMMMMMMMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMNNNNNNNNNNmmmmmNNNNMMNMMNNMMMMMMMMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
NNNNNNNNNNNmmmmdddddmNNNNMNNMMNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMNNMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
NNNNNNNNNmmmddddhhhdNNNmmMMMMNmmNNNNNNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMNMMMMMMMMMNMMMMMMMMMMMMMMMNMMNMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
NNNNNNNNmmddddhhhhhdmNNmNmNNNNNNNNNNNNNNNNNNMMMMMMMMMMMMMMMMMMMMNMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMMMMNMMMMMMMMMMMMMMMNMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMM
NNNNNNNmmddddhhhhhhhdNNmNNNNNNNNmmNNNNNNNNNNMMMMMMMMMMMMNMMNMMMMNMMMMMNMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMMMMNMMMMMMMMMMMMMMNMNMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMM
NNNNNNNmddhhhhhhhyyyhmmNmmmNNMMMMNmNNNNNNNNNMMMMMMMMMMMNMMMNMMMMNMMMMNNMMMMNMMMNMMMMMMMMMMMMMMMMNMMNMMMMMMMMMMMMMMMMMMMNMMMMMMMMMMMMMMMNNMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMM
NNNNNNmdhhhhhhyyysssshmdmNMMNNNNNNNmmmmmmmmMMMMMMMMMMMMNMMMNMMMMMMMMMNNMMMMNMMMNMMMMMMMMMMMMMMMMNMMNMMMNMMMNMMMNMMMMMMMMNMMMMMMMMMMMMMMNMMMMMMNNNNNNNNNMMNNNNNNNNNNNNNNNMM
MNNNNmdhyyyyyyysssssssdNNNNNNNNNNNNNNNNNNNmMMMMMMMMMMMMNMMMNMMMNMMMMMNNMMMMNMMMMMMMMMMMMMMMMMMMMNMMNMMMNMMMNMMMMNMMMMMMMNNNNMMMMMMMMMMMNMMMMMMMmmmmmNNNNmmmmmmmmmmmmmmmNNN
MMNNmmdhsoooooooooooooohmNNNNNNNNNNNNNNNdNNMMMMMMMMMMMMNMMMNMMMNNMMMMNMNMMMNMMMMNMMMMMMMMMMMMMMMNMMNMMMNMMMNMMMMMNMMMMMMNNNMNNNMMMMMMMNmMMMMMMMmdddmmmdddddddddddddddddmmN
MNNmmmdhsooooooooooo++ooshmNNNNNNNNNNmhysNNMMMMMMMMMMMNNMMMNMMMNNMMMMNMNMMMNMMMMNMMMMMMMMMMMMMMNMMNMMMNMMMMNNNMMMNMMMMMMNNNMMMMNNMMNNNMdMMMMNMMNmddddddddddddhhhhhhhhddmmN
NmmddddhhhhhhhhhhhhyyyyyyyyhdddmmdddhsoosdNMMMMMMMMMMMNNMMMNMMMNNMMNNmNNMMMNNMMMNMMMMMMMMMMMMMMNMMNMMMNMNNmNMMMMMMNMMMMMMNNNMMmNNNNMMMMmNMMMNNMNmNNNNNNNNNNNmmmmmmmmmNNNMM
mmdddddddddddddddddddhhyyyyyyyhhhyyyoooosdNMMMMMMMMMMMNNMMMNMMMNNMMMMNMNmNNMNMMMNMMMMMMMMMMMMMNNMNNMMNNNNNNMMMMMMMMNMMMMMNMMNMMmNNMmmMmNNMMMMNMMNNNNNNNNNNNNNNNNNNNNNNMMMM
mmddddhdddddddddddddddhhhyyyhhhysssoooosshNMMMMMMMMMMMNNMMMNMMMNNMMMMNMMNMMNNmNNNmMMMMMMMMMMMMNMNmNNNNMMMNMMMMMMMMMMNMMMMNMMMNNMMMMNMNNMNMMMMNNMNNNNNNNNNNNNmmmNNNNNNMMMMM
dddddhhhdddddddddddddddhhhhhhysosyoooosmsyNMMMMMMMMMMMNNMMMNMMMMNNMMMdMNNNMMMNNMMmNMMMMMMMMMMNMMNNMMNMMMNNNMNMMMMMMMMNMMMNMMNNNNNMMMmNMMNMMMMMNNNNNNNNNNNNNNmmNNNNNNMMMMMM
dddddhhhddddddddddddddddhhhsoosyhooooodNssNMMMMMMMMMMMNNNMMNNMNmdhhysshmNNNNNMNNMNmMMMMMMMMMNNMNNMMNNNNmNNNmyhddmmNMMMNMMNMNmMNdNMMmNmNMNMMMMMNmMmNNNNNNMMNNNNNNNMMMMMMMMM
dddddhhhddddddddddddddddysoooyhho++o+sNmosNMMMMMMMMMMMNNNMNdyhhhho////oyssydmmMNNMNNMMMMMMMMNMMNMMMNNNmdhyso++oosssyddNNNNMmMMNMNmNNmMmNmMMMMMMmmNmNNNNNNNNNNNNMMMMMMMMMMM
hdddhhhhhhhddddddddddddsoooyhhho++ssodNmosMMMMMMMMMMMMmNmhddmNMNNy/////+mmy/hNMMMMMMMMMMMMMMMMMMMMMMNmsohdo:::::+mNNdhhmNNNNMMNmNNmNMMNmmMMMMMMNdNmmNNNNNNNNNNMMMMMMMMMMMM
hhhhhyyyhhhhhdddddddddh++shhhho++shooNMdoyMMMMMMMMMMMMmMNdMMMMN+yy+sss++oMMdsmMMMMMMMMMMMMMMMMMMMMMMmyhNhmh+oo++:+MMMMNdNmmNNNNNMMNNmNMdmNMMMMMMNdNmNNNNNNNNMMMMMMMMMMMMMM
hhhhhyyyyhhhhhddddddddy++hhhhs+/+ys+hNNyoyNMMMMMMMMMMMNMMNNMMMh-oshdddyy+NMMNhMMMMMMMMMMMMMMMMMMMMMMdNMM+/yyddhss:NMMMMNMmNMMMMMMMMMNmmdNNNMMMMMNmmNmmNNNMMMMMMMMMMMMMMMMM
hhhhyyyyyyyhhhhddddddhs++hhhy+/:+o+smNNoodMMMMMMMMMMMMNMMMmMMMh-yydhddhhoNMMMNMMMMMMMMMMMMMMMMMMMMMMMMMM/oyddddydoNMMMmNMNMMMMMMMMMMMNNmNNNNNNNNNNdmmmNNNMMMMMMMMMMMMMMMMM
hhhhyyyyyyyhhhhddddddhs++yyo+++///ohNNs+dmNNNNNNNMMMMNNMMMNmMMN/+dhdmmhmhMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMs+hhddhdmmMMMNNMMNNNNNNNNNNNNNNNNNNNNNNNNNmmNmNNMMMMMMMMMMMMMMMMMM
hhhyyyyyyyyhhhhhhhhdhhy//o+/+s////yhNy+yNmNNNNNNNNNNNNNMMMMNNMMNoodNNNdsmMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNohNNNmdyNMMNNMMMNNNNNNNNNNNNNNNNNNNNNNNNNmmmNmMMMMMMMMMMMMMMMMMMM
hhhyyyyyyyyyhhhhhhhhhhh+//+sho/::/hhs+yNNmNNNNNNNNNNNNNMMMMMNNNNNmhdmddMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmdmmmmNNNNNNNNNmNNNNNNNNNNNNNNNNNNNNNNNNNmNmmNMMMMMMMMMMMMMMMMMM
hhhyyyyyhyyhhhhhhhhhhhhhhhhhh+/://+/+hNNNmNNNNNNNNNNNNNNNNNNNNNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNmNNNNNNNNNNNNNNNmNNNNNNNNNmNNmmMMMMMMMMMMMMMMNMMM
hhyyyyyyhhhhhhhhhhhhhhhhhhhho:/os//smNNNNmNNNNNNNNNNNNmNNNNNNNNNNNNNNNMMMMMMMMMMMMMMMMMNNMMMMMMMMMMMMMMMMMMMNNNNNNNNNNMNNmNNNNNNNNNNNNNNNmNNNNNNNNNNmNmmmMMMMMMMMMMNNMMMMM
hyyyyyyyhhhhhhhhhhhhhhhhhhho://hhyyNNNNNNmNNNNNNNNNNNNmNNNNNNNNNNNNNNNMMMMMMMMMMMMMMMMMNmMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNdNNNNNNNNNNNNNNNmNNNNNNNNNNmMMmmNMMMMMMMMNNNMMMMM
yyyyyyyhhhhhhhhhhhhhhhhhhho/:/+hhhhNNNNNmmNNNNNNNNNNNNmNNNNNNNNNNNNNNNMMMMMMMMMMMMMMMMMMNMMMMMMMMMMMMMMMMMMNNNNNNNNNNNmmmdNNNNNNNNNNNNNNmmNNNNNNNNNNmNMMmmNMMMMMMMMMMMMMMM
yysyyyyhhhhhhhhhhhhhhhhhho::::ohhhdNNNNNmmNNNNNNNNNNNNmNNNNNNNNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNmdNNNNNNNNNNNNNNmmNNmNNNNNNNNmMMNmmNMMMMMMMMMMMMMM
yssyyyyhhyyyyyhhhhhhhhhyo:/o::shhhdNNNNmNmNNNNNNNNNNNNyNNNNNNNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNmsNNNNNNNNNNNNNNmmNNmNNNNNNNNmNNNmmmNNMMMMMMMMMMMN
ssssssyyysssyyyyyyyyyyy+:/so::syyymNNNmmNdNNNNNNNNNNNNhdNNNNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNhsNNNNNNNNNNNNNNmNNNdNNNNNNNNmddddhmdNNNNNMNNNNNNN
oo++++oooooossssssssso/:/os/::+oosNNNNdNNdNNNNNNNNNNNNhymNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNmyyNNNNNNNNNNNNNNmNNNdNNNNNNNNmyyyhhhmdmmmNNmmmmddd
++////++oosssssssssso::/sss:::+++yNNNdNNNdNNNNNNNNNNNNhhyNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNyyyNNNNNNNNNNNNNNdNNNmmmmmmmmmmhdhddddmdddddddhhhhh
////////+ossyysysss+::/ssss::+ssshmNmmNNNdNNNNNNNNNNNNhhhhNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNhhhymNNNNNNNNNNNmmdmmmmdmmmmmmmmdddddmddhddhhhhhhhhh
//:::--:/+ssyyyyys/--+ssssy:-+sssmmmdmmNmdNNNNNNNNNNNNyyhyyNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNhyhhymNNNmmmmmmmmmmymmmmdmmmmmmmmdhhddddhdyhhhhhhhhhh
///::---/+osssyys/--+ssyysy--+sssmmdmmmmmdmmmmmNmNNNmmhssyyymNNNNNNNNNNNNNNNNNNNNNmmmNmmNNmmmmmNNNNNNNNNNNNNNNNNNNNNhssyssmmmmmmmmmmmmmmydmmmhmmmmmmmmdhdddddhhdyyyyhhhhhh
///::--:/+osssss:-:osssssys--+ssymdmmmmdmhmmmmmmmmmmmmhyyyyyohmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNdyssssssmmmmmmmmmmmmmmshmmmhmmmmmmmddhddddhhyhhyyyyhhhhh
///::--:/osssso--:ssssssyys--+ssyddmmmdmmhmmmmmmmmmmmmhsssssosshmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNdyssssssssmmmmmmmmmmmmmmsymmmhdddddddddyddhhhhhhhyyyyhhhhh
///::--:/osss+--:sssssssyss--+soydmmmhmmmhmmmmmmmmmmmmhsssssossssydNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmhsssssosssssmmmmmmmmmmmmddosdddhdddddddddyhhhhhhyyyhsyyhhhhh
////:--:+oss/--/sssssssyyss--+sohdddhddddddmmmmmmmmmmmysssssosssssoshNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNdyosossssosssssddmddddddddddhoodddhhddddddddydhhhyyyyyysyyhhhhh
////:::/+os/../ssssssssysss--/osddddhdddddhdddddddddmdyssssoosssssoossydNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmysosssoossooooooodddddddddddddsoohdddyddddddhhyhhhhhyyyhsyshddddd
////:::/+o/../sssssssssssss--:sddddyddddddhdddddddddddyooooooooooooooo+syhmmmmmmmmmmmmmmmmmmmmmmmmmmmmhyy+oooooooooo+ooooodddddddddddddooohddhshhhhhhhhhyhhhhhhhhhssdmmmmm
++//:::/+/../sssssssssyssss--:hhddyhhdddddydddddddddddyoooooooooooo+oo+yyysydmmmmmmmmmmmmmmmmmmmmmmdyyyys+oooooo+ooo+oooosdddddddddddhhoo+yhhhshhhhhhhhhshhhhhyyyysyyddddd
++//::://../ssyyyyyysyyssss:.-hhhhyyhhdddyyhddddddddddyoooo+ooooooo+oo+sssysssyhdmmmmmmmmmmmmmmdhysssssso+oooooo+ooo+ooooshdddhhhhhhhhy+++yhhyohhhhhhhhhsyyyyysssysosyyhhh
+++/:://..:ssyyyyyyyyyyyyss/.-hhhsyyhhhhhyhyhhhhhhhddhyoooo+ooooooyhhyosssssssssssyhdmmmmmmdhyssssssssssoooo+ooo+o+++++++shhhhhhhhhhhhs+++shhsshhhhyyyyyossssssssyyosoyyhh
+++////..-ossyyyyyyyhyyyyyy+..shyyshhhhhhyhshhhhhhhhhhy++++++++ooddddddhssssssssssssssyhhysssssssssssoyhdddhyo++/++++++++shhhhhhhhhhhy++++syysoyyyyyyyyyosssssssssysooyyhh
+++///-..+ossyyyyyyyhhhhyyss..oyssyhhhhhhyhshhhhhhhhhhy++++/++++++/:/oyddyossssssssssssossssssssssssoydho+++sy++/++/+++++yhhhhhhhhhyys/+//syyooyyyyyyyyyosssssssssysossyhh
+++//-../ooossyyyyyyyhyyysyy-.:oysyyyyyyyyysyhhhhhhhhhy++++/++++--+oo/-+hdyssyyyyssoooooooooooossssshds--///::://++/++++/yyyyyyyyyyyy+////oyyooyyyyyyyysosssssssssyysooyyh
++++/...+ooossyyyyyyyyyyssyy/..ooyyyyyyysyyysyyyyyyyyyy+++//++++:yhddhs-:yhhhhhhhddhooooooooyhhhhhhhho-+hhhhhy://///////+yyyyyyyyyyys/////oyssoyssssssss+ssssssssssyy+osyy
////.``/+++ossyyyyyyyyyyosss+..+oyyyyyyyoyyysyyyyyyyyyy//////////yhhhhhy--:---:://shh+oooo+yhhs/:::::-+hhhhhh+//////////+yyyyyyyyyyyo/////osoyosssssssss+ssssssssyyyyoooyy
/::-``-///++oossssssyyyosssso..-ssssyyyyoyyyssyyyyyyyyy//////////ohhhhhhyssoooo+:..+hy+oo+yhy:.:oyhhyshhhhhyo://////////+yyyyyyyysss/////:osohosssssssss+yyyyyyyyyhhhhoohh
:::.``::://+++o++o++oo+osssss-.-ssssssssossssossssyyyyy+o+////////hhhhhhhhhhhhhhhs-.sy++++hs-.ohhhhhhhhhhyo+/:/:/://////osssssssssso::::::ssshossssssooooyyyyyyhhhhdmmo+hh
//:--:////+++oo+++///++osssss:.-ooosssssossssosssosssysossyyssossossyyyyyyyyyyyyyyo-/so+/ss:-oyyyyysyyyyy++/-:::////++o+osossssssss///////ooos+ooooooooo+syyyyyyyyyyddo+yh
*/


#include <set>
#include <map>
#include <deque>
#include <string>
#include <cstdint>
#include <cmath>
#include <queue>
#include <cassert>
#include <random>
#include <bitset>
#include <iomanip>
#include <cstring>
#include <numeric>
#include <time.h>//////////////
#include <ctime>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <complex>
#include <chrono>
#include <unordered_set>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define pbc push_back
#define pob pop_back()
#define vin(a) for (auto& i : a) cin >> i
#define sp system("pause")
#define mp make_pair
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2>
inline void chkmin(T1& x, const T2& y)
{
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y)
{
    if (x < y) x = y;
}
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
ld asdasdcl = 0;
double getTime() { return (clock() - asdasdcl) / (double)CLOCKS_PER_SEC; }
pair<int, int> operator-(pair<int, int> a, pair<int, int> b)
{
    return { a.first - b.first, a.second - b.second };
}
pair<int, int> operator+(pair<int, int> a, pair<int, int> b)
{
    return { a.first + b.first, a.second + b.second };
}
/*
#define getchar_unlocked _getchar_nolock
inline int readInt()
{
    char x;
    while (x = getchar_unlocked())
    {
        if (x >= '0' && x <= '9')
        {
            int ans = x - '0';
            while (x = getchar_unlocked())

            {
                if (!(x >= '0' && x <= '9')) return ans;
                ans = ans * 10 + x - '0';
            }
        }
    }
}*/
/*using namespace __gnu_pbds;

using ordered_set = tree<
    pair<int, int>,
    null_type,
    less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update>;*/
const int inf = 1e9 + 228;
const ld EPS = 1e-12;
const ld PI = acos(-1.0);
const ld INF = 1e18;
int ask(int a, int b)
{
    cout << "? " << a << ' ' << b << endl;
    int x;
    cin >> x;
    return x;
}
signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int n;
    cin >> n;
    vector<set<int>> g(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    set<int> lft;
    int sz = n;
    for (int i = 1; i <= n; ++i) lft.insert(i);
    while (sz > 1)
    {
        if (sz == 2)
        {
            int y = ask(*lft.begin(), *lft.rbegin());
            cout << "! " << y << endl;
            return 0;
        }
        else
        {
            bool fnd = 0;
            for (int i : lft)
            {
                if (g[i].size() == 1)
                {
                    int u = *g[i].begin();
                    int lv = -1;
                    for (int x : g[u])
                    {
                        if (g[x].size() == 1 && x!= i)
                        {
                            lv = x;
                            break;
                        }
                    }
                    if (lv != -1)
                    {
                        int val = ask(i, lv);
                        if (val == i || val == lv)
                        {
                            cout << "! " << val << endl;
                            return 0;
                        }
                        g[lv].erase(u);
                        g[u].erase(lv);
                        g[i].erase(u);
                        lft.erase(i);
                        lft.erase(lv);
                        g[u].erase(i);
                        fnd = 1;
                        break;
                    }
                    else
                    {
                        if (g[u].size() == 2)
                        {
                            g[u].erase(i);
                            int lv = *g[u].begin();
                            int y = ask(lv, i);
                            if (y == u || y == i)
                            {
                                cout << "! " << y << endl;
                                return 0;
                            }
                            g[u].erase(lv);
                            g[lv].erase(u);
                            g[i].erase(u);
                            lft.erase(i);
                            lft.erase(u);
                            fnd = 1;
                            break;
                        }
                    }
                }
                
            }
            sz -= 2;
        }
    }
    cout << "! " << *lft.begin() << endl;
    //sp;
}
//stop investigating combinatoric problems
//tle/mle - think?? wrong asympthotics??
//don't distract
//look at different ideas, don't get stuck