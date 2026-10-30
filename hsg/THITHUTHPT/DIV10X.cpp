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

struct Node{
    ll x, c2, c5;
};
const int limN = 1e5 + 5;
Node A[limN];
int main(void) {
    minhtuan0312;

    #define TASK "DIV10X"
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    int n, x; cin >> n >> x;
    FOR(i, 1, n + 1) {
        cin >> A[i].x;
        ll tmp = A[i].x;
        if(tmp == 0) continue;
        while(tmp % 2 == 0) {
            A[i].c2++;
            tmp /= 2;
        }
        while(tmp % 5 == 0) {
            A[i].c5++;
            tmp /= 5;
        }
    }

    ll dp[x + 1][x + 1];
    FOR(i, 0, x + 1) {
        FOR(j, 0, x + 1) {
            dp[i][j] = LLONG_MAX;
        }
    }
    dp[0][0] = 0;
    FOR(i, 1, n + 1) {
        FORd(j, 0, x + 1) {
            FORd(k, 0, x + 1) {
                int nj = max(0ll, j - A[i].c2);
                int nk = max(0ll, k - A[i].c5);
                if(dp[nj][nk] == LLONG_MAX) continue;
                minimize(dp[j][k], dp[nj][nk] + 1);
            }
        }
    }
    cout << dp[x][x];


    return (0 ^ 0);

}

// thou art fair
