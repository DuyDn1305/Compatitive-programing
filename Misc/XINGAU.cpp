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

int n, m, u;
int r[123];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("XINGAU.inp", "r", stdin);
        freopen("XINGAU.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ///       2
    /// 1 4 6 3 1
    ///       5
    /// 3     4
    /// 1 2 6 5 1
    /// 4

    r[1] = 1; r[2] = 4; r[3] = 6; r[4] = 3;
    u = 5;

    scanf("%d%d", &n, &m);

    int division = m/4;
    int rest = m-division*4;
    ll ans = (ll)n*division*14;

    if (!(m%4)) n = 0;

    fto(i, 1, n) {
        if (i%2) {
            fto(j, 1, rest) ans += r[j];
            int pre = r[rest];
            r[rest] = u;
            u = 7-pre;
            if (rest-2 > 0) r[rest-2] = 7-r[rest];
            if (rest+2 < 5) r[rest+2] = 7-r[rest];
        }
        else {
            fto(j, 1, rest) ans += r[j];
            int pre = r[1];
            r[1] = u;
            u = 7-pre;
            r[3] = 7-r[1];
        }

    }

    printf("%d\n", ans);

    return 0;
}
