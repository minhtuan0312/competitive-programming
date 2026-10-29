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

vector<ll> divp;
vector<pair<ll, int>> ie;
void factorization(ll n) {
    vector<pair<int, int>> res;
    int sq = sqrt(n);
    FOR(i, 2, sq + 1) {
        if(n % i == 0){
            divp.eb(i);
            while(n % i == 0){
                n/=i;
            }
        }
    }
    if(n != 1) divp.eb(n);
}

void duyet() {
    int m = sz(divp);
    for(int mask = 1; mask < (1 << m); mask++) {
        ll prod = 1;
        int cnt = 0;
        FOR(i, 0, m) {
            if(bit(mask, i)) {
                prod *= divp[i];
                cnt++;
            }
        }
        if(cnt) ie.pb({prod, cnt});
    }
}

ll compute(ll l, ll r, ll x) {
    return r/x - (l - 1)/ x;
}

int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    ll n, q; cin >> n >> q;

    factorization(n);
    duyet();

    while(q--) {
        ll l, r; cin >> l >> r;
        ll res = 0;
        for(auto [p, cnt]: ie) {
            if(cnt & 1) res += compute(l, r, p);
            else res -= compute(l, r, p);
        }
        cout << r - l + 1 - res << nl;
    }

    return (0 ^ 0);

}

// thou art fair
