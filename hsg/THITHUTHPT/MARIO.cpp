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
inline bool maximize(T &x, const T &y) {
    if (x < y) return x = y, 1;
    return 0;
}

template<class T>
inline bool minimize(T &x, const T &y) {
    if (x > y) return x = y, 1;
    return 0;
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

struct Point {
    ll x, y;
};
ll calc(const Point &a, const Point &b) {
    return llabs(a.x - b.x) + abs(a.y - b.y);
}
ll n, d;
ll A[105];
Point P[105];
ll dist[105];
bool check(ll x) {

    FOR(i, 1, n + 1) dist[i] = -1;
    dist[1] = x;
    FOR(u, 1, n) {
        if(dist[u] == -1) continue;
        FOR(v, u + 1, n + 1) {
            ll cost = calc(P[u], P[v]) * d;
            if(dist[u] - cost >= 0) {
                maximize(dist[v], dist[u] - cost + A[v]);
            }
        }
    }
    return dist[n] >= 0;
}

int main(void) {
    minhtuan0312;

    #define TASK "MARIO"
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    cin >> n >> d;
    FOR(i, 2, n) {
        cin >> A[i];
    }
    FOR(i, 1, n + 1) {
        cin >> P[i].x >> P[i].y;
    }
    ll l = 0, r = 1e16, res = 0;
    while(l <= r) {
        ll m = (l + r) >> 1;
        if(check(m)) {
            res = m;
            r = m - 1;
        } else l = m + 1;
    }
    cout << res;

    return (0 ^ 0);

}

// thou art fair
