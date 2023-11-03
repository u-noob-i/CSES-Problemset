#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 2e9
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
    int n;
    cin >> n;
    vvi a(n, vi(3));
    rep(i, 0, n - 1)
    {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    sort(a.begin(), a.end(), [&](const vi & x, const vi & y) {
        if (x[0] == y[0])
            return x[1] > y[1];
        return x[0] < y[0];
    });
    vb ans1(n, 0), ans2(n, 0);
    int end = INF;
    irep(i, n - 1, 0)
    {
        if (a[i][1] >= end)
            ans1[a[i][2]] = 1;
        end = min(end, a[i][1]);
    }
    end = -1;
    rep(i, 0, n - 1)
    {
        if (a[i][1] <= end)
            ans2[a[i][2]] = 1;
        end = max(end, a[i][1]);
    }
    for (auto x : ans1)
        cout << x << " ";
    cout << "\n";
    for (auto x : ans2)
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

    int tt;
    tt = 1;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
