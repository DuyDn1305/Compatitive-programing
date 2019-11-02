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
#define oo 1000000000
#define OO 1000000000000000003LL

struct Matrix {
	ll v[10][10];
	Matrix() {
		fto1 (i, 0, 10) fto1 (j, 0, 10) v[i][j] = 0;
	}
};

Matrix operator * (Matrix a, Matrix b) {
	Matrix ans;
	fto1 (i, 0, 10) {
		fto1 (j, 0, 10) {
			fto1 (k, 0, 10) {
				ans.v[i][j] += a.v[i][k]*b.v[k][j];
				ans.v[i][j] %= oo;
			}
		}
	}
	return ans;
}

ll a[105];
ll b[105];

Matrix power(Matrix x, int n) {
	Matrix res;
	fto1 (i, 0, 10) res.v[i][i] = 1;
	while (n) {
		if (n%2) res = res*x;
		n /= 2;
		x = x*x;
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
		int k, n;
		cin >> k;
		fto (i, 1, k) cin >> a[i];
		fto (i, 1, k) cin >> b[k-i+1];
		fto1 (i, k+1, k*2) {
			ll res = 0;
			int first = i-k-1;
			fto (j, 1, k) {
				res += b[j]*a[first+j];
				res %= oo;
			}
			a[i] = res;
		}
		//fto (i, 1, 2*k) bug(a[i]);
		cin >> n;
		if (n < 2*k) bug(a[n]);
		else {
			Matrix c;
			fto1 (i, 0, k) {
				fto1 (j, 0, k) {
					c.v[i][j] = a[i+j+1];
				}
			}
			Matrix d;
			fto1 (i, 1, k) {
				d.v[i][i-1] = 1;
			}
			fto1 (i, 0, k) d.v[i][k-1] = b[i+1];
			Matrix ans = c*power(d, n-(2*k-1));
			bug(ans.v[k-1][k-1]);
		}
	}

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}