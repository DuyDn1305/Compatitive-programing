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
#define maxn 200005
#define pll pair<ll, ll>

struct node {
    int val;
    int lid, rid;
};

int n, q;
int a[maxn], b[maxn], root[maxn], depth[maxn];
int f[maxn][21];
vector <int> ke[maxn];
vector <node> st;

int LCA(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    int d = depth[v]-depth[u];
    fto(i, 0, 20) if (d&(1<<i)) v = f[v][i];
    if (u == v) return u;
    fdto(i, 20, 0) {
        if (f[u][i] != f[v][i]) {
            u = f[u][i];
            v = f[v][i];
        }
    }
    return f[u][0];
}

int update(int id, int l, int r, int k) {
    if (k > r || k < l) return id;
    node p = st[id];
    int mid = (l+r)/2;
    node newp = node({p.val+1, 0, 0});
    if (l < r) {
        newp.lid = update(p.lid, l, mid, k);
        newp.rid = update(p.rid, mid+1, r, k);
    }
    st.push_back(newp);
    return sz(st)-1;
}

int get(node u, node v, node x, node p, int l, int r, int k) {
    int cnt = st[u.lid].val+st[v.lid].val-st[x.lid].val-st[p.lid].val;
    if (l == r) return l;
    int mid = (l+r)/2;
    if (cnt >= k) return get(st[u.lid], st[v.lid], st[x.lid], st[p.lid], l, mid, k);
    return get(st[u.rid], st[v.rid], st[x.rid], st[p.rid], mid+1, r, k-cnt);
}

void dfs(int u, int p) {
    // LCA
    f[u][0] = p;
    fto(i, 1, 20) f[u][i] = f[f[u][i-1]][i-1];
    depth[u] = depth[p]+1;
    // IT
    root[u] = update(root[p], 1, n, lower_bound(b+1, b+1+n, a[u])-b);
    fit(ke[u], it) {
        int v = *it;
        if (v != p) {
            dfs(v, u);
        }
    }
    return;
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> q;
    fto(i, 1, n) cin >> a[i];
    fto(i, 1, n) b[i] = a[i];

    sort(b+1, b+1+n);

    fto1(i, 1, n) {
        int u, v;
        cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }

    st.push_back({0, 0, 0});
    root[0] = 0;

    dfs(1, 0);


    while (q--) {
        int u, v, k;
        cin >> u >> v >> k;
        int x = LCA(u, v);
        cout << b[get(st[root[u]], st[root[v]], st[root[x]], st[root[f[x][0]]], 1, n, k)] << endl;
    }


	return 0;
}
