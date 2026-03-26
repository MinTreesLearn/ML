#include <bits/stdc++.h>

using namespace std;

#define improvePerformance ios_base::sync_with_stdio(false); cin.tie(0)
#define getTest int t; cin >> t
#define eachTest for (int _var=0;_var<t;_var++)
#define get(name) int (name); cin >> (name)
#define getList(cnt, name) vector<int> (name); for (int _=0;_<(cnt);_++) { get(a); (name).push_back(a); }
#define out(o) cout << (o)

#define int long long int

signed main() {
    improvePerformance;
    
    
        get(n);

        map<int, vector<int>> lists;
        vector<int> beginners;


        for (int _=0;_<n;_++) {
            get(m);
            getList(m, cur);

            bool downsorted = true;

            for (int i = 0; i < m - 1; i++) {
                if (cur[i] < cur[i + 1]) {
                    downsorted = false;
                    break;
                }
            }

            if (lists.find(cur[0]) == lists.end()) {
                if (downsorted) {
                    lists[cur[0]]={(cur[cur.size() - 1])};
                }
            } else {
                if (downsorted) {
                    lists[cur[0]].push_back(cur[cur.size() - 1]);
                }
            }
        }

        for (map<int, vector<int>>::iterator it = lists.begin(); it != lists.end(); it++) {
            beginners.push_back(it->first);
        }

        sort(beginners.begin(), beginners.end());

        vector<int> prefixSums;

        prefixSums.push_back(0ll);

        int invalidPairs = 0ll;

        for (int beginner: beginners) {
            prefixSums.push_back(prefixSums[prefixSums.size() - 1] + lists[beginner].size());

            for (int val: lists[beginner]) {
                int lowerBound = 0ll;
                int upperBound = prefixSums.size() - 1ll;

                while (upperBound - lowerBound > 1) {
                    int middle = (lowerBound + upperBound) / 2;
                    if (beginners[middle - 1] <= val) {
                        lowerBound = middle;
                    } else {
                        upperBound = middle;
                    }
                }

                invalidPairs += prefixSums[lowerBound];
                if (val == beginner) invalidPairs += lists[beginner].size();
            }
        }

        out(n * n - invalidPairs);
}