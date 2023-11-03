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

vl pp;

void solve()
{
    ll k;
    cin >> k;
    ll tot = 0;
    rep(i, 1, 18)
    {
        if (tot + (pp[i] - pp[i - 1])*i > k)
        {
            k -= tot;
            ll num = 1, dig = k % i;
            rep(j, 1, i - 1) num *= 10ll;
            num += (k + i - 1) / i - 1;
            if (!dig)
                dig = i;
            irep(j, i, 1)
            {
                if (dig == j)
                {
                    cout << num % 10;
                    return;
                }
                num /= 10;
            }
        }
        tot += (pp[i] - pp[i - 1]) * i;
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

    pp.pb(1);
    rep(i, 1, 18) pp.pb(pp[pp.size() - 1] * 10);

    int tt;
    cin >> tt;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
