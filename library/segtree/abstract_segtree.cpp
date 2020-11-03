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
    
    T def;         //埋め込む値
    int n;         // 葉の数
    vector<T> dat; // 完全二分木の配列
    function<T(T, T)> operation;   //処理の関数、es)min __gcd maxなど
    function<T(T, T)> updater;     //値の上書き時の処理関数

    RMQ(size_t sz, T _def, function<T(T, T)> _operation, function<T(T, T)> _updater)
    : def(_def), operation(_operation), updater(_updater)
    {
        n = 1;
        while (n < sz) n *= 2;
        dat = vector<T>(2 * n-1, def);
    }

    void update(int i, T x) {
        i += n - 1;
        dat[i] = updater(dat[i], x);
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
    auto GCD = [](int a, int b){
        if(a == -1 || b == -1) return (a+b+1);
        else return __gcd(a, b);
        //dafは-1で初期化
    };
    auto SUM = [](int e, int f){return (e+f);};  //def = 0
    auto MIN = [](int g, int h){return min(g, h);}; //def = 1e9+7
    auto MAX = [](int p, int q){return max(p, q);}; //def = 0 or -1
    auto up = [](int c, int d){return d;};

    vector<int> v={1, 2, 4, 4, 8, 6, 2};
    RMQ<int> tree(v.size(), -1, GCD, up);

    for(int i=0; i<v.size(); i++) tree.update(i, v[i]);

    for(auto x : tree.dat) cout << x << " ";
    cout << endl;
    cout << tree.query(4, 6) << endl;
	return 0;
}