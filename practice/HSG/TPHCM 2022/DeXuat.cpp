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
inline bool minimize(T &x, const T &y) {
    if (x > y) return x = y, 1;
    return 0;
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
ll n, m, k, s, t;
const ll limN = 1e4 + 5;
vector<ii> adj[limN], rev_adj[limN];
ll dist_s[limN], dist_t[limN];
void dijkstra(ll s, ll dist[]) {
    fill(dist + 1, dist + 1 + n, LLONG_MAX);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;
        for(const auto [v, w]: adj[u]) {
            if(minimize(dist[v], w + d)) {
                pq.push({w + d, v});
            }
        }
    }
}

void dijkstra_rev(ll s, ll dist[]) {
    fill(dist + 1, dist + 1 + n, LLONG_MAX);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;
        for(const auto [v, w]: rev_adj[u]) {
            if(minimize(dist[v], w + d)) {
                pq.push({w + d, v});
            }
        }
    }
}

int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    cin >> n >> m >> k >> s >> t;
    FOR(i, 1, m + 1) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].eb(v, w);
        rev_adj[v].eb(u, w);
    }

    dijkstra(s, dist_s);
    dijkstra_rev(t, dist_t);
    ll st = dist_s[t];
    ll best = LLONG_MAX;
    FOR(i, 1, k + 1) {
        ll u, v, w; cin >> u >> v >> w;
        if(dist_s[u] != LLONG_MAX && dist_t[v] != LLONG_MAX) {
            minimize(best, dist_s[u] + dist_t[v] + w);
        }
        if(dist_s[v] != LLONG_MAX && dist_t[u] != LLONG_MAX) {
            minimize(best, dist_s[v] + dist_t[u] + w);
        }
    }
    ll res = min(best, st);
    cout << (res == LLONG_MAX? -1: res);
    return (0 ^ 0);

}

// thou art fair
