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
int a[105];
vector <pair<char, char> > ans;

void solve(int n, int d) {
    if (n == 0) return;
    if (a[n] != d) {
        solve(n-1, 3-d-a[n]);
        ans.pb(mp(a[n]+'A', d+'A'));
        a[n] = d;
    }
    solve(n-1, d);
}

int main() {
    freopen("hanoi.inp", "r", stdin);
    freopen("hanoi.out", "w", stdout);

    scanf("%d\n", &n);
    fto(i, 1, n) {
        char t;
        scanf("%c", &t);
        a[i] = t-'A';
    }

    solve(n, 2);
    printf("%d\n", ans.size());
    fto(i, 0, (int)ans.size()-1) printf("%c%c\n", ans[i].ff, ans[i].ss);

    return 0;
}

