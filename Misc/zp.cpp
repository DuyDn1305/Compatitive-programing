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

int n;
bool f[1000005];

void solve(int x) {
    if (f[x]) return;
    fto(i, 1, (int)sqrt(x)) {
        if (x%i == 0) {
            int j = x/i;
            if (i > j) break;
            solve((i-1)*(j+1));
        }
    }
    f[x] = 1;
    return;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("zp.inp", "r", stdin);
        freopen("zp.out", "w", stdout);
    #endif // ONLINE_JUDGE
    scanf("%d", &n);
    solve(n);
    int ans = 0;
    fto(i, 0, n-1) ans += f[i];
    printf("%d\n", ans);
    fto(i, 0, n-1) {
        if (f[i]) printf("%d ", i);
    }
    return 0;
}
///12436
