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

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL

int a[5][5];

void rotate() {
	int res[5][5];
	fto(i, 1, 4) {
		fto(j, 1, 4) {
			res[i][j] = a[j][4-i+1];
		}
	}
	fto(i, 1, 4) fto(j, 1, 4) a[i][j] = res[i][j];
	return;
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int type;

	fto(i, 1, 4) fto(j, 1, 4) cin >> a[i][j];
	cin >> type;

	vector <int> res[5];

	fto(i, 1, type) rotate();

	fto(i, 1, 4) {
		fto(j, 1, 4) {
			if (!a[i][j]) continue;
			res[i].pb(a[i][j]);
			fto(k, j+1, 4) if (a[i][k]) {
				if (a[i][j] == a[i][k]) {
					res[i].back() *= 2;
					j = k;
				} else j = k-1;
				break;
			}
		}
		res[i].resize(4, 0);
	}

	fto(i, 1, 4) fto(j, 1, 4) a[i][j] = res[i][j-1];

	if (type) fto1(i, type, 4) {
		rotate();
	}

	fto(i, 1, 4) {
		fto(j, 1, 4) cout << a[i][j] << " ";
		cout << endl;
	}

	
	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}


