#include <bits/stdc++.h>

using namespace std;

#define long long long
#define ve vector
#define vi ve<int>
#define ii pair<int, int>
#define xx first
#define yy second
#define inf(t) numeric_limits<t>::max()
#define sz(v) ((int)v.size())

#define maxc 4
#define maxn 1010101
#define mod ((long) 1e9 + 7)

long t, n, k;
long dp[maxn][1 << maxc] = {0};

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("codef.inp", "r", stdin);
    freopen("codef.out", "w", stdout);
#endif
    cin >> t >> n >> k;

    for (int i = 0; i < maxc; ++i) dp[0][1 << i] = 1;
    for (int i = 1; i < n; ++i) {
        for (int m = 1; m < (1 << maxc); ++m) {
            for (int c = 0; c < maxc; ++c) {
                if (m & (1 << c)) {
                    dp[i][m] = (dp[i][m] + dp[i - 1][m]) % mod;
                    dp[i][m] = (dp[i][m] + dp[i - 1][m ^ (1 << c)]) % mod;
                }
            }
        }
    }

    long ans = 0;
    for (int m = 1; m < (1 << maxc); ++m) {
        if (__builtin_popcount(m) < k) continue;
        ans = (ans + dp[n - 1][m]) % mod;
    }

    long base = ans; ans = 1;
    for (; t > 0; t >>= 1) {
        if (t & 1) ans = (ans * base) % mod;
        base = (base * base) % mod;
    }
    cout << ans;

    return 0;
}
