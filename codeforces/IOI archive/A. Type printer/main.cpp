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

vector<int> res;
struct trie{
    static const int MAXNODE = 500005;
    int nxt[MAXNODE][26], cnt;
    bool isEnd[MAXNODE], on_longest_path[MAXNODE];
    trie() {
        cnt = 0;
        memset(nxt, 0, sizeof nxt);
        memset(isEnd, 0, sizeof isEnd);
        memset(on_longest_path, 0, sizeof on_longest_path);
    }
    void Insert(const string &s) {
        int u = 0;
        for(const char &c: s) {
            int k = c - 'a';
            if(!nxt[u][k]) nxt[u][k] = ++cnt;
            u = nxt[u][k];
        }
        isEnd[u] = 1;
    }
    void dfs(int u = 0) {

        if(isEnd[u]) res.eb('P');

        int special = -1;
        FOR(k, 0, 26) {
            if(!nxt[u][k]) continue;
            int v = nxt[u][k];
            if(on_longest_path[v]) {
                special = k;
                break;
            }
        }
        FOR(k, 0, 26) {
            if(!nxt[u][k] || k == special) continue;
            res.eb(char(k + 'a'));
            dfs(nxt[u][k]);
            res.eb('-');
        }

        if(special != -1) {
            res.eb(char(special + 'a'));
            dfs(nxt[u][special]);
        }

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

    res.reserve(1e6);

    int n; cin >> n;
    string s, longest_word;
    while(n--) {
        cin >> s;
        if(sz(longest_word) < sz(s)) longest_word = s;
        t.Insert(s);
    }

    int u = 0;
    for(const char &c: longest_word) {
        u = t.nxt[u][c - 'a'];
        t.on_longest_path[u] = 1;
    }
    t.dfs();
    cout << sz(res) << nl;
    for(const char &c: res) cout << c << nl;

    return (0 ^ 0);

}

// thou art fair
