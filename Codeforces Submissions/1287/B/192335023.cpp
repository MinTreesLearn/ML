#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<string> vec(n);
    unordered_map<string, int> mpp;
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        mpp[vec[i]]++;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            string s = "";
            for (int z = 0; z < k; z++)
            {
                if (vec[i][z] == vec[j][z])
                    s += vec[i][z];
                else
                {
                    if (vec[i][z] == 'S' && vec[j][z] == 'E' || vec[i][z] == 'E' && vec[j][z] == 'S')
                        s += 'T';
                    if (vec[i][z] == 'S' && vec[j][z] == 'T' || vec[i][z] == 'T' && vec[j][z] == 'S')
                        s += 'E';
                    if (vec[i][z] == 'T' && vec[j][z] == 'E' || vec[i][z] == 'E' && vec[j][z] == 'T')
                        s += 'S';
                }
            }
            /* debug(s); */
            if (mpp[s])
            {
                count++;
            }
            mpp[vec[j]]--;
        }
        for (int t = i + 1; t < n; t++)
            mpp[vec[t]]++;
        mpp[vec[i]]--;
    }
    cout << count;
}
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int t = 1;
    /*   cin >> t; */
    while (t--)
    {
        solve();
    }
 
    return 0;
}