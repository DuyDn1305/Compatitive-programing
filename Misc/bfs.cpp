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
vector <int> a[100005];
bool visit[100005];
int trace[100005];

void bfs(int s) {
    queue <int> q;
    q.push(s);
    visit[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        fto(i, 0, (int)a[u].size()-1) {
            int v = a[u][i];
            if (!visit[v]) {
                visit[v] = 1;
                q.push(v);
                trace[v] = u;
            }
        }
    }
    return;
}

void out(int t) {
    vector <int> ans;
    int cur = t;
    while (cur) {
        ans.pb(cur);
        cur = trace[cur];
    }
    fdto(i, (int)ans.size()-1, 0) printf("%d ", ans[i]);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("bfs.inp", "r", stdin);
        freopen("bfs.out", "w", stdout);
    #endif // ONLINE_JUDGE
    int s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    fto(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u].pb(v);
    }
    fto(i, 1, n) sort(a[i].begin(), a[i].end());
    bfs(s);
    out(t);
    return 0;
}
///12436

