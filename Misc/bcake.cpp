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

int n, m, k, maxsquare;
ll a[505][505];
ll f[505];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("bcake.inp", "r", stdin);
        freopen("bcake.out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &k);

    fto(i, 1, n) {
        fto(j, 1, m) {
            int x;
            scanf("%d", &x);
            if (x < k) a[i][j] = -10LL*oo;
            else a[i][j] = x;
        }
    }

    ll ans = 0;

    fto(l, 1, m) {
        fto(i, 1, n) f[i] = 0;
        fto(r, l, m) {
            fto(i, 1, n) f[i] += a[i][r];
            ll sum = 0;
            ll res = 0;
            int p = 0;
            int s = 0;
            int e = 0;
            fto(i, 1, n) {
                res += f[i];
                if (res < 0) res = 0, p = i+1;
                else {
                    if (sum < res) {
                        sum = res;
                        s = p;
                        e = i;
                    }
                }
            }
            if (sum >= ans) {
                maxsquare = (r-l+1)*(e-s+1);
                ans = sum;
            }
        }
    }

    printf("%d\n", maxsquare);

    return 0;
}
