#include <bits/stdc++.h>
using namespace std;

// num of digit, last used digit, bounded, pref 0 or not
long long dp[2][19][12][2][2];
vector<int> l, r;

long long calc(bool x, int i, int last, bool bd, bool pz)
{
    if (i < 0)
        return 1;
    if (dp[x][i][last][bd][pz] != -1)
        return dp[x][i][last][bd][pz];
    long long v = 0;
    int lim = 9;
    if (bd && !x)
        lim = r[i];
    if (bd && x)
        lim = l[i];
    for (int j = 0; j <= lim; j++)
        if (j != last)
            v += calc(x, i - 1, (pz && !j ? 11 : j), (bd && j == lim), (pz && !j));
    dp[x][i][last][bd][pz] = v;
    return v;
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    long long a, b;
    cin >> a >> b;
    a--;
    while (a)
    {
        l.push_back(a % 10);
        a /= 10;
    }
    while (b)
    {
        r.push_back(b % 10);
        b /= 10;
    }
    if (a == -1 && b == -1)
        cout << 1;
    else if (a == -1)
        cout << calc(0, r.size() - 1, 11, 1, 1);
    else
        cout << calc(0, r.size() - 1, 11, 1, 1) - calc(1, l.size() - 1, 11, 1, 1);
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
