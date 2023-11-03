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
    int n, m;
    cin >> n >> m;
    vi a(n), b(n);
    rep(i, 0, n - 1)
    {
        cin >> a[i];
        a[i]--;
        b[a[i]] = i;
    }
    int ans = 1, px, py, x, y;
    rep(i, 1, n - 1) if (b[i] < b[i - 1]) ans++;
    rep(i, 1, m)
    {
        cin >> px >> py;
        px--, py--;
        x = a[px];
        y = a[py];
        if (x > y)
            swap(x, y);
        // cout << x << " " << y << " : ";
        if (y == x + 1)
        {
            if (b[y] > b[x])
                ans++;
            else
                ans--;
            if (x > 0)
            {
                if (b[x] > b[x - 1] && b[y] < b[x - 1])
                    ans++;
                else if (b[x] < b[x - 1] && b[y] > b[x - 1])
                    ans--;
            }
            if (y < n - 1)
            {
                if (b[y] < b[y + 1] && b[x] > b[y + 1])
                    ans++;
                else if (b[y] > b[y + 1] && b[x] < b[y + 1])
                    ans--;
            }
        }
        else
        {
            if (x > 0 && b[x] < b[x - 1] && b[y] > b[x - 1])
                ans--;
            else if (x > 0 && b[x] > b[x - 1] && b[y] < b[x - 1])
                ans++;
            if (x < n - 1 && b[x + 1] < b[x] && b[x + 1] > b[y])
                ans--;
            else if (x < n - 1 && b[x + 1] > b[x] && b[x + 1] < b[y])
                ans++;
            if (y > 0 && b[y] < b[y - 1] && b[x] > b[y - 1])
                ans--;
            else if (y > 0 && b[y] > b[y - 1] && b[x] < b[y - 1])
                ans++;
            if (y < n - 1 && b[y + 1] < b[y] && b[y + 1] > b[x])
                ans--;
            else if (y < n - 1 && b[y + 1] > b[y] && b[y + 1] < b[x])
                ans++;
        }
        swap(a[px], a[py]);
        swap(b[x], b[y]);
        cout << ans << "\n";
    }
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
