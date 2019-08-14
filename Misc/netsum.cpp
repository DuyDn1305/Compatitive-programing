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

int n, m, k;
int a[105][105];
int f[105][105];
pii q[10005];
int s[20005];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void initQ() {
    fto(i, 1, n*2-1) {
        if (i <= n) s[i] = s[i-1] + i;
        else {
            s[i] = s[i-1]+2*n-i;
        }
    }
    int s = 0;
    fto(i, 1, n) {
        int x = i;
        int y = 1;
        while (x > 0 && y <= n) {
            ++s;
            q[s] = mp(x, y);
            --x;
            ++y;
        }
    }
    fto(j, 2, n) {
        int x = n;
        int y = j;
        while (x > 0 && y <= n) {
            ++s;
            q[s] = mp(x, y);
            --x;
            ++y;
        }
    }
    return;
}

void solve(int cur) {
    fto(i, 1, s[min(n*2-1, cur)]) {
        int u = q[i].ff;
        int v = q[i].ss;
        if ((u+v)%2 != cur%2) {
            fto(l, 0, 3) {
                int x = dx[l]+u;
                int y = dy[l]+v;
                f[u][v] = max(f[u][v], f[x][y]+a[u][v]);
            }
        }
    }
    return;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("netsum.inp", "r", stdin);
        freopen("netsum.out", "w", stdout);
    #endif // ONLINE_JUDGE
    scanf("%d%d", &n, &k);
    fto(i, 1, n) fto(j, 1, n) scanf("%d", &a[i][j]);
    initQ();
    fto(i, 1, k) {
        solve(i);
    }
    int ans = 0;
    fto(i, 1, n) fto(j, 1, n) ans = max(ans, f[i][j]);
    //fto(i, 1, n) fto(j, 1, n) if (f[i][j] == ans) {trace(i, j, k); break
    printf("%d\n", ans);
}
///12436
