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

struct Matrix {
	vector<vector<ll>> v;
	Matrix(int n, int m, int val) {
		v.resize(n, vector<ll>(m, val));
	}
};

Matrix operator * (Matrix const &a, Matrix const &b) {
	Matrix ans(sz(a.v), sz(b.v[0]), 0);
	fto1 (i, 0, sz(a.v)) {
		fto1 (j, 0, sz(b.v[0])) {
			fto1 (k, 0, sz(b.v)) {
				ans.v[i][j] += a.v[i][k]*b.v[k][j];
				ans.v[i][j] %= oo;
			}
		}
	}
	return ans;
}

Matrix power(Matrix m, int n) {
	Matrix res(26, 26, 0);
	fto (i, 0, 25) res.v[i][i] = 1;
	while (n) {
		if (n%2) res = res*m;
		n /= 2;
		m = m*m;
	}
	return res;
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	Matrix m(26, 26, 0);

	fto (i, 0, 25) {
		fto (j, 0, 25) cin >> m.v[i][j];
	}
	int test;
	cin >> test;
	while (test--) {
		char c;
		int l;
		cin >> c >> l;
		Matrix t(1, 26, 1);
		t = t*power(m, l-1);
		bug(t.v[0][c-'a']);
	}

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}