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

int n, m;
const int limN = 1e5 + 5;
vector<int> adj[limN];
int A[limN];

int timer = 0;
int disc[limN], low[limN];
stack<int> st;
int onStack[limN];
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
        } else if(onStack[v]){
            minimize(low[u], disc[v]);
        }
    }
    if(disc[u] == low[u]) {
        scc++;
        while(1) {
            int v = st.top(); st.pop();
            scc_id[v] = scc;
            onStack[v] = 0;
            if(v == u) break;
        }
    }
}
vector<int> dag[limN]; // đồ thị dag sau khi nén
ll weight_scc[limN]; // trọng số (tổng A[i]) của mỗi siêu đỉnh
ll dp[limN];

int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    cin >> n >> m;
    FOR(i, 1, n + 1) {
        cin >> A[i];
    }
    FOR(i, 1, m + 1) {
        int u, v; cin >> u >> v;
        adj[u].eb(v);
    }
    // bước 1: chạy tarjan tìm scc_id
    FOR(u, 1, n + 1) {
        if(!disc[u]) dfs(u);
    }
    // bước 2: duyệt qua mọi cạnh (u,v)
    FOR(u, 1, n + 1) {
        for(const int &v: adj[u]) {
            // nếu u và v thuộc 2 scc khác nhau, tạo cạnh nối 2 siêu đỉnh
            if(scc_id[u] != scc_id[v]) {
                dag[scc_id[u]].eb(scc_id[v]);
            }
        }
    }
    // bước 3: giải quyết bài toán
    FOR(u, 1, n + 1) {
        weight_scc[scc_id[u]] += A[u]; // tính trọng số cho mỗi siêu đỉnh scc
    }
    ll res = 0; // dp[u] = max(dp[v]) + weight
    FOR(u, 1, scc + 1) {
        maximize(dp[u], weight_scc[u]); // skip
        for(const int &v: dag[u]) {
            maximize(dp[u], dp[v] + weight_scc[u]); // take
        }
        maximize(res, dp[u]);
    }
    cout << res;

    return (0 ^ 0);

}

// thou art fair
