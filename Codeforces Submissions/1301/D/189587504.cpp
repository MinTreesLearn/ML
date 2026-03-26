#include<bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m, k; cin >> n >> m >> k;

    if(4*n*m - 2*n - 2*m < k) cout << "NO\n";
    else
    {
        cout << "YES\n";
        vector<string>moves;
        vector<pair<int,string>>finalMoves;

        for(int i = 0; i < n; i++)
        {
            if(i == 0)
            {
                for(int i = 0; i < m - 1; i++) moves.push_back("R");
                for(int i = 0; i < m - 1; i++) moves.push_back("L");
            }
            else
            {
                moves.push_back("D");
                for(int i = 0; i < m - 1; i++) moves.push_back("RUD");
                for(int i = 0; i < m - 1; i++) moves.push_back("L");
            }
        }
        for(int i = 0; i < n - 1; i++) moves.push_back("U");

        for(auto &i : moves)
        {
            if(k == 0) break;

            if(k >= i.size())
            {
                k -= i.size();
                if(finalMoves.size() && finalMoves.back().second == i)
                {
                    finalMoves[finalMoves.size() - 1].first++;
                }
                else
                {
                    finalMoves.push_back({1, i});
                }
            }
            else
            {
                finalMoves.push_back({1, string(i.begin(), i.begin() + k)});
                k = 0;
            }
        }

        cout << finalMoves.size() << "\n";
        for(auto &i : finalMoves) cout << i.first << " " << i.second << "\n";
    }
}