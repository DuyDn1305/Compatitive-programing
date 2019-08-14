#include <bits/stdc++.h>

#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define ff first
#define ss second
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define ll long long
#define pi = 3.1415926535897
#define oo 1000000007
#define OO 1000000000000000007

using namespace std;

int n, m, k, maxsquare;
ll a[505][505];
ll f[505];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("rank.inp", "r", stdin);
        freopen("rank.out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n, &m);

    fto(i, 1, m) {
        int x, y;
        scanf("%d %d", &x, &y);

        if (store[x]) x = store[x];
        else x = store[x] = ++cnt;

        if (store[y]) y = store[y];
        else y = store[y] = ++cnt;

        if (!edge[x][y]) a[x].pb[y], edge[x][y] = 1, ++deg[y];
    }

    fto(u, 1, cnt) {
        if (!deg[u]) dfs(u);
    }

    return 0;
}
