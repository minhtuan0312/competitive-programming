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

struct Event{
    ll x;
    int type; // 1: open (cạnh trái), -1: close (cạnh phải)
    ll y1, y2;
    bool operator <(const Event &other) const {
        if(x == other.x) return type > other.type;
        return x < other.x;
    }
};

vector<ll> compress;
struct Node{
    int cnt; // số lần bị phủ (counter)
    int len; // độ dài thực tế bị phủ
};
struct segment_tree{
    int n;
    vector<Node> st;
    segment_tree() {}
    segment_tree(int n): n(n), st(n << 2) {}
    void upd(int v, int l, int r, int ql, int qr, int val) {
        if(ql > qr) return;
        if(l == ql && r == qr) {
            st[v].cnt += val;
        } else {
            int m = (r + l) >> 1;
            upd(v << 1, l, m, ql, min(qr, m), val);
            upd(v << 1 | 1, m + 1, r, max(ql, m + 1), qr, val);
        }
        if(st[v].cnt > 0) {
            // bị phủ hoàn toàn, độ dài = khoảng cách giữa 2 đầu tọa độ
            // Y[r + 1] - Y[l] -> compress[r] - compress[l - 1]
            st[v].len = compress[r] - compress[l - 1];
        } else {
            // không bị phủ hoàn toàn, lấy tổng từ 2 con
            if (l == r) st[v].len = 0;
            else st[v].len = st[v << 1].len + st[v << 1 | 1].len;
        }
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
    FOR(i, 1, n + 1) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        events.pb({x1, 1, y1, y2});
        events.pb({x2, -1, y1, y2});
        compress.eb(y1);
        compress.eb(y2);
    }
    sort(all(compress));
    compress.erase(unique(all(compress)), compress.end());
    sort(all(events));

    ll res = 0;
    ll m = size(compress);
    segment_tree seg(m - 1); // quản lý đoạn nên kích thước phải là m - 1
    ll last_x = events[0].x;
    for(const auto &e: events) {
        // cộng dồn diện tích: độ dài x * độ dài y đang bao phủ
        res += (e.x - last_x) * seg.st[1].len;
        int l = lower_bound(all(compress), e.y1) - compress.begin() + 1;
        int r = lower_bound(all(compress), e.y2) - compress.begin() + 1;
        if(l < r) {
            seg.upd(1, 1, m - 1, l, r - 1, e.type);
        }
        last_x = e.x;
    }
    cout << res;

    return (0 ^ 0);
}

// thou art fair
