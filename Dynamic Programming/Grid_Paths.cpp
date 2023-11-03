#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m = 1e9 + 7;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> dp(n, vector<int>(n, 0));
    if (a[0][0] == '.')
        dp[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == '*')
                continue;
            if (i)
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % m;
            if (j)
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % m;
        }
    cout << dp[n - 1][n - 1];
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
