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

int f[1234];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("demcapso.inp", "r", stdin);
        freopen("demcapso.out", "w", stdout);
    #endif // ONLINE_JUDGE

    int n;
    scanf("%d", &n);
    fto(i, 1, n) {
        int x;
        scanf("%d", &x);
        int res = 0;
        while (x) {
            int j = x%10;
            x /= 10;
            res |= (1 << j);
        }
        ++f[res];
        //cout << res << endl;
    }


    ll ans = 0;
    fto(i, 1, 1023) {
        ans += (f[i]*(f[i]-1))/2;
    }

    fto(i, 1, 1023) {
        fto(j, i+1, 1023) {
            if ((i&j)) ans += f[i]*f[j];
        }
    }

    cout << ans << endl;

    return 0;
}
