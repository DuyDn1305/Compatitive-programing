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
int a[1000005];
map <int, int> store;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("LSUB.inp", "r", stdin);
        freopen("LSUB.out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);

    int r = 0;
    int ans = 1;

    fto(l, 1, n) {
        while (!store[a[r+1]] && r < n) ++r, store[a[r]] = 1;
        ans = max(ans, r-l+1);
        store[a[l]] = 0;
        //cout << l << " " << ans<< endl;
    }
//
//    int L = 1;
//    store.clear();
//    int _ans = 1;
//    fto(R, 1, n) {
//        ++store[a[R]];
//        while (store[a[R]] > 1) --store[a[L++]];
//        _ans = max(_ans, R-L+1);
//    }

    printf("%d\n", ans);
//    printf("%d\n", _ans);

    return 0;
}
