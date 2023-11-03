#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m = 1e9 + 7;
    cin >> n;
    int s = n * (n + 1) / 2;
    if (s % 2)
    {
        cout << 0;
        return;
    }
    vector<int> dp(s + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n - 1; i++)
        for (int j = s; j >= i; j--)
            dp[j] = (dp[j] + dp[j - i]) % m;
    cout << dp[s / 2];
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
