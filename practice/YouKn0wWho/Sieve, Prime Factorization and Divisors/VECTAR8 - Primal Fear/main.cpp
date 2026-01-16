#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;
#define ll long long
#define nl '\n'
#define all(x) x.begin(), x.end()
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define FORd(i, a, n) for (int i = n - 1; i >= a; i--)
#define minhtuan0312 ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define sz(x) size(x)
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

const int limN = 1e6 + 5;
bitset<limN> isPrime = bitset<limN>().set();
vector<int> primes;


bool isAfraidNumber(int n) {

    int tmp = n;
    while(tmp) {
        if(tmp % 10 == 0) return 0;
        tmp /= 10;
    }

    tmp = n;
    int p = 1;
    while(p <= n) p *= 10;
    p /= 10;
    while(p >= 10) {
        if(!isPrime[tmp % p]) return 0;
        p /= 10;
    }

    return 1;

}


void sieve() {
    isPrime[0] = isPrime[1] = 0;
    int sq = sqrt(limN);
    for(int i = 2; i <= sq; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j <= limN; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    for(int i = 2; i <= limN; i++) {
        if(isPrime[i] && isAfraidNumber(i)) primes.pb(i);
    }
}

int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    sieve();

    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        cout << upper_bound(all(primes), x) - primes.begin() << nl;
    }

    return (0 ^ 0);

}

// study smart, not hard
