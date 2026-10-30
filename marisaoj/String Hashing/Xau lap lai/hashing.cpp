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

const int limN = 1e5 + 5;
const int base = 911;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;

ll pow1[limN], pow2[limN];
void init() {
    pow1[0] = pow2[0] = 1;
    FOR(i, 1, limN) {
        pow1[i] = pow1[i - 1] * base % mod1;
        pow2[i] = pow2[i - 1] * base % mod2;
    }
}

typedef pair<ll, ll> ii;
struct string_hashing {
    int n;
    string s;
    vector<ll> dp1, dp2;
    string_hashing() {}
    string_hashing(string s, int n): s(s), n(n), dp1(n + 1), dp2(n + 1) {
        FOR(i, 1, n + 1) {
            dp1[i] = dp1[i - 1] * base % mod1 + s[i];
            dp1[i] %= mod1;
            dp2[i] = dp2[i - 1] * base % mod2 + s[i];
            dp2[i] %= mod2;
        }
    }
    ii query(int l, int r) {
        if(l > r) return {0, 0};
        ll v1 = dp1[r] - dp1[l - 1] * pow1[r - l + 1] % mod1;
        v1 += mod1;
        v1 %= mod1;
        ll v2 = dp2[r] - dp2[l - 1] * pow2[r - l + 1] % mod2;
        v2 += mod2;
        v2 %= mod2;
        return {v1, v2};
    }
    ii operator() (int l, int r) {
        return query(l, r);
    }
};

int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    init();

    string s; cin >> s;
    int n = sz(s);
    s = ' ' + s;
    string_hashing hash_s(s, n);
    FOR(len, 1, n + 1) {
        if(hash_s(1, n - len) == hash_s(len + 1, n)) return cout << s.substr(1, len), 0;
    }
    cout << s.substr(1, n);

    return (0 ^ 0);

}

// thou art fair
