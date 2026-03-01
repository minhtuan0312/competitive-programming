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

int n, q;
const int limN = 2e5 + 5;
const int limLOG = 20 + 1; //2^20 cho N <= 1e6
vector<int> adj[limN];
int up[limN][limLOG];
int dist[limN];
// DFS để tính dist và tổ tiên trực tiếp (2^0)
void dfs(int u, int p) {
    up[u][0] = p;
    FOR(j, 1, limLOG) {
        // tổ tiên thứ 2^j của i là tổ tiên thứ 2^(j-1) của (tổ tiên thứ 2^(j-1) của i)
        up[u][j] = up[up[u][j - 1]][j - 1];
    }
    for(const int &v: adj[u]) {
        if(v == p) continue;
        dist[v] = dist[u] + 1;
        dfs(v, u);

    }
}
int get_kth(int u, int k) {
    if(dist[u] < k) return -1; // nếu k lớn hơn độ sâu của u thì không có tổ tiên bậc k
    FOR(j, 0, limLOG) {
        if(bit(k, j)) u = up[u][j];
    }
    return u;
}
int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    cin >> n >> q;
    FOR(u, 2, n + 1) {
        int boss; cin >> boss;
        adj[boss].eb(u);
    }
    // init
    dist[1] = 0;
    dfs(1, 0);
    while(q--) {
        int x, k; cin >> x >> k;
        cout << get_kth(x, k) << nl;
    }

    return (0 ^ 0);

}

// thou art fair
