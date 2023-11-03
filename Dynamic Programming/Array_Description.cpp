#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, M = 1e9 + 7;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1)
            {
                if (!a[i - 1])
                    dp[i][j] = 1;
                else
                    dp[i][j] = (j == a[i - 1]);
            }
            else if (a[i - 1] && a[i - 1] != j)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = ((dp[i - 1][j] +
                             (j > 1 ? dp[i - 1][j - 1] : 0)) % M +
                            (j < m ? dp[i - 1][j + 1] : 0)) % M;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
        ans = (ans + dp[n][i]) % M;
    cout << ans;
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
