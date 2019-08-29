#include <bits/stdc++.h>

using namespace std;

#define fto(i, s, e) for (int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for (int i = (s); i < (e); ++i)
#define fdto(i, s, e) for (int i = (s); i >= (e); --i)
#define fit(var, it) for (auto it = (var).begin(); it != (var).end(); ++it)
#define frit(var, it) for (auto it = (var).rbegin(); it != (var).rend(); ++it)

#define endl '\n'
#define bug1(x, i) cout << #x << '[' << i << "] = " << x[i] << endl
#define bug2(x, i, j) cout << #x << '[' << i << "][" << j << "] = " << x[i][j] << endl
#define bug3(x, i, j, k) cout << #x << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << endl

#define bc __builtin_popcountll
#define onb(x, bit) (x & (1 << bit))
#define gcd __gcd
#define y1 ansdj

#define ll long long
#define ii pair<int, int>
#define x first
#define y second
#define pb push_back
#define sz(v) int((v).size())

template<class T1, class T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.x << ", " << v.y << ')';
}

char* sfm(const char *fmt, ...) {
	static char res[256];va_list args;va_start(args, fmt);vsnprintf(res, 256, fmt, args);va_end(args);return res;
}

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 100005
#define pll pair<ll, ll>


vector <int> num;
ll dp[32][105][2];

ll calc(int pos, int sum, bool tight) {
    if (pos == sz(num)) return sum;
    if (dp[pos][sum][tight] != -1) return dp[pos][sum][tight];
    int lim = (tight) ? num[pos] : 9;
    ll res = 0;
    fto(i, 0, lim) {
        if (i != lim) res += calc(pos+1, sum+i, 0);
        else res += calc(pos+1, sum+i, tight);
    }
    return dp[pos][sum][tight] = res;
}

ll solve(ll n) {
    num.clear();
    while (n) {
        num.push_back(n%10);
        n /= 10;
    }

    reverse(num.begin(), num.end());

    fto(pos, 0, 20) {
        fto(sum, 0, 100) {
            fto(tight, 0, 1) dp[pos][sum][tight] = -1;
        }
    }

    return calc(0, 0, 1);
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    while (1) {
        int a, b;
        cin >> a >> b;
        if (a == -1) return 0;
        else cout << solve(b) - solve(a-1) << endl;
    }

	return 0;
}
