#include <bits/stdc++.h>

#define fto(i, a, b) for(int i = a; i <= b; ++i)
#define fdto(i, a, b) for(int i = a; i >= b; --i)
#define ff first
#define ss second
#define ll long long
#define ull unsigned long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define pb push_back
#define oo 1000000007

using namespace std;

int ti, tj, si, sj;
int f[8][8];
bool visit[8][8];
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void solve(int i, int j) {
    //priority_queue <pair<int, pii>, vector<pair<int, pii> > >q;
    queue <pii> q;
    //q.push(mp(0, mp(i, j)));
    q.push(mp(i, j));
    f[i][j] = 0;
    while (!q.empty()) {
        //int u = q.top().ss.ff;
        //int v = q.top().ss.ss;
        int u = q.front().ff;
        int v = q.front().ss;
        q.pop();
        fto(k, 0, 7) {
            int x = u+dx[k];
            int y = v+dy[k];
            if (x < 0 || x > 7 || y < 0 || y > 7) continue;
            if (f[u][v] >= f[x][y]) continue;
            f[x][y] = min(f[x][y], f[u][v]+u*x+v*y);
            //q.push(mp(f[x][y], mp(x, y)));
            q.push(mp(x, y));
        }

    }
    return;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("codef.inp", "r", stdin);
        freopen("codef.out", "w", stdout);
    #endif // ONLINE_JUDGE
    while (1) {
        if (scanf("%d%d%d%d", &si, &sj, &ti, &tj) == -1) break;
        fto(i, 0, 7) fto(j, 0, 7) f[i][j] = oo;
        solve(si, sj);
        if (f[ti][tj] != oo) printf("%d\n", f[ti][tj]);
        else printf("-1\n");
    }

    return 0;
}
