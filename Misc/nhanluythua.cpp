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

ll luyThua(ll n, ll x) {
    if (x == 0) return 1;
    if (x == 1) return n;
    ll res = luyThua(n, x/2);
    res = (res*res)%oo;
    if (x%2 == 1) res = (res*n)%oo;
    return res;
}


int main() {
//    freopen("nhanluythua.inp", "r", stdin);
//    freopen("nhanluythua.out", "w", stdout);

    ll a, b;

    while (cin >> a >> b) {
        if (a == 0 && b == 0) break;
        cout << luyThua(a, b) << endl;
    }

    return 0;
}

