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
ll f[1005][1005];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("sodd.in", "r", stdin);
        freopen("sodd.out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);

    fto(i, 1, n) {
        fto(j, 1, m) {
            if (i == 1 && j == i) {
                f[i][j] = 1;
                continue;
            }
            f[i][j] = f[i][j-1]+f[i-1][j];
        }
    }

    cout << f[n][m];

    return 0;
}
