#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fto(i, s, e) for(int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for(int i = (s); i < (e); ++i)
#define fdto(i, s, e) for(int i = (s); i >= (e); --i)
#define fit(it, var) for(auto it = (var).begin(); it != (var).end(); ++it)
#define frit(it, var) for(auto it = (var).rbegin(); it != (var).rend(); ++it)

#define bc __builtin_popcountll
#define onb(x, bit) (((x >> bit) & 1) != 0)
#define y1 ansdj

#define ll long long
#define ii pair<int, int>
#define x first
#define y second
#define pb push_back
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()

template<class T1, class T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.x << ", " << v.y << ')';
}

template<class T> ostream& operator<< (ostream &os, vector<T> const &v) {
	os << '['; for (int i = 0; i < sz(v); ++i) { os << v[i]; if (i < sz(v)-1) os << ' '; }
	return os << ']';
}

template<class T> void bug(T const &v) { cout << v << endl; }
template<class T, class... Args> void bug(T const &v, Args const&... args) { cout << v << ' '; bug(args...); }

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
int const maxn = 1e5+3;

int n;
ii a[maxn];
int c[maxn], k[maxn], p[maxn];
bool visit[maxn];
vector<int> vec, node, ke[maxn];
vector<ii> edge;

ll dt(int i, int j) {
	return abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
}

void dfs(int u) {
	visit[u] = 1;
	vec.pb(u);
	fit (it, ke[u]) if (!visit[*it]) dfs(*it);
}

int Par(int u) {
	return p[u] < 0 ? u : p[u] = Par(p[u]);
}

bool Union(int u, int v) {
	u = Par(u); v = Par(v);
	if (u == v) return 0;
	if (p[u] > p[v]) swap(u, v);
	p[u] += p[v];
	p[v] = u;
	return 1;
}

ll ans = 0;
vector<ii> res;

void kruskal() {
	while (!edge.empty()) {
		ii val = edge.back();
		edge.pop_back();
		if (Union(val.x, val.y)) {
			ans += dt(val.x, val.y) * (k[val.x] + k[val.y]);
			res.pb(val);
		}
	}
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	fto (i, 1, n) {
		cin >> a[i].x >> a[i].y;
		p[i] = -1;
	}

	fto (i, 1, n) cin >> c[i];
	fto (i, 1, n) cin >> k[i];

	fto (i, 1, n) {
		fto (j, i+1, n) {
			if (dt(i, j)*(k[i] + k[j]) <= max(c[i], c[j])) {
				ke[i].pb(j);
				ke[j].pb(i);
			}
		}
	}

	fto (i, 1, n) if (!visit[i]) {
		vec.clear();
		dfs(i);
		ii tmp = {oo, 0};
		fto1 (j, 0, sz(vec)) {
			fto1 (k, j+1, sz(vec)) {
				edge.pb({vec[j], vec[k]});
			}
			tmp = min(tmp, {c[vec[j]], vec[j]});
		}
		ans += tmp.x;
		node.pb(tmp.y);
		sort(all(edge), [](ii l, ii r) {
			return dt(l.x, l.y) * (k[l.x] + k[l.y]) > dt(r.x, r.y) * (k[r.x] + k[r.y]);
		});
		kruskal();
	}

	bug(ans);
	bug(sz(node));
	fit (it, node) cout << *it << ' ';
	bug("");
	bug(sz(res));
	fit (it, res) bug(it->x, it->y);

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}