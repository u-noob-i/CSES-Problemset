#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s, p;
    cin >> s >> p;
    int n = s.length(), m = p.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (!i && !j)
                dp[i][j] = 0;
            else if (!i)
                dp[i][j] = 1 + dp[i][j - 1];
            else if (!j)
                dp[i][j] = 1 + dp[i - 1][j];
            else if (s[i - 1] == p[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                dp[i][j]++;
            }
        }
    }
    cout << dp[n][m];
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
