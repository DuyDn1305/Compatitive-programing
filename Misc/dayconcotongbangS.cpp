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

int n, s;
int a[10005];
int f[1005][40005];

int main() {
//    freopen("dayconcotongbangS.inp", "r", stdin);
//    freopen("dayconcotongbangS.out", "w", stdout);

    scanf("%d%d", &n, &s);
    fto(i, 1, n) scanf("%d", &a[i]);

    f[0][0] = 1;

    fto(t, 1, s) {
        fto(i, 1, n) {
            if (f[i-1][t]) {
                f[i][t] = f[i-1][t-a[i]];
                trace[i][t] = i-1;
            }
            if (f[i-1][t-a[i]]) {
                f[i][t] = f[i-1][t-a[i]]+1;
                trace[i][t] = i-1;
            }
        }
    }

    string ans = "YES";
    if (!f[n][s]) ans = "NO";

    cout << ans << endl;

    return 0;
}

