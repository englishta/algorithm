#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<n; i++)
/* SegmentTree：[0,n-1] について、区間ごとの最小値を管理する構造体
    update(i,x): i 番目の要素を x に更新。O(log(n))
    query(a,b): [a,b) での最小の要素を取得。O(log(n))
*/
template <typename T>
struct SegmentTree {

    int n;         // 葉の数
    vector<T> node; // 完全二分木の配列

    SegmentTree(vector<T> v) { // 葉の数は 2^x の形
        int sz = v.size;
        n = 1; while (n < sz) n *= 2;
        node.resize(2*n-1, INF);

        // 最下段に値を入れたあとに、下の段から順番に値を入れる
        // 値を入れるには、自分の子の 2 値を参照すれば良い
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }

    void update(int i, T x) {
        i += n - 1;
        node[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;  // parent
            node[i] = min(node[i * 2 + 1], node[i * 2 + 2]);
        }
    }

    // the minimum element of [a,b)
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return INF;
        } else if (a <= l && r <= b) {
            return node[k];
        } else {
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
};


int main() {
    
	return 0;
}