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

int n;
pair<ll, int> a[205];
int f[205];
vector <int> ans[205];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("DIVSET2.inp", "r", stdin);
        freopen("DIVSET2.out", "w", stdout);
    #endif // ONLINE_JUDGE


    scanf("%d", &n);
    fto(i, 1, n) cin >> a[i].ff, a[i].ss = i;

    sort(a+1, a+1+n);

    int k = 0;
    fto(i, 1, n) {
        f[i] = 1;
        fto(j, 1, i-1) {
            if (a[i].ff%a[j].ff == 0) f[i] = max(f[i], f[j]+1);
        }
        k = max(k, f[i]);
    }

    fto(i, 1, n) {
        ans[f[i]].pb(a[i].ss);
    }

    printf("%d\n", k);
    fto(i, 1, k) {
        fto(j, 0, (int)ans[i].size()-1) printf("%d ", ans[i][j]);
        puts("");
    }

    return 0;
}
