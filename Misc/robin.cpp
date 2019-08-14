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

int n, m;
int pSet[1005];
pair <int, pii> a[10005];

void initSet(int l, int r) {fto(i, l, r) pSet[i] = i;}

int findSet(int x) {return (x == pSet[x]) ? x : findSet(pSet[x]);}

void unionSet(int x, int y) {pSet[findSet(x)] = findSet(y);}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("electric.inp", "r", stdin);
        freopen("electric.out", "w", stdout);
    #endif // ONLINE_JUDGE
    scanf("%d%d", &n, &m);
    fto(i, 1, m) {
        int u, v, t;
        scanf("%d%d%d", &u, &v, &t);
        a[i].ff = mp(t, i);
        a[i].ss = mp(u, v);
    }
    initSet(1, n);
    sort(a+1, a+1+m, greater<pair<int, pii> >());
    int ans = 0;
    fto(i, 1, m) {
        int x = a[i].ss.ff;
        int y = a[i].ss.ss;
        int v = a[i].ff.ff;
        int id = a[i].ff.ss;
        if (findSet(x) != findSet(y)) {
            unionSet(x, y);
            ans += v;
            f.pb(id);
        }
    }

    printf("%d\n", ans);
}
///12436
