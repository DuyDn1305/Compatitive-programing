#include <bits/stdc++.h>

#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define ff first
#define ss second
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define ll long long
#define oo 1000000007
#define OO 1000000000000000007

using namespace std;

int n, m;
int a[105][105];
int cur[105];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("codef.inp", "r", stdin);
        freopen("codef.out", "w", stdout);
    #endif // ONLINE_JUDGE
    while (1) {
        scanf("%d%d", &n, &m);
        if (n == 0) break;
        fto(i, 1, n) fto(j, 1, m) scanf("%d", &a[i][j]);
        int ans = 0;
        int l, r, u, d;
        l = r = u = d = 0;
        fto(i, 1, m) {
            fto(k, 1, n) cur[k] = 0;
            fto(j, i, m) {
                int res = 0;
                fto(k, 1, n) {
                    cur[k] += a[k][j];
                }
                int pre = 0;
                fto(k, 1, n) {
                    if (cur[k] == 0) res = max(res, pre+1), ++pre;
                    else pre = 0;
                }
                ans = max(ans, res*(j-i+1));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
