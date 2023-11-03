#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n + 1), pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
    for (int l = 1; l <= n; l++)
    {
        for (int i = 1, j = i + l - 1; j <= n; i++, j++)
        {
            if (l == 1)
                dp[i][j] = a[i];
            else
                dp[i][j] = pref[j] - pref[i - 1] - min(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[1][n];
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
