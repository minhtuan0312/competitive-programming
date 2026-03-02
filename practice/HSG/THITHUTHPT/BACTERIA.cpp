#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;
#define bit(mask, i) ((mask >> i) & 1)
#define ll long long
#define nl '\n'
#define all(x) x.begin(), x.end()
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define FORd(i, a, n) for (int i = n - 1; i >= a; i--)
#define minhtuan0312 ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
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


typedef pair<ll, ll> ii;
ll n, m, C;
const int limN = 1e6 + 5;
int lp[limN];
ll dist[limN];
ii trace[limN];
vector<int> primes;
void init() {
    FOR(i, 2, limN) {
        if(!lp[i]) {
            lp[i] = i;
            primes.eb(i);
        }
        for(int j = 0; j < sz(primes) && i * primes[j] < limN; j++) {
            lp[i * primes[j]] = primes[j];
            if(lp[i] == primes[j]) break;
        }
    }
}

vector<ii> prime_factorization(ll n) {
    vector<ii> res;
    while(n > 1) {
        ll p = lp[n];
        ll e = 0;
        while(n % p == 0) {
            e++;
            n /= p;
        }
        res.pb({p, e});
    }
    return res;
}

int main(void) {
    minhtuan0312;

    #define TASK "BACTERIA"
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    memset(dist, -1, sizeof dist);
    init();
    cin >> n >> m >> C;
    queue<ll> qu;
    qu.push(n);
    trace[n] = {-1, -1};
    dist[n] = 0;
    while(!qu.empty()) {
        int u = qu.front(); qu.pop();
        if (u == m) {
            cout << dist[u] << nl;
            ii last = {u, -1};
            vector<int> res;
            while(last.fi != -1) {
                if(last.se != -1) res.eb(last.se);
                last = trace[last.fi];
            }
            reverse(all(res));
            for(int &v: res) cout << v << ' ';
            return 0;
        }
        for(auto [p, e]: prime_factorization(u)) {
            if(p > C) break;
            if(dist[u / p] == -1) {
                dist[u / p] = dist[u] + 1;
                trace[u / p] = {u, p};
                qu.push(u / p);
            }
        }
        if((u * u) <= C && dist[u * u] == -1) {
            dist[u * u] = dist[u] + 1;
            trace[u * u] = {u, 0};
            qu.push(u * u);
        }
    }
    cout << "Impossible";

    return (0 ^ 0);

}

// thou art fair
