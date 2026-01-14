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

const int limN = 1e6 + 5;
int lp[limN];
vector<int> primes;
void linear_sieve() {
    FOR(i, 2, limN) {
        if(!lp[i]) {
            lp[i] = i;
            primes.pb(i);
        }
        int size_ = sz(primes);
        for(int j = 0; j < size_ && i * primes[j] < limN; j++) {
            lp[i * primes[j]] = primes[j];
            if(i == primes[j]) break;
        }
    }
}

int freq[limN] = {0};

vector<pair<int, int>> factorization(int n) {
    vector<pair<int, int>> res;
    int sq = sqrt(n);
    for(int i = 2; i <= sq; i++) {
        if (n % i == 0) {
            int p = 0;
            while(n % i == 0) {
                p++;
                n /= i;
            }
            res.eb(i, p);
        }
    }
    if(n != 1) res.eb(n, 1);
    return res;
}

vector<vector<pair<int, int>>> facts;

int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    linear_sieve();

    int n; cin >> n;
    int A[n + 1];
    FOR(i, 1, n + 1) {
        cin >> A[i];
        facts.pb(factorization(A[i]));
    }
    for(const auto &x: facts) {
        for(const auto &[p, e]: x) {
            freq[p] += e;
        }
    }
    ll d = 1, c = 0;
    for(const int &p: primes) {

        if(!freq[p]) continue;

        int require = freq[p] / n;
        d *= pow(p, require);
        int need = 0;
        for(const auto &x: facts) {
            int ie = 0;
            for(const auto [p_, e_]: x) {
                if(p_ != p) continue;
                ie = e_;
                break;
            }
            if(ie < require) {
                need += require - ie;
            }
        }
        c += need;
    }
    cout << d << ' ' << c;

    return (0 ^ 0);

}

// thou art fair
