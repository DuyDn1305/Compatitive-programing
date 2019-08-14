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
int a[1005];
int f[1005];

void updateBIT(int index, int v) {
    for (; index <= n; index += (index&(-index))) f[index] += v;
}

int getBIT(int index) {
    int res = 0;
    for (; index > 0; index -= index&-index) res += f[index];
    return res;
}

void pri(int x) {printf("%d\n", getBIT(x));}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("luongnv.inp", "r", stdin);
        freopen("luongnv.out", "w", stdout);
    #endif // ONLINE_JUDGE

    //scanf("%d%d", &n, &q);
    scanf("%d",  &n);
    fto(i, 1, n) scanf("%d", &a[i]);

    fto(i, 1, n) updateBIT(i, a[i]);

    pri(8);
    updateBIT(1, 1);
    updateBIT(8, -1);
    pri(8);
    return 0;
}
