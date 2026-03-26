#include <iostream>
using namespace std;

const int N = 2 * 100 * 1000 +10;

int n, q;
string s;
int dp_l[N], dp_r[N];

int r = 3127;
int mod1 = 1000 * 1000 * 1000 + 7;
int mod2 = 1000 * 1000 * 1000 + 9;
int h[3][N], pw[3][N], cnt[N];

pair<int, int> get_hash(int l, int r)
{
    pair<int, int> ret;
    ret.first =  ((long long)h[1][r] - ((long long)h[1][l-1] * pw[1][cnt[r] - cnt[l-1]]) % mod1 + mod1) % mod1;
    ret.second = ((long long)h[2][r] - ((long long)h[2][l-1] * pw[2][cnt[r] - cnt[l-1]]) % mod2 + mod2) % mod2;
    return ret;
}
pair<int, int> Make_hash(int L, int R)
{
    int L2, R2;
    int left, right;
    if(s[L-1] == '0')
        L2 = L, left = 0;
    else
    {
        L2 = dp_r[L] + 1;
        left = (L2 - L) % 2;
    }

    if(s[R-1] == '0')
        R2 = R, right = 0;
    else
    {
        R2 = dp_l[R] - 1;
        right = (R - R2) % 2;
    }

    if(L2 > R2)
    {
        pair<int, int> ret = {(R - L + 1) % 2, (R - L + 1) % 2};
        return ret;
    }

    pair<int, int> mid = get_hash(L2, R2);
    int cnt_mid = cnt[R2] - cnt[L2] + 1;
    pair<int, int> ret;

    if(left && right)
    {
        ret.first =  (((long long)left * pw[1][cnt_mid + 1]) % mod1 + ((long long)mid.first  * r) % mod1 + right) % mod1;
        ret.second = (((long long)left * pw[2][cnt_mid + 1]) % mod2 + ((long long)mid.second * r) % mod2 + right) % mod2;
    }
    else if(left || right)
    {
        if(left)
        {
            ret.first =  (((long long)left * pw[1][cnt_mid]) % mod1 + (long long)mid.first)  % mod1;
            ret.second = (((long long)left * pw[2][cnt_mid]) % mod2 + (long long)mid.second) % mod2;
        }
        else
        {
            ret.first =  (((long long)mid.first  * r) % mod1 + right) % mod1;
            ret.second = (((long long)mid.second * r) % mod2 + right) % mod2;
        }
    }
    else
        ret = mid;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>s;

    for(int i=1; i<=n; i++)
    {
        if(i == 1)
            dp_l[i] = i;
        else if(s[i-1] == '1' && s[i-2] == '1')
            dp_l[i] = dp_l[i-1];
        else
            dp_l[i] = i;
    }
    for(int i=n; i>=1; i--)
    {
        if(i == n)
            dp_r[i] = i;
        else if(s[i-1] == '1' && s[i] == '1')
            dp_r[i] = dp_r[i+1];
        else
            dp_r[i] = i;
    }

    pw[1][0] =  pw[2][0] = 1;
    h[1][0] = h[2][0] = cnt[0] = 0;
    for(int i=1; i<=n; i++)
    {
        pw[1][i] = ((long long)pw[1][i-1] * r) % mod1;
        pw[2][i] = ((long long)pw[2][i-1] * r) % mod2;

        if(s[i-1] == '0')
        {
            h[1][i] = ((long long)h[1][i-1] * r + 2) % mod1;
            h[2][i] = ((long long)h[2][i-1] * r + 2) % mod2;
            cnt[i] = cnt[i-1] + 1;
        }
        else
        {
            if(dp_r[i] == i)
            {
                int bit = (i - dp_l[i] + 1) % 2;
                if(bit)
                {
                    h[1][i] = ((long long)h[1][dp_l[i] - 1] * r + 1) % mod1;
                    h[2][i] = ((long long)h[2][dp_l[i] - 1] * r + 1) % mod2;
                    cnt[i] = cnt[dp_l[i] - 1] + 1;
                }
                else
                {
                    h[1][i] = h[1][dp_l[i] - 1];
                    h[2][i] = h[2][dp_l[i] - 1];
                    cnt[i] = cnt[dp_l[i] - 1];
                }
            }
        }
    }

    cin>>q;
    while(q--)
    {
        int l1, l2, len; cin>>l1>>l2>>len;
        int r1 = l1 + len - 1;
        int r2 = l2 + len - 1;
        pair<int, int> Hash1 = Make_hash(l1, r1);
        pair<int, int> Hash2 = Make_hash(l2, r2);
        if(Hash1 == Hash2)
            cout<<"Yes";
        else
            cout<<"No";
        if(q) cout<<'\n';
    }
    cout.flush();
    return 0;
}
