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
    int prev1, prev2;
};

struct Node{
    ll val = 0;
    int idx = -1;
};

inline bool maximize_node(Node &a, int val, int idx) {
    if(a.val < val) {
        a.val = val;
        a.idx = idx;
        return 1;
    }
    return 0;
}

struct fenwick_tree{
    int n;
    vector<Node> BIT;
    fenwick_tree() {}
    fenwick_tree(int n): n(n), BIT(n + 1) {}
    void upd(int idx, ll val, int id) {
        for(; idx <= n; idx += (idx & -idx)) {
            maximize_node(BIT[idx], val, id);
        }
    }
    Node query(int idx) {
        Node res;
        for(; idx >= 1; idx -= (idx & -idx)) {
            if(BIT[idx].val > res.val) res = BIT[idx];
        }
        return res;
    }
};

struct fenwick_tree_suffix{
    int n;
    vector<Node> BIT;
    fenwick_tree_suffix() {}
    fenwick_tree_suffix(int n): n(n), BIT(n + 1) {}
    void upd(int idx, ll val, int id) {
        for(; idx >= 1; idx -= (idx & -idx)) {
            maximize_node(BIT[idx], val, id);
        }
    }
    Node query(int idx) {
        Node res;
        for(; idx <= n; idx += (idx & -idx)) {
            if(BIT[idx].val > res.val) res = BIT[idx];
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
    int A[n + 1], org[n + 1];
    vector<int> compress;
    FOR(i, 1, n + 1) {
        cin >> A[i];
        compress.eb(A[i]);
    }
    sort(all(compress));
    FOR(i, 1, n + 1) {
        int tmp = A[i];
        A[i] = lower_bound(all(compress), A[i]) - compress.begin() + 1;
        org[A[i]] = tmp;
    }

    ll dp[n + 1][2];
    trace_node trace[n + 1][2];
    memset(dp, 0, sizeof dp);
    memset(trace, -1, sizeof trace);

    fenwick_tree fw1(n);
    fenwick_tree_suffix fw2(n);

    ll maxi = 0, last_idx = 1, last_state = 0;
    FOR(i, 1, n + 1) dp[i][0] = dp[i][1] = 1;
    FOR(i, 1, n + 1) {
//        FOR(j, 1, i) {
//            if(A[j] < A[i]) {
//                if (maximize(dp[i][0], dp[j][1] + 1)) {
//                    trace[i][0] = {j, 1};
//                }
//            }
//            else if(A[j] > A[i]) {
//                if (maximize(dp[i][1], dp[j][0] + 1)) {
//                    trace[i][1] = {j, 0};
//                }
//            }
//        }

        Node down = fw1.query(A[i] - 1);
        if(maximize(dp[i][0], down.val + 1)) {
            trace[i][0] = {down.idx, 1};
        }

        Node up = fw2.query(A[i] + 1);
        if(maximize(dp[i][1], up.val + 1)) {
            trace[i][1] = {up.idx, 0};
        }

        fw1.upd(A[i], dp[i][1], i);
        fw2.upd(A[i], dp[i][0], i);

        FOR(j, 0, 2) {
            if(maximize(maxi, dp[i][j])) {
                last_idx = i;
                last_state = j;
            }
        }
    }

    vector<int> res;
    while(last_idx != -1) {
        res.eb(A[last_idx]);
        trace_node t = trace[last_idx][last_state];
        last_idx = t.prev1;
        last_state = t.prev2;
    }
    reverse(all(res));
    cout << sz(res) << nl;
    for(const auto &x: res) cout << org[x] << ' ';


    return (0 ^ 0);

}

// thou art fair
