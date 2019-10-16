#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fto(i, s, e) for(int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for(int i = (s); i < (e); ++i)
#define fdto(i, s, e) for(int i = (s); i >= (e); --i)
#define forit(it, l, r) for(auto it = (l); it != (r); ++it)
#define fit(it, var) forit(it, (var).begin(), (var).end())
#define frit(it, var) forit(it, (var).rbegin(), (var).rend())

#define endl '\n'
#define bug1(x, i) cout << #x << '[' << i << "] = " << x[i] << endl
#define bug2(x, i, j) cout << #x << '[' << i << "][" << j << "] = " << x[i][j] << endl
#define bug3(x, i, j, k) cout << #x << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << endl

#define bc __builtin_popcountll
#define onb(x, bit) ((x & (1 << bit)) != 0)
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

template<class T> void bug(T const &v) { cout << v << endl; }
template<class T, class... Args> void bug(T const &v, Args const&... args) { cout << v << ' '; bug(args...); }

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL

ll fac[100];

ll power(ll x, ll y, ll mod) {
	ll res = 1;
	while (y) {
		if (y%2) res = res*x%mod;
		x = x*x%mod;
		y /= 2;
	}
	return res;
}

ll lucas(ll n, ll k, int p) {
	fac[0] = 1;
	fto (i, 1, p) fac[i] = fac[i-1]*i%p;
	ll res = 1;
	while (k) {
		int x = n%p, y = k%p;
		if (x < y) return 0LL;
		res = res*fac[x]%p*power(fac[x-y], p-2, p)%p*power(fac[y], p-2, p)%p;
		k /= p;
		n /= p;
	}
	return res;
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int test;
	cin >> test;
	while (test--) {
		int n, k, m;
		cin >> n >> k >> m;
		ll ans = 0;
		ll tmp = m;
		fto (i, 2, 50) if (tmp%i == 0) {
			while (tmp%i == 0) tmp /= i;
			//if (!(m-210)) bug("'day ne'",i);
			ans += lucas(n, k, i)*(m/i)%m*power(m/i, i-2, i)%m;
			ans %= m;
		}
		bug(ans);
	}

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}