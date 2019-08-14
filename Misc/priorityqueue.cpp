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
    queue <pii> q;
    q.push(mp(i, j));
    visit[i][j] = 1;
    f[i][j] = 0;
    while (!q.empty()) {
        int u = q.front().ff;
        int v = q.front().ss;
        fto(k, 0, 7) {
            int x = u+dx[k];
            int y = v+dy[k];
            if (x < 0 || x > 7 || y < 0 || y > 7) continue;
            if (visit[x][y] && f[u][v] >= f[x][y]) continue;
            q.push(mp(x, y));
            visit[x][y] = 1;
            f[x][y] = min(f[x][y], f[u][v]+u*x+v*y);
        }
        q.pop();
    }
    return;
}


bool custom(pair <int, pii> a , pair<int, pii> b) {
    if (a.ff == b.ff) {
        if (a.ss.ff == b.ss.ff) return a.ss.ss > b.ss.ss;
        return a.ss.ff > b.ss.ff;
    }
    return a.ff > b.ff;
}

int main() {
    #ifndef ONLINE_JUDGE
        //freopen("codef.inp", "r", stdin);
        freopen("codef.inp", "w", stdout);
    #endif // ONLINE_JUDGE
    int n;
//    priority_queue< pair<int, pii>, vector<pair<int, pii> >,  greater<pair<int, pii> > > q;
//    pair <int, pii> a[50];
//    scanf("%d", &n);
//    fto(i, 1, n) scanf("%d%d%d", &a[i].ff, &a[i].ss.ff, &a[i].ss.ss);
//    sort(a+1, a+1+n, custom);
//    fto(i, 1, n) {
//        printf("%d %d %d\n", a[i].ff, a[i].ss.ff, a[i].ss.ss);
//    }
//    puts("");
//    fto(i, 1, n) q.push(pair<int, pii> (i, mp(i, i)));
//    while (!q.empty()) {
//        printf("%d %d %d\n", q.top().ff, q.top().ss.ff, q.top().ss.ss);
//        q.pop();
//    }
    fto(i, 0, 7) {
        fto(j, 0, 7) {
            fto(k, 0, 7) {
                fto(l, 0, 7) printf("%d %d %d %d\n", i, j, k, l);
            }
        }
    }
    return 0;
}
