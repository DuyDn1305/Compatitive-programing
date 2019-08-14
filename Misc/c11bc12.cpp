#include <bits/stdc++.h>

#define fto(i, a, b) for(int i = a; i <= b; ++i)
#define fdto(i, a, b) for(int i = a; i >= b; --i)
#define ff first
#define ss second
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define pb push_back
#define oo 1000000007
#define OO 1000000000000000007

using namespace std;

int n, m;
int pSet[10005];

void initSet(int l, int r) {fto(i, l, r) pSet[i] = i;}

int findSet(int x) {return (x == pSet[x]) ? x : findSet(pSet[x]);}

void unionSet(int x, int y) {pSet[findSet(x)] = findSet(y);}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("c11bc2.inp", "r", stdin);
        freopen("c11bc2.out", "w", stdout);
    #endif // ONLINE_JUDGE
    scanf("%d%d", &n, &m);
    initSet(1, n);
    fto(i, 2, n) {
        int u, k;
        scanf("%d%d", &u, &k);
        if (k == 1) unionSet(i, u);
    }
    fto(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (findSet(u) == findSet(v)) puts("NO");
        else puts("YES");
    }
}
///12436
