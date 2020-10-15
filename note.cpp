#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<n; i++)

template<class T>
class SegmentTree {

public:
    /**
     * @param N size
     * @param e identity element
     * @param operation operation for query
     * @param updater operation for update
     */
    SegmentTree(size_t N, T e, function<T(T, T)> operation, function<T(T, T)> updater)
            : e(e), operation(std::move(operation)), updater(move(updater)) {
        n = 1;
        while (n < N) {
            n *= 2;
        }
        data = vector<T>(2 * n - 1, e);
    }

    /**
     * iの値をxに更新
     * @param i index ( 0-indexed )
     * @param x  value
     */
    void update(int i, T x) {
        i += n - 1;
        data[i] = updater(data[i], x);
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = operation(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }

    /**
     * [a, b)の区間でクエリを実行
     */
    T query(int a, int b) {
        return query(a, b, 0, 0, n);
    }

    /**
     * 添字でアクセス
     * @param i index ( 0-indexed )
     */
    T operator[](int i) {
        return data[i + n - 1];
    }

private:
    int n;
    vector<T> data;
    T e;
    function<T(T, T)> operation;
    function<T(T, T)> updater;

    T query(int a, int b, int k, int l, int r) {
        // 交差しない
        if (r <= a || b <= l) return e;
        // 区間 [a, b) に l, r が含まれる
        if (a <= l && r <= b) return data[k];
        // 左の子
        T c1 = query(a, b, 2 * k + 1, l, (l + r) / 2);
        // 右の子
        T c2 = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return operation(c1, c2);
    }
};






int main() {
    vector<int> a={1, 3, 7, 2, 5, 3, 5, 9, 2, 4, 3, 5, 5, 2, 5};
	return 0;
}