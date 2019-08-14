#include <bits/stdc++.h>

#define fto(i, a, b) for(int i = a; i <= b; ++i)
#define fdto(i, a, b) for(int i = a; i >= b; --i)
#define ff first
#define ss second
#define ll long long
#define ull unsigned long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define pb push_back
#define oo 1000000007
#define OO 1000000000000000007

using namespace std;

int n;
ll f[100005];
string s;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("friend.inp", "r", stdin);
        freopen("friend.out", "w", stdout);
    #endif // ONLINE_JUDGE
    while (1) {
        cin >> s;
        if (s == "0") break;
        int n = s.size(); s = "!"+s;

        f[1] = 1;
        f[0] = 1;

        fto(i, 2, n) {
            f[i] = f[i-1];
            if (s[i-1] <= '1' || (s[i-1] == '2' && s[i] <= '6')) f[i] += f[i-2];
        }
        cout << f[n] << endl;
    }
    return 0;
}
