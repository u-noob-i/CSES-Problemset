#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string s;
int n = 48;
bool vis[9][9];
int t[4][2] = {{1, 0}, { -1, 0}, {0, -1}, {0, 1}};

// To pass the strict time limit:
// 1. prune impossible solutions where line divides grid into 2 halves where both
//    have univisted cells
// 2. return if reached destination early
// 3. instead of making function calls to check if next position is valid or not
//    add padding to grid and check directly using boolean matrix

int rec(int x, int y, int i)
{
    if (vis[x][y + 1] && vis[x][y - 1] && !vis[x + 1][y] && !vis[x - 1][y])
        return 0;
    if (!vis[x][y + 1] && !vis[x][y - 1] && vis[x + 1][y] && vis[x - 1][y])
        return 0;

    if (i == n && x == 7 && y == 1)
        return 1;
    if (i == n || (x == 7 && y == 1))
        return 0;

    if (!vis[x][y + 1] && !vis[x][y - 1] && !vis[x + 1][y] && !vis[x - 1][y])
        return 0;

    int ret = 0;
    vis[x][y] = true;
    if (s[i] == 'U' && !vis[x - 1][y])
        ret += rec(x - 1, y, i + 1);
    else if (s[i] == 'D' && !vis[x + 1][y])
        ret += rec(x + 1, y, i + 1);
    else if (s[i] == 'L' && !vis[x][y - 1])
        ret += rec(x, y - 1, i + 1);
    else if (s[i] == 'R' && !vis[x][y + 1])
        ret += rec(x, y + 1, i + 1);
    else if (s[i] == '?')
    {
        for (int j = 0; j < 4; j++)
            if (!vis[x + t[j][0]][y + t[j][1]])
                ret += rec(x + t[j][0], y + t[j][1], i + 1);
    }
    vis[x][y] = false;
    return ret;
}

void solve()
{
    cin >> s;
    memset(vis, false, sizeof vis);
    for (int i = 0; i < 9; i++)
        vis[0][i] = vis[i][0] = vis[8][i] = vis[i][8] = true;
    cout << rec(1, 1, 0);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
}
