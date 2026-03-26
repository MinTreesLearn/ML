#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    cin >> n;

    int l, r;

    switch(n%4)
    {
        case 0:
            l = n/2+1;
            r = n/2-1;
        break;

        case 1:
            l = n/2+1;
            r = n/2;
        break;

        case 2:
            l = n/2+2;
            r = n/2-2;
        break;

        case 3:
            l = n/2;
            r = n/2+1;
    }

    if(n==2)
    {
        l = 1;
        r = 1;
    }

    vector<vector<int>> L(l+1, vector<int>(26, 0)), R(r+1, vector<int>(26, 0)), N(n+1, vector<int>(26, 0));
    vector<string> left, right, all;

    if(l>1)
    {
        cout << "? 1 " << l << "\n";
        cout.flush();

        string x;
        for(int i=0; i<l*(l+1)/2; i++)
        {
            cin >> x;
            for(char c: x)
            {
                L[x.size()][c-97]++;
            }
        }

        vector<int> prev(26, 0);

        for(int s=1; s<=(l+1)/2; s++)
        {
            string S;
            vector<int> temp(26, 0);

            for(int i=0; i<26; i++)
            {
                temp[i] += L[1][i] + L[s][i] - L[s+1][i] - prev[i];
                prev[i] += temp[i];
                while(temp[i]-->0) S += (char) 97+i;
            }

            //cout << "! " << S << "\n";
            left.pb(S);
        }
    }
    else if(l==1)
    {
        cout << "? 1 " << l << "\n";
        cout.flush();

        string x;
        cin >> x;
        left.pb(x+x);
    }

    if(r>1)
    {
        cout << "? " << l + 1 << " " << n << "\n";
        cout.flush();

        string x;
        for(int i=0; i<r*(r+1)/2; i++)
        {
            cin >> x;
            for(char c: x)
            {
                R[x.size()][c-97]++;
            }
        }

        vector<int> prev(26, 0);

        for(int s=1; s<=(r+1)/2; s++)
        {
            string S;
            vector<int> temp(26, 0);

            for(int i=0; i<26; i++)
            {
                temp[i] += R[1][i] + R[s][i] - R[s+1][i] - prev[i];
                prev[i] += temp[i];
                while(temp[i]-->0) S += (char) 97+i;
            }

            //cout << "! " << S << "\n";
            right.pb(S);
        }
    }
    else if(r==1)
    {
        cout << "? " << l + 1 << " " << n << "\n";
        cout.flush();

        string x;
        cin >> x;
        right.pb(x+x);
    }

    if(n>1)
    {
        cout << "? 1 " << n << "\n";
        cout.flush();

        string x;
        for(int i=0; i<n*(n+1)/2; i++)
        {
            cin >> x;
            for(char c: x)
            {
                N[x.size()][c-97]++;
            }
        }

        vector<int> prev(26, 0);

        for(int s=1; s<=(n+1)/2; s++)
        {
            string S;
            vector<int> temp(26, 0);

            for(int i=0; i<26; i++)
            {
                temp[i] += N[1][i] + N[s][i] - N[s+1][i] - prev[i];
                prev[i] += temp[i];
                while(temp[i]-->0) S += (char) 97+i;
            }

            //cout << "! " << S << "\n";
            all.pb(S);
        }
    }
    else if(n==1)
    {
        cout << "? 1 " << n << "\n";
        cout.flush();

        string x;
        cin >> x;
        all.pb(x+x);
    }

    int now = (l+1)/2;
    string ans(n, ' ');
    ans[now-1] = left[now-1][0];

    for(int i=0; i<n; i++)
    {
        //cout << now << " " << ans[now-1] << "\n";
        if(i%2==0)
        {
            now = n + 1 - now;
            if(all[min(now, n+1-now)-1][0]==ans[n-now]) ans[now-1] = all[min(now, n+1-now)-1][1];
            else ans[now-1] = all[min(now, n+1-now)-1][0];
        }
        else if(now<=l)
        {
            now = l + 1 - now;
            if(left[min(now, l+1-now)-1][0]==ans[l-now]) ans[now-1] = left[min(now, l+1-now)-1][1];
            else ans[now-1] = left[min(now, l+1-now)-1][0];
        }
        else
        {
            now = n + l + 1 - now;
            if(right[min(now, n+l+1-now)-l-1][0]==ans[n+l-now]) ans[now-1] = right[min(now, n+l+1-now)-l-1][1];
            else ans[now-1] = right[min(now, n+l+1-now)-l-1][0];
        }
    }

    cout << "! " << ans << "\n";
    cout.flush();
}
/*
5
a
as
ask
s
sk
k
b
y
by
askby
askb
skby
ask
skb
kby
as
sk
kb
by
a
s
y
k
b
*/
