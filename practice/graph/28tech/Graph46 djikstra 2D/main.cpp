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

int const limN = 505;
int n, m;
typedef tuple<ll, int, int> iii;
int A[limN][limN];
ll dist[limN][limN];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void dijkstra(int s, int t) {

    memset(dist, 0x3f, sizeof dist);
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push({0, s, t});
    dist[s][t] = A[s][t];
    while(!pq.empty()) {
        auto [d, u, v] = pq.top(); pq.pop();
        if(d != dist[u][v]) continue;
        FOR(k, 0, 4) {
            int nu = u + dx[k];
            int nv = v + dy[k];
            if(nu >= 1 && nv >= 1 && nu <= n && nv <= m) {
                ll nd = d + A[nu][nv];
                if(dist[nu][nv] > nd) {
                    dist[nu][nv] = nd;
                    pq.push({nd, nu, nv});
                }
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

    cin >> n >> m;
    FOR(i, 1, n + 1) {
        FOR(j, 1, m + 1) {
            cin >> A[i][j];
        }
    }
    dijkstra(1, 1);
    cout << dist[n][m];

    return (0 ^ 0);

}

// thou art fair
