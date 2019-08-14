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

int n;
int a[15];
int trace[10005];
int f[1005];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("tacxi.in", "r", stdin);
        freopen("tacxi.out", "w", stdout);
    #endif // ONLINE_JUDGE

    fto(i, 1, 10) scanf("%d", &a[i]);
    scanf("%d", &n);

    queue <int> q;
    q.push(0);

    fto(i, 1, n) f[i] = oo;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        fto(i, 1, 10) {
            int v = u+i;
            if (f[v] > f[u]+a[i]) {
                f[v] = f[u]+a[i];
                trace[v] = i;
                q.push(v);
            }
        }
    }

    int cur = n;
    while (cur) {
        printf("%d %d\n", trace[cur], a[trace[cur]]);
        cur -= trace[cur];
    }

    printf("%d\n", f[n]);

    return 0;
}
