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

int n, m, d, r;
struct edge{
    int w, u, v, type;
//    0: khong bi hong
//    1: normal bi hong
//    2: special bi hong
};
vector<edge> edges;

struct disjoint_set_union{
    int n;
    vector<int> parent, sz;
    disjoint_set_union() {}
    disjoint_set_union(int n) : n(n), parent(n + 1) {
        sz.assign(n + 1, 1);
        FOR(i, 1, n + 1) parent[i] = i;
    }
    int Find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = Find(parent[u]);
    }
    bool Unite(int u, int v) {
        u = Find(u);
        v = Find(v);
        if (u == v) return 0;
        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        parent[v] = u;
        return 1;
    }
};

ll kruskal() {
    sort(all(edges), [&](const edge&x, const edge&y) {
         return x.type == y.type? x.w < y.w : x.type < y.type;
         });
    disjoint_set_union dsu(n);
    vector<edge> mst;
    ll d = 0;
    FOR(i, 0, m) {
        if(sz(mst) == n - 1) break;
        if(dsu.Unite(edges[i].u, edges[i].v)) {
            if(edges[i].type > 0) {
                d += edges[i].w;
            }
            mst.pb(edges[i]);
        }
    }
    return d;

}

int main(void) {
    minhtuan0312;

    #define TASK "cau2"
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    cin >> n >> m >> d >> r;
    FOR(i, 1, m + 1) {
        int u, v, w; cin >> u >> v >> w;
        edges.pb({w, u, v, 0});
    }
    FOR(i, 1, d + 1) {
        int u; cin >> u;
        edges[--u].type = 1;
    }
    FOR(i, 1, r + 1) {
        int u; cin >> u;
        edges[--u].type = 2;
    }

    cout << kruskal();

    return (0 ^ 0);

}

// thou art fair
