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

int n;
int a[1005];
int f[1005][1005];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("stones.in", "r", stdin);
        freopen("stones.out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);

    fto(i, 1, n) fto(j, 1, n) f[i][j] = oo;
    fto(i, 1, n) f[i][i] = a[i];

    fto(k, 2, n) {
        fto(i, 1, n-k+1) {
            fto(j, i, i+k-2) f[i][i+k-1] = min(f[i][i+k-1], f[i][j]+f[j+1][i+k-1]);
        }
    }

    printf("%d\n", f[1][n]);

    return 0;
}
