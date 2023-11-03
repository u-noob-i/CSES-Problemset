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

vector<string> ret;

void rec(int i, string s, string temp)
{
    int n = s.length();
    if (i == n)
    {
        ret.pb(temp);
        return;
    }
    set<char> used;
    rep(j, i, n - 1)
    {
        if (used.find(s[j]) == used.end())
        {
            used.insert(s[j]);
            temp[i] = s[j];
            swap(s[j], s[i]);
            rec(i + 1, s, temp);
            swap(s[j], s[i]);
        }
    }
}

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    string temp(n, '.');
    rec(0, s, temp);
    sort(ret.begin(), ret.end());
    cout << ret.size() << "\n";
    for (auto x : ret)
        cout << x << "\n";
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
