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

int n, ans;
int a[30005];
int h[30005];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("vector2.inp", "r", stdin);
        freopen("vector2.out", "w", stdout);
    #endif // ONLINE_JUDGE
    scanf("%d", &n);
    fto(i, 1, n) {
        scanf("%d", &a[i]);
    }
    int ans = 1;
    h[1] = a[1];
    h[0] = -oo;
    fto(i, 2, n) {
        if (a[i] > h[ans]) {
            ++ans;
            h[ans] = a[i];
            continue;
        }
        if (a[i] < h[ans] && a[i] > h[ans-1]) {
            h[ans] = a[i];
            continue;
        }
        else {
            int left = 0;
            int right = ans;
            while (left < right-1) {
                int mid = (left+right)/2;
                if (a[i] < h[mid] && a[i] > h[mid-1]) {
                    h[mid] = a[i];
                    break;
                }
                if (a[i] > h[mid]) left = mid;
                else right = mid;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
/// 362
