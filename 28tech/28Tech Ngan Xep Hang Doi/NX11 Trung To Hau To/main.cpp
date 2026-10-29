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

int priority(const char &c) {
    if(c == '-' || c == '+') return 1;
    if(c == '*' || c == '/') return 2;
    if(c == '^') return 3;
    return 0;
}

string toPostfix(string s) {
    string res;
    stack<char> st;
    int n = sz(s);
    s = ' ' + s;
    FOR(i, 1, n + 1) {
        if(isspace(s[i])) continue;
        if(isdigit(s[i])) {
            while(i <= n && (isdigit(s[i]) || s[i] == '.')) {
                res += s[i++];
            }
            res += " "; // phân cách các số
            i--;
        }
        else if(s[i] == '(') {
            st.push(s[i]);
        }
        else if(s[i] == ')') {
            while(!st.empty() && st.top() != '(') {
                res += st.top(); st.pop();
                res += " ";
            }
            if(!st.empty()) st.pop(); // đẩy dấu '(' ra
        }
        else {
            while(!st.empty() && st.top() != '(' && (priority(s[i]) < priority(st.top()) || (priority(s[i]) == priority(st.top()) && s[i] != '^'))) {
                res += st.top(); st.pop();
                res += " ";
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()) {
        if(st.top() != '(') {
            res += st.top(); st.pop();
            res += " ";
        } else {
            st.pop();
        }
    }
    return res;
}

double applyOp(double a, double b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
    }
    return 0;
}

double evaluatePostfix(string s) {
    stringstream ss(s);
    string tmp;
    stack<double> st;
    while(ss >> tmp) {
        if(sz(tmp) == 1 && !isdigit(tmp[0]) && tmp[0] != '.') {
            double b = st.top(); st.pop();
            double a = st.top(); st.pop();
            double ab = applyOp(a, b, tmp[0]);
            st.push(ab);
        } else {
            st.push(stod(tmp));
        }
    }
    return st.top();
}

int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    string s; getline(cin, s);
    string pf = toPostfix(s);
    cout << evaluatePostfix(pf);

    return (0 ^ 0);

}

// thou art fair
