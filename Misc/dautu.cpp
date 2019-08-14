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
int a[1005][1005];
int d[1005][1005];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("dautu.in", "r", stdin);
        freopen("dautu.out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &m, &n);
    fto(i, 1, m) fto(j, 1, n) scanf("%d", &a[i][j]);

    fto(i, 1, m) {
        fto(j, 1, n) {
            fto(k, 0, i) d[i][j] = max(d[i][j], max(d[i][j-1], d[k][j-1]+a[i-k][j]));
        }
    }

    printf("%d\n", d[m][n]);

    return 0;
}
