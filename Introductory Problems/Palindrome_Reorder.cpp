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
    string s;
    cin >> s;
    int n = s.length();
    vi a(26, 0);
    rep(i, 0, n - 1) a[s[i] - 'A']++;
    bool f = 0;
    string ans(n, '.');
    int l = 0, r = n - 1;
    rep(i, 0, 25)
    {
        while (a[i] > 1)
        {
            a[i] -= 2;
            ans[l++] = ans[r--] = 'A' + i;
        }
        if (a[i] == 1)
        {
            if (n % 2 == 0 || f)
            {
                cout << "NO SOLUTION";
                return;
            }
            f = 1;
            ans[n / 2] = 'A' + i;
            a[i]--;
        }
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
