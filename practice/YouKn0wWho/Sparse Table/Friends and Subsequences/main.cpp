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

struct sparse_table_min{
    int n, max_log;
    vector<vector<ll>> st;
    sparse_table_min() {}
    sparse_table_min(ll A[], int n) : n(n), max_log(__lg(n) + 1), st(max_log, vector<ll>(n + 1)) {
        FOR(i, 1, n + 1) st[0][i] = A[i];
        FOR(j, 1, max_log) {
            for(int i = 1; i + (1 << j) - 1 <= n; i++) {
                st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    ll query(int l, int r) {
        if(l > r) return LLONG_MAX;
        int j = __lg(r - l + 1);
        return min(st[j][l], st[j][r - (1 << j) + 1]);
    }
};

struct sparse_table_max{
    int n, max_log;
    vector<vector<ll>> st;
    sparse_table_max() {}
    sparse_table_max(ll A[], int n) : n(n), max_log(__lg(n) + 1), st(max_log, vector<ll>(n + 1)) {
        FOR(i, 1, n + 1) st[0][i] = A[i];
        FOR(j, 1, max_log) {
            for(int i = 1; i + (1 << j) - 1 <= n; i++) {
                st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    ll query(int l, int r) {
        if(l > r) return LLONG_MIN;
        int j = __lg(r - l + 1);
        return max(st[j][l], st[j][r - (1 << j) + 1]);
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
    ll A[n + 1], B[n + 1];
    FOR(i, 1, n + 1) {
        cin >> A[i];
    }
    FOR(i, 1, n + 1) {
        cin >> B[i];
    }
    sparse_table_min st1(B, n);
    sparse_table_max st2(A, n);
    ll res = 0;
    FOR(i, 1, n + 1) {
        int l = i, r = n, upper = -1;
        while(l <= r) {
            int m = (l + r) >> 1;
            if(st2.query(i, m) > st1.query(i, m)) {
                upper = m;
                r = m - 1;
            } else l = m + 1;
        }
        if(upper == -1) upper = n + 1;
        l = i, r = n;
        int lower = -1;
        while(l <= r) {
            int m = (l + r) >> 1;
            if(st2.query(i, m) >= st1.query(i, m)) {
                lower = m;
                r = m - 1;
            } else l = m + 1;
        }
        if(lower == -1 || st2.query(i, lower) != st1.query(i, lower)) continue;
        res += upper - lower;
    }
    cout << res;


    return (0 ^ 0);

}

// thou art fair
