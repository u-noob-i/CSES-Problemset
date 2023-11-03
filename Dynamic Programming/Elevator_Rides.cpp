#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> a, dp1, dp2;

void rec(int mask)
{
    if (dp1[mask] != -1)
        return;
    int cost = 1e9, weight = x;
    for (int i = 0; i < n; i++)
        if ((1 << i)&mask)
        {
            int nmask = mask ^ (1 << i);
            rec(nmask);
            int w = dp2[nmask] + a[i], c = dp1[nmask];
            if (w > x)
                w = a[i], c++;
            if (c < cost)
            {
                cost = c;
                weight = w;
            }
            else if (c == cost)
                weight = min(weight, w);
        }
    dp1[mask] = cost;
    dp2[mask] = weight;
    return;
}

void solve()
{
    cin >> n >> x;
    a.resize(n);
    dp1.assign(1 << n, -1);
    dp2.assign(1 << n, -1);
    for (auto &i : a)
        cin >> i;
    dp1[0] = 0;
    dp2[0] = x;
    rec((1 << n) - 1);
    cout << dp1[(1 << n) - 1];
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
