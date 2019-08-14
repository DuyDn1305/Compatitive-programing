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
int a[1005][1005];

void dijstra(int s) {
    fto(i, 1, n) f[i] = oo;
    f[s] = 0;
    priority_queue <pii, vector<pii>, greater<pii> > q;
    q.push(mp(0, s));
    while (!q.empty()) {
        int u = q.top().ss;
        q.pop();
        fto(i, 0, (int)a[u].size()-1) {
            int v = a[u][i].ff;
            int t = a[u][i].ss;
            if (f[u]+t < f[v]) {
                f[v] = f[u]+t;
                trace[v] = u;
            }
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("travel.inp", "r", stdin);
        freopen("travel.out", "w", stdout);
    #endif // ONLINE_JUDGE
    scanf("%d%d", &n, &m);
    fto(i, 1, n) {
        fto(j, 1, n) if (i != j) a[i][j] = oo;
    }
    fto(i, 1, m) {
        int u, v, t;
        scanf("%d%d%d", &u, &v, &t);
        a[u][v] = t;
    }
    fto(k, 1, n) {
        fto(u, 1, n) {
            fto(v, 1, n)
                a[u][v] = min(a[u][k]+a[k][v], a[u][v]);
        }
    }
    fto(i, 1, n) {
        int res = oo;
        int found = 0;
        fto(j, 1, n) {
            if (i != j) {
                if (a[i][j]+a[j][i] < res) {
                    res = a[i][j]+a[j][i];
                    found = 1;
                }
            }
        }
        if (found) printf("%d\n", res);
        else puts("-1");
    }
    return 0;
}
///12436
