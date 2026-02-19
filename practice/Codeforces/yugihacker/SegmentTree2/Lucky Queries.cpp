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

struct Node {
    int c4, c7, lis, lds;
    Node() : c4(0), c7(0), lis(0), lds(0) {}
};

Node Merge(const Node &l, const Node &r) {
    Node res;
    res.c4 = l.c4 + r.c4;
    res.c7 = l.c7 + r.c7;
    res.lis = max(l.c4 + r.lis, l.lis + r.c7);
    res.lds = max(l.c7 + r.lds, l.lds + r.c4);
    return res;
}

const ll NO_LAZY = 0;
struct segment_tree {
    int n;
    vector<Node> st;
    vector<bool> lazy;
    segment_tree() {}
    segment_tree(int n): n(n), st(n << 2), lazy(n << 2, NO_LAZY) {}
    void apply(int v) {
        swap(st[v].c4, st[v].c7);
        swap(st[v].lis, st[v].lds);
        lazy[v] = !lazy[v];
    }
    void push(int v, int l, int r) {
        if(lazy[v] == NO_LAZY) return;
        apply(v << 1);
        apply(v << 1 | 1);
        lazy[v] = 0;
    }
    void build(int v, int l, int r, const string &A) {
        if (l == r) {
            st[v].c4 += A[l] == '4';
            st[v].c7 += A[l] == '7';
            st[v].lis = st[v].lds = 1;
            return;
        }
        int m = (l + r) >> 1;
        build(v << 1, l, m, A);
        build(v << 1 | 1, m + 1, r, A);
        st[v] = Merge(st[v << 1], st[v << 1 | 1]);
    }
    void upd(int v, int l, int r, int ql, int qr) {
        if (ql > qr) return;
        if (l == ql && r == qr) {
            apply(v);
            return;
        }
        push(v, l, r);
        int m = (l + r) >> 1;
        upd(v << 1, l, m, ql, min(qr, m));
        upd(v << 1 | 1, m + 1, r, max(ql, m + 1), qr);
        st[v] = Merge(st[v << 1], st[v << 1 | 1]);
    }
    Node query(int v, int l, int r, int ql, int qr) {
        if (ql > qr) return Node();
        if (l == ql && r == qr) return st[v];
        push(v, l, r);
        int m = (l + r) >> 1;
        Node q1 = query(v << 1, l, m, ql, min(m, qr));
        Node q2 = query(v << 1 | 1, m + 1, r, max(ql, m + 1), qr);
        return Merge(q1, q2);
    }
};

int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    int n, m; cin >> n >> m;
    string s; cin >> s;
    s = ' ' + s;
    segment_tree seg(n);
    seg.build(1, 1, n, s);
    while(m--) {
        string op; cin >> op;
        if(op[0] == 's') {
            int l, r; cin >> l >> r;
            seg.upd(1, 1, n, l, r);
        } else {
            cout << seg.st[1].lis << nl;
        }
    }

    return (0 ^ 0);

}

// thou art fair
