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

int n, m;
int a[100][100];
int f[100][100];
int g[100][100];
int h[50][50][50][50];

int sum1(int u, int v, int x, int y) {
    return f[x][y]-f[x][v-1]-f[u-1][y]+f[u-1][v-1];
}

int sum0(int u, int v, int x, int y) {
    return g[x][y]-g[x][v-1]-g[u-1][y]+g[u-1][v-1];
}

int solve(int u, int v, int x, int y) {
    if (sum1(u, v, x, y) == 0 || sum0(u, v, x, y) == 0) return h[u][v][x][y] = 1;
    if (h[u][v][x][y] != -1) return h[u][v][x][y];

    int res = oo;

    fto(i, u, x-1) {
        res = min(res, solve(u, v, i, y)+solve(i+1, v, x, y));
    }

    fto(j, v, y-1) {
        res = min(res, solve(u, v, x, j)+solve(u, j+1, x, y));
    }

    return h[u][v][x][y] = res;

}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("cathinh.in", "r", stdin);
        freopen("cathinh.out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) fto(j, 1, m) scanf("%d", &a[i][j]);

    fto(i, 1, n) fto(j, 1, m) f[i][j] = f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];
    fto(i, 1, n) fto(j, 1, m) g[i][j] = g[i-1][j]+g[i][j-1]-g[i-1][j-1]+(a[i][j] == 0);

    fto(i, 1 ,n) fto(j, 1, m) fto(x, 1, n) fto(y, 1, m) h[i][j][x][y] = -1;

    printf("%d\n", solve(1, 1, n, m));

    return 0;
}
