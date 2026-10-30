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

struct sct{
    int bac, nam;
    operator <(const sct &other) const {
        return bac == other.bac ? nam > other.nam : bac < other.bac;
    }
};

int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    int m, n, k; cin >> m >> n >> k;
    sct A[k + 2];
    FOR(i, 1, k + 1) {
        cin >> A[i].bac >> A[i].nam;
    }
    A[0] = {0, 0};
    A[k + 1] = {m + 1, n + 1};

    sort(A, A + k + 2, [&](const sct&x, const sct&y) {
            return x.bac < y.bac;
    });
    int p; cin >> p;
    vector<sct> cand;
    FOR(i, 1, p + 1) {
        int u, v; cin >> u >> v;
        auto it = lower_bound(A, A + k + 2, u, [&](const sct&x, int val) {
                return x.bac < val;
        });
        if(it != A + k + 2) {
            int idx = it - A;
            if(A[idx - 1].bac < u && u < A[idx].bac) {
                if(A[idx - 1].nam < v && v < A[idx].nam) {
                    cand.pb({u, v});
                }
            }
        }
    }
    sort(all(cand));
    int cand_sz = sz(cand);
    int dp[cand_sz];
    vector<int> tails;
    FOR(i, 0, cand_sz) {
        int v = cand[i].nam;
        auto it = lower_bound(all(tails), v);
        if(it == tails.end()) {
            tails.eb(v);
        } else {
            *it = v;
        }
    }
    cout << sz(tails);


    return (0 ^ 0);

}

// thou art fair
