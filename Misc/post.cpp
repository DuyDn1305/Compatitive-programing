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

int n, m;
int a[1005];
int trace[1005];
int f[1005];
int ans[1005];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("post.in", "r", stdin);
        freopen("post.out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) scanf("%d", &a[i]);

    queue <int> q;
    q.push(0);
    f[0] = 0;
    fto(i, 1, m) f[i] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        fto(i, 1, n) {
            int v = u+a[i];
            if (f[v] != -1) continue;
            f[v] = f[u]+1;
            trace[v] = a[i];
            q.push(v);
        }
    }

    int cur = m;
    while (cur) {
        ++ans[trace[cur]];
        cur -= trace[cur];
    }

    fto(i, 1, n) printf("%d\n", ans[a[i]]);

    return 0;
}
