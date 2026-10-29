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

const int offset = 5000;
const int limV = 10005;
typedef pair<int, int> ii;

int main(void) {
    minhtuan0312;

    #define TASK "DOMINO"
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    int n; cin >> n;
    ii A[n + 1];
    FOR(i, 1, n + 1) {
        cin >> A[i].fi >> A[i].se;
    }

    ll dp[n + 1][10005];
    FOR(i, 0, n + 1) {
        FOR(j, 0, 10005) dp[i][j] = LLONG_MAX;
    }

    dp[0][offset] = 0;
    FOR(i, 1, n + 1) {
        int stay = A[i].fi - A[i].se;
        int change = A[i].se - A[i].fi;
        FOR(v, 0, limV) {
            if(dp[i - 1][v] == LLONG_MAX) continue;
            // stay
            if(v + stay >= 0 && v + stay < limV) {
                minimize(dp[i][v + stay], dp[i - 1][v]);
            }
            // change
            if(v + change >= 0 && v + change < limV) {
                minimize(dp[i][v + change], dp[i - 1][v] + 1);
            }
        }
    }

    ll res = LLONG_MAX;
    ll res_rotate = LLONG_MAX;
    FOR(v, 0, limV) {
        if(dp[n][v] == LLONG_MAX) continue;
        int cur = abs(v - offset);
        if(res > cur) {
            res = cur;
            res_rotate = dp[n][v];
        } else if(cur == res) {
            minimize(res_rotate, dp[n][v]);
        }
    }
    cout << res << ' ' << res_rotate;


    return (0 ^ 0);

}

// thou art fair
