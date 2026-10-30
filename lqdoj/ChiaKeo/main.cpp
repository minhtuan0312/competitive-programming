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

int n;
namespace sub12 {
    inline bool check() {
        return n <= 40;
    }
    void solve() {

        ll A[n + 1];
        ll s = 0;
        FOR(i, 1, n + 1){
            cin >> A[i];
            s += A[i];
        }

        int n1 = n >> 1;
        int n2 = n - n1;
        vector<ll> v1, v2;
        FOR(mask, 0, (1 << n1)) {
            ll sum = 0;
            FOR(i, 1, n1 + 1) {
                if(bit(mask, i - 1)) {
                    sum += A[i];
                }
            }
            v1.eb(sum);
        }
        FOR(mask, 0, (1 << n2)) {
            ll sum = 0;
            FOR(i, 1, n2 + 1) {
                if(bit(mask, i - 1)) {
                    sum += A[n1 + i];
                }
            }
            v2.eb(sum);
        }
        sort(all(v2));
        ll res = LLONG_MAX;
        for(const ll &x: v1) {
            ll target = s / 2 - x;
            auto it = lower_bound(all(v2), target);
            if(it != v2.end()) {
                ll cur = x + *it;
                minimize(res, abs(cur - (s - cur)));
            }
        }
        cout << res;

    }
}

namespace sub24 {
    const ll limSum = 12 * 1e5 + 5;
    inline bool check() {
        return  40 < n && n <= 1e4;
    }
    void solve() {

        ll A[n + 1];
        ll s = 0;
        FOR(i, 1, n + 1){
            cin >> A[i];
            s += A[i];
        }

        ll target = s >> 1;
        bitset<limSum> dp;
        dp[0] = 1;
        FOR(i, 1, n + 1) {
            if(A[i] <= target) {
                dp |= (dp << A[i]);
            }
        }
        for(ll x = target; x >= 0; x--) {
            if(dp[x]) {
                return cout << abs(x - (s - x)), void();
            }
        }

    }
}

int main(void) {
    minhtuan0312;

    #define TASK "CANDY"
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    cin >> n;
    if(sub12::check()) return sub12::solve(), 0;
    if(sub24::check()) return sub24::solve(), 0;

    return (0 ^ 0);

}

// thou art fair
