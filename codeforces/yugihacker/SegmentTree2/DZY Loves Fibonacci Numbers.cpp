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
struct segment_tree {
    int n;
    vector<ll> st, lazy_A, lazy_B;
    segment_tree() {}
    segment_tree(int n): n(n), st(n << 2), lazy_A(n << 2, NO_LAZY), lazy_B(n << 2, NO_LAZY) {}
    ll sum_index(ll l, ll r) {
        return (r + l) * (r - l + 1) / 2;
    }
    void build(int v, int l, int r, int A[]) {
        if(l == r) {
            return st[v] = A[l], void();
        }
        int m = (l + r) >> 1;
        build(v << 1, l, m, A);
        build(v << 1 | 1, m + 1, r, A);
        st[v] = st[v << 1] + st[v << 1 | 1];
    }
    void push(int v, int l, int r) {
        if(lazy_A[v] == NO_LAZY && lazy_B[v] == NO_LAZY) return;
        int m = (l + r) >> 1;
        ll A = lazy_A[v], B = lazy_B[v];
        st[v << 1] += A * sum_index(l, m) + B * (m - l + 1); // l -> m
        st[v << 1 | 1] += A * sum_index(m + 1, r) + B * (r - m); // m + 1 -> r
        lazy_A[v << 1] += A;
        lazy_A[v << 1 | 1] += A;
        lazy_A[v] = NO_LAZY;
        lazy_B[v << 1] += B;
        lazy_B[v << 1 | 1] += B;
        lazy_B[v] = NO_LAZY;
    }
    void upd(int v, int l, int r, int ql, int qr, ll A, ll B) {
        if(ql > qr) return;
        if(ql == l && qr == r) {
            st[v] += A * sum_index(l, r) + B * (r - l + 1);
            lazy_A[v] += A;
            lazy_B[v] += B;
            return;
        }
        push(v, l, r);
        int m = (l + r) >> 1;
        upd(v << 1, l, m, ql, min(m, qr), A, B);
        upd(v << 1 | 1, m + 1, r, max(m + 1, ql), qr, A, B);
        st[v] = st[v << 1] + st[v << 1 | 1];
    }
    ll query(int v, int l, int r, int ql, int qr) {
        if(ql > qr) return 0;
        if(ql == l && qr == r) {
            return st[v];
        }
        push(v, l, r);
        int m = (l + r) >> 1;
        ll q1 = query(v << 1, l, m, ql, min(m, qr));
        ll q2 = query(v << 1 | 1, m + 1, r, max(m + 1, ql), qr);
        return q1 + q2;
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
    int A[n + 1];
    FOR(i, 1, n + 1) {
        cin >> A[i];
    }
    segment_tree seg(n);
    seg.build(1, 1, n, A);
    int q; cin >> q;
    while(q--) {
        int op, l, r; cin >> op >> l >> r;
        if(op == 1) {
            seg.upd(1, 1, n, l, r, 1, 1 - l);
        } else {
            cout << seg.query(1, 1, n, l, r) << nl;
        }
    }

    return (0 ^ 0);

}

// thou art fair
