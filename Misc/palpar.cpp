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
string s;
//int f[2005][2005];
//int solve(int i, int j) {
//    if (i > j) return 0;
//    if (f[i][j] != -1) return f[i][j];
//    //if (i == j) return 1;
//
//    int best = 1;
//    ll L = 0;
//    ll R = 0;
//    ll m = 1;
//    fto(l, 1, (j-i+1)/2) {
//        L = (L*31+(s[i+l-1]-'a'))%oo;
//        R = (R+m*(s[j-l+1]-'a'))%oo;
//        m = (m*31)%oo;
//        //cout << L << " " << R << endl;
//
//        if (L == R) {
//            int tmp = solve(i+l, j-l);
//            if (tmp+2 > best) best = tmp+2;
//        }
//    }
//
//    return f[i][j] = best;
//}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("palpar.inp", "r", stdin);
        freopen("palpar.out", "w", stdout);
    #endif // ONLINE_JUDGE

    int T;
    scanf("%d", &T);

    while (T--) {
        cin >> s;

        n = s.size();
        s = '!'+s;

        int ans = 0;


        ll L = 0;
        ll R = 0;
        ll m = 1;

        fto(i, 1, n/2) {
            int j = n-i+1;
            L = (L*31+(s[i]-'a'))%oo;
            R = (R+m*(s[j]-'a'))%oo;
            if (L == R) {
                m = 1;
                L = 0;
                R = 0;
                ans += 2;
                if (n%2 && i == n/2) ++ans;
            }
            else {
                m = (m*31)%oo;
                if (i == n/2) ++ans;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
