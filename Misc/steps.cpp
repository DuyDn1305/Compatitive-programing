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
int f[1000];
int main() {
    #ifndef ONLINE_JUDGE
        freopen("steps.inp", "r", stdin);
        freopen("steps.out", "w", stdout);
    #endif // ONLINE_JUDGE
    scanf("%d%d", &n, &m);
    fto(i, 1, m) {
        int x;
        scanf("%d", &x);
        f[x] = -1;
    }
    f[1] = 1;
    fto(i, 2, n) {
        if (f[i] == -1) continue;
        if (f[i-1] != -1) f[i] += f[i-1];
        if (f[i-2] != -1) f[i] += f[i-2];
    }
    printf("%d\n", f[n]);
    return 0;
}
///12436

