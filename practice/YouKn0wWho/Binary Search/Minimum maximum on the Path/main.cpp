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
int n, m, d;
const int limN = 1e5 + 5;
vector<ii> adj[limN];
int dist[limN], visited[limN];
inline bool check(ll mx) {
    memset(dist, 0, sizeof dist);
    memset(visited, 0, sizeof visited);
    queue<int> qu;
    qu.push(1);
    visited[1] = 1;
    while(!qu.empty()) {
        int u = qu.front(); qu.pop();
        if(u == n) return 1;
        for(const auto &[v, w]: adj[u]) {
            if(!visited[v] && w <= mx && dist[u] + 1 <= d) {
                visited[v] = 1;
                dist[v] = dist[u] + 1;
                qu.push(v);
            }
        }
    }
    return 0;
}

int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    cin >> n >> m >> d;
    int maxi = INT_MIN;
    FOR(i, 1, m + 1) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].eb(v, w);
        maximize(maxi, w);
    }

    int l = 0, r = maxi, res = -1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if(res == -1) return cout << -1, 0;

    int trace[limN];
    memset(trace, -1, sizeof trace);
    memset(dist, 0, sizeof dist);
    memset(visited, 0, sizeof visited);
    queue<int> qu;
    qu.push(1);
    visited[1] = 1;

    while(!qu.empty()) {
        int u = qu.front(); qu.pop();
        if(u == n) break;
        for(const auto &[v, w]: adj[u]) {
            if(!visited[v] && w <= res && dist[u] + 1 <= d) {
                visited[v] = 1;
                dist[v] = dist[u] + 1;
                qu.push(v);
                trace[v] = u;
            }
        }
    }

    int last = n;
    vector<int> ans;
    while(last != -1){
        ans.eb(last);
        last = trace[last];
    }
    reverse(all(ans));
    cout << sz(ans) - 1 << nl;
    for(const auto &x: ans) cout << x << ' ';

    return (0 ^ 0);

}

// thou art fair
