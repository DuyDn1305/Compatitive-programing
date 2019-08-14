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

string s;
int n, M;
int ans = 0;
ll f[205][205];

ll solve(int l, int r) {
//    if (l > r) return 0;
//    if (f[l][r] != -1) return f[l][r];
//    int x = solve(l+1,r-1);
//    int y = solve(l+1, r);
//    int z = solve(l, r-1);
//    int res = 0;
//    if (s[l] == s[r]) res = y+z;
//    else res = y+z-x;
//    return f[l][r] = res;

    if (l > r) return 1;
    if (l == r) return 2;
    if (f[l][r] != -1) return f[l][r];

    ll res = M+solve(l, r-1)+solve(l+1, r)-solve(l+1, r-1);
    if (s[l] == s[r]) res += solve(l+1, r-1);

    return f[l][r] = res%M;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("palin.inp", "r", stdin);
        freopen("palin.out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &M);
    while (cin >> s) {
        n = s.size();
        s = '!'+s;
        fto(i, 1, n) fto(j, 1, n) f[i][j] = -1;
        printf("%d\n", solve(1, n));
    }
    return 0;
}
