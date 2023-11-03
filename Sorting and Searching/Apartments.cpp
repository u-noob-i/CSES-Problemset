#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define INF 1e9
#define pb push_back
#define pr pop_back
#define rep(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vi vector<int>
#define vb vector<bool>
#define vl vector<ll>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<ll, ll>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vvvi vector<vector<vector<int>>>
ll M = 1e9 + 7;

void solve()
{
    int n, m, k, x;
    cin >> n >> m >> k;
    vpi a(n);
    vi b(m);
    rep(i, 0, n - 1)
    {
        cin >> x;
        a[i] = {x - k, x + k};
    }
    rep(i, 0, m - 1) cin >> b[i];
    sort(a.begin(), a.end(), [&](const pi & x, const pi & y) { return x.first < y.first; });
    sort(b.begin(), b.end());
    int ans = 0;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (b[j] >= a[i].first && b[j] <= a[i].second)
        {
            ans++;
            i++;
            j++;
        }
        else if (a[i].second < b[j])
            i++;
        else
            j++;
    }
    cout << ans;
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

    int tt;
    tt = 1;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
