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

const int limN = 505;
typedef pair<ll, pair<int, int>> iii;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
ll A[limN][limN], dist[limN][limN];
int n;
void dijkstra(int s, int t) {

    memset(dist, 0x3f, sizeof dist);
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push({0, {s, t}});
    dist[s][t] = 0;
    while(!pq.empty()) {
        iii u = pq.top(); pq.pop();
        ll d = u.fi;
        auto [x, y] = u.se;
        if(d > dist[x][y]) continue;
        FOR(k, 0, 4) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx > 0 && ny > 0 && nx <= n && ny <= n) {
                // relax
                ll nd = max(dist[x][y], abs(A[nx][ny] - A[x][y]));
                if(dist[nx][ny] > nd) {
                    dist[nx][ny] = nd;
                    pq.push({nd, {nx, ny}});
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

    cin >> n;
    FOR(i, 1, n + 1) {
        FOR(j, 1, n + 1) {
            cin >> A[i][j];
        }
    }

    dijkstra(1, 1);

    cout << dist[n][n];

    return (0 ^ 0);

}

// thou art fair
