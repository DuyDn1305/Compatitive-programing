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

int n, m, len, s, t;
pair <pii, int> trace[21][21][2005];
int a[25][25];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    #ifndef ONLINE_JUDGE
        freopen("robots.inp", "r", stdin);
        freopen("robots.out", "w", stdout);
    #endif // ONLINE_JUDGE
    scanf("%d%d", &n, &m);
    fto(i, 1, n) {
        fto(j, 1, m) scanf("%d", &a[i][j]);
    }
    scanf("%d%d", &s, &t);
    trace[1][1][1] = mp(mp(1,1), 2);
    fto(k, 2, 2000) {
        bool found = 0;
        fto(i, 1, n) {
            fto(j, 1, m) {
                //printf("%d %d %d %d\n", i, j, k, trace[i][j][k-1].ff.ff);
                if (trace[i][j][k-1].ff.ff != 0) {
                    int d = trace[i][j][k-1].ss;
                    fto(l, -1, 0) {
                        int x = dx[(d+l+4)%4]+i;
                        int y = dy[(d+l+4)%4]+j;
                        if (min(x, y) < 1 || x > n || y > m) continue;
                        if (a[x][y]) continue;
                        trace[x][y][k] = mp(mp(i, j), (d+l+4)%4);
                        if (x == s && y == t) {
                            found = 1;
                            len = k;
                            break;
                        }
                    }
                }
                if (found) break;
            }
            if (found) break;
        }
        if (found) break;
    }
    if (!len) puts("0");
    else {
        printf("%d\n", len);
        pii cur = mp(s, t);
        vector <pii> ans;
        while (len > 0) {
            ans.pb(cur);
            cur = trace[cur.ff][cur.ss][len].ff;
            --len;
        }
        fdto(i, (int)ans.size()-1, 0) printf("%d %d\n", ans[i].ff, ans[i].ss);
    }
    return 0;
}
///12436
