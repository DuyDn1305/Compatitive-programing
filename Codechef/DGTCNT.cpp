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
ll c[25][25];
ll pw[25][25]; // x^y
int a[10];

void init() {
    // ckn
    fto(n, 0, 20) {
        c[0][n] = 1;
        fto(k, 1, n) c[k][n] = c[k-1][n-1]+c[k][n-1];
    }
    // power
    fto(x, 1, 10) {
        pw[x][0] = 1;
        fto(y, 1, 18) pw[x][y] = pw[x][y-1]*x;
    }
    return;
}

bool check(int cnt[]) {
    int count[10];
    fto(i, 0, 9) count[i] = 0;
    fto1(i, 0, sz(num)) ++count[num[i]];
    fto(i, 0, 9) if (count[i] == cnt[i]) return 1;
    return 0;
}

ll calc (int &mask, int cnt[], int len) {
    ll res = 1;
    fto(i, 0, 9) {
        if (onb(mask, i)) {
            if (len < cnt[i] || cnt[i] < 0) return 0;
            res *= c[cnt[i]][len];
            len -= cnt[i];     
        }
    }
    res *= pw[10-bc(mask)][len]; 
    return res;
}

ll go (int mask) {
    //if (bc(mask) == 10) return 0;
    ll ans = 0;
    int cnt[10];
    fto(i, 0, 9) cnt[i] = a[i];

    fto1(pos, 0, sz(num)) {
        int digit = num[pos];
        fto1(tmp, 0, digit) {
            if (!tmp && !pos) {
                fdto(len, sz(num)-1, 1) {
                    fto(j, 1, 9) {
                        --cnt[j];
                        ans += calc(mask, cnt, len-1); 
                        ++cnt[j];
                    }
                }
                continue;
            }
            --cnt[tmp];
            ans += calc(mask, cnt, sz(num)-pos-1);
            ++cnt[tmp];
        }
        --cnt[digit];
        if (cnt[digit] < 0 && (1<<digit)&mask) return ans;
    }

    return ans;
}

ll solve(ll n) {
    if (n == 0) return 0;
    ll ans = 0;
    num.clear();
    while (n) {
        num.push_back(n%10);
        n /= 10;
    }
    reverse(num.begin(), num.end());
    if (!check(a)) ++ans;
    fto1(i, 0, (1<<10)) {
        ans -= (ll)((bc(i)%2) ? go(i) : -go(i));
    }
    //cout << go(0) << endl;
    return ans;
}


int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    init();

    int q;
    cin >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        fto(i, 0, 9) cin >> a[i];
        cout << solve(r)-solve(l-1)<< endl;
    }
    #ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}
