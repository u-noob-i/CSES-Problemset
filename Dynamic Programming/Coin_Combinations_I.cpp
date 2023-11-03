#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, s, m = 1e9 + 7;
    cin >> n >> s;
    vector<int> a(n), dp(s + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dp[0] = 1;
    for (int j = 0; j <= s; j++)
        for (int i = 0; i < n; i++)
            if (j - a[i] >= 0)
                dp[j] = (dp[j - a[i]] + dp[j]) % m;
    cout << dp[s];
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
