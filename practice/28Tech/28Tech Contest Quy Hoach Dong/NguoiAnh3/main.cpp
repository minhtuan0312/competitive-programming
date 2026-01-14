#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;
#define ll long long
#define nl '\n'
#define all(x) x.begin(), x.end()
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define FORd(i, a, n) for (int i = n - 1; i >= a; i--)
#define minhtuan0312 ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define sz(x) ((int)(x).size())
#define pb push_back
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

int m1, m2, n;
struct g{
    int w, v;
};

g A[205];

namespace dp_3d {

    ll dp[205][205][205]; //dp[i][w1][w2]: giá trị lớn nhất tại vật thứ i với túi w1 và túi w2 là

    void solve() {

        memset(dp, 0, sizeof dp);

        FOR(i, 1, n + 1) {
            FOR(w1, 0, m1 + 1) {
                FOR(w2, 0, m2 + 1) {

                    //TH1 skip
                    maximize(dp[i][w1][w2], dp[i - 1][w1][w2]);

                    //TH2 bỏ vô túi w1
                    if(A[i].w <= w1)
                        maximize(dp[i][w1][w2], dp[i - 1][w1 - A[i].w][w2] + A[i].v);

                    //TH3 bỏ vô túi w2
                    if(A[i].w <= w2)
                        maximize(dp[i][w1][w2], dp[i - 1][w1][w2 - A[i].w] + A[i].v);

                }
            }
        }

        cout << dp[n][m1][m2];

    }

}

namespace dp_2d {

    ll dp[205][205]; // dp[w1][w2]: giá trị lớn nhất với túi w1 và túi w2 là

    void solve() {

        memset(dp, 0, sizeof dp);
        FOR(i, 1, n + 1) {

            for(int w1 = m1; w1 >= 0; w1--) {

                for(int w2 = m2; w2 >= 0; w2--) {

                    //TH2 bỏ vô túi w1
                    if(A[i].w <= w1)
                        maximize(dp[w1][w2], dp[w1 - A[i].w][w2] + A[i].v);

                    //TH3 bỏ vô túi w2
                    if(A[i].w <= w2)
                        maximize(dp[w1][w2], dp[w1][w2 - A[i].w] + A[i].v);

                }

            }

        }

        cout << dp[m1][m2];


    }

}

int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    cin >> m1 >> m2 >> n;
    FOR(i, 1, n + 1) {
        cin >> A[i].v >> A[i].w;
    }

    dp_2d::solve();

    return (0 ^ 0);

}

// thou art fair
