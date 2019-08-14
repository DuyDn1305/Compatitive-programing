#include <bits/stdc++.h>

#define fto(i, a, b) for(int i = a; i <= b; ++i)
#define fdto(i, a, b) for(int i = a; i >= b; --i)
#define ff first
#define ss second
#define ll long long
#define ull unsigned long long
#define ull unsigned ll
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define pb push_back
#define oo 1000000007

using namespace std;

int n, l;
int a[2000];
int f[1501][1501];
int F[1501][1501];

void solve(int left, int right) {
    if (F[left][right] != -1) return;
    if (left == right-1) {
        F[left][right] = 0;
        return;
    }
    int res = oo;
    fto(i, left+1, right-1) {
        solve(left, i);
        solve(i, right);
        res = min(F[left][i]+F[i][right], res);
    }
    F[left][right] = res+a[right]-a[left];
    return;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("catthep.inp", "r", stdin);
        freopen("catthep.out", "w", stdout);
    #endif // ONLINE_JUDGE
    scanf("%d%d", &n, &l);
    fto(i, 1, n) scanf("%d", &a[i]);
    a[n+1] = l;

    fto(i, 0, n+1) fto(j, 0, n+1) f[i][j] = oo;
    fto(i, 0, n+1) f[i][i] = 0;
    fto(i, 0, n) f[i][i+1] = 0;

    fto(i, 1, n) {
        fto(j, 0, n-i) {
            fto(k, j+1, j+i) {
                f[j][j+i+1] = min(f[j][k]+f[k][j+i+1], f[j][j+i+1]);
            }
            f[j][j+i+1] += a[j+i+1]-a[j];
        }
    }

    fto(i, 0, n+1) fto(j, 0, n+1) F[i][j] = -1;

    solve(0, n+1);

    printf("Bottom-up: %d\n", f[0][n+1]);
    printf("Top-down : %d\n", F[0][n+1]);
    return 0;
}
