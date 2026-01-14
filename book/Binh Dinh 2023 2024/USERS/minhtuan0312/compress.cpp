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

ll bcnn(ll a, ll b) {
    return a / __gcd(a, b) * b;
}
unsigned ll BC[10005];

ll compress(ll n) {
    ll res = 2;
    while(n % res == 0) res++;
    return res;
}
// giả sử k là số mà n không chia hết nhỏ nhất thì từ 1 đến k - 1 n sẽ chia hết, tức n chia hết cho bcnn(1 ... k - 1)

ll compressness(ll n) {
    int res = 0;
    ll cur = n;
    while(1) {
        res++;
        cur = compress(cur);
        if(cur <= 2) break;
    }
    return res;
}

ll compute(ll n) {
    ll res = 0;
    FOR(k, 2, 44) {
        ll cnt = n / BC[k - 1] - n / BC[k];
        res += (k == 2 ? cnt:(compressness(k) + 1) * cnt);
    }
    return res;
}

int main(void) {
    minhtuan0312;

    #define TASK "compress"
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    memset(BC, 0, sizeof BC);
    BC[0] = 1;
    FOR(i, 1, 44) {
        BC[i] = bcnn(BC[i - 1], i);
        if(BC[i] >= 1e18) break;
    }

    ll a, b; cin >> a >> b;
    cout << compute(b) - compute(a - 1);

    return (0 ^ 0);

}

// thou art fair
