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
int f[1000];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("BIT.inp", "r", stdin);
        freopen("BIT.out", "w", stdout);
    #endif // ONLINE_JUDGE

    string s;

    cin >> s;
    int n = s.size();

    fto(i, 0, n-1) ++f[s[i]];

    if (f['a'] == n || f['b'] == n) {
        fto(i, 1, n) printf("%d ", 1);
        return 0;

    }

    int l = 1;

    fdto(i, n-1, 0) {
        if (s[i] != s[i-1] && s[i] == 'a') {
            l = i;
            break;
        }
    }

    while (s[l] == s[l+1] && l+1 < s.size()) ++l;

    fto(i, 0, n-2) {
        if (s[i] != s[i+1]) printf("%d ", 1);
        else printf("%d ", 0);

    }

    if (s[n-1] == 'a') printf("%d ", 1);
    else printf("%d ", 0);

    return 0;
}
