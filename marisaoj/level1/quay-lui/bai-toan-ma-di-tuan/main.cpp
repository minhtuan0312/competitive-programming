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

/* ----------------------------- END OF TEMPLATE ---------------------------- */

int n, m;

int dx[8] = {1,2,-1,-2,1,2,-1,-2};
int dy[8] = {2,1,2,1,-2,-1,-2,-1};
int path[7][7];
int deg[7][7];
int cnt = 0;
using iii = pair<int, pair<int, int>>;
void solve(int i, int j) {
    if (cnt == n * m) {
        FOR(i, 0, n) {
            FOR(j, 0, m) {
                cout << path[i][j] << ' ';
            }
            cout << nl;
        }
        exit(0);
        return;
    }
    priority_queue<iii, vector<iii>, greater<iii>> min_heap;
    FOR(k, 0, 8) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || path[nx][ny]) continue;
        min_heap.push({deg[nx][ny], {nx, ny}});
    }
    while(!min_heap.empty()) {
        auto [deg, u] = min_heap.top(); min_heap.pop();
        auto [nx, ny] = u;
        path[nx][ny] = ++cnt;
        solve(nx, ny);
        --cnt;
        path[nx][ny] = 0;
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

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int tmp = 0;
            FOR(k, 0, 8) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                tmp++;
            }
            deg[i][j] = tmp;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            memset(path, 0, sizeof path);
            cnt = 1;
            path[i][j] = cnt;
            solve(i, j);
        }
    }
    
    return (0 ^ 0);

}

/* ------------------------------ THOU ART FAIR ----------------------------- */