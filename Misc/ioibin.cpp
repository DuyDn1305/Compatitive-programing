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

int n;
int pSet[10005];

void buildSet(int l, int r) {fto(i, l, r) pSet[i] = i;}

int findSet(int x) {
    return pSet[x] = (x == pSet[x]) ? x : findSet(pSet[x]);
}

void unionSet(int x, int y) {
    pSet[findSet(x)] = findSet(y); return;
}


int main() {
    #ifndef ONLINE_JUDGE
        freopen("ioibin.inp", "r", stdin);
        freopen("ioibin.out", "w", stdout);
    #endif // ONLINE_JUDGE
    int q;
    scanf("%d", &q);
    buildSet(1, 10000);
    fto(i, 1, q) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (z == 1) unionSet(x, y);
        else printf("%d\n", (findSet(x) == findSet(y)));
    }
    return 0;
}
///12436
