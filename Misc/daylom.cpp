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

int n, ans = 0, lm = 20000;
int st[80005];
int f[10005];
int a[10005];
int F[10005];

int query(int p, int x, int y, int l, int r) {
    if (x > r || y < l) return 0;
    if (r <= y && l >= x) return st[p];
    int m = (l+r)/2;
    return max(query(p*2, x, y, l, m), query(p*2+1, x, y, m+1, r));
}

int update(int p, int x, int l, int r, int v) {
    if (x > r || x < l) return st[p];
    if (l == r && r == x) {
        return st[p] = v;
    }
    int m = (l+r)/2;
    return st[p] = max(update(p*2, x, l, m, v), update(p*2+1, x, m+1, r, v));
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("daylom.inp", "r", stdin);
        freopen("daylom.out", "w", stdout);
    #endif // ONLINE_JUDGE
    scanf("%d\n", &n);
    fto(i, 1, n) scanf("%d\n", &a[i]), a[i] += 10000;
    fto(i, 1, n) {
        f[i] = query(1, a[i]+1, lm, 1, lm)+1;
        update(1, a[i], 1, lm, f[i]);
    }
    fto(i, 1, lm*4) st[i] = 0;
    fdto(i, n, 1) {
        F[i] = query(1, a[i]+1, lm, 1, lm)+1;
        update(1, a[i], 1, lm, F[i]);
    }
    fto(i, 1, n) {
        if (f[i] > 1 && F[i] > 1) ans = max(ans, f[i]+F[i]-1);
    }
    printf("%d\n", ans);
}
///12436
