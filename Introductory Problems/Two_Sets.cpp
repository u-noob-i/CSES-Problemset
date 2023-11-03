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
    int n;
    cin >> n;
    ll sum = 1ll * n * (n + 1) / 2;
    if (sum % 2ll)
    {
        cout << "NO";
        return;
    }
    cout << "YES\n";
    sum /= 2;
    set<ll> a, b;
    rep(i, 1, n) a.insert(i);
    while (sum)
    {
        auto itr = a.lower_bound(sum);
        if (itr == a.end() || *itr > sum)
            itr--;
        ll x = *itr;
        b.insert(x);
        a.erase(x);
        sum -= x;
    }
    cout << a.size() << "\n";
    for (auto x : a)
        cout << x << " ";
    cout << "\n" << b.size() << "\n";
    for (auto x : b)
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
