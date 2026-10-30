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

const ll NO_LAZY = 0;
struct segment_tree{
    int n;
    vector<ll> st, lazy;
    segment_tree() {}
    segment_tree(int n): n(n), st(n << 2, 0), lazy(n << 2, NO_LAZY) {}
    void build(int v, int l, int r, int A[]) {
        if(l == r) {
            st[v] = A[l];
            return;
        }
        int m = (l + r) >> 1;
        build(v << 1, l, m, A);
        build(v << 1 | 1, m + 1, r, A);
        st[v] = st[v << 1] + st[v << 1 | 1];
    }
    void push(int v) {
        if(lazy[v] == NO_LAZY) return;
        st[v << 1] += lazy[v];
        st[v << 1 | 1] += lazy[v];

        lazy[v << 1] += lazy[v];
        lazy[v << 1 | 1] += lazy[v];

        lazy[v] = NO_LAZY;
    }
    void upd(int v, int l, int r, int ql, int qr, ll val) {
        if(ql > qr) return;
        if(ql == l && qr == r) {
            st[v] += val;
            lazy[v] += val;
            return;
        }
        push(v);
        int m = (l + r) >> 1;
        upd(v << 1, l, m, ql, min(m, qr), val);
        upd(v << 1 | 1, m + 1, r, max(ql, m + 1), qr, val);
        st[v] = min(st[v << 1], st[v << 1 | 1]);
    }
    ll query(int v, int l, int r, int ql, int qr) {
        if(ql > qr) return LLONG_MAX;
        if(ql == l && qr == r) {
            return st[v];
        }
        push(v);
        int m = (l + r) >> 1;
        ll q1 = query(v << 1, l, m, ql, min(m, qr));
        ll q2 = query(v << 1 | 1, m + 1, r, max(ql, m + 1), qr);
        return min(q1, q2);
    }
};

int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    int n, q; cin >> n >> q;
    int A[n + 1];
    FOR(i, 1, n + 1){
        cin >> A[i];
    }
    segment_tree seg(n);
    seg.build(1, 1, n, A);
    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int l, r; cin >> l >> r;
            ll x; cin >> x;
            seg.upd(1, 1, n, l, r, x);
        } else {
            int l, r; cin >> l >> r;
            cout << seg.query(1, 1, n, l, r) << nl;
        }
    }


    return (0 ^ 0);

}

// thou art fair
