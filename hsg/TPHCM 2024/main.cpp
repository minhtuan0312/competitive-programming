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

struct team{
    int solved, penalty;
};
inline bool cmp(const team &x, const team &y) {
    return x.solved == y.solved? x.penalty < y.penalty : x.solved > y.solved;
}
const int limN = 1e5 + 5;
team teams[limN];
int n, m;
int get_rank() {
    int better = 0;
    FOR(i, 2, n + 1) {
        if(cmp(teams[i], teams[1])) better++;
    }
    return better + 1;
    // số lượng (x.solved == 1.solved && x.penalty < 1.penalty) + số lượng (x.solved > 1.solved) + 1
}

struct fenwick_tree{
    int n;
    vector<ll> BIT;
    fenwick_tree() {}
    fenwick_tree(int n): n(n), BIT(n + 1) {}
    void upd(int idx, ll val) {
        for(; idx <= n; idx += idx & -idx) {
            BIT[idx] += val;
        }
    }
    ll query(int idx) {
        ll res = 0;
        for(; idx; idx -= idx & -idx) {
            res += BIT[idx];
        }
        return res;
    }
};

typedef pair<int, int> ii;
int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    cin >> n >> m;
    vector<team> compress;
    compress.pb({0, 0});
    vector<ii> events;
    FOR(i, 1, m + 1) {
        int u, v; cin >> u >> v;
        events.eb(u, v);
        teams[u].solved++;
        teams[u].penalty += v;
        compress.eb(teams[u]);
    }
    sort(all(compress), cmp);
    states.erase(unique(all(states), [](const team &a, const team &b){
        return a.solved == b.solved && a.penalty == b.penalty;
    }), states.end());

    auto get_id = [&](int i) {
        return lower_bound(all(compress), teams[i], cmp) - compress.begin() + 1;
    };
    memset(teams, 0, sizeof teams); // bắt đầu mô phỏng thật
    fenwick_tree fw(sz(compress));
    fw.upd(get_id(0), n); // ban đầu cả n đội đều (0, 0)
    for(const auto [u, v]: events) {

        fw.upd(get_id(u), -1);

        teams[u].solved++;
        teams[u].penalty += v;

        fw.upd(get_id(u), 1);

        cout << fw.query(get_id(1) - 1) + 1 << nl;

    }
    return (0 ^ 0);

}

// thou art fair
