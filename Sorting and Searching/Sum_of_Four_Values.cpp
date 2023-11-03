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
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    map<ll, pi> m;
    rep(i, 1, n - 2)
    {
        rep(j, i + 1, n - 1)
        {
            if (m.find(x - a[i] - a[j]) != m.end())
            {
                cout << i + 1 << " " << j + 1 << " " <<
                     m[x - a[i] - a[j]].first << " " << m[x - a[i] - a[j]].second;
                return;
            }
        }
        rep(j, 0, i - 1) m[a[i] + a[j]] = {i + 1, j + 1};
    }
    cout << "IMPOSSIBLE";
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
