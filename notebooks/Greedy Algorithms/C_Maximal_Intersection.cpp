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

/* ----------------------------- END OF TEMPLATE ---------------------------- */

// intersection = (max(l1, l2, ...), min(r1, r2, ...))
// length = R - L

int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    
    int n; cin >> n;
    int preL[n + 1], preR[n + 1], sufL[n + 2], sufR[n + 2];
    // pre: intersection from 1 to i
    // suf: intersection from i to n
    pair<int, int> p[n + 1];
    FOR(i, 1, n + 1) {
        cin >> p[i].fi >> p[i].se;
    }
    preL[0] = INT_MIN;
    preR[0] = INT_MAX;
    FOR(i, 1, n + 1) {
        preL[i] = max(preL[i - 1], p[i].fi);
        preR[i] = min(preR[i - 1], p[i].se);
    }

    sufL[n + 1] = INT_MIN;
    sufR[n + 1] = INT_MAX;
    for(int i = n; i >= 1; i--) {
        sufL[i] = max(sufL[i + 1], p[i].fi);
        sufR[i] = min(sufR[i + 1], p[i].se);
    }

    int res = 0;
    FOR(i, 1, n + 1) {
        int L = max(preL[i - 1], sufL[i + 1]);
        int R = min(preR[i - 1], sufR[i + 1]);
        maximize(res, R - L);
    }
    cout << res;
    
    return (0 ^ 0);

}

/* ------------------------------ THOU ART FAIR ----------------------------- */