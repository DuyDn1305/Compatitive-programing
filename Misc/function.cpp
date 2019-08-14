#include <bits/stdc++.h>

#define fto(i, a, b) for (int i = a; i <= b; ++i)

#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define ff first
#define ss second
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define ll long long
#define oo 1000000007
#define OO 1000000000000000007

using namespace std;

int main() {
//    #ifndef ONLINE_JUDGE
//        freopen("codef.inp", "r", stdin);
//        freopen("codef.out", "w", stdout);
//    #endif // ONLINE_JUDGE
    int n;
    scanf("%d", &n);
    fto(i, 1, n) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        printf("%d\n", max(abs(a-b), abs(b-c))-1);
    }
    return 0;
}
