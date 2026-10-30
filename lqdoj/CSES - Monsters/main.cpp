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
const int limN = 1005;
char A[limN][limN];
int parent[limN][limN];
ll monster_dist[limN][limN], hero_dist[limN][limN];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char d[4] = {'D', 'R', 'U', 'L'};
int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    queue<ii> qu;
    cin >> n >> m;
    int startX, startY;
    FOR(i, 1, n + 1) {
        FOR(j, 1, m + 1) {
            monster_dist[i][j] = hero_dist[i][j] = LLONG_MAX;
            cin >> A[i][j];
            if(A[i][j] == 'M') {
                monster_dist[i][j] = 0;
                qu.push({i, j});
            }
            if(A[i][j] == 'A') {
                startX = i;
                startY = j;
            }
        }
    }
    while(!qu.empty()) {
        auto [x, y] = qu.front(); qu.pop();
        FOR(k, 0, 4) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx >= 1 && ny >= 1 && nx <= n && ny <= m && A[nx][ny] != '#' && monster_dist[nx][ny] == LLONG_MAX) {
                monster_dist[nx][ny] = monster_dist[x][y] + 1;
                qu.push({nx, ny});
            }
        }
    }
    if(startX == 1 || startY == 1 || startX == n || startY == m) {
        cout << "YES" << nl << 0;
        return 0;
    }
    qu.push({startX, startY});
    hero_dist[startX][startY] = 0;
    while(!qu.empty()) {
        auto [x, y] = qu.front(); qu.pop();
        FOR(k, 0, 4) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx >= 1 && ny >= 1 && nx <= n && ny <= m && A[nx][ny] != '#' && hero_dist[nx][ny] == LLONG_MAX && hero_dist[x][y] + 1 < monster_dist[nx][ny]) {
                hero_dist[nx][ny] = hero_dist[x][y] + 1;
                qu.push({nx, ny});
                parent[nx][ny] = k;
                if(nx == 1 || ny == 1 || nx == n || ny == m) {
                    int lastX = nx, lastY = ny;
                    string path;
                    while(lastX != startX || lastY != startY) {
                        int lastk = parent[lastX][lastY];
                        path.pb(d[lastk]);
                        lastX -= dx[lastk];
                        lastY -= dy[lastk];
                    }
                    reverse(all(path));
                    cout << "YES" << nl << sz(path) << nl << path;
                    return 0;

                }
            }
        }
    }
    cout << "NO";


    return (0 ^ 0);

}

// thou art fair
