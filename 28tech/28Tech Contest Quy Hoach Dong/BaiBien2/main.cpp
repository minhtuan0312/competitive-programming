#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;
#define ll long long
#define nl '\n'
#define all(x) x.begin(), x.end()
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define FORd(i, a, n) for (int i = n - 1; i >= a; i--)
#define minhtuan0312 ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define sz(x) ((int)(x).size())
#define pb push_back
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

struct fenwick_tree{

    int n;
    vector<int> BIT;
    fenwick_tree(int a) : n(a), BIT(n + 1) {}
    void update_pre(int idx, int val) {
        for(; idx; idx -= (idx & -idx)) {
            maximize(BIT[idx], val);
        }
    }
    int get_suf(int idx) {
        int res = 0;
        for(; idx <= n; idx += (idx & -idx)) {
            maximize(res, BIT[idx]);
        }
        return res;
    }
    void update_suf(int idx, int val) {
        for(; idx <= n; idx += (idx & -idx)) {
            maximize(BIT[idx], val);
        }
    }
    int get_pre(int idx) {
        int res = 0;
        for(; idx; idx -= (idx & -idx)) {
            maximize(res, BIT[idx]);
        }
        return res;
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
    FOR(i, 1, n + 1) cin >> A[i];

    vector<int> compress;
    FOR(i, 1, n + 1) compress.emplace_back(A[i]);
    sort(all(compress));
    FOR(i, 1, n + 1) A[i] = lower_bound(all(compress), A[i]) - compress.begin() + 1;

    int res = 0;
    int f3[n + 1], g3[n + 1];
    fenwick_tree inc(n), dec(n);
    FORd(i, 1, n + 1) {
        f3[i] = inc.get_suf(A[i] + 1) + 1;
        inc.update_pre(A[i], f3[i]);
        g3[i] = dec.get_pre(A[i] - 1) + 1;
        dec.update_suf(A[i], g3[i]);
    }
    FOR(i, 1, n + 1) {
        maximize(res, f3[i] + g3[i] - 1);
    }

    cout << res;

    return (0 ^ 0);

}

// thou art fair
