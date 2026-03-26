#include <bits/stdc++.h>
using namespace std;

using int32 = int32_t;
using int64 = int64_t;

const int64 INF = 1'000'000'000LL * 1'000'000'000;

int32 getPopCount(int32 mask)
{
    return popcount((uint32_t)mask);
}

int32 main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int32 N, P, K;
    cin >> N >> P >> K;

    vector<int32> A(N + 1);
    for (int32 i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }

    vector<vector<int32>> S(N + 1, vector<int32>(P));
    for (int32 i = 1; i <= N; ++i)
    {
        for (int32 j = 0; j < P; ++j)
        {
            cin >> S[i][j];
        }
    }

    vector<int32> order(N);
    iota(order.begin(), order.end(), 1);
    sort(order.begin(), order.end(), [&](int32 i, int32 j)
         { return A[i] > A[j]; });

    int32 have_seen = 0;
    vector<int64> dp(1 << P, -INF);
    dp[0] = 0;

    for (int32 i : order)
    {
        ++have_seen;
        vector<int64> new_dp = dp;
        for (int32 mask = 0; mask < (1 << P); ++mask)
        {
            if (new_dp[mask] == -INF)
            {
                continue;
            }

            if (have_seen - getPopCount(mask) <= K)
            {
                new_dp[mask] += A[i];
            }
        }

        for (int32 position = 0; position < P; ++position)
        {
            for (int32 mask = 0; mask < (1 << P); ++mask)
            {
                if ((mask >> position & 1) == 0 || dp[mask ^ (1 << position)] == -INF)
                {
                    continue;
                }
                new_dp[mask] = max(new_dp[mask], dp[mask ^ (1 << position)] + S[i][position]);
            }
        }
        dp.swap(new_dp);
    }
    cout << dp[(1 << P) - 1] << "\n";
    return 0;
}