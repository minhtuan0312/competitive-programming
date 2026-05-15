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


// * ví dụ 1: liệt kê dãy số
// cho hai số n và k, liệt kê theo thứ tự từ điển tăng dần các dãy số độ dài n, với các số có giá trị từ 1 đến k

// - dãy có thứ tự từ điển nhỏ nhất là dãy n số 1
// - cách tìm dãy liền sau của a[1] a[2] ... a[n]
    // + duyệt i từ n về 1, tìm vị trí phải nhất mà a[i] < k
        // a[i]++
        // với mọi j = i + 1 -> n, gán a[j] = 1
    // + nếu không tìm được vị trí có a[i] < k -> mọi vị trí đều = k -> dãy có thứ tự từ điển lớn nhất

namespace vidu1 {
    int n, k;
    bool getNext(int A[]) {
        for(int i = n; i >= 1; i--) {
            if(A[i] < k) {
                A[i]++;
                for(int j = i + 1; j <= n; j++) A[j] = 1;
                return 1;
            }

        }
        return 0;
    }

    void solve() {
        cin >> n >> k;
        int A[n + 1];
        FOR(i, 1, n + 1) A[i] = 1;
        do {
            FOR(i, 1, n + 1) {
                if(i > 1) cout << ", ";
                cout << A[i];
            }
            cout << nl;
        } while(getNext(A));
    }
}

// * ví dụ 2: liệt kê hoán vị

// 1. tìm hậu tố giảm dần dài nhất. Nói cách khác duyệt i từ n về 1, tìm vị trí đầu tiên sau cho a[i] < a[i + 1] (vị trí đầu tiên không giảm dần)
// -> a[i + 1] > a[i + 2] > a[i + 3]... > a[n] là hậu tố giảm dần dài nhất

// 2. tăng a[i] lên giá trị tiếp theo trong đoạn a[i + 1 -> n] (gán a[i] = giá trị nhỏ nhất > a[i] hiện tại trong đoạn a[i + 1 - > n]), đổi chỗ với vị trí đó
// 3. đảo ngược a[i + 1 -> n] để thành dãy tăng dần

// - nếu ở bước 1 ko tìm thấy giảm dần -> hoán vị cuối cùng cần liệt kê -> thứ tự từ điển lớn nhất

namespace vidu2 {

    int n;
    bool getNext(int A[]) {

        for(int i = n - 1; i >= 1; i--) {

            if(A[i] < A[i + 1]) {

                for(int j = n; j >= i + 1; j--) {
                    if(A[i] < A[j]) {
                        swap(A[i], A[j]);
                        break;
                    }
                }
                reverse(A + i + 1, A + n);
                return 1;
            }
        }
        return 0;

    }

    void solve() {
        cin >> n;

        int A[n];
        FOR(i, 1, n + 1) A[i] = i;

        do{
            FOR(i, 1, n + 1) {
                if(i > 1) cout << ", ";
                cout << A[i];
            }
            cout << nl;
        } while(getNext(A));

    }

}

// *quy luật chung

// Bước 1. tìm đoạn mà ở đó mọi vị trí đều chọn phương án lớn nhất có thể. Gọi i là vị trí phải nhất còn có thể lớn hơn
// Bước 2. tăng vị trí i tìm được ở bước 1 thêm 1 nấc (giá trị lớn hơn tiếp theo)
// Bước 3. đưa mỗi vị trí từ i + 1 -> n, chọn giá trị nhỏ nhất có thể cho nó
// + trong trường hợp không tìm được vị trí i ở bước 1, ta đã ở dãy có thứ tự từ điển lớn nhất

// độ phức tạp cho việc tìm dãy tiếp theo tối đa có thể là O(n), thực tế nó tuyến tính với độ dài phần bị biến đổi

// ******************************************* HỆ QUẢ QUAN TRỌNG
// ** nếu trường hợp tìm hoán vị tiếp theo thứ tự từ điển, khi gọi 1 lần hàm next, độ phức tạp có thể là O(n)
// Nhưng nếu gọi 1e6 lần next liên tiếp, tổng đpt chỉ ~ O(n + 1e6) chứ không phải O(n * 1e6)

// * ví dụ 3: liệt kê dãy ngoặc đúng
// cho số n, liệt kê các dãy ngoặc đúng theo thứ tự từ điển tăng dần

// - định nghĩa dãy ngoặc đúng
// + mỗi kí tự trong xâu đều là mở ngoặc (hoặc đóng ngoặc)
// + số ký tự mở ngoặc bằng số ký tự đóng ngoặc (bằng n / 2)
// + trong một tiền tố bất kỳ, số ký tự mở ngoặc không ít hơn số ký tự đóng ngoặc
// + số lượng dãy ngoặc đúng độ dày n: số catalan


int main(void) {
    minhtuan0312;

    #define TASK ""
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    vidu2::solve();

    return (0 ^ 0);

}

// thou art fair
