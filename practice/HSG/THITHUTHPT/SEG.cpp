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

struct Point {
    int l, r;
    int id;
    bool operator < (const Point &other) const {
        return l == other.l? r > other.r : l < other.l;
    }
};

inline bool is_the_same(const Point &a, const Point &b) {
    return a.l == b.l && a.r == b.r;
}

int main(void) {
    minhtuan0312;

    #define TASK "SEG"
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    int n; cin >> n;
    Point A[n + 1];
    FOR(i, 1, n + 1) {
        cin >> A[i].l >> A[i].r;
        A[i].id = i;
    }
    sort(A + 1, A + 1 + n);

    bool contains[n + 1] = {0};
    bool contained[n + 1] = {0};

    int max_r = 0;
    FOR(i, 1, n + 1) {
        if(max_r >= A[i].r) {
            contained[A[i].id] = 1;
        }
        if(i > 1 && is_the_same(A[i], A[i - 1])) {
            contained[A[i].id] = 1;
            contained[A[i - 1].id] = 1;
        }
        maximize(max_r, A[i].r);
    }

    int min_r = INT_MAX;
    for(int i = n; i >= 1; i--) {
        if(min_r <= A[i].r) {
            contains[A[i].id] = 1;
        }
        if(i < n && is_the_same(A[i], A[i + 1])) {
            contains[A[i].id] = 1;
            contains[A[i + 1].id] = 1;
        }
        minimize(min_r, A[i].r);
    }

    FOR(i, 1, n + 1) cout << contains[i] << ' ';
    cout << nl;
    FOR(i, 1, n + 1) cout << contained[i] << ' ';

    return (0 ^ 0);

}

// thou art fair
