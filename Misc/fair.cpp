#include <bits/stdc++.h>

#define fto(i, a, b) for(int i = a; i <= b; ++i)
#define fdto(i, a, b) for(int i = a; i >= b; --i)
#define ff first
#define ss second
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define pb push_back
#define oo 1000000007
#define OO 1000000000000000007

using namespace std;

int n, m;
int a[1005][1005];
int f[1005][1005];
pii trace[1005][1005];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

pair<int, vector<pii> > solve(int si, int sj) {
    fto(i, 1, n) fto(j, 1, m) f[i][j] = oo;
    fto(i, 1, n) fto(j, 1, m) trace[i][j] = mp(0, 0);
    f[si][sj] = a[si][sj];
    priority_queue <pair<int, pii>, vector<pair<int, pii> >, greater<pair<int, pii> > > q;
    q.push(mp(0, mp(si, sj)));
    while (!q.empty()) {
        pii u = q.top().ss;
        q.pop();
        fto(k, 0, 3) {
            int x = u.ff+dx[k];
            int y = u.ss+dy[k];
            if (min(x, y) > 0 && x <= n && y <= m) {
                if (f[x][y] > f[u.ff][u.ss]+a[x][y]) {
                    f[x][y] = f[u.ff][u.ss]+a[x][y];
                    trace[x][y] = u;
                    q.push(mp(f[x][y], mp(x, y)));
                }
            }
        }
    }
    int res = oo;
    pii cur;
    fto(i, 1, n) {
        if (res > f[i][m]) {
            cur = mp(i, m);
            res = f[i][m];
        }
    }
    vector <pii> path;
    while (trace[cur.ff][cur.ss] != mp(0, 0)) {
        path.pb(cur);
        cur = trace[cur.ff][cur.ss];
    }
    path.pb(mp(si, sj));
    return mp(res, path);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("fair.inp", "r", stdin);
        freopen("fair.out", "w", stdout);
    #endif // ONLINE_JUDGE
    scanf("%d%d", &n, &m);
    fto(i, 1, n) {
        fto(j, 1, m) {
            scanf("%d", &a[i][j]);
        }
    }
    pair<int, vector<pii> > ans;
    ans.ff = oo;
    fto(i, 1, n) {
        pair<int, vector<pii> > res = solve(i, 1);
        if (res.ff < ans.ff) {
            ans = res;
        }
    }
    printf("%d\n", ans.ff);
    vector <pii> path = ans.ss;
    fdto(i, (int)path.size()-1, 0) {
        printf("%d %d\n", path[i].ff, path[i].ss);
    }
    return 0;
}
///12436
