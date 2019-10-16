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

string a, b, ans, tmp;
map<string, bool> s; 
bool found;
int n, m;

void gen(int n, int k) {
	if (k == n) {
		if (!s.count(tmp)) {
			ans = tmp;
			found = 1;
		}
	} else {
		fto (i, '0', '1') {
			tmp[k] = i;
			gen(n, k+1);
			if (found) return;
		}
	}
}

bool check(int k) {
	s.clear();
	fto (i, 0, sz(a)-k) s[a.substr(i, k)] = 1;
	fto (i, 0, sz(b)-k) s[b.substr(i, k)] = 1;
	
	tmp = "";
	found = 0;
	while (sz(tmp) < k) tmp += '0';
	gen(k, 0);
	return found;
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> a >> b;
	n = sz(a);
	m = sz(b);
	
	int l = 1;
	int r = max(n, m)+1;

	while (l <= r) {
		int mid = (l+r)/2;
		if (check(mid)) r = mid-1;
		else l = mid+1;
	}

	bug(ans);
	
	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}