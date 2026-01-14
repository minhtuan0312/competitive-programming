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

ll extended_euclid(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = extended_euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

bool exist_solution(ll a, ll b, ll c, ll &x, ll &y, ll &g){
    g = extended_euclid(abs(a), abs(b), x, y);
    if(c % g) return 0;
    x *= c / g;
    y *= c / g;
    if(a < 0) x = -x;
    if(b < 0) y = -y;
    return 1;
}

ll floor_div(ll a, ll b) {
    return a / b - ((a % b != 0) & ((a ^ b) < 0));
}
ll ceil_div(ll a, ll b) {
    return a / b + ((a % b != 0) & ((a ^ b) >= 0));
}

// x = x0 + b/g
// y = y0 - a/g
ll find_all_solutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) {
    ll x0, y0, g;
    if(!exist_solution(a, b, c, x0, y0, g)) return 0;
    a /= g; // chuan hoa
    b /= g;

    // x = x0 + k*b  =>  minx <= x0 + k*b <= maxx
    ll kx1, kx2;
    if(b > 0) {
        kx1 = ceil_div(minx - x0, b);
        kx2 = floor_div(maxx - x0, b);
    } else {
        kx1 = ceil_div(maxx - x0, b);
        kx2 = floor_div(minx - x0, b);
    }
    // y = y0 - k*a => miny <= y0 - k*a <= maxy
    // => -miny + y0 >= k*a >= -maxy + y0
    ll ky1, ky2;
    if(a > 0) {
        ky1 = ceil_div(-maxy + y0, a);
        ky2 = floor_div(-miny + y0, a);
    } else {
        ky1 = ceil_div(-miny + y0, a);
        ky2 = floor_div(-maxy + y0, a);
    }
    ll l = max(kx1, ky1);
    ll r = min(kx2, ky2);
    if(l > r) return 0;
    else return r - l + 1;
}

void solve() {

    ll a, b, c, x1, x2, y1, y2; cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
    if(a == 0 && b == 0 && c == 0) { //a0 + b0 = 0 (luôn thỏa)
        return cout << 1ll * (x2 - x1 + 1) * (y2 - y1 + 1) << nl, void();
    } else if (a == 0 && b == 0) { // a0 + b0 = c (vô nghiệm)
        return cout << 0 << nl, void();
    } else if (a == 0) {// a0 + by = -c -> y = -c / b;

        if(c % b == 0 && (y1 <= -c / b && -c / b <= y2)) {
            return cout << (x2 - x1 + 1) << nl, void();
        } else {
            return cout << 0 << nl, void();
        }

    } else if (b == 0) {// ax + b0 = -c -> x = -c / a;

       if(c % a == 0 && (x1 <= -c / a && -c / a <= x2)) {
            return cout << (y2 - y1 + 1) << nl, void();
        } else {
            return cout << 0 << nl, void();
        }

    } else {
        return cout << find_all_solutions(a, b, -c, x1, x2, y1, y2) << nl, void();
    }

}

int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    int t; cin >> t;
    while(t--) {
        solve();
    }

    return (0 ^ 0);

}

// thou art fair
