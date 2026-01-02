#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;
#define ll long long
#define nl '\n'
#define all(x) x.begin(), x.end()
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define FORd(i, a, n) for (int i = n - 1; i >= a; i--)
#define minhtuan0312 ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define sz(x) ((int)(x).size())
#define pb push_back
#define fi first
#define se second

const ll mod = 1e9 + 7;

template<class T>
void maximize(T &x, const T &y) {
    if (x < y) x = y;
}

template<class T>
void minimize(T &x, const T &y) {
    if (x > y) x = y;
}

template<typename T1, typename T2>
void __print(const pair<T1, T2> &p);

template<typename T, typename... V>
void __print(const vector<T, V...> &v);

template<typename T1, typename T2, typename... V>
void __print(const map<T1, T2, V...> &m);

template<typename T>
void __print(const T &x) {cerr << x;}

template<typename T1, typename T2>
void __print(const pair<T1, T2> &p) {
    cerr << '(';
    __print(p.fi);
    cerr << ", ";
    __print(p.se);
    cerr << ')';
}

template<typename T, typename... V>
void __print(const vector<T, V...> &v) {
    cerr << '[';
    FOR(i, 0, sz(v)) {
        if(i) cerr << ", ";
        __print(v[i]);
    }
    cerr << ']';
}

template<typename T1, typename T2, typename... V>
void __print(const map<T1, T2, V...> &m) {
    cerr << '{';
    bool first = 1;
    for(const auto &x: m) {
        if(!first) cerr << ", ";
        first = 0;
        __print(x);
    }
    cerr << '}';
}

template<typename T>
void _print(T t) { __print(t);}
void _print() {}
template<typename T, typename... V>
void _print(T t, V... v) {__print(t); if(sizeof...(v)) cerr << ", "; _print(v...); }

#ifdef LOCAL
#define deb(...) do {\
    cerr << "[In " <<  __func__ << "(): line " << __LINE__ << "] [" << #__VA_ARGS__ << "] = [";\
    _print(__VA_ARGS__);\
    cerr << ']' << nl;\
} while(0);
#else
#define deb(...)
#endif

const int limN = 2e5 + 5;
ll f[limN], inv[limN];

ll bin_pow(ll a, ll b, ll m) {
    ll res = 1;
    a = a % m;
    while(b) {
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void init() {
    f[0] = 1;
    FOR(i, 1, limN) f[i] = f[i - 1] * i % mod;
    FOR(i, 0, limN) inv[i] = bin_pow(f[i], mod - 2, mod);
}

ll combination(ll k, ll n) {
    if(k > n) return 0;
    return f[n] * inv[k] % mod * inv[n - k] % mod;
}

pair<int, int> p[limN];
int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    init();

    int n, m, k; cin >> n >> m >> k;
    FOR(i, 1, k + 1) cin >> p[i].fi >> p[i].se;

    sort(p + 1, p + 1 + k, [&](const pair<int, int> &x, const pair<int, int> &y) {
         return x.fi == y.fi ? x.se < y.se : x.fi < y.fi;
         });

    ll dp[k + 1]; // dp[i] số cách để đi đến vật cản i mà không đi qua các vật cản trước đó
    FOR(i, 1, k + 1){ // vật cản sau
        dp[i] = combination(p[i].fi - 1, p[i].fi + p[i].se - 2);
        FOR(j, 1, i) { // vật cản trước
            if(p[j].fi <= p[i].fi && p[j].se <= p[i].se) {
                int x = p[i].fi - p[j].fi;
                int y = p[i].se - p[j].se;
                dp[i] -= dp[j] * combination(x, x + y) % mod;
                dp[i] %= mod;
                dp[i] += mod;
                dp[i] %= mod;
            }
        }
    }
    ll res = combination(n - 1, n + m - 2);
    FOR(i, 1, k + 1) {
        int x = n - p[i].fi;
        int y = m - p[i].se;
        res -= dp[i] * combination(x, x + y) % mod;
        res %= mod;
        res += mod;
        res %= mod;
    }
    cout << res;

    return (0 ^ 0);

}

// thou art fair
