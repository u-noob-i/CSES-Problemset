#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> c(n), p(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    vector<int> dp(x + 1, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> t = dp;
        for (int j = 1; j <= x; j++)
        {
            t[j] = max(t[j], dp[j - 1]);
            if (j >= c[i])
                t[j] = max(t[j], p[i] + dp[j - c[i]]);
        }
        swap(dp, t);
    }
    cout << dp[x];
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
