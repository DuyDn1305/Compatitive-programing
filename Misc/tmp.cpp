#include <bits/stdc++.h>

// limit
#define mod1 22439423LL
#define mod2 42342432LL
#define mod3 56454765LL
#define mod4 66867574LL
#define oo 1000000007
#define OO 1000000009LL
#define maxN 100009

// loop
#define fto(i, x, y) for(int i = (x); i <= (y); ++i)
#define fdto(i, x, y) for(int i = (x); i >= (y); --i)
#define ftoa(i, x, y, a) for(int i = (x); i <= (y); i += a)
#define fdtoa(i, x, y, a) for(int i = (x); i >= (y); i -= a)
#define ftosqrt(i, x, y) for(int i = (x); i*i <= (y); ++i)
#define ftoit(it, var) for (__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define fdtoit(rit, var) for (__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)

// debug
#define debug cout << "*" << endl;
#define bug1d(a, x, y) { cout << #a << ": "; fto(_, x, y) cout << a[_] << ' '; cout << endl; }
#define bug2d(a, x, y, u, v) { cout << #a << ": " << endl; fto(i, x, y) {fto(j, u, v) cout << a[i][j] << ' '; cout << endl;}; cout << endl;}
#define bug(a) cout << #a << " = " << a << endl;
#define bug2(a, b) cout << #a << " = " << a << "; "; cout << #b << " = " << b << endl;
#define bug3(a, b, c) cout << #a << " = " << a << "; "; cout << #b << " = " << b << "; "; cout << #c << " = " << c << endl;

// operation
#define mp make_pair
#define pb push_back
#define pf push_front
// structure
#define ii pair<int, int>
#define iii pair<ii, int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>
#define matrix vector<vi>

// get value
#define FF first
#define SS second

// data type
#define ll long long
#define ull unsigned long long

// function
#define lb lower_bound
#define ub upper_bound

// const value
#define pi 3.14159265358979323846264338327950288419716939937510

using namespace std;

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T min(T a, T b, T c, T d) {
    return min(a, min(b, min(c, d)));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

template <class T>
T max(T a, T b, T c, T d) {
    return max(a, max(b, max(c, d)));
}

bool cmp(const ii& a, const ii& b) {return (a.FF > b.FF || (a.FF == b.FF && a.SS >= b.SS));}
ll GCD(ll a, ll b) {return (a%b) ? GCD(b, a%b) : b;}

const string namePro = "codef";

ll power(ll n, ll k, ll mod) {
    if (n == 0LL) return 1LL;
    ll tmp = power(n/2LL, k, mod);

    if (n%2) return (((tmp*tmp)%mod)*k)%mod; // neu n le, k^n = (k^(n/2))*(k^(n/2))*k
    return (tmp*tmp)%mod;                    // neu n chan, k^n = (k^(n/2))*(k^(n/2))

    // vi du:
    // k^7 = (k^3)*(k^3)*k
    // k^8 = (k^4)*(k^4)

    // vi moi lan n lai chia cho 2 => DPT: O(logN)
}

ll solve(ll n, ll k, ll mod) {
    if (n == 0LL) return 1LL;
    if (n%2LL) {
        ll tmp = solve(n/2LL, k, mod);
        return ((power(n/2LL+1LL, k, mod)*tmp)%mod + tmp)%mod;
        // x^7 = x^4*(x^3+x^2+x+1)+x^3+x^2+x+1
    }
    else {
        ll tmp = solve(n/2LL-1LL, k, mod);
        return ((power(n/2LL+1LL, k, mod)*tmp)%mod + (k*tmp)%mod + 1LL)%mod;
        // x^6 = x^4*(x^2+x+1)+x(x^2+x+1)+1
    }
}

int main() {
    string remain = "CF round 422/ Bai thi THT/ bai anh long";

    #ifndef ONLINE_JUDGE
        freopen("codef.inp", "r", stdin);
        freopen("codef.out", "w", stdout);
    #endif // ONLINE_JUDGE

    ll x, n, m;
    scanf("%lld%lld%lld", &x, &n, &m);

    ll k = 1LL;
    while (k <= x) k *= 10LL;

    cout << (x*solve(n-1, k, m))%m << endl;
    return 0;
}
