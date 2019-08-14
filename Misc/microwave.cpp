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
        freopen("recognize.inp", "r", stdin);
        freopen("recognize.out", "w", stdout);
    #endif // ONLINE_JUDGE
    int n;
    scanf("%d", &n);
    fto(i, 1, n) {
        string x;
        cin >> x;
        if (check(x)) {
            cout << x.size() << " " << x[x.size()/2+1] << endl;
            break;
        }
    }
    return 0;
}
///12436
