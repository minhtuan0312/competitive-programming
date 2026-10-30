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
    if (x < y) return x = y, 1;
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

int main(void) {
    minhtuan0312;

    #define TASK "DISH"
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    int n, p; cin >> n >> p;
    int A[n + 1];
    ll pre[n + 1], pre_min[n + 1];
    pre[0] = pre[0] = 0;
    FOR(i, 1, n + 1) {
        cin >> A[i];
        pre[i] = pre[i - 1] + A[i];
        pre_min[i] = min(pre_min[i - 1], pre_min[i]);
    }

    int res = -1, res_r = -1, res_l = -1;
    FOR(i, 1, n + 1) {
        ll target = pre[i] - p;
        int l = 0, r = i - 1, best = -1;
        while(l <= r) {
            int m = (l + r) >> 1;
            if(pre[m] <= target) {
                best = m;
                r = m - 1;
            } else l = m + 1;
        }
        if(best != -1) {
            int len = i - (best + 1) + 1;
            if(maximize(res, len)) {
                res_r = i;
                res_l = best + 1;
            }
        }
    }
    if(res == -1) cout << -1;
    else {
        cout << res_l << ' ' << res_r;
    }


    return (0 ^ 0);

}

// thou art fair
