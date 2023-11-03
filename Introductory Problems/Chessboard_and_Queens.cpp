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

set<int> c, rd, ld;
int ans;

void bckt(int row, vector<string> &a)
{
    if (row == 8)
    {
        ans++;
        return;
    }
    rep(i, 0, 7)
    {
        if (c.find(i) != c.end() || rd.find(row + i) != rd.end() ||
                ld.find(row - i) != ld.end() || a[row][i] == '*')
            continue;
        c.insert(i);
        rd.insert(row + i);
        ld.insert(row - i);
        bckt(row + 1, a);
        c.erase(i);
        rd.erase(row + i);
        ld.erase(row - i);
    }
    return;
}

void solve()
{
    vector<string> a(8);
    rep(i, 0, 7) cin >> a[i];
    ans = 0;
    bckt(0, a);
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
