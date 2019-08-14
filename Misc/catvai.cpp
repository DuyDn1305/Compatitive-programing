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
int f[10001][10001];

int solve(int x, int y) {
    if (x == y) return f[x][y] = 1;
    if (min(x, y) == 0) return 0;
    if (f[x][y]) return f[x][y];
    f[x][y] = oo;
    fto(i, 1, min(x, y)) {
        f[x][y] = min(f[x][y], solve(x-i, y-i)+solve(x-i, y)+solve(x, y-i)+1);
    }
    return f[x][y];
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("catvai.in", "r", stdin);
        freopen("catvai.out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);

    printf("%d\n", solve(n, m));
    return 0;
}
