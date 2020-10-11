// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

class Prints {
private:
    class __Prints {
    public:
        __Prints(const char* _sep, const char* _term) : sep(_sep), term(_term) {}
        template <class... Args> void operator()(const Args&... args) const { print(args...); }
        template <typename T> void pvec(const T& vec, size_t sz) const {
            for (size_t i = 0; i < sz; i++) std::cout << vec[i] << (i == sz - 1 ? term : sep);
        }
        template <typename T> void pmat(const T& mat, size_t h, size_t w) {
            for (size_t i = 0; i < h; i++)
                for (size_t j = 0; j < w; j++) std::cout << mat[i][j] << (j == w - 1 ? term : sep);
        }

    private:
        const char *sep, *term;
        void print() const { std::cout << term; }
        void print_rest() const { std::cout << term; }
        template <class T, class... Tail> void print(const T& head, const Tail&... tail) const {
            std::cout << head, print_rest(tail...);
        }
        template <class T, class... Tail> void print_rest(const T& head, const Tail&... tail) const {
            std::cout << sep << head, print_rest(tail...);
        }
    };

public:
    Prints() {}
    __Prints operator()(const char* sep = " ", const char* term = "\n") const { return __Prints(sep, term); }
};

/* -------------------------------------------------- */

Prints print;

int main() {
    int a = 4, b = 5;
    string S = "abc";
    print()(a, b, S);
    print(", 区切り ,", "改行\n")("あ", "いう", "えお");
    print()();

    V<int> A = {1, 2, 3, 4, 5, 6};
    print().pvec(A, 6);
    print()();

    VV<int> mat = {{10, 20, 30}, {40, 50, 60}};
    print().pmat(mat, 2, 3);
}