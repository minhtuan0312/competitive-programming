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

typedef pair<ll, int> ii;
const int limN = 1005;
int n, m, s;
vector<ii> adj[limN];
ll dist[limN];

void dijkstra(int s) {
    memset(dist, 0x3f, sizeof dist);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(d != dist[u]) continue;
        for(auto [v, w]: adj[u]) {
            if(dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
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

    cin >> n >> m >> s;
    FOR(i, 1, m + 1) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].eb(v, w);
        adj[v].eb(u, w);
    }

    dijkstra(s);
    FOR(i, 1, n + 1) {
        cout << dist[i] << ' ';
    }


    return (0 ^ 0);

}

// thou art fair

//10 44 5
//7 5 60
//9 8 31
//9 1 83
//4 3 25
//6 2 1
//4 1 52
//6 3 76
//7 6 95
//9 8 84
//8 2 91
//10 7 8
//6 4 32
//10 2 76
//3 1 62
//10 6 88
//8 3 12
//5 3 15
//5 4 40
//9 2 20
//3 2 5
//5 1 36
//9 4 98
//8 6 65
//8 5 95
//10 3 55
//9 6 95
//10 1 5
//4 2 70
//7 1 80
//10 4 35
//7 2 99
//10 9 24
//6 5 94
//2 1 77
//8 1 12
//8 4 76
//9 3 27
//5 2 5
//9 5 12
//10 5 1
//8 7 59
//6 1 1
//10 8 92
//7 3 54
