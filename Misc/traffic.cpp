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

int n, k;
int pSet[1005];
pair<int, pii> a[1000005];

void initSet(int n) {fto(i, 1, n) pSet[i] = i;}

int findSet(int x) {return pSet[x] = (x == pSet[x]) ? x : findSet(pSet[x]);}

void unionSet(int x, int y) {pSet[findSet(x)] = findSet(y);}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("traffic.inp", "r", stdin);
        freopen("traffic.out", "w", stdout);
    #endif // ONLINE_JUDGE
    scanf("%d%d", &n, &k);
    initSet(n);
    fto(i, 1, k) {
        int u, v;
        scanf("%d%d", &u, &v);
        unionSet(u, v);
    }
    fto(i, 1, n) {
        fto(j, 1, n) {
            int x;
            scanf("%d", &x);
            if (i == j) continue;
            a[(i-1)*n+j] = mp(x, mp(i, j));
        }
    }
    int ans = 0;
    sort(a+1, a+1+n);
    fto(i, 1, n*(n-1)) {
        int u = a[i].ss.ff;
        int v = a[i].ss.ss;
        if (findSet(u) != findSet(v)) {
            unionSet(u, v);
            ans += a[i].ff;
        }
    }
    if (ans == 0) puts("YES");
    else printf("%d\n", ans);
    return 0;
}
///12436
