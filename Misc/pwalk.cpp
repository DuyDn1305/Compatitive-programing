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

int n, q;
vector <pii> a[100005];
int f[100005];

int bfs(int s, int t) {
    fto(i, 1, n) f[i] = 0;
    queue <int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        fto(i, 0, (int) a[u].size()-1) {
            int v = a[u][i].ff;
            if (!f[v]) {
                q.push(v);
                f[v] = f[u]+a[u][i].ss;
            }
            if (v == t) return f[v];
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("pwalk.inp", "r", stdin);
        freopen("pwalk.out", "w", stdout);
    #endif // ONLINE_JUDGE
    scanf("%d%d", &n, &q);
    fto(i, 1, n-1) {
        int u, v, t;
        scanf("%d%d%d", &u, &v, &t);
        a[u].pb(mp(v, t));
        a[v].pb(mp(u, t));
    }
    fto(i, 1, q) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x == y) puts("0");
        else printf("%d\n", bfs(x, y));
    }
    return 0;
}
///12436
