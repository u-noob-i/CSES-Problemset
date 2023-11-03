#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, M = 1e9 + 7;
    cin >> n >> m;
    vector<int> dp(1 << n, 0);
    dp[(1 << n) - 1] = 1;
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
        {
            vector<int> t(1 << n);
            for (int mask = 0; mask < (1 << n); mask++)
            {
                t[mask] = dp[mask ^ (1 << i)];
                if (i && ((1 << i)&mask) && ((1 << (i - 1))&mask))
                    t[mask] += dp[mask ^ (1 << (i - 1))];
                t[mask] %= M;
            }
            swap(dp, t);
        }
    cout << dp[(1 << n) - 1];
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
}
