// CF template, version 3.0

#include <bits/stdc++.h>

using namespace std;

#define improvePerformance ios_base::sync_with_stdio(false); cin.tie(0)
#define getTest int t; cin >> t
#define eachTest for (int _var=0;_var<t;_var++)
#define get(name) int (name); cin >> (name)
#define out(o) cout << (o)
#define getList(cnt, name) vector<int> (name); for (int _=0;_<(cnt);_++) { get(a); (name).push_back(a); }
#define sortl(name) sort((name).begin(), (name).end())
#define rev(name) reverse((name).begin(), (name).end())
#define forto(name, var) for (int (var) = 0; (var) < (name); (var)++)
#define decision(b) if (b){out("YES");}else{out("NO");}

#define int long long int

int gcd(int a, int b) {
    if (a == b) return a;
    return gcd(max(a, b), max(a, b) % min(a, b));
}

/*
Segtree:
void build(vector<int> &tree, vector<int> &array, int i, int l, int r) {
    if (l == r) {
        tree[i] = array[l];
    } else {
        int middle = (l + r) / 2;
        build(tree, array, i * 2, l, middle);
        build(tree, array, i * 2 + 1, middle + 1, r);

        tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
    }
}

void set_(vector<int> &tree, int v, int l, int r, int i, int x) {
    if (l == r) {
        tree[v] = x;
    } else {
        int middle = (l + r) / 2;
        if (i <= middle) {
            set_(tree, v * 2, l, middle, i, x);
        } else {
            set_(tree, v * 2 + 1, middle + 1, r, i, x);
        }
        tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
    }
}

int query(vector<int> &tree, int v, int cl, int cr, int l, int r) {
    if (l == cl && r == cr) {
        return tree[v];
    }
    if (l > r) return 0;
    int middle = (cl + cr) / 2;
    return max(
        query(tree, v * 2, cl, middle, l, min(r, middle)),
        query(tree, v * 2 + 1, middle + 1, cr, max(l, middle + 1), r)
    );
}

vector<int> tree(4 * n);
build(tree, initial, 1, 0, n-1); // replace initial with name of array
set_(tree, 1, 0, n-1, a, b);
query(tree, 1, 0, n-1, a, b); // this returns an int
data structure can be changed
*/

signed main() {
    improvePerformance;
    getTest;
    
    eachTest {
        get(n);
        getList(n, nums);
        vector<int> adjs;
        int maxdiff = 0;
        forto(n, i) {
            int cur = nums[i];
            if (i != n - 1 && cur != -1 && nums[i + 1] != -1) maxdiff = max(maxdiff, abs(nums[i + 1] - cur));
            if (((i && nums[i - 1] == - 1) || (i != n - 1 && nums[i + 1] == -1)) && cur != -1) adjs.push_back(cur);
        }

        sortl(adjs);

        if (adjs.size() > 1) {

            int middle = (adjs[adjs.size() - 1] + adjs[0]) / 2;
            int ans = max(maxdiff, max(adjs[adjs.size() - 1] - middle, middle - adjs[0]));

            out(ans);
            out(" ");
            out(middle);
        } else if (adjs.size() == 0) {
            out(maxdiff);
            out(" ");
            out(0);
        } else {
            out(maxdiff);
            out(" ");
            out(adjs[0]);
        }

        out("\n");
    }
}