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

typedef pair<int, int> ii;
int n, m;
const int limN = 10005;
// đổi mảng kề sang lưu pair: {v, edge_id}
vector<ii> adj[limN];
int timer = 0;
int low[limN], disc[limN];
set<int> ap;
vector<ii> bridges;
void dfs(int u, int pid) { // (đỉnh hiện tại, ID cạnh vừa đi qua)
    disc[u] = low[u] = ++timer;
    int child = 0;

    for(const auto &[v, id]: adj[u]) {
        // chỉ bỏ qua đúng cái cạnh vừa đi tới *quan trọng
        if(id == pid) continue;
        if(!disc[v]) {
            child++;
            dfs(v, id);
            minimize(low[u], low[v]);
            if(disc[u] <= low[v] && pid) {
                ap.insert(u);
            }
            if(disc[u] < low[v]) {
                bridges.eb(u, v);
                // nếu đề bài yêu cầu in chỉ số cạnh là cầu:
                // bridges_id.push_back(id);
            }
        } else {
            minimize(low[u], disc[v]);
        }
    }
    if(!pid && child > 1) {
        ap.insert(u);
    }
}

int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    cin >> n >> m;
    FOR(i, 1, m + 1) {
        int u, v; cin >> u >> v;
        // lưu đỉnh và id cạnh i
        adj[u].eb(v, i);
        adj[v].eb(u, i);
    }
    FOR(i, 1, n + 1) {
        if(!disc[i]) {
            dfs(i, 0);
        }
    }
    cout << sz(ap) << ' ' << sz(bridges);

    return (0 ^ 0);

}

// thou art fair
