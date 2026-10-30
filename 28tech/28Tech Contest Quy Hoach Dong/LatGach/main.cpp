#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;
#define ll long long
#define nl '\n'
#define all(x) x.begin(), x.end()
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define FORd(i, a, n) for (int i = n - 1; i >= a; i--)
#define minhtuan0312 ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define sz(x) ((int)(x).size())
#define pb push_back
#define fi first
#define se second

const ll mod = 111539786;

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

struct matrix{

    int n;
    vector<vector<ll>> f;
    matrix(int a) : n(a), f(n, vector<ll>(n)) {}

    matrix identity() const {
        matrix res(n);
        FOR(i, 0, n) res.f[i][i] = 1;
        return res;
    }

    matrix operator * (const matrix &other) const {
        matrix res(n);
        FOR(i, 0, n) {
            FOR(k, 0, n) {
                if(!f[i][k]) continue;
                FOR(j, 0, n) {
                    res.f[i][j] += f[i][k] * other.f[k][j] % mod;
                    res.f[i][j] %= mod;
                }
            }
        }
        return res;
    }

    matrix operator ^ (ll b) const {
        matrix res = identity();
        matrix a = (*this);
        while(b) {
            if(b & 1) res = res * a;
            a = a * a;
            b >>= 1;
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

    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        if(n == 1 || n == 2) {
            cout << n << nl;
            continue;
        }
        matrix a(2);
        a.f = {{1, 1}, {1, 0}};
        matrix b(2);
        b.f = {{2, 0}, {1, 0}};
        cout << ((a ^ (n - 2)) * b).f[0][0] << nl;
    }

    return (0 ^ 0);

}

// thou art fair
