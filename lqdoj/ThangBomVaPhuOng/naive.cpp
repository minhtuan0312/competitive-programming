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
inline bool minimize(T &x, const T &y) {
    if (x > y) {
        return x = y, 1;;
    }
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

int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    int n, k; cin >> n >> k;
    ll sum = 0;
    ll A[n + 2];
    FOR(i, 1, n + 1) {
        cin >> A[i];
        sum += A[i];
    }
    A[n + 1] = 0;

    ll dp[n + 2];
    ll trace[n + 2];
    memset(dp, 0x3f, sizeof dp);
    memset(trace, -1, sizeof trace);
    dp[0] = 0;
    FOR(i, 1, n + 2) {
        FOR(j, max(i - k, 0), i) {
            if(minimize(dp[i], dp[j] + A[i])) {
                trace[i] = j;
            }
        }
    }

    vector<int> res;

    bool skipped[n + 2] = {0};
    int last_idx = n + 1;
    while(last_idx != -1) {
        skipped[last_idx] = 1;
        last_idx = trace[last_idx];
    }

    FOR(i, 1, n + 1) {
        if(!skipped[i]) {
            res.eb(i);
        }
    }

    cout << sz(res) << ' ' << sum - dp[n + 1] << nl;
    for(const auto &x: res) cout << x << ' ';


    return (0 ^ 0);

}

// thou art fair
