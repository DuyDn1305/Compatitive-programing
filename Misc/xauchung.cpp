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
int f[1005][1005];
string a, b;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("xauchung.inp", "r", stdin);
        freopen("xauchung.out", "w", stdout);
    #endif // ONLINE_JUDGE
    cin >> a >> b;
    int n = a.size(); a = "!"+a;
    int m = b.size(); b = "!"+b;
    fto(i, 1, n) {
        fto(j, 1, m) {
            f[i][j] = max(f[i-1][j], f[i][j-1]);
            if (a[i] == b[j]) f[i][j] = max(f[i][j], f[i-1][j-1]+1);
        }
    }
    int ans = f[n][m];
    string res = "";
    int x = n, y = m;
    cout << ans << endl;
    while (ans) {
        while (f[x-1][y] == f[x][y]) --x;
        while (f[x][y-1] == f[x][y]) --y;
        --ans;
        res = a[x]+res;
        --x, --y;
    }
    //cout << res;
    return 0;
}
///12436
