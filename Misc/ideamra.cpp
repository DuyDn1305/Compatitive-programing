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

int f['z'+1];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("codef.inp", "r", stdin);
        freopen("codef.out", "w", stdout);
    #endif // ONLINE_JUDGE
    string s;
    int k, n;
    cin >> s;
    scanf("%d", &k);
    fto(i, 0, (int)s.size()-1) ++f[s[i]];
    if (s.size() < k) puts("impossible");
    else {
        int ans = 0;
        int cur = 0;
        fto(i, 'a', 'z') cur += (f[i] != 0);
        while (cur < k) {
            fto(i, 'a', 'z') {
                if (f[i] > 1) {
                    --f[i];
                    ++cur;
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
///12436
