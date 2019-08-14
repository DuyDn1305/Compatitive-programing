#include <bits/stdc++.h>

#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define pii pair <int, int>
#define pll pair <long long, long long>
#define ss second
#define ff first
#define mp make_pair
#define pb push_back
#define ll long long
#define oo 1000000007
#define OO 1000000000000000007

using namespace std;

int n;
int a[200005];
int b[200005];

int main() {
    freopen("wagons.inp", "r", stdin);
    freopen("wagons.out", "w", stdout);
    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);
    fto(i, 1, n) scanf("%d", &b[i]);
    bool ok = 1;
    fto(i, 1, n) if (a[i] != b[i]) ok = 0;
    cout << ok << endl;
    return 0;
}
