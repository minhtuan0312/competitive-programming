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

const int limN = 355;
int n;
int lp[limN];
vector<int> primes;

void linear_sieve() {
    FOR(i, 2, limN) {
        if(!lp[i]) {
            lp[i] = i;
            primes.emplace_back(i);
        }
        for(int j = 0; j < sz(primes) && i * primes[j] < limN; j++) {
            lp[i * primes[j]] = primes[j];
            if(i == primes[j]) break;
        }
    }
}

unsigned ll dp[limN + 1][limN + 1];
void init() {

    linear_sieve();

    memset(dp, 0, sizeof dp);

    FOR(i, 0, limN + 1) {
        dp[0][i] = 1;
    }
    FOR(i, 1, sz(primes)) {
        FOR(j, 0, limN + 1) {
            int p = 1;
            maximize(dp[i][j], dp[i - 1][j]);
            while(j - p >= 0) {
                maximize(dp[i][j], dp[i - 1][j - p] * p);
                p *= primes[i - 1];
            }
        }

    }

}

void solve() {

    cin >> n;
    cout << dp[sz(primes) - 1][n] << nl;

}

int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    init();
    int t; cin >> t;
    while(t--) {
        solve();
    }

    return (0 ^ 0);

}

// thou art fair
