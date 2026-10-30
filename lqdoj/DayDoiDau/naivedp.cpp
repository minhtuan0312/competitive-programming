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
    if (x < y) {
        x = y;
        return 1;
    }
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

struct trace_node{
    int prev_id;
    int prev_state;
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

    int dp[n + 1][2];
    trace_node trace[n + 1][2];
    memset(dp, 0, sizeof dp);
    memset(trace, -1, sizeof trace);

    int maxi = 0, last_id = 1, last_state = 0;
    FOR(i, 1, n + 1) dp[i][0] = dp[i][1] = 1;
    FOR(i, 1, n + 1) {
        FOR(j, 1, i) {
            if(A[j] < A[i]) {
                if(maximize(dp[i][0], dp[j][1] + 1)) {
                    trace[i][0] = {j, 1};
                }
            }
            else if (A[j] > A[i]) {
                if(maximize(dp[i][1], dp[j][0] + 1)) {
                    trace[i][1] = {j, 0};
                }
            }
        }
        FOR(j, 0, 2) {
            if(maximize(maxi, dp[i][j])) {
                last_id = i;
                last_state = j;
            }
        }
    }

    vector<int> res;
    while(last_id != -1) {
        res.eb(A[last_id]);
        trace_node t = trace[last_id][last_state];
        last_id = t.prev_id;
        last_state = t.prev_state;
    }
    reverse(all(res));

    cout << sz(res) << nl;
    for(const auto &x: res) {
        cout << x << ' ';
    }

    return (0 ^ 0);

}

// thou art fair
