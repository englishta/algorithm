#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<n; i++)

/* RMQ：[0,n-1] について、区間ごとの最小値を管理する構造体
    update(i,x): i 番目の要素を x に更新。O(log(n))
    query(a,b): [a,b) での最小の要素を取得。O(log(n))
*/
template <typename T>
class RMQ {
    public:
    
    T def;
    int n;         // 葉の数
    vector<T> dat; // 完全二分木の配列
    function<T(T, T)> operation;


    RMQ(size_t sz, T _def, function<T(T, T)> _operation)
    : def(_def), operation(_operation)
    {
        n = 1;
        while (n < sz) n *= 2;
        dat = vector<T>(2 * n-1, def);
    }

    void update(int i, T x) {
        i += n - 1;
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;  // parent
            dat[i] = operation(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }

    // the minimum element of [a,b)
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return def;
        } else if (a <= l && r <= b) {
            return dat[k];
        } else {
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return operation(vl, vr);
        }
    }
};


int main() {
    auto f = [](int a, int b){return max(a, b);};

    vector<int> a={2, 2, 2, 4, 8, 6, 2, 2};
    RMQ<int> tree(a.size(), 1e9+7, f);

    for(int i=0; i<a.size(); i++) tree.update(i, a[i]);

    for(auto x : tree.dat) cout << x << " ";
    cout << endl;
    cout << tree.query(2, 6) << endl;
	return 0;
}