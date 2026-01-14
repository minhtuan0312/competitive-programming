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

int main(void) {
    minhtuan0312;

    #define TASK "cau3"
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    int n; cin >> n;
    char A[n + 1][n + 1] = {0};
    FOR(i, 1, n + 1) {
        FOR(j, 1, n + 1) cin >> A[i][j];
    }

    string dp[n + 1][n + 1]; //dp[i][j] binary lon nhat khi xet den i, j
    dp[1][1] = A[1][1];
    FOR(i, 1, n + 1) {
        FOR(j, 1, n + 1) {
            if(i == 1 && j == 1) continue;
            string best = "";
            if(i == 1) maximize(best, dp[i][j - 1]);
            else if(j == 1) maximize(best, dp[i - 1][j]);
            else maximize(best, max(dp[i - 1][j], dp[i][j - 1]));
            dp[i][j] = best + A[i][j];
        }
    }

    char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    string res = dp[n][n];

    auto one = res.find("1");
    if(one == string::npos) {
        return cout << 0, 0;
    }
    res = res.substr(one);

    string ans = "";
    int cnt = 0;
    ll s = 0;
    ll p = 1; // 1 2 4 8
    for(int i = sz(res) - 1; i >= 0; i--) {
        if(res[i] == '1') {
            s += p;
        }
        p <<= 1;
        cnt++;
        if(cnt == 4) {
            ans.pb(hex[s % 16]);
            s = 0;
            p = 1;
            cnt = 0;
        }
    }
    if(cnt > 0) {
        ans.pb(hex[s % 16]);
    }
    reverse(all(ans));
    cout << ans;

    return (0 ^ 0);

}

// thou art fair
