#include <bits/stdc++.h>

using namespace std;

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

int n, m;
int a[200005];
ll ans[200005];
pair<ii, int> q[200005];
ll f[1000005];
ll res = 0;

void add(int x) {
	res -= f[x]*f[x]*x;
	++f[x];
	res += f[x]*f[x]*x;
	return;
}

void remove(int x) {
	res -= f[x]*f[x]*x;
	--f[x];
	res += f[x]*f[x]*x;
	return;
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	int block = sqrt(n);
	fto (i, 1, n) cin >> a[i];
	fto (i, 1, m) {
		cin >> q[i].x.x >> q[i].x.y;
		q[i].y = i;
	}

	sort(q+1, q+1+m, [&](auto &l, auto &r) {
		if (l.x.x/block == r.x.x/block) {
			return ((l.x.x/block)%2 == 0) ? l.x.y < r.x.y : r.x.y < l.x.y;
		}
		return l.x.x < r.x.x;
	});
	int curL, curR;
	curL = curR = 0;

	fto (i, 1, m) {
		int l = q[i].x.x;
		int r = q[i].x.y;
		int id = q[i].y;
		while (curR < r) add(a[++curR]);
		while (curL < l) remove(a[curL++]);
		while (curL > l) add(a[--curL]);
		while (curR > r) remove(a[curR--]);
		ans[id] = res;
	}

	fto (i, 1, m) cout << ans[i] << endl;

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}