#include <bits/stdc++.h>

#define fto(i, a, b) for (int i = a; i <= b; ++i)

#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define ff first
#define ss second
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define ll long long
#define oo 1000000007
#define OO 1000000000000000007

using namespace std;

ll a[100];
vector <ll> res;

int main() {
//    #ifndef ONLINE_JUDGE
//        freopen("codef.inp", "r", stdin);
//        freopen("codef.out", "w", stdout);
//    #endif // ONLINE_JUDGE
    ll n;
    cin >> n;
    a[0] = 1; res.pb(1);
    fto(i, 1, 60) a[i] = (ll)a[i-1]*2, res.pb(a[i]);
    fto(i, 1, 60) res.pb((ll)a[i]*3);
    sort(res.begin(), res.end());
    fto(i, 0, (int)res.size()-1) {
        if (n < res[i]) {
            cout << n-res[i-1];
            return 0;
        }
    }
    return 0;
}
