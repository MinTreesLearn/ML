#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

#define x first
#define y second

using namespace std;
typedef pair<int, int> pii;
const int N = 1510;
unordered_map<int, vector<pii>> mp;
int n, s[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        int a;
        cin >> a;
        s[i] += s[i - 1] + a;
    }
    for (int i = 1; i <= n; i ++ )
        for (int j = i; j <= n; j ++ )
            mp[s[j] - s[i - 1]].push_back({i, j});
            
    int k = 0;
    vector<pii> res;
    for (auto& t : mp)
    {
        vector<pii> path, tmp = t.y;
        sort(tmp.begin(), tmp.end(), [&](pii& a, pii& b){
            return a.y < b.y;
        });
        int st = -2e9, ed = -2e9, cnt = 0;
        for (auto& range : tmp)
        {
            int l = range.x, r = range.y;
            if (ed < l) {
                if (ed != -2e9) path.push_back({st, ed});
                st = l;
                ed = r;
                cnt ++;
            }
        }
        path.push_back({st, ed});
        if (k < cnt)    k = cnt, res = path;
    }
    
    cout << k << endl;
    for (auto& t : res)
        cout << t.x << ' ' << t.y << endl;
    return 0;
}
