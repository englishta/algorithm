#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<(n); i++)
using ll = long long;


template<typename T>
struct segtree {
private:
	int siz=1, N;
	vector<T> node;
	const function<T(T, T)> op;
	const T e_;
 
public:
	segtree(int n, function<T(T, T)> func, T e) : N(n), op(func), e_(e) {
		while(siz < N) siz *= 2;
		node.resize(2*siz-1, e_);
	}
	segtree(const vector<T> &v, function<T(T,T)> func, T e) : N(v.size()), op(func), e_(e) {
		while(siz < N) siz *= 2;
		node.resize(2*siz-1, e_);
		for(int i=0; i<N; i++) node[siz-1+i] = v[i];
		for(int i=siz-2; i>=0; i--) node[i] = op(node[2*i+1], node[2*i+2]);
	}
 
	void update(int idx, T val) {
		idx += siz-1;
		node[idx] = val;
 
		while(idx > 0) {
			idx = (idx-1)/2;
			node[idx] = op(node[2*idx+1], node[2*idx+2]);
		}
	}
 
	T get(int idx) {
		assert(0<=idx && idx<N);
		return get(idx, idx+1);
	}
	T get(int L, int R) {
		if(L < 0) L = 0;
		if(R > N) R = N;
		assert(L < R);
		return get__(L, R, 0, 0, siz);
	}
private:
	T get__(int L, int R, int id, int l, int r) {
		if(r<=L || R<=l) return e_;
		if(L<=l && r<=R) return node[id];
		T vl = get__(L, R, 2*id+1, l, (l+r)/2);
		T vr = get__(L, R, 2*id+2, (l+r)/2, r);
		return op(vl, vr);
	}
public:
};

int main(void){
    ll N, Q; cin >> N >> Q;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];

    auto XOR =[&](int a, int b){return a^b;};
    segtree<ll> sg(a, XOR, 0);

    rep(i,Q){
        ll mode, X, Y; cin >> mode >> X >> Y;
        X--;
        if(mode == 2){
            cout << sg.get(X, Y) << endl;
        }else{
            sg.update(X, sg.get(X)^Y);
        }
    }
    return 0;
}