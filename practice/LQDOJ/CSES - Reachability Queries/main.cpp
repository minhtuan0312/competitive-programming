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

int n, m, q;
const int limN = 5e4 + 5;
vector<int> adj[limN];

int timer = 0;
int disc[limN], low[limN];
stack<int> st;
bool onStack[limN];
int scc = 0;
int scc_id[limN];

void dfs(int u) {
    disc[u] = low[u] = ++timer;
    st.push(u);
    onStack[u] = 1;
    for(const int &v: adj[u]) {
        if(!disc[v]) {
            dfs(v);
            minimize(low[u], low[v]);
        } else if(onStack[v]) {
            minimize(low[u], disc[v]);
        }
    }
    if(disc[u] == low[u]) {
        scc++;
        while(1) {
            int v = st.top(); st.pop();
            scc_id[v] = scc;
            onStack[v] = 0;
            if(u == v) break;
        }
    }
}

vector<int> dag[limN];
bitset<limN> reach[limN];

int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    cin >> n >> m >> q;
    FOR(i, 1, m + 1) {
        int u, v; cin >> u >> v;
        adj[u].eb(v);
    }

    FOR(u, 1, n + 1) {
        if(!disc[u]) dfs(u);
    }

    FOR(u, 1, n + 1) {
        if(!scc_id[u]) continue;
        for(const int &v: adj[u]) {
            if(scc_id[v] && scc_id[u] != scc_id[v]) {
                dag[scc_id[u]].eb(scc_id[v]);
            }
        }
    }

    FOR(u, 1, scc + 1) { // topo ngược
        reach[u][u] = 1; // u đi được đến chính nó
        for(const int &v: dag[u]) {
            reach[u] |= reach[v];
        }
    }

    while(q--) {
        int u, v; cin >> u >> v;
        u = scc_id[u];
        v = scc_id[v];
        cout << (reach[u][v] ? "YES": "NO") << nl;
    }


    return (0 ^ 0);

}

// thou art fair
