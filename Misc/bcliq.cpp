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

int n, ans = 1, lm = 10000;
int st[40005];

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
        freopen("liq.inp", "r", stdin);
        freopen("liq.out", "w", stdout);
    #endif // ONLINE_JUDGE
    scanf("%d\n", &n);
    fto(i, 1, n) {
        int x;
        scanf("%d\n", &x);
        int res = query(1, 1, x-1, 1, lm)+1;
        ans = max(ans, res);
        update(1, x, 1, lm, res);
    }
    printf("%d\n", ans);
}
///12436
