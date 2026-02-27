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

template<class T>
struct SWAG{
    struct Node {
        T val, agg;
    };
    vector<Node> s_front, s_back;

    T op(T a, T b) {
        return __gcd(a, b);
        // return min(a, b);
        // return a + b;
    }
    void push(T x) {
        if(s_back.empty()) s_back.pb({x, x});
        else s_back.pb({x, op(s_back.back().agg, x)}); // op(tổng cũ, phần tử mới)
    }
    void pop() {
        if(s_front.empty()) {
            while(!s_back.empty()) {
                T x = s_back.back().val; s_back.pop_back();
                if(s_front.empty()) s_front.pb({x, x});
                else s_front.pb({x, op(x, s_front.back().agg)}); // op(phần tử mới, tổng cũ)
            }
        }
        if (!s_front.empty()) s_front.pop_back();
    }
    T get_all() {
        if(s_front.empty() && s_back.empty()) return 0;
        if(s_front.empty()) return s_back.back().agg;
        if(s_back.empty()) return s_front.back().agg;
        return op(s_front.back().agg, s_back.back().agg); // op(tổng front, tổng back)
    }
    int get_size() {
        return sz(s_back) + sz(s_front);
    }
};

int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }



    return (0 ^ 0);

}

// thou art fair
