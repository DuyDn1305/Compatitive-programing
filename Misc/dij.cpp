#include <bits/stdc++.h>

#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define ff first
#define ss second
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define ll long long
#define pi = 3.1415926535897
#define oo 1000000007
#define OO 1000000000000000007

using namespace std;

int n, m, q;
ll A[405][405];

void precal() {
    fto(i, 1, n) {
        fto(u, 1, n) {
            fto(v, 1, n) A[u][v] = min(A[u][v], A[u][i]+A[i][v]);
        }
    }
}

ll solve() {
    ll a[405][405];
    fto(i, 1, n+3) fto(j, 1, n+3) a[i][j] = A[i][j];

    int k;
    scanf("%d", &k);
    fto(i, 1, k) {
        int u, v, t;
        scanf("%d%d%d", &u, &v, &t);
        a[u][v] = min(a[u][v], (ll)t);
    }

    fto(i, 1, n) {
        fto(u, 1, n) {
            fto(v, n+1, n+3) a[u][v] = min(a[u][v], a[u][i]+a[i][v]);
        }
    }

    fto(i, 1, n) {
        fto(u, n+1, n+3) {
            fto(v, 1, n+3) a[u][v] = min(a[u][v], a[u][i]+a[i][v]);
        }
    }

    fto(i, n+1, n+3) {
        fto(u, 1, n+3) {
            fto(v, 1, n+3) a[u][v] = min(a[u][v], a[u][i]+a[i][v]);
        }
    }

    ll res = 0;

    fto(i, 1, n+3) fto(j, 1, n+3) res += a[i][j];

    return res;
}

int main() {
    freopen("dij.inp", "r", stdin);
    freopen("dij.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &q);

    fto(i, 1, n+3) fto(j, 1, n+3) A[i][j] = (i == j) ? 0 : OO;

    fto(i, 1, m) {
        int u, v, t;
        scanf("%d%d%d", &u, &v, &t);
        A[u][v] = min(A[u][v], (ll)t);
    }

    precal();

    fto(i, 1, q) {
        cout << solve() << endl;
    }

    return 0;
}

