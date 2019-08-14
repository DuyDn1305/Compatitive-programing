#include <bits/stdc++.h>

#define fto(i, a, b) for(int i = a; i <= b; ++i)
#define fdto(i, a, b) for(int i = a; i >= b; --i)
#define ff first
#define ss second
#define ll long long
#define ull unsigned long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define pb push_back
#define oo 1000000007
#define OO 1000000000000000007

using namespace std;

int n, m, yes, no;
int pSet[1000005];

void initSet(int l) {
    fto(i, 1, l) pSet[i] = i;
}

int findSet(int i) {
    return (pSet[i] == i) ? i : (pSet[i] = findSet(pSet[i]));
}

void unionSet(int i, int j) {
    int x = findSet(i);
    int y = findSet(j);
    if (x == y) return;
    pSet[x] = y;
    return;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("network2.inp", "r", stdin);
        freopen("network2.out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d\n", &n, &m);
    initSet(n);
    fto(i, 1, m) {
        char c;
        int u, v;
        scanf("%c%d%d\n", &c, &u, &v);
        if (c == 'c') unionSet(u, v);
        else {
            if (findSet(u) == findSet(v)) ++yes;
            else ++no;
        }
    }
    printf("%d %d\n", yes, no);
    return 0;
}
