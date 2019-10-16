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
	int cnt;
	int child[26];
	trie() {
		cnt = 0;
		fto1 (i, 0, 26) child[i] = -1;
	}
};
 
vector<trie> node(1);
string a[1000005];
ll f[1000005];
 
void add(string &x) {
	int root = 0;
	fto1 (i, 0, sz(x)) {
		int c = x[i]-'a';
		if (node[root].child[c] == -1) {
			node[root].child[c] = sz(node);
			node.pb(trie());
		}
		root = node[root].child[c];
		++node[root].cnt;
	}
	return;
}
 
int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n;
	int mx = 0;
	cin >> n;
	fto(i, 1, n) cin >> a[i];
	sort(a+1, a+1+n, [](string &l, string &r) {return sz(l)>sz(r);});
	fto (i, 1, n) {
		mx = max(mx, sz(a[i]));
		int root = 0;
		fto (l, 0, sz(a[i])) {
			if (l == sz(a[i])) {
				f[l] += node[root].cnt;
				continue;
			}
			int c = a[i][l]-'a';
			fto1 (tmp, 0, 26) if (tmp != c) 
				if (node[root].child[tmp] != -1) {
					int down = node[root].child[tmp];
					f[l] += node[down].cnt;
				}
			root = node[root].child[c];
			if (root == -1) break; 
		}
		add(a[i]);
	}
 
	fto (i, 0, mx) cout << f[i] << " ";
 
	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}