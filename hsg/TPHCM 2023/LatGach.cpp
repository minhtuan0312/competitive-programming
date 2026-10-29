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

struct Event{
    int x;
    int type;
    int y1, y2;
    int id;
    bool operator < (const Event &other) {
        return x == other.x ? type > other.type: x < other.x;
    }
};

struct disjoint_set_union{
    int n;
    vector<int> sz, parent;
    vector<ll> area;
    disjoint_set_union() {}
    disjoint_set_union(ll og_area[], int n): n(n), parent(n + 1), area(n + 1) {
        sz.assign(n + 1, 1);
        FOR(i, 1, n + 1) {
            parent[i] = i;
            area[i] = og_area[i];
        }
    }
    int Find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = Find(parent[u]);
    }
    bool Unite(int u, int v) {
        u = Find(u);
        v = Find(v);
        if(u == v) return 0;
        if(sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        parent[v] = u;
        area[u] += area[v];
        return 1;
    }
};

const int NO_LAZY = -1;
struct segment_tree{
    int n;
    vector<ll> seg, lazy;
    segment_tree() {}
    segment_tree(int n): n(n), seg(n << 2), lazy(n << 2, NO_LAZY) {}
    void push(int v, int l, int r)  {
        if(lazy[v] == NO_LAZY) return;
        seg[v << 1] = lazy[v];
        seg[v << 1 | 1] = lazy[v];
        lazy[v << 1] = lazy[v];
        lazy[v << 1 | 1] = lazy[v];
        lazy[v] = NO_LAZY;
    }
    void upd(int v, int l, int r, int ql, int qr, int val, int id, disjoint_set_union &dsu) {
        if(ql > qr) return;
        if(ql == l && qr == r) {
            if(seg[v] != 0) {
                dsu.Unite(seg[v], id);
            }
            seg[v] = val;
            lazy[v] = val;
            return;
        }
        push(v, l, r);
        int m = (l + r) >> 1;
        upd(v << 1, l, m, ql, min(qr, m), val, id, dsu);
        upd(v << 1 | 1, m + 1, r, max(ql, m + 1), qr, val, id, dsu);
        if(seg[v << 1] == seg[v << 1 | 1]) seg[v] = seg[v << 1];
        else seg[v] =  0;
    }
};

int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    int n; cin >> n;
    vector<Event> events;
    vector<int> compress;
    ll area[n + 1];
    FOR(i, 1, n + 1) {
        int x, y, d, c; cin >> x >> y >> d >> c;
        int x1 = x, x2 = x + d, y1 = y, y2 = y + c;
        events.pb({x1, 1, y1, y2, i});
        events.pb({x2, -1, y1, y2, i});
        compress.eb(y1);
        compress.eb(y2);
        area[i] = d * c;
    }
    sort(all(events));
    sort(all(compress));
    compress.erase(unique(all(compress)), compress.end());

    auto get_id = [&](int x) {
        return lower_bound(all(compress), x) - compress.begin() + 1;
    };

    int m = sz(compress);
    segment_tree st(m - 1);
    disjoint_set_union dsu(area, n);

    for(const Event &e: events) {

        int y1  = get_id(e.y1);
        int y2  = get_id(e.y2);
        if(y1 > y2) continue;
        if(e.type == 1) {
            st.upd(1, 1, m - 1, y1, y2 - 1, e.id, e.id, dsu);
        } else {
            st.upd(1, 1, m - 1, y1, y2 - 1, 0, e.id, dsu);
        }
    }
    ll res = 0;
    FOR(i, 1, n + 1) {
        if(dsu.Find(i) == i) {
            maximize(res, dsu.area[i]);
        }
    }
    cout << res;

    return (0 ^ 0);

}

// thou art fair
