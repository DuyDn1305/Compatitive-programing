#include <bits/stdc++.h>

#define fto(i, s, e) for (int i = s; i <= e; ++i)
#define fdto(i, s, e) for (int i = s; i >= e; --i)
#define ll long long
#define ii pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define oo 1000000007
#define pii pair<int, int>

using namespace std;

int st[120005];
int f[30005];
int a[30005];
int b[30005];
int c[30005];
int cnt = 0, n;
map <int, int> mp;

void buildST(int p, int l, int r) {
    if (l > r) return;
    if (l == r) {
        st[p] = 0;
        return;
    }
    int m = (l+r)/2;
    buildST(p*2, l, m);
    buildST(p*2+1, m+1, r);
    return;
}

int get(int p, int l, int r, int x, int y) {
    if (l >= x && r <= y) return st[p];
    if (l > y || r < y) return 0;
    int m = (l+r)/2;
    return max(get(p*2, l, m, x, y), get(p*2+1, m+1, r, x, y));
}

int update(int p, int l, int r, int x, int y) {
    if (l > x || r < x) return st[p];
    if (x == l && r == l) return st[p] = y;
    int m = (l+r)/2;
    return st[p] = max(update(p*2, l, m, x, y), update(p*2+1, m+1, r, x, y));
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("daykg.in", "r", stdin);
		freopen("daykg.out", "w", stdout);
	#endif
    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]), b[i] = a[i], c[i] = a[i];

    sort(a+1, a+1+n);
    fto(i, 1, n) {
        if (!mp[a[i]]) mp[a[i]] = ++cnt;
    }
    fto(i, 1, n) b[i] = mp[b[i]];

    buildST(1, 1, n);
    fto(i, 1, n) {
        f[i] = get(1, 1, n, 1, b[i])+1;
        update(1, 1, n, b[i], f[i]);
    }
    int ans = 0;
    fto(i, 1, n) ans = max(ans, f[i]);
    printf("%d\n", ans);

    vector<pii> tr;
    int p = oo;
    fdto(i, n, 1) {
        if (f[i] == ans && c[i] <= p) {
            p = c[i];
            tr.pb(make_pair(c[i], i));
            --ans;
        }
    }
    fdto(i, (int)tr.size()-1, 0) printf("%d %d\n", tr[i].ff, tr[i].ss);
	return 0;
}
