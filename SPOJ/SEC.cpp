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

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL

struct trie {
	int child[2];
	int eow;
	trie() {
		eow = 0;
		child[0] = child[1] = -1;
	}
};

int f[500005];
vector <trie> a(1);

void add(bool b[], int &k) {
	int root = 0;
	fto1(i, 0, k) {
		if (a[root].child[b[i]] == -1) {
			root = a[root].child[b[i]] = sz(a);
			a.pb(trie());
		}
		else {
			root = a[root].child[b[i]];
		}
	}
	++a[root].eow;
}

void calc(int u) {
	int res = a[u].eow;
	fto(tmp, 0, 1) {
		int v = a[u].child[tmp];
		if (v != -1) {
			calc(v);
			res += f[v];
		}
	}
	f[u] = res;
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	fto(i, 1, n) {
		int k;
		cin >> k;
		bool bits[k];
		fto1(j, 0, k) cin >> bits[j];
		add(bits, k);
	}
	calc(0);
	fto(i, 1, m) {
		int k;
		cin >> k;
		bool bits[k];
		fto1(j, 0, k) cin >> bits[j];
		int root = 0;
		int ans = 0;
		fto1(j, 0, k) {
			int newRoot = a[root].child[bits[j]];
			if (newRoot != -1) {
				root = newRoot;
				ans += a[root].eow;
				if (j == k-1) ans += f[root]-a[root].eow;
			}
			else {
				break;
			}
		}
		cout << ans << endl;
	}

    #ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}
