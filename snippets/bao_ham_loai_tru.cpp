#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;
#define ll long long
#define nl '\n'
#define all(x) x.begin(), x.end()
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define FORd(i, a, n) for (int i = n - 1; i >= a; i--)
#define minhtuan0312 ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define sz(x) size(x)
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

int n, l, r;
const int limN = 51;
int A[limN], x[limN];

ll res = 0;

ll ucln(ll a, ll b) {
    if (b == 0) return a; // (a, 0) = a
    return ucln(b, a % b); // (a, b) = (b, r)
}

ll bcnn(ll a, ll b) {
    return a / ucln(a, b) * b;
}

ll cnt(ll x) {
    return r / x - (l - 1) / x;
}

void calc(void) {

    vector<int> tmp;
    FOR(i, 1, n + 1) if(x[i]) tmp.pb(A[i]);
    if(tmp.empty()) return;

    ll cur = tmp[0];
    FOR(i, 1, sz(tmp)) {
        cur = bcnn(cur, tmp[i]);
        if(cur > r) return;
    }

    if(sz(tmp) & 1) {
        res += cnt(cur);
    } else {
        res -= cnt(cur);
    }

    return;

}

void Try(int idx) {

    if (idx == n + 1) { // xây xong cấu hình

        calc();
        return;

    }
    x[idx] = 1;
    Try(idx + 1);
    x[idx] = 0;
    Try(idx + 1);
}

int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    cin >> n >> l >> r;
    FOR(i, 1, n + 1) cin >> A[i];
    Try(1);
    cout << res;

    return (0 ^ 0);

}

// study smart, not hard
