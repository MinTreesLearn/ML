#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200001

int P = 7;
int M1 = 1000000009, M2 = 1000000007;

int Power(int x, int y, int M){
    int res = 1;
    while (y){
        if (y % 2){
            res *= x;
            res %= M;
        }
        x *= x;
        x %= M;
        y >>= 1;
    }
    return res;
}

int ModInv(int a, int M){
    return Power(a, M - 2, M);
}

class StringHash{
    public:
    int M;
    string s;
    int n;
    vector<int> pref;
    vector<int> b;
    vector<int> nb;
    vector<int> st;

    StringHash(int n, string s, int M){
        this->n = n;
        this->s = s;
        this->M = M;
        pref.assign(n, 0);
        b.assign(n, 0);
        nb.assign(n, 0);
        st.assign(n, 0);
        int pr = 1;
        int c = 0;
        for (int i = 0; i < n; i++){
            st[i] = ModInv(pr, M);
            if (s[i] == '0'){
                if (c % 2){
                    b[i] = 1;
                }
                pref[i] = (1 + b[i]) * pr;
                pr *= P;
                pr %= M;
                c = 0;
            }
            else c++;
            if (i) pref[i] += pref[i - 1];
            pref[i] %= M;
        }
        for (int i = n - 2; i >= 0; i--){
            if (s[i] != '0') b[i] = b[i + 1];
        }
        nb[n - 1] = (s[n - 1] == '0' ? 0 : 1);
        for (int i = n - 2; i >= 0; i--){
            nb[i] = (s[i] == '0' ? 0 : (nb[i + 1] ^ 1));
        }
        // for (int i = 0; i < n; i++) cout << pref[i] << ' ';
        // cout << endl;
        // for (int i = 0; i < n; i++) cout << b[i] << ' ';
        // cout << endl;
        // for (int i = 0; i < n; i++) cout << nb[i] << ' ';
        // cout << endl;
        
    }

    int hashval(int i, int l){
        int val = pref[i + l - 1] - (i == 0 ? 0 : pref[i - 1]);
        val %= M;
        val *= st[i];
        val -= b[i] + 1;
        val += nb[i] + 1;
        val %= M;
        val += M;
        val %= M;
        return val;
    }

};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    string s; cin >> s;
    int c1[n];
    c1[0] = (s[0] == '0');
    for (int i = 1; i < n; i++){
        c1[i] = c1[i - 1] + (s[i] == '0');
    }

    StringHash H1(n, s, M1);
    StringHash H2(n, s, M2);

    int q; cin >> q;
    for (int i = 0; i < q; i++){
        int l1, l2, len; cin >> l1 >> l2 >> len;
        l1--; l2--;
        if (c1[l1 + len - 1] - (l1 == 0 ? 0 : c1[l1 - 1]) == 0){
            cout << (c1[l2 + len - 1] - (l2 == 0 ? 0 : c1[l2 - 1]) == 0 ? "YES" : "NO") << endl;
        }
        else if (c1[l2 + len - 1] - (l2 == 0 ? 0 : c1[l2 - 1]) == 0){
            cout << "NO" << endl;
        }
        else{
            // cout << H1.hashval(l1, len) << ' ' << H1.hashval(l2, len) << ' ' << H2.hashval(l1, len) << ' ' << H2.hashval(l2, len) << endl;
            if (H1.hashval(l1, len) == H1.hashval(l2, len) && H2.hashval(l1, len) == H2.hashval(l2, len)){
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        }
    }
}