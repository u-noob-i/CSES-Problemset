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
    ll x;
    cin >> n >> x;
    vl a(n + 1, 0);
    rep(i, 1, n) cin >> a[i], a[i] += a[i - 1];
    ll ans = 0;
    rep(i, 1, n)
    {
        int v1 = -1, v2 = -1, l = i, r = n, mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (a[mid] - a[i - 1] > x)
                r = mid - 1;
            else
            {
                v1 = mid;
                l = mid + 1;
            }
        }
        if (a[v1] - a[i - 1] != x)
            continue;
        l = i, r = n;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (a[mid] - a[i - 1] < x)
                l = mid + 1;
            else
            {
                v2 = mid;
                r = mid - 1;
            }
        }
        ans += v1 - v2 + 1;
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
