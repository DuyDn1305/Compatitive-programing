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
vector <int> a[10005];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("dothi.inp", "r", stdin);
        freopen("dothi.out", "w", stdout);
    #endif // ONLINE_JUDGE
    scanf("%d%d", &n, &m);
    fto(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u].pb(v);
        a[v].pb(u);
    }
    fto(i, 1, n) {
        sort(a[i].begin(), a[i].end());
        fto(j, 0, (int)a[i].size()-1) printf("%d ", a[i][j]);
        puts("");
    }
    return 0;
}
///12436
