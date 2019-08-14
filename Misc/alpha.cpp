//not complete
#include <bits/stdc++.h>

#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define ff first
#define ss second
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define ll long long
#define pi = 3.1415926535897
#define oo 1000000007
#define OO 1000000000000000007

using namespace std;

ll GCD(ll a, ll b) {return (!(a%b)) ? b : GCD(b, b%a);}

void sieve() {
    fto(i, 1, n) f[i] = i;
    fto(i, 2, 1000000) {
        if (f[i] == i) {
            for (int j = i*i; j <= 1000000; j += i) if (f[j] == j) f[j] = i;
        }
    }
    return;
}

void buildST(int node, int l, int r) {
    if (l > r) return;
    if (l == r) {
        if (l == 1) st[node] = mp(1, 1);
        else st[node] = mp(l, 0);
        return;
    }
    int mid = (left+right)/2;
    buildST(node*2, l, mid);
    buildST(node*2+1, mid+1, r);
    ll p1 = st[node*2].ff;
    ll p2 = st[node*2+1].ff;
    int q1 = st[node*2].ss;
    int q2 = st[node*2+1].ss;
    int q = GCD(q1, q2);
    ll p = nhanad(power(p1, q1/q), power(p2, q2/q));
    st[node] = mp(p, q);
}

void update(int node, int l, int r, int x, int q) {
    if (x < l || x > r) return;
    if (x == l && x == r) {
        st[node] = mp(x, q);
    }
    int mid = (left+right)/2;
    update(node*2, l, mid, x, q);
    update(node*2+1, mid+1, r, x, q);

    int q1 = st[node*2].ss; int q2 = st[node*2+1].ss; int q = GCD(q1, q2);
    ll p1 = st[node*2].ff; ll p2 = st[node*2+1].ff;
    if ()
    ll res1 = power(p1, q1/q);
    ll res2 = power(p2, q2/q);

    return st[node] = mp(p, q);
}

void process(int a, int b, int type) {
    while (a > 1) {
        int fractor = f[a];
        int d = 0;
        while (!(a%fractor)) {
            a /= fractor;
            ++d;
        }
        update(1, 1, maxN, fractor, (type == 1) ? b*d : -b*d);
    }
}

int main() {
    freopen("alpha.inp", "r", stdin);
    freopen("alpha.out", "w", stdout);

    scanf("%d%d", &M, &T);

    sieve();

    fto(i, 1, T) {
        int type;
        scanf("%d", &t);
        if (type == 1) {
            int a, b;
            scanf("%d%d", &a, &b);
            process(a, b, type);
        }
        if (type == 2) {
            int a, b;
            scanf("%d%d", &a, &b);
            process(a, b, type);
        }
        if (type == 3) {

        }
    }

    return 0;
}

