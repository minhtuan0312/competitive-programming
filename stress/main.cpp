#include <bits/stdc++.h>

using namespace std;

#define bit(mask, i) ((mask >> i) & 1)
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define ll long long

template<class T>
void minimize(T &x, const T &y) {
    if(x > y) x = y;
}
template<class T>
void maximize(T &x, const T &y) {
    if(x < y) x = y;
}

template<typename T1, typename T2>
void __print(const pair<T1, T2> &p);

template<typename T, typename ...V>
void __print(const vector<T, V...> &v);

template<typename T>
void __print(const T &t) {cerr << t;}

template<typename T1, typename T2>
void __print(const pair<T1, T2> &p) {
    cerr << "(";
    __print(p.fi);
    cerr << ", ";
    __print(p.se);
    cerr << ")";
}

template<typename T, typename ...V>
void __print(const vector<T, V...> &v) {
    cerr << "[";
    FOR(i, 0, sz(v)) {
        if(i) cerr << ", ";
        __print(v[i]);
    }
    cerr << "]";
}


template<typename T, typename ...V>
void __print(const vector<T, V...> &v);

int main() {
    #define TASK "main"
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }

    ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0);

    int a, b; cin >> a >> b;
    cout << a + b + 1;

}
