#pragma region Macros
#include<bits/stdc++.h>
//#include<atcoder/all>
//using namespace atcoder;
using namespace std;
using ll = long long;
#define endk '\n'
#define pf(a, e) a.insert(a.begin(), e)
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vll vector<ll>
#define rep(i,n) for(ll i=0; i<(n); i++)
#define loop(i, j, n) for(ll i=j; i<(n); i++)
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define drop(s) cout << s << endk, exit(0)
#define print(x) cout << (x) << '\n'
#define all(x) (x).begin(), (x).end()
#define UNIQUE(v) v.erase(unique(all(v)), v.end())
#define SP(num, keta) cout << setprecision(keta) << fixed <<num<< '\n'
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
constexpr int INF  = 0x3f3f3f3f;
const long long mod=1e9+7;
const long double PI = acos(-1);
template<class T, class S> inline bool chmax(T &a, const S &b){ 
    if (a<b){ 
        a = b; 
        return 1; 
    } 
    return 0; 
}
template<class T, class S> inline bool chmin(T &a, const S &b){
    if (a>b){
        a = b;
        return 1; 
    } 
    return 0; 
}
#define INT(...)                                                                                                                                               \
    int __VA_ARGS__;                                                                                                                                           \
    IN(__VA_ARGS__)
#define LL(...)                                                                                                                                                \
    ll __VA_ARGS__;                                                                                                                                            \
    IN(__VA_ARGS__)
#define STR(...)                                                                                                                                               \
    string __VA_ARGS__;                                                                                                                                        \
    IN(__VA_ARGS__)
#define CHR(...)                                                                                                                                               \
    char __VA_ARGS__;                                                                                                                                          \
    IN(__VA_ARGS__)
#define DBL(...)                                                                                                                                               \
    double __VA_ARGS__;                                                                                                                                        \
    IN(__VA_ARGS__)
template<class T> void scan(T &a) { cin >> a; }
void IN() {}
template<class Head, class... Tail> void IN(Head &head, Tail &... tail)
{
    scan(head);
    IN(tail...);
}
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }

void dump() { cerr << '\n'; }
template <class Head, class... Tail> void dump(Head head, Tail... tail) {
    cerr << to_string(head) << " ";
    dump(tail...);
}
#define Dump(...) cout<<"  "; \
cout<<#__VA_ARGS__<<" :["<<__LINE__<<":"<<__FUNCTION__<<"]"<<endl; \
cout<<"   "; \
dump(__VA_ARGS__)

template<class T> inline T div_up(T a, T b){
    if(b == 0) cout << "ZERO_de_WATTERUYO!!" << '\n';
    return (a%b == 0)? a/b : a/b+1; 
}
//デバッグ方法
//debug(配列、変数など一つだけ);
//Dump(変数を複数 a, b, c);
//多次元配列初期化方法
// vv(int, seq, 5, 5, -1);
// vv(型, 名前, 縦, 横, 埋める数);
/* ------------------------------------------------------------------------- */
#pragma endregion   

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
 

int main() {
    LL(N, Q);
    vector<ll> a(N);
    rep(i,N) cin >> a[i];
    segtree<ll> sg(a, [&](int a, int b){return a^b;}, 0);

    rep(i,Q){
        LL(mode, X, Y);
        X--;
        if(mode == 2){
            cout << sg.get(X, Y) << endl;
        }else{
            sg.update(X, sg.get(X)^Y);
        }
    }

	return 0;
}



