#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> dp(n + 1, -1);
    int h = -1;
    for (auto &x : a)
    {
        int l = 0, r = h, mid, v = -1;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (dp[mid] >= x)
            {
                v = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        if (v == -1)
            dp[++h] = x;
        else
            dp[v] = x;
    }
    cout << h + 1;
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
