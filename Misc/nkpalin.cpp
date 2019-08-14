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

int n, m, ans = -oo;
int a[105][105];
int f[105][105];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("qbmax.inp", "r", stdin);
        freopen("qbmax.out", "w", stdout);
    #endif // ONLINE_JUDGE
    scanf("%d%d", &n, &m);
    fto(i, 1, n) {
        fto(j, 1, m) scanf("%d", &a[i][j]);
    }
    fto(i, 0, n+1) fto(j, 1, n) f[i][j] = -oo;
    fto(j, 1, n) {
        fto(i, 1, n) {
            f[i][j] = max(f[i][j-1], max(f[i-1][j-1], f[i+1][j-1]))+a[i][j];
        }
    }
    fto(i, 1, n) ans = max(ans, f[i][m]);
    printf("%d\n", ans);
}
///12436
