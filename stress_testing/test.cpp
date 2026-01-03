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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
// Random n numbers between l and r
void num(int l, int r, int n) {
    for (int i = 0; i < n; ++i)
    {
        cout << rand(l,r) << " ";
    }
}

//Random n real numbers between l and r with dig decimal places
void real(int l, int r, int dig, int n) {
    for (int i = 0; i < n; ++i)
    {
        cout << rand(l,r) <<"."<<rand(0,pow(10,dig)-1)<< " ";
    }
}
// Random n strings of length l
void str(int l, int n) {
    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < l; ++j) {
            int v = rand(1,150);
            if(v%3==0) cout<<(char)rand('a','z');
            else if(v%3==1) cout<<(char)rand('A','Z');
            else cout<<rand(0,9);
        }
        cout<<" ";
    }
}
// Random n strings of max length l
void strmx(int mxlen, int n) {
    for (int i = 0; i < n; ++i)
    {
        int l = rand(1,mxlen);
        for(int j = 0; j < l; ++j) {
            int v = rand(1,150);
            if(3%3==0) cout<<(char)rand('a','z');
            else if(v%3==1) cout<<(char)rand('A','Z');
            else cout<<rand(0,9);
        }
        cout<<" ";
    }
}
// Random tree of n nodes
void tree(int n) {
    int prufer[n-2];
    for ( int i = 0; i < n; i++ ){
        prufer[i] = rand(1,n);
    }
    int m = n-2;
    int vertices = m + 2;
    int vertex_set[vertices];
    for (int i = 0; i < vertices; i++)
        vertex_set[i] = 0;
    for (int i = 0; i < vertices - 2; i++)
        vertex_set[prufer[i] - 1] += 1;
    int j = 0;
    for (int i = 0; i < vertices - 2; i++) {
        for (j = 0; j < vertices; j++) {
            if (vertex_set[j] == 0) {
                vertex_set[j] = -1;
                cout << (j + 1) << " "
                     << prufer[i] << '\n';
                vertex_set[prufer[i] - 1]--;
                break;
            }
        }
    }
    j = 0;
    for (int i = 0; i < vertices; i++) {
        if (vertex_set[i] == 0 && j == 0) {
            cout << (i + 1) << " ";
            j++;
        }
        else if (vertex_set[i] == 0 && j == 1)
            cout << (i + 1) << "\n";
    }
}

int main(void) {
    minhtuan0312;

    #define TASK "main"
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }



    return (0 ^ 0);

}

// thou art fair
