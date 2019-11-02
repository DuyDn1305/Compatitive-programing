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

ll base = 111539786;

struct Matrix {
	ll a[2][2];
	Matrix(int x, int y, int z, int t) {
		a[0][0] = x;
		a[0][1] = y;
		a[1][0] = z;
		a[1][1] = t;
	}
	Matrix() {
		a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;
	}
};

Matrix operator * (Matrix const &x, Matrix const &y) {
	Matrix ans;
	fto	(i, 0, 1) {
		fto (j, 0, 1) {
			fto (k, 0, 1) {
				ans.a[i][j] += x.a[i][k]*y.a[k][j];
				ans.a[i][j] %= base;
			}
		}
	}
	return ans;
}

Matrix unit = Matrix({0, 1, 1, 1});
Matrix one = Matrix({1, 0, 0, 1});

Matrix mu(Matrix m, int n) {
	Matrix res;
	res = one;
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

	int n;
	cin >> n;
	while (n--) {
		int k;
		cin >> k; 
		Matrix res = Matrix({1, 1, 1, 2});
		if (k > 2) {
			res = res*mu(unit, k-2);
			bug(res.a[1][1]);
		} else bug(res.a[1][k-1]);
	}

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}