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

const int limN = 2e5+5;
int bit[limN];
void upd(int idx, int val) {
    for(; idx; idx -= (idx & -idx)) {
        maximize(bit[idx], val);
    }
}
int query(int idx) {
    int res = 0;
    for(; idx < limN; idx += (idx & -idx)) {
        maximize(res, bit[idx]);
    }
    return res;
}

int dp[limN];

void solve() {

    int n; cin >> n;
    pair<int, int> A[n + 1];
    FOR(i, 1, n + 1) cin >> A[i].fi >> A[i].se;
    sort(A + 1, A + 1 + n, [&](const pair<int, int> &x, const pair<int, int> &y) {
         return x.fi == y.fi ? x.se > y.se : x.fi < y.fi;
         });

    // dp[i] số búp bê lồng lớn nhất khi xét đến i
    // dp[i] = max(dp[j]) + 1 với j < i và wj < wi && hj < hi

    memset(bit, 0, sizeof bit);
    memset(dp, 0, sizeof dp);

    FOR(i, 1, n + 1) {
        dp[i] = query(A[i].se) + 1;
        upd(A[i].se, dp[i]);
    }
    cout << *max_element(dp + 1, dp + 1 + n) << nl;

}

int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    int t; cin >> t;
    while(t--) {
        solve();
    }


    return (0 ^ 0);

}

// thou art fair
