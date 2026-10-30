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

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    int n, p; cin >> n >> p;
    int A[n + 1];
    FOR(i, 1, n + 1){
        cin >> A[i];
    }

    if (3 * p == n) {
        int res = 0;
        for (int i = 1; i <= n; i += 3) {
            int a = A[i];
            int b = A[i+1];
            int c = A[i+2];
            res = max(res, max({a, b, c}) - min({a, b, c}));
        }
        cout << res << endl;
        return 0;
    }

    auto check = [&](int x) {
        int cnt = 0;
        int l = 1;
        while(l <= n - 3 + 1) {
            vector<int> cur;
            bool ok = 0;
            FOR(r, l, n + 1) {
                auto it = lower_bound(all(cur), A[r]);
                cur.insert(it, A[r]);
                if(sz(cur) >= 3) {
                    FOR(i, 0, sz(cur) - 3 + 1) {
                        if(cur[i + 2] - cur[i] <= x) {
                            ok = 1;
                            break;
                        }
                    }
                }
                if(ok) {
                    cnt++;
                    l = r + 1;
                    break;
                }
                if(r == n) l = n + 1;
            }
            if(cnt >= p) {
                return 1;
            }
        }
        return 0;

    };

    int l = 0, r = 2e9, res = -1;
    while(l <= r) {

        int m = (l + r) >> 1;
        if(check(m)) {
            res = m;
            r = m - 1;
        } else l = m + 1;
    }
    cout << res;

    return (0 ^ 0);

}

// thou art fair
