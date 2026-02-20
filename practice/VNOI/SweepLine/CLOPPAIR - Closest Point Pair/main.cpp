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
inline bool minimize(T &x, const T &y) {
    if (x > y) return x = y, 1;
    return 0;
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

struct Point{
    double x, y;
    int id; //nếu đề bài yêu cầu in ra vị trí điểm
    bool operator<(const Point &other) const {
        if(x == other.x) return y < other.y;
        return x < other.x;
    }
};

typedef pair<int, int> ii;

double dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

struct cmp{
    bool operator()(const Point &a, const Point &b) const {
        if(a.y == b.y) return a.x < b.x;
        return a.y < b.y;
    }
};

int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    int n; cin >> n;
    Point A[n + 1];
    FOR(i, 1, n + 1) {
        cin >> A[i].x >> A[i].y;
        A[i].id = i;
    }
    sort(A + 1, A + 1 + n); // sort theo hoành độ
    set<Point, cmp> se;

    double min_d = 1e18;
    int best_i = -1, best_j = -1;
    int j = 1;
    FOR(i, 1, n + 1) {
        while(j < i && A[i].x - A[j].x >= min_d) {
            se.erase(A[j]);
            j++;
        }
        // lấy y đầu tiên thõa mãn [y[i] - d, y[i] + d]
        // x = -1e18 để đảm bảo nếu nhiều điểm cùng y thì lấy điểm đầu tiên
        Point lower_bound_pt = {-1e18, A[i].y - min_d, - 1};
        auto it = se.lower_bound(lower_bound_pt);
        while(it != se.end() && it->y <= A[i].y + min_d) {
            if(minimize(min_d, dist(A[i], *it))) {
                best_i = A[i].id;
                best_j = it->id;
            }
            it++;
        }
        se.insert(A[i]);
    }
    if(best_i > best_j) swap(best_i, best_j);
    best_i--, best_j--;
    cout << best_i << ' ' << best_j << ' ';
    cout << fixed << setprecision(6) << min_d;

    return (0 ^ 0);

}

// thou art fair
