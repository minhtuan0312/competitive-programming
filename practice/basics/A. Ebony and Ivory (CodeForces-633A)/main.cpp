// https://vjudge.net/problem/CodeForces-633A

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

// ax + by = d
// bx1 + ry1 = d, r = a % b = a - b * (a / b)
// bx1 + (a - b * a / b) y1
// bx1 + y1a - y1 * b * a/b
// ay1 + b(x1 - y1 * a/b)

ll extended_euclid(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1, y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * static_cast<int>(a / b);
    return d;
}

// (a, b) = d, d | c -> k = c / d
// -> a(x' * c / d) + b(y' * c/ d) = c

// d | a -> a = d a1
// d | b -> b = d b1
// (a1, b1) = 1

// a1(x - x0) = -b1(y - y0)

// a1 | (y - y0) -> y - y0 = ka1
// -b1 | (x - x0) -> x - x0 = -kb1

// -> x = x0 - k * b / d
// -> y = y0 + k * a / d

// A = x' * c / d
// B = y' * c   / d

// -> x = A - k * b / d > 0
// -> y = B + k * a / d > 0

// k < A * d / b
// k > -B * d / a

// -B * d / a < k < A * d / b

bool check(int a, int b, int c) {

    int x, y;
    int d = extended_euclid(a, b, x, y);
    if (c % d != 0) return 0;

    x *= c / d;
    y *= c / d;

    ll kl = ceil(-1.0L * y * d / a);
    ll kr = floor(1.0L * x * d / b);

    return kl <= kr;
}

int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    // ax + by = c
    // (a, b) = d && d | c

    int a, b, c; cin >> a >> b >> c;
    if(a == 0) {
        if(b == 0) return cout << "No", 0;
    }
    else if (b == 0) {
        if(a == 0) return cout << "No", 0;
    }
    else {
        cout << (check(a, b, c)? "Yes": "No");
    }

    return (0 ^ 0);

}

// study smart, not hard
