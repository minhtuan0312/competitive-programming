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

int n, maxw;
struct g{
    int w, v;
};
g A[105];

namespace dp_2d {

    ll dp[105][100005]; //dp[i][j] max giá trị đồ vật Taro có thể mang về nhà khi xét tới vật thứ i với trọng lượng tối đa là j

    void solve(void) {

        memset(dp, 0, sizeof dp);
        FOR(i, 1, n + 1) {
            FOR(j, 1, maxw + 1) {
                //TH1 skip
                maximize(dp[i][j], dp[i - 1][j]);
                //TH2 take
                if(A[i].w <= j) {
                    maximize(dp[i][j], dp[i - 1][j - A[i].w] + A[i].v);
                }
            }
        }
        cout << dp[n][maxw];

    }

}

namespace dp_1d {

    ll dp[100005]; // dp[w] cướp được tổng w trọng lượng thì tổng giá trị lớn nhất là

    void solve(void){

        memset(dp, 0, sizeof dp);
        FOR(i, 1, n + 1) {
            for(int j = maxw; j >= A[i].w; j--) { // chạy ngược lại vì nếu chạy xuôi thì sẽ dẫn đến chạy qua những giá trị đã cập nhật và dẫn đến bài toán trở thành unbounded knapsack
                maximize(dp[j], dp[j - A[i].w] + A[i].v);
            }
        }
        cout << dp[maxw];

    }

}

int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    cin >> n >> maxw;
    FOR(i, 1, n + 1) cin >> A[i].w >> A[i].v;

    //dp_2d::solve();
    dp_1d::solve();

    return (0 ^ 0);

}

// thou art fair
