#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    bitset<100001> dp = 0;
    dp[0] = 1;
    for (auto &x : a)
        dp |= dp << x;
    vector<int> ans;
    for (int i = 1; i <= 100000; i++)
        if (dp[i])
            ans.push_back(i);
    cout << ans.size() << "\n";
    for (auto &x : ans)
        cout << x << " ";
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
