#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> t(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> t[i][j];
    vector<long long> dp(n + 1, 0);
    sort(t.begin(), t.end(), [&](const vector<int> & x, const vector<int> & y) {return x[0] < y[0];});
    for (int i = n - 1; i >= 0; i--)
    {
        int l = i + 1, r = n - 1, mid, v = n;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (t[mid][0] > t[i][1])
            {
                v = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        dp[i] = max(dp[i + 1], dp[v] + t[i][2]);
    }
    cout << dp[0];
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
