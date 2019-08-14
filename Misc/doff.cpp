/usr/bin/g++ -DEVAL -static -O2 -std=c++11 -o DOFF DOFF.cpp
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

int main() {

    #ifndef ONLINE_JUDGE
        freopen("doff.inp", "r", stdin);
        freopen("doff.out", "w", stdout);
    #endif // ONLINE_JUDGE
    int n;
    scanf("%d", &n);
    int x = (n/7)*2;
    int y = n%7;
    printf("%d %d\n", x+max(y-5, 0), x+min(2, y));
    return 0;
}
/// 362
