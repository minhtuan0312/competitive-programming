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

int n, m;
const int limN = 105;
struct Edge{
    int u, v;
    ll w;
};
typedef pair<ll, ll> ii;
vector<ii> adj[limN];
ll dist[limN], trace[limN];
void dijkstra(int s) {
    FOR(i, 1, n + 1) {
        dist[i] = LLONG_MAX;
        trace[i] = -1;
    }
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;
        for(const auto &[v, w]: adj[u]) {
            if(minimize(dist[v], d + w)){
                trace[v] = u;
                pq.push({d + w, v});
            }
        }
    }
}

int main(void) {
    minhtuan0312;

    #define TASK "RBLOCK"
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    cin >> n >> m;
    vector<Edge> edges;
    FOR(i, 1, m + 1) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
        edges.pb({u, v, w});
    }

    dijkstra(1);

    ll og = dist[n];
    int last = n;
    vector<ii> roads;
    while(last != 1) {
        roads.eb(trace[last], last);
        last = trace[last];
    }
    ll res = 0;
    for(const auto&[u, v]: roads) {

        ll old_w = 0;
        for(auto &e: adj[u]) {
            if(e.fi == v) {
                old_w = e.se;
                e.se *= 2;
                break;
            }
        }
        for(auto &e: adj[v]) {
            if(e.fi == u) {
                e.se *= 2;
                break;
            }
        }
        dijkstra(1);
        ll new_dist = dist[n];
        if(new_dist != LLONG_MAX) {
            maximize(res, new_dist - og);
        }
        for(auto &e: adj[u]) {
            if(e.fi == v) {
                e.se = old_w;
                break;
            }
        }
        for(auto &e: adj[v]) {
            if(e.fi == u) {
                e.se = old_w;
                break;
            }
        }
    }

    cout << res;

    return (0 ^ 0);

}

// thou art fair
