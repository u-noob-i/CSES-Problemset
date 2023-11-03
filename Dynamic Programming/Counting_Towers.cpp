#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int m = 1e9 + 7;
    vector<vector<int>> dp(1000001, vector<int>(2));
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= 1000000; i++)
    {
        dp[i][0] = (2ll * dp[i - 1][0] + dp[i - 1][1]) % m;
        dp[i][1] = (4ll * dp[i - 1][1] + dp[i - 1][0]) % m;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % m << "\n";
    }
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
