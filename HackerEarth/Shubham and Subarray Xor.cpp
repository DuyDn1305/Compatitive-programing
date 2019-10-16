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
	bool eon;
	int child[2];
	trie() {
		eon = 0;
		child[0] = child[1] = -1;
	}
};
 
int n;
int f[1005];
vector <trie> a(1);
 
 
void add(int x) {
	bitset<20> m(x);
	int root = 0;
	fdto(i, 19, 0) {
		if (a[root].child[m[i]] != -1) {
			root = a[root].child[m[i]];
		}
		else {
			root = a[root].child[m[i]] = sz(a);
			a.pb(trie());
		}
	}
	a[root].eon = 1;
	return;
}
 
int get (int x) {
	bitset<20> m(x);
	int root = 0;
	int ans = 0;
	fdto(i, 19, 0) {
		if (a[root].child[1-m[i]] != -1) {
			root = a[root].child[1-m[i]];
			ans |= (1<<i);
		}
		else root = a[root].child[m[i]];
	}
	return ans;
}
 
int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	fto(i, 1, n) {
		int x;
		cin >> x;
		f[i] = f[i-1]+x;
	}
 
	int ans = 0;
	add(f[1]);
	fto(i, 2, n) {
		fto(j, i, n) {
			ans = max(ans, get(f[j]-f[i-1]));
		}
		fto(j, 1, i) add(f[i]-f[j-1]);
	}
	cout << ans << endl;
 
	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}