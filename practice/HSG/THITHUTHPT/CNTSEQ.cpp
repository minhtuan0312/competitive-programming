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
    ll v, cnt;
    bool operator < (const Node &other) const {
        return v < other.v;
    }
};

int main(void) {
    minhtuan0312;

    #define TASK "CNTSEQ"
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    int n; cin >> n;
    Node A[n + 1];
    FOR(i, 1, n + 1) {
        cin >> A[i].v;
    }

    stack<ll> st;
    ll closest_right[n + 1];
    FOR(i, 1, n + 1) {
        while(!st.empty() && A[st.top()].v <= A[i].v) {
            ll u = st.top(); st.pop();
            closest_right[u] = i;
        }
        st.push(i);
    }
    while(!st.empty()) {
        ll u = st.top(); st.pop();
        closest_right[u] = n + 1;
    }
    ll closest_left[n + 1];
    FORd(i, 1, n + 1) {
        while(!st.empty() && A[st.top()].v < A[i].v) {
            ll u = st.top(); st.pop();
            closest_left[u] = i;
        }
        st.push(i);
    }
    while(!st.empty()) {
        ll u = st.top(); st.pop();
        closest_left[u] = 0;
    }
    FOR(i, 1, n + 1) {
        A[i].cnt = (i - closest_left[i]) * (closest_right[i] - i);
    }
    sort(A + 1, A + 1 + n);
    A[0].cnt = 0;
    FOR(i, 1, n + 1) {
        A[i].cnt = A[i - 1].cnt + A[i].cnt;
    }
    int q; cin >> q;
    while(q--) {
        ll l, r; cin >> l >> r;
        auto itR = upper_bound(A + 1, A + 1 + n, r, [&](ll val, const Node &node){
                              return val < node.v;
                              }) - A - 1;
        auto itL = lower_bound(A + 1, A + 1 + n, l, [&](const Node &node, ll val){
                              return node.v < val;
                              }) - A - 1;
        cout << A[itR].cnt - A[itL].cnt << nl;
    }
    return (0 ^ 0);

}

// thou art fair
