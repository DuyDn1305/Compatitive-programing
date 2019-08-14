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

string s;
int f[1005][1005];

int solve(int l, int r) {
    if (l == r) return 1;
    if (f[l][r] != -1) return f[l][r];
    if (((s[l] == '(') && (s[r] == ')')) || ((s[l] == '[') && s[r] == ']')) return f[l][r] = solve(l+1, r-1);
    int res = oo;
    fto(i, l, r-1) res = min(res, solve(l, i)+solve(i+1, r));
    return f[l][r] = res;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("bracket.inp", "r", stdin);
        freopen("bracket.out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> s;
    int n = s.size();
    s = '!'+s;

    fto(i, 1, n) fto(j, 1, n) f[i][j] = -1;

    printf("%d\n", solve(1, n));

    return 0;
}
