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

struct trie {
	int child[2];
	trie() {
		child[0] = child[1] = -1;
	}
};

vector <trie> node;
int n, m;
int f[10005][25];
int a[10005][25];

void add(int x) {
	int root = 0;
	fdto(i, 26, 0) {
		bool bit = onb(x, i);
		if (node[root].child[bit] == -1) {
			node[root].child[bit] = sz(node);
			node.pb(trie());
		}
		root = node[root].child[bit]; 
	}
}

int get(int x) {
	int root = 0, res = 0;
	fdto(i, 26, 0) {
		bool bit = onb(x, i)^1;
		if (node[root].child[bit] == -1) bit ^= 1;
		else res |= 1<<i;
		root = node[root].child[bit];
	}
	return res;
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	fto(i, 1, n) {
		fto(j, 1, m) {
			cin >> a[i][j];
			f[i][j] = f[i][j-1]^a[i][j];
		}
	}

	int ans = 0;
	fto(l, 1, m) {
		fto(r, l, m) {
			node.clear();
			node.pb(trie());
			add(0);
			int cur = 0;
 			fto(i, 1, n) {
				cur ^= f[i][r]^f[i][l-1];
				ans = max(ans, get(cur));
				add(cur);
			}
		}
	}
	cout << ans << endl;

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}

