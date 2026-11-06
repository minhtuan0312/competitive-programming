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

/* ----------------------------- END OF TEMPLATE ---------------------------- */

int A[9][9];

unordered_map<int, bool> check_grid_3_3[3][3];
unordered_map<int, bool> check_row[9];
unordered_map<int, bool> check_col[9];

void solve(int i, int j) {
    if(i == 9) {
        FOR(i, 0, 9) {
            FOR(j, 0, 9) {
                if(!A[i][j]) {
                    return;
                }
            }
        }
        FOR(i, 0, 9) {
            FOR(j, 0, 9) {
                cout << A[i][j] << ' ';
            }
            cout << nl;
        }
        exit(0);
        return;
    }
    if(A[i][j] == 0) {
        FOR(v, 1, 10) {
            int st_row = i / 3;
            int st_col = j / 3;
            if(check_grid_3_3[st_row][st_col][v] || check_row[j][v] || check_col[i][v]) continue;
            
            A[i][j] = v;
            check_grid_3_3[st_row][st_col][v] = check_row[j][v] = check_col[i][v] = 1;
            if(j == 8) {
                solve(i + 1, 0);
            } else {
                solve(i, j + 1);
            }
            A[i][j] = 0;
            check_grid_3_3[st_row][st_col][v] = check_row[j][v] = check_col[i][v] = 0;
        }
        return;
    }

    if(j == 8) {
        solve(i + 1, 0);
    } else {
        solve(i, j + 1);
    }
}

int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    
    FOR(i, 0, 9) {
        FOR(j, 0, 9) {
            cin >> A[i][j];
        }
    }

    // pre processing row
    FOR(j, 0, 9) {
        FOR(i, 0, 9) {
            if(!A[i][j]) continue;
            check_row[j][A[i][j]] = 1;
        }
    }

    // pre processing col
    FOR(i, 0, 9) {
        FOR(j, 0, 9) {
            if(!A[i][j]) continue;
            check_col[i][A[i][j]] = 1;
        }
    }

    // pre processing grid 3x3
    FOR(i, 0, 3) {
        FOR(j, 0, 3) {
            FOR(s, i * 3, i * 3 + 3) {
                FOR(t, j * 3, j * 3 + 3) {
                    if(!A[s][t]) continue;
                    check_grid_3_3[i][j][A[s][t]] = 1;
                }
            }
        }
    }

    solve(0, 0);

    return (0 ^ 0);

}

/* ------------------------------ THOU ART FAIR ----------------------------- */