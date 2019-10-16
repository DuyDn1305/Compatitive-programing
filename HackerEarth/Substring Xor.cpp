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
	int child[2];
	trie() {
		cnt = 0;
		fto1 (i, 0, 2) child[i] = -1;
	}
};

vector<trie> node(1);
int f[100005];
int n;

void add(int x) {
	int root = 0;
	fdto (i, 20, 0) {
		bool bit = onb(x, i);
		if (node[root].child[bit] == -1) {
			node[root].child[bit] = sz(node);
			node.pb(trie());
		}
		root = node[root].child[bit];
		++node[root].cnt;
	}
	return;
}

int get(int a, int c) {
	int root = 0, res = 0;
	fdto (i, 20, 0) {
		bool bitA = onb(a, i);
		bool bitC = onb(c, i);
		bool bitB = bitA^1;
		if (bitC) {
			if (node[root].child[bitB] != -1) root = node[root].child[bitB];
			else break;
		}
		else {
			if (node[root].child[bitB] != -1) res += node[node[root].child[bitB]].cnt; 
			root = node[root].child[1^bitB];
			if (!(root+1)) return res;
			// code của tao có check flag nữa đ hiểu =)))
		}
	}
	return res;
}

ll calc(int x) {
	ll res = 0;
	fto (i, 0, n) {
		res += get(f[i], x);
	}	
	return res/2;
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll k;
	cin >> n >> k;
	add(0);
	fto(i, 1, n) {
		int x;
		cin >> x;
		f[i] = f[i-1]^x;
		add(f[i]);
	}

	int l = 1, r = (1<<21)-1, ans = 0;
	--k;
	while (l <= r) {
		int mid = (l+r)>>1;
		ll cnt = calc(mid);
		//cout << mid << " " << cnt << endl;
		if (cnt <= k) {
			r = mid-1;
			ans = mid;
			// sao k đặt ans = mid ở đk dưới ?
			// đặt làm gì, kq nó cho cnt lớn mà, v sao k đặt lúc lớn mà đặt lúc nhỏ ?
			// đm nãy h kh hiểu hả :v muốn khẩu nghiệp quá :v
			// vì m đặt > nó kh xử lí được th cái kq vd như là 7 thì có nhiều con số 7, cnt nó k ra như mong đợi
			// vd như có nhiều con số 7
		} else l = mid + 1;
	}

	cout << ans << endl;

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}