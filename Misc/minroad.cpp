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

int n, a, b;
pii in[300005];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("minroad.inp", "r", stdin);
        freopen("minroad.out", "w", stdout);
    #endif // ONLINE_JUDGE
    scanf("%d%d%d", &n, &a, &b);
    fto(i, 1, n) scanf("%d%d", &in[i].ff, &in[i].ss);
    sort(in+1, in+1+n);
    int l = 1;
    int ans = oo;
    int tung = 0;
    int truc = 0;
    fto(r, 1, n) {
        if (in[r].ss == 1) ++tung;
        else ++truc;
        while (1) {
            int x = in[l].ss == 1;
            int y = in[l].ss == 2;
            if (tung-x >= a && truc-y >= b) ++l, tung -= x, truc -= y;
            else break;
        }
        if (tung >= a && truc >= b) ans = min(ans, in[r].ff-in[l].ff);
    }
    printf("%d\n", ans);
    return 0;
}
///12436

