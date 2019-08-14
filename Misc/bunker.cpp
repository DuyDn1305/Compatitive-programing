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

int r, n;
double a[105];
pair <double, double> v[105];
double pi = 3.1415926535897;


int main() {
//    #ifndef ONLINE_JUDGE
//        freopen("codef.inp", "r", stdin);
//        freopen("codef.out", "w", stdout);
//    #endif // ONLINE_JUDGE
    scanf("%d%d", &r, &n);
    fto(i, 1, n) cin >> a[i];
    double ans = oo;
    sort(a+1, a+1+n);
    fto(i, 1, n) {
        double t = 0;
        fto(j, 1, i) {
            if (a[i] < 360-a[i]) t += a[i];
            else {
                t -= 360-a[i];
            }
        }
        t /= i;
        double res = 0;
        fto(j, 1, n) {
            res += pi*2*r*(min(abs(t-a[j]), abs(360-a[j]+t))/360.0);
        }
        ans = min(ans, res);
    }
    printf("%.3f", ans);
    return 0;
}
