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

int n, m;
string a, b;
pii trace[1005][1005];
int f[1005][1005];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("number.in", "r", stdin);
        freopen("number.out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    a = '0'+a;
    b = '0'+b;

    fto(i, 1, n) fto(j, 1, m) if (a[i] == b[j]) f[i][j] = 1;

    fto(i, 1, n) {
        fto(j, 1, m) {
            if (a[i] == b[j]) {

                int res = 0;
                pii pre = mp(0, 0);

                fto(u, 1, i-1) {
                    fto(v, 1, j-1) {
                        if (a[u] == b[v] && (res < f[u][v] || ((res == f[u][v]) && a[u] >= a[pre.ff]))) {
                            res = f[u][v];
                            pre = mp(u, v);
                        }
                    }
                }

                trace[i][j] = pre;
                f[i][j] = res+1;

            }
        }
    }

    int ans = 0;
    char c = '0';
    pii p = mp(0, 0);
    fto(i, 1, n) {
        fto(j, 1, m) {
            if (ans < f[i][j] || (ans == f[i][j] && c < a[i])) {
                c = a[i];
                ans = f[i][j];
                p = mp(i, j);
            }
        }
    }
    //printf("%d\n", ans);
    if (ans == 0) puts("-1");
    vector <char> r;
    while (f[p.ff][p.ss] != 0) {
        r.pb(a[p.ff]);
        p = trace[p.ff][p.ss];
    }

    reverse(r.begin(), r.end());
    fto(i, 0, ans-1) printf("%c", r[i]);

    return 0;
}
