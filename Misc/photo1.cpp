#include <bits/stdc++.h>

#define fto(i, a, b) for(int i = a; i <= b; ++i)
#define fdto(i, a, b) for(int i = a; i >= b; --i)
#define ff first
#define ss second
#define ll long long
#define ull unsigned long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define pb push_back
#define oo 1000000007
#define OO 1000000000000000007

using namespace std;

int a[50];
int n, s;

bool check() {
    if (s%4) return 0;
    fto(i, 1, n) if (a[i] > s) return 0;
    return 1;
}

bool solve(int sum) {
    int f[50][50];
    vector <int> b; b.pb(0);
    fto(i, 1, n) if (!used[i]) b.pb(a[i]);
    int m = (int) b.size()-1;
    fto(i, 0, m) fto(j, 0, s) f[i][j] = 0;
    fto(i, 1, m) {
        fto(j ,1, s) {
            f[i][j] = f[i-1][j];
            if (a[i] <= s) f[i][j] = max(f[i][j], f[i-1][j-b[i]]+b[i]);
        }
    }
    bool ok = 0;
    int p = 0;
    fto(i, 1, m) if (f[i][m] == 1) {ok = 1, p = i, break; }
    if (!ok) return 0;
    else {
        int i = p;
        int j = m;
        while (f[i][j] != 0) {
            while (f[i-1][j] == f[i][j]) --i;
            while (f[i][j-1] == f[i][j]) --j;

        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("photo1.inp", "r", stdin);
        freopen("photo1.out", "w", stdout);
    #endif // ONLINE_JUDGE
    int T;
    scanf("%d", &T);
    while (T) { --T;
        scanf("%d", &n);
        s = 0;
        fto(i, 1, n) scanf("%d", &a[i]), s += a[i], used[i] = 0;
        if (check()) {
            s /= 4;
            bool ok = 1;
            fto(i, 1, 4) {
                if (!solve(s)) ok = 0;
            }
            if (ok) printf("yes\n");
            else printf("no\n");
        }
        else printf("no\n");
    }
    return 0;
}
