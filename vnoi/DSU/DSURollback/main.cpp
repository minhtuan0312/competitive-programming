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

struct disjoint_set_union_rollback{
    vector<int> parent, sz;
    int comps;

    vector<pair<int*, int>> st;
    disjoint_set_union_rollback() {}
    disjoint_set_union_rollback(int n) : parent(n + 1) {
        FOR(i, 1, n + 1) parent[i] = i;
        sz.assign(n + 1, 1);
        comps = n;
    }
    void Save(int &x) {
        st.eb(&x, x);
    }
    int Find(int u) {
        while(u != parent[u]) u = parent[u];
        return u;
    }
    bool Unite(int u, int v) {
        u = Find(u);
        v = Find(v);
        if(u == v) return 0;
        if(sz[u] < sz[v]) swap(u, v);

        Save(parent[v]);
        Save(sz[u]);
        Save(comps);

        sz[u] += sz[v];
        parent[v] = u;
        comps--;
        return 1;
    }
    int Snapshot() {
        return sz(st);
    }
    void Rollback() {
        *st.back().first = st.back().second;
        st.pop_back();
    }
    void Rollback(int snap) {
        while(sz(st) > snap) {
            Rollback();
        }
    }
};

int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    int n, q; cin >> n >> q;
    disjoint_set_union_rollback dsu(n);
    stack<int> checkpoints;
    while(q--) {
        string op; cin >> op;
        if(op == "union") {
            int u, v; cin >> u >> v;
            dsu.Unite(u, v);
            cout << dsu.comps << nl;
        } else if(op == "persist") {
            checkpoints.push(dsu.Snapshot());
        } else if(op == "rollback") {
            int cur = checkpoints.top(); checkpoints.pop();
            dsu.Rollback(cur);
            cout << dsu.comps << nl;
        }
    }

    return (0 ^ 0);

}

// thou art fair
