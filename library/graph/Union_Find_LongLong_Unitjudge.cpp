
#include<bits/stdc++.h>
// Begin Header {{{
using namespace std;
using ll = long long;

class UnionFind{
	public:
	vector<ll> r;

	UnionFind(ll N){
		r = vector<ll>(N, -1);
	}

	int root(ll x){
		if(r[x] < 0) return x;
		return r[x] = root(r[x]);
	}

	bool unit(ll x, ll y){
		x = root(x);
		y = root(y);
		if(x == y) return false;
		if(r[x] > r[y]) swap(x, y);
		r[x] += r[y];
		r[y] = x;
		return true;
	}

	ll size(ll x){
		return -r[root(x)];
	}

    bool unit_judge(ll a_, ll b_){
        if(root(a_) == root(b_)) return true;
        else return false;
    }

};

int main() {
	int N, M, x_, y_;
	cin >> N >> M >> x_ >> y_;
	UnionFind UF(N);
	for(int i = 0; i<M; i++){
		ll A, B;
		cin >> A >> B;
		// A-=1; B-=1;
		UF.unit(A, B);
	}
    //if x_ and y_ are  in same group, output "Yes".
    //if not output "No".
    if(UF.unit_judge(x_, y_)) cout << "Yes" << endl;
    else cout << "No" << endl;
	
	return 0;
}