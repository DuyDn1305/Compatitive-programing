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

int n, m;
int a[2000][2000];
bool f[1000005];
int dx[3] = {0, 1, 1};
int dy[3] = {1, 1, 0};
ll ans, cnt;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("prime.inp", "r", stdin);
        freopen("prime.out", "w", stdout);
    #endif // ONLINE_JUDGE
    scanf("%d%d", &n, &m);
    fto(i, 1, n) {
        fto(j, 1, m) {
            scanf("%d", &a[i][j]);
        }
    }
    fto(i, 1, 10000) f[i] = 1;
    f[1] = 0;

    fto(i, 2, (int)sqrt(100000)) {
        if (f[i]) {
            for(int j = i*i; j <= 1000000; j += i) f[j] = 0;
        }
    }
    fto(i, 1, n) {
        fto(j, 1, m) {
            if (f[a[i][j]]) ans += (ll)a[i][j], ++cnt;
            fto(k, 0, 2) {
                int res = a[i][j];
                if (a[i][j] == 0) break;
                fto(l, 1, 5) {
                    int x = dx[k]*l+i;
                    int y = dy[k]*l+j;
                    if (x > n || y > m || x < 1 || y < 1) break;
                    if (f[res = res*10 + a[x][y]]) ans += (ll)res, ++cnt;
                }
            }
        }
    }
    cout << cnt << " " << ans << endl;
    return 0;
}
