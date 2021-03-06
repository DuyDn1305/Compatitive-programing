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
	bool eow;
	int child[26];
	trie() {
		eow = 0;
		fto(i, 0, 25) child[i] = -1;
	}
};

vector <trie> a(1);
int f[int(3e5+5)];

void add(string &x) {
	int root = 0;
	fto1(i, 0, sz(x)) {
		int c = x[i]-'a';
		if (a[root].child[c] != -1) {
			root = a[root].child[c];
		}
		else {
			root = a[root].child[c] = sz(a);
			a.pb(trie());
		}
	}
	a[root].eow = 1;
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m;
	string s;
	cin >> s;
	n = sz(s);
	s = "@"+s;
	cin >> m;
	while (m--) {
		string x;
		cin >> x;
		add(x);
	}

	f[0] = 1;
	fto1(i, 0, n) {
		int root = 0;
		fto(j, i+1, min(i+100, n)) {
			int c = s[j]-'a';
			if (a[root].child[c] == -1) break;
			root = a[root].child[c];
			if (a[root].eow) f[j] = (f[j]+f[i])%1337377;
		}
	}

	cout << f[n] << endl;

    #ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}
