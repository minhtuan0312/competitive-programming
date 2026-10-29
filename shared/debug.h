// Local-only debug printer: dbg(x, v, mp) -> stderr with line number.
// Only included when compiled with -DLOCAL, so it never reaches the judge.
#pragma once
#include <bits/stdc++.h>

namespace dbg_impl {
template <class T, class = void> struct is_iterable : std::false_type {};
template <class T>
struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>()))>> : std::true_type {};

template <class T> void print(const T &x);
template <class A, class B> void print(const std::pair<A, B> &p) {
    std::cerr << '(';
    print(p.first);
    std::cerr << ", ";
    print(p.second);
    std::cerr << ')';
}
template <class... Ts> void print(const std::tuple<Ts...> &t) {
    std::cerr << '(';
    std::apply([](const auto &...xs) {
        int i = 0;
        ((std::cerr << (i++ ? ", " : ""), print(xs)), ...);
    }, t);
    std::cerr << ')';
}
template <class T, class S, class C> void print(std::priority_queue<T, S, C> q) {
    std::cerr << "pq{";
    for (bool f = true; !q.empty(); q.pop(), f = false) std::cerr << (f ? "" : ", "), print(q.top());
    std::cerr << '}';
}
template <class T> void print(std::stack<T> s) {
    std::vector<T> v;
    for (; !s.empty(); s.pop()) v.push_back(s.top());
    std::reverse(v.begin(), v.end());
    print(v);
}
template <class T> void print(std::queue<T> q) {
    std::vector<T> v;
    for (; !q.empty(); q.pop()) v.push_back(q.front());
    print(v);
}
template <class T> void print(const T &x) {
    if constexpr (std::is_convertible_v<T, std::string_view>) {
        std::cerr << '"' << std::string_view(x) << '"';
    } else if constexpr (is_iterable<T>::value) {
        std::cerr << '{';
        bool f = true;
        for (const auto &e : x) std::cerr << (f ? "" : ", "), print(e), f = false;
        std::cerr << '}';
    } else {
        std::cerr << x;
    }
}
template <class... Ts> void out(const char *names, const Ts &...xs) {
    std::cerr << names << " = ";
    int i = 0;
    ((std::cerr << (i++ ? " | " : ""), print(xs)), ...);
    std::cerr << std::endl;
}
}  // namespace dbg_impl

#define dbg(...) (std::cerr << "\033[1;33m[L" << __LINE__ << "]\033[0m ", dbg_impl::out(#__VA_ARGS__, __VA_ARGS__))
