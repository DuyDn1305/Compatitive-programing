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


int main() {
    #ifndef ONLINE_JUDGE
        freopen("bfs.inp", "r", stdin);
        freopen("bfs.out", "w", stdout);
    #endif // ONLINE_JUDGE
    scanf("%d", &n);
    fto(i, 1, n*2) {
        int k;
        bool f[4005];
        scanf("%d", &k);
        fto(j, 1, 2*n) f[j] = 0;
        fto(j, 1, k) {
            int u;
            scanf("%d", &u);
            f[u] = 1;
        }
        fto(j, 1, 2*n) if (!f[j]) a[i].pb(j);
    }
    dfs(1);
    return 0;
}
///12436

