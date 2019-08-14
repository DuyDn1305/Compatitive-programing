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

int GCD(int a, int b) {if (b == 0) return a;return (!(a%b)) ? b : GCD(b, a%b);}

int n, m;
pii a[30005];
int f[30005];
int in[30005];
int st[120005];

int query(int p, int x, int y, int left, int right) {
    if (x > right || y < left) return 0;
    if (left >= x && right <= y) return st[p];
    int mid = (left+right)/2;
    return max(query(p*2, x, y, left, mid), query(p*2+1, x, y, mid+1, right));
}

int update(int p, int x, int left, int right, int v) {
    if (x < left || x > right) return st[p];
    if (left == right && x == left) return st[p] = v;
    int mid = (left+right)/2;
    return st[p] = max(update(p*2, x, left, mid, v), update(p*2+1, x, mid+1, right, v));
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("codef.inp", "r", stdin);
        freopen("codef.out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i].ff), a[i].ss = i, in[i] = a[i].ff;
    sort(a+1, a+1+n); in[0] = -1;
    sort(in+1, in+1+n);

    fto(i, 1, n) if (in[i] != in[i-1]) ++m;
    fto(i, 1, n) {
        a[i].ff = a[i-1].ff;
        if (in[i] != in[i-1]) ++a[i].ff;
    }
    fto(i, 1, n) swap(a[i].ff, a[i].ss);
    sort(a+1, a+1+n);

    fto(i, 1, n) {
        int p = a[i].ss;
        int x = query(1, 1, p-1, 1, m)+1;
        f[i] = x;
        update(1, p, 1, m, x);
    }
    int ans = 0;
    fto(i, 1, n) ans = max(f[i], ans);
    printf("%d\n", ans);
    return 0;
}
