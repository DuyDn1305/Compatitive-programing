
#include <bits/stdc++.h>

#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fto1(i, a, b) for (int i = a; i < b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define ff first
#define ss second
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define ll long long
#define pi = 3.1415926535897
#define oo 1000000007
#define OO 1000000000000000007
#define glen(x) ((int)x.size())
#define bitSize(x) ((int) __builtin_popcount(x))


using namespace std;

string l[4];
int a[10][4];
int t[10];

int conv(int x, int y, string s) {
    int base = 1;
    int res = 0;
    fdto(i, y, x) {
        res += base*(s[i]-'0');
        base *= 10;
    }
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("resPredictor.inp", "r", stdin);
        freopen("resPredictor.out", "w", stdout);
    #endif // ONLINE_JUDGE

    int n;
    scanf("%d", &n);
    l[0] = "wood";
    l[1] = "clay";
    l[2] = "iron";
    l[3] = "wheat";
    fto(i, 1, n) {
        scanf("%d%d%d%d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
        string s;
        cin >> s;
        t[i] += conv(0, 1, s)*60*60;
        t[i] += conv(3, 4, s)*60;
        t[i] += conv(6, 7, s);
    }

    int x, y;
    while (cin >> x) {
        cin >> y;
        int deltaT = t[y]-t[x];
        while (deltaT < 0) deltaT += 3600*24;
        printf("%d->%d:\n| ", x, y);
        fto(i, 0, 3) {
            int deltaM = a[y][i] - a[x][i];
            cout << l[i] << ": ";
            printf("%.2f | ", 3600.0*deltaM/deltaT);
        }
        puts("");
    }

    return 0;
}
