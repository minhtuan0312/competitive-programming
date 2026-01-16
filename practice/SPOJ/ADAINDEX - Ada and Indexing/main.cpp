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

struct trie{
    static const int MAXNODE = 1e6 + 5;
    int cnt, cntPass[MAXNODE], cntEnd[MAXNODE], nxt[MAXNODE][26];
    trie() {
        cnt = 0;
        memset(cntPass, 0, sizeof cntPass);
        memset(cntEnd, 0, sizeof cntEnd);
        memset(nxt, 0, sizeof nxt);
    }
    void Insert(const string &s) {
        int u = 0;
        cntPass[u]++;
        for(char c : s) {
            int k = c - 'a';
            if(!nxt[u][k]) nxt[u][k] = ++cnt;
            u = nxt[u][k];
            cntPass[u]++;
        }
        cntEnd[u]++;
    }
    int CountPrefix(const string &s) {
        int u = 0;
        for(char c : s) {
            int k = c - 'a';
            if(!nxt[u][k]) return 0;
            u = nxt[u][k];
        }
        return cntPass[u];
    }
};

trie t;
int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    int n, q; cin >> n >> q;
    string s;
    while(n--) {
        cin >> s;
        t.Insert(s);
    }
    while(q--) {
        cin >> s;
        cout << t.CountPrefix(s) << nl;
    }

    return (0 ^ 0);

}

// thou art fair
