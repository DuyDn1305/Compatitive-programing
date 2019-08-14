#include <bits/stdc++.h>

#define oo 1000000007

using namespace std;

int n;
int a[100005];
int st[400005];

void buildST(int p, int l, int r) {
    if (l == r) st[p] = a[l];
    if (l < r) {
        buildST(2*p, l, (l+r)/2);
        buildST(2*p+1, ((l+r)/2)+1, r);
        st[p] = min(st[p*2], st[p*2+1]);
    }
}

int query(int p, int l, int r, int u, int v) {
    if (u <= l && v >= r) return st[p];
    if (u > r || v < l) return oo;
    return min(query(2*p, l, (l+r)/2, u, v), query(2*p+1, ((l+r)/2)+1, r, u, v));
}

int update(int p, int l, int r, int x, int v) {
    if (x == l && l == r) return st[p] = v;
    if (x > r || x < l) return st[p];
    return st[p] = min(update(p*2, l, (l+r)/2, x, v), update(p*2+1, ((l+r)/2)+1, r, x, v));
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("segmenttree.inp", "r", stdin);
        freopen("segmentree.out", "w", stdout);
    #endif // ONLINE_JUDGE
    int q;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    buildST(1, 1, n);
    while (q) {--q;
        int i, j, k;
        scanf("%d%d%d", &i, &j, &k);
        if (i == 1) printf("%d\n", query(1, 1, n, j, k));
        else update(1, 1, n, j, k);
    }
    return 0;
}
