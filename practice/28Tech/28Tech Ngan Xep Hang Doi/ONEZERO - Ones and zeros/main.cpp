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

const int limN = 20000 + 5;
int visited[limN];
int trace[limN];
int digit[limN];
int session = 0; // trick tối ưu bộ nhớ thay vì cứ phải memset mỗi testcase

void solve() {
    session++;
    int n; cin >> n;
    queue<int> qu;
    int start_r = 1 % n;
    if(start_r == 0) return cout << 1 << nl, void();
    visited[start_r] = session;
    trace[start_r] = -1; // ko có cha
    digit[start_r] = 1;
    qu.push(start_r);
    while(!qu.empty()) {
        int r = qu.front(); qu.pop();
        if(r == 0) break; // tìm thấy số nhỏ nhất chia hết cho n
        for(const int &k: {0, 1}) {
            int nr = (r * 10 + k) % n;
            if(visited[nr] != session) {
                visited[nr] = session;
                trace[nr] = r;
                digit[nr] = k;
                qu.push(nr);
            }
        }
    }
    int last = 0;
    string res;
    while(last != -1) {
        res.pb(char('0' + digit[last]));
        last = trace[last];
    }
    reverse(all(res));
    cout << res << nl;
}
int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    int t; cin >> t;
    while(t--) solve();

    return (0 ^ 0);

}

// thou art fair
