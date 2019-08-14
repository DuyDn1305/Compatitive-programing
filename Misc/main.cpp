#include <bits/stdc++.h>

using namespace std;

#define fto(i, s, e) for (int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for (int i = (s); i < (e); ++i)
#define fdto(i, s, e) for (int i = (s); i >= (e); --i)
#define fit(var, it) for (auto it = (var).begin(); it != (var).end(); ++it)
#define frit(var, it) for (auto it = (var).rbegin(); it != (var).rend(); ++it)

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

char* sfm(const char *fmt, ...) {
	static char res[256];va_list args;va_start(args, fmt);vsnprintf(res, 256, fmt, args);va_end(args);return res;
}

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 100005
#define pll pair<ll, ll>

struct node {
    int val;
    node *left, *right;
};

int a[maxn];
int b[maxn];
node * root[maxn];

node * update(node * root, int l, int r, int k) {
    if (k > r || k < l) return root;
    int mid = (l+r)/2;
    node * newroot = new node({root->val+1, nullptr, nullptr});
    if (l < r) {
        newroot->left = update(root->left, l, mid, k);
        newroot->right = update(root->right, mid+1, r, k);
    }
    return newroot;
}

int query(node * root1, node * root2, int l, int r, int k) {
    if (l == r) return l;
    int cnt = root2->left->val-root1->left->val;
    int mid = (l+r)/2;
    if (cnt >= k) {
        return query(root1->left, root2->left, l, mid, k);
    }
    return query(root1->right, root2->right, mid+1, r, k-cnt);
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    fto(i, 1, n) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b+1, b+1+n);

    root[0] = new node();
    root[0]->val = 0;
    root[0]->left = root[0]->right = root[0];

    fto(i, 1, n) root[i] = update(root[i-1], 1, n, lower_bound(b+1, b+1+n, a[i])-b);

    while (q--) {
        int ql, qr, k;
        cin >> ql >> qr >> k;
        cout << b[query(root[ql-1], root[qr], 1, n, k)] << endl;
    }

    #ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}
