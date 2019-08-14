#include <bits/stdc++.h>

#define fto(i, a, b) for(int i = a; i <= b; ++i)
#define fdto(i, a, b) for(int i = a; i >= b; --i)
#define ff first
#define ss second
#define ll long long
#define ull unsigned long long
#define ull unsigned ll
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define pb push_back
#define oo 1000000007

using namespace std;

int n;
ll a[205];
int f[205];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("DIVSET.inp", "r", stdin);
        freopen("DIVSET.out", "w", stdout);
    #endif // ONLINE_JUDGE


    scanf("%d", &n);
    fto(i, 1, n) cin >> a[i];

    sort(a+1, a+1+n);

    int ans = 0;
    fto(i, 1, n) {
        f[i] = 1;
        fto(j, 1, i-1) {
            if (a[i]%a[j] == 0) {
                f[i] = max(f[i], f[j]+1);
            }
        }
        ans = max(ans, f[i]);
    }

    printf("%d\n", ans);

    return 0;
}
