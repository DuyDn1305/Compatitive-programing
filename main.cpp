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
int dp[20][100][100][2];
int pow10[10];

int calc(int pos, int mod_sum, int mod_num, bool tight, int &k) {
    if (pos == sz(num)) {
        if (!mod_num && !mod_sum) return 1;
        else return 0;
    }
    if (dp[pos][mod_sum][mod_num][tight] != -1) return dp[pos][mod_sum][mod_num][tight];
    int res = 0;
    int lim = (tight) ? num[pos] : 9;
    fto(i, 0, lim) {
        int ans;
        int mod = (i*pow10[sz(num)-1-pos]+mod_num)%k;
        if (i == lim) ans = calc(pos+1, (mod_sum+i)%k, mod, tight, k);
        else ans = calc(pos+1, (mod_sum+i)%k, mod, 0, k);
        res += ans;
    }
    return dp[pos][mod_sum][mod_num][tight] = res;
}

int solve(int n, int k) {
    if (n == 0) return 1;
    if (k >= 100) return 1;
    num.clear();
    while (n) {
        num.push_back(n%10);
        n /= 10;
    }
    reverse(num.begin(), num.end());
    fto(i, 0, 10) {
        fto(j, 0, 99) {
            fto(k, 0, 99) {
                fto(l, 0, 1) dp[i][j][k][l] = -1;
            }
        }
    }
    return calc(0, 0, 0, 1, k);
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int q;
    cin >> q;

    pow10[0] = 1;
    fto(i, 1, 9) pow10[i] = pow10[i-1]*10;

    fto(i, 1, q) {
        int a, b, k;
        cin >> a >> b >> k;
        cout << "Case " << i << ": " << solve(b, k)-solve(a-1, k) << endl;
    }

	return 0;
}
